;;
;; CLU mode for GNU Emacs
;;
;; clu-mode: S. Blau, February 1987
;; clu-doc:  Boaz Ben-Zvi, January 30, 1991
;;

(defvar clu-mode-syntax-table nil
  "Syntax table used while in clu mode.")

(if (null clu-mode-syntax-table)
    (let ((st (syntax-table)))
      (unwind-protect
       (progn
	(setq clu-mode-syntax-table (make-syntax-table))
	(set-syntax-table clu-mode-syntax-table)
	(modify-syntax-entry ?[ "(]   ")
	(modify-syntax-entry ?] ")[   ")
	(modify-syntax-entry ?{ "(}   ")
	(modify-syntax-entry ?} "){   ")
	(modify-syntax-entry ?\" "\"   ")
	(modify-syntax-entry ?' "\"    ")
	(modify-syntax-entry ?_ "w    ")
	(modify-syntax-entry ?% "<    ")
	(modify-syntax-entry ?\n ">    "))
       (set-syntax-table st))))

(defvar clu-mode-map nil
  "keymap used in clu-mode")

(if (not clu-mode-map)
    (progn
     (setq clu-mode-map (make-sparse-keymap))
     (define-key clu-mode-map "\t" 'clu-tab)
     (define-key clu-mode-map "\r" 'clu-ret)
     (define-key clu-mode-map "\e&" 'clu-compile)
     (define-key clu-mode-map "\e\t" 'cludent)
     (define-key clu-mode-map "\^x\^k" 'kill-compilation)))

(defun clu-mode ()
  "clu-mode is for editing CLU programs.
TAB     at beginning of line reindents the line, but sometimes poorly
        with prefix-arg, indents all following lines, but slowly
RET     new-line-and-indent
ESC-TAB indents the entire buffer (works better than TAB)
ESC-&   runs interactive CLU compiler
^X`     finds the next error message
^X^K    kills the compiler
Variables controlling indentation style:
 clu-indent
   If nil, turns off automatic language directed indent.
   Default is t.
 clu-indent-size
   Each indentation level offsets text by this much.
   Default is 4.
 clu-cluster-indent
   If nil, turns off indent for cluster and guardian bodies.
   Default is t.
 clu-except-offset
   Extra indentation for line beginning with except-statement.
   Default is 1.
 clu-when-offset
   Extra indentation for line beginning with when-statement.
   Default is -1."
  (interactive)
  (kill-all-local-variables)
  (use-local-map clu-mode-map)
  (setq mode-name "Clu")
  (setq major-mode 'clu-mode)
  (set-syntax-table clu-mode-syntax-table)
  (define-abbrev-table 'clu-mode-abbrev-table ())
  (setq local-abbrev-table clu-mode-abbrev-table)
  (make-local-variable 'indent-line-function)
  (setq indent-line-function 'clu-indent-line)
  (make-local-variable 'comment-start)
  (setq comment-start "%")
  (make-local-variable 'comment-column)
  (setq comment-column 40)
  (make-local-variable 'last-filename) ;For incremental error parsing
  (setq last-filename nil)
  ;; Variables used by external compile program
  (make-local-variable 'name-of-mode)
  (setq name-of-mode "clu-compilation")
  (make-local-variable 'compile-command)
  (setq compile-command
	(concat "pclu " (file-name-nondirectory buffer-file-name)))
  ;;Execute usr's mode-hook if hook defined and not nil
  (and (boundp 'clu-mode-hook)
       clu-mode-hook
       (funcall clu-mode-hook)))

(defvar clu-mode-abbrev-table nil
  "Abbrev table in use in Clu-mode buffers.")

(defvar clu-indent t
   "*If non-nil TAB and RET will do fancy things")

(defvar clu-indent-size 4
  "*Each indentation level offsets text by this much")

(defvar clu-cluster-indent t
   "*If nil cluster and guardian bodies will not be indented")

(defvar clu-except-offset 1
  "*Extra indentation for except-statement")

(defvar clu-when-offset -1
  "*Extra indentation for when-statement")

(defun clu-module (string)
  "Expands current word to a template for a module"
  (let (id)
    (beginning-of-line)
    (setq id
	  (buffer-substring (point)
			    (progn
			      (skip-chars-forward "^ \t$")
			      (point))))
    (end-of-line)
    (insert-string (concat " = " string " ()\n"))
    (clu-indent-line)
    (insert-string (concat "end " id)))
  (skip-chars-backward "^\("))

(defun clu-tab (&optional argp)
  "Indent current line if point is at beginning of line, else insert tab."
  (interactive "P")
  (if (or (not (bolp)) (not clu-indent))
      (insert ?\t)
    (beginning-of-line)
    (if (not argp)
	(clu-indent-line) ;indent current line
      (message "Reindent started...")
      (set-mark (point))
      (while (< (point) (point-max))
	(clu-indent-line)
	(forward-line 1))
      (goto-char (mark))
      (message "Reindent done..."))))

(defun clu-ret ()
;  "Reindent current line then newline and indent"
  "Newline and indent"
  (interactive)
  (if (not clu-indent)
      (newline)
    ;(clu-indent-line)
    (newline)
    (clu-indent-line)))

(defun clu-indent-line (&optional whole-exp)
  "Indent current line as CLU code.
Argument means shift any additional lines of grouping
rigidly with this line."
  (interactive "P")
  (delete-horizontal-space)
  (indent-to (calculate-clu-indent)))

(defun calculate-clu-indent (&optional parse-start)
  "Return appropriate indentation for current line as CLU code."
     (let ((count 0) (count1 0) (col 0) (end-of-line-pos 0))
      (progn
      (save-excursion
	(beginning-of-line)
	(if (eq (point) (point-min)) ;first line in file
	    nil
	(backward-word 1)
	(end-of-line)
	(setq end-of-line-pos (dot))
	(beginning-of-line)
	(setq col (current-indentation))
	(while (not (= (following-char) ?\n))
	  (cond ( (= (following-char) ?%)
		  (progn
		    (end-of-line)
		    (backward-char 1)))
		;( (= (following-char) ?\")
		;  (progn
		;    (forward-char 2)
		;    (re-search-forward "[^\\]\"" end-of-line-pos)
		;    (backward-char 1)))
		( (= (following-char) ?\()
		  (setq count (1+ count)))
		( (= (following-char) ?\))
		  (setq count (1- count)))
		( (looking-at "=[ \t]*")
		  (progn
		    (skip-chars-forward "= \t")
		    (if (or (looking-at "iter")
			    (looking-at "proc")
			    (and clu-cluster-indent
				 (looking-at "cluster")))
			(setq count (1+ count)))))
		( (if (or (= (preceding-char) ? )
			  (= (preceding-char) ?\t))
		  (progn
		    (if (or (looking-at "for[ \t\n(]+")
			     (looking-at "if[ \t\n(]+")
			     (looking-at "while")
			     (looking-at "begin")
			     (looking-at "except")
			     (looking-at "tagcase"))
			(setq count (1+ count))
		      (if (looking-at "end[ \t\n]+")
			  (setq count (1- count))))))))
	  (forward-char 1))
	(beginning-of-line)
	(skip-chars-forward " \t")
	(cond ((looking-at "except") (setq col (- col clu-except-offset)))
	      ((looking-at "else") (setq col (- col -2)))
	      ((looking-at "when") (setq col (- col clu-when-offset))))
	(end-of-line)
	(forward-word 1)
	(beginning-of-line)
	(forward-to-indentation 0)
	(cond ((looking-at "except") (setq col (+ col clu-except-offset)))
	      ((looking-at "else") (setq col (+ col -2)))
	      ((looking-at "when") (setq col (+ col clu-when-offset)))))
	(+ col (* count clu-indent-size))))))

(defun clu-compile ()
  "Compile the CLU program in the current buffer"
  (interactive)
  (if (and (boundp 'compilation-process)
	   compilation-process
	   (eq (process-status compilation-process) 'run))
      (let* ((buf (process-buffer compilation-process))
	     (cbuf (current-buffer)))
	(call-interactively 'clu-command)
	(pop-to-buffer buf)
	(set-window-start (get-buffer-window buf) (- (point) 12))
	(pop-to-buffer cbuf))
    (call-interactively 'compile)
    (if compilation-process
	(progn
	  (save-excursion
	    (set-buffer (process-buffer compilation-process))
	    (clu-compilation-mode))
	  (set-process-filter compilation-process 'clu-filter)))))

(defvar clu-regexp
  "\\(^Compiling[ a-zA-Z0-9/\.]+\\)\\|\\(^[0-9]+:\\)\\|\\(^command\(s\):\\)"
  "Regular expression for filename-lines and error-msg-lines")

(defun clu-filter (proc string)
  "This gets called with each string the compiler outputs"
  (save-window-excursion
    (set-buffer (process-buffer proc))
    ;(if (bolp) (forward-line 2))
    (goto-char (point-max))
    (let ((save-pos (point)) save-pos2 save-pos3)
      ;(goto-char (point-max))
      (insert-string string)
      (goto-char save-pos)
      (while (re-search-forward clu-regexp nil t)
	(setq save-pos2 (match-beginning 0))
	(setq save-pos3 (match-end 0))
	(save-excursion
	  (goto-char (match-beginning 0))
	  (cond ((looking-at "[0-9]+:")
		 (skip-chars-forward "^ \t")
		 (insert-string "\n ")
		 (goto-char save-pos2)
		 (insert-string (concat last-filename ", line ")))
		((looking-at "command\(s\):")
		 (goto-char (point-max))
		 (ding)
		 (message "CLU compiler ready to receive new command\(s\)..."))
		((looking-at "Compiling")
		 (goto-char save-pos3)
		 (skip-chars-backward "^ \n")
		 (setq last-filename
		       (buffer-substring (point)
					 (progn
					   (skip-chars-forward "^\$")
					   (point))))))))
      ;remove \r before \n
      (goto-char save-pos)
      (while (re-search-forward "\" nil t)
	(delete-backward-char 1)))
    (goto-char (point-max))))

(defun clu-command (command)
  "This gets called to prompt and get command for running compiler"
  (interactive (list (read-input "CLU command\(s\): " "")))
  (send-string compilation-process (concat command "\n")))

;;
;;
;; clu-compilation-mode
;;
;;
(defvar clu-compilation-mode nil)
(defvar clu-compilation-mode-map nil)
;(defvar clu-save-buffer nil)

(if (not clu-compilation-mode-map)
    (progn
      (setq clu-compilation-mode-map (make-sparse-keymap))
      (define-key clu-compilation-mode-map "\e&" 'clu-compilation-go-end)
      (define-key clu-compilation-mode-map "\r" 'clu-compilation-command)))

(defun clu-compilation-mode ()
  "string+RET at end of file after the text \"command\(s\):\"
  is interpreted as a command to the clu-compiler"
  (interactive)
  ;(kill-all-local-variables)
  (use-local-map clu-compilation-mode-map)
  ;(setq clu-save-buffer (current-buffer))
  (setq mode-name "clu-compilation")
  (setq major-mode 'clu-compilation-mode))

(defun clu-compilation-command ()
  "This gets called when RET-key is input to *compilation* buffer"
  (interactive)
  (skip-chars-forward " \t")
  (if (not (equal (point) (point-max)))
      (insert-string "\n")
    (skip-chars-backward "^:")
    (set-mark (point))
    (setq command
	  (buffer-substring (point)
			    (progn
			      (skip-chars-forward "^$")
			      (point))))
    (goto-char (mark))
    (delete-region (point) (point-max))
    ;(save-excursion
    ;  (beginning-of-line)
    ;  (set-window-start
    ;   (get-buffer-window (current-buffer)) (point)))
    (send-string compilation-process
		 (concat command "\n"))))

(defun clu-compilation-go-end ()
  "This gets called on ESC-&"
  (interactive)
  (goto-char (point-max)))


; (setq compile-command "clu #externals false #locals false #optimize time\n")


(defun cludent ()
   "indent CLU buffer"
   (interactive)
   (shell-command-on-region (point-min) (point-max) "cludent" t)
   (goto-char (point-min)))
