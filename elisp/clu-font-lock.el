;;;; clu-font-lock.el - highlighting for CLU programming language

;;;; Copyright (c) 2021 Valery Ushakov
;;;; All rights reserved.
;;;;
;;;; Redistribution and use in source and binary forms, with or without
;;;; modification, are permitted provided that the following conditions
;;;; are met:
;;;; 1. Redistributions of source code must retain the above copyright
;;;;    notice, this list of conditions and the following disclaimer.
;;;; 2. Redistributions in binary form must reproduce the above copyright
;;;;    notice, this list of conditions and the following disclaimer in the
;;;;    documentation and/or other materials provided with the distribution.
;;;;
;;;; THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
;;;; IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
;;;; OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
;;;; IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
;;;; INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
;;;; NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;;;; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;;;; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;;;; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
;;;; THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

(defvar clu-font-lock-keywords-1 nil
  "Subdued level highlighting for Clu mode.")

(defvar clu-font-lock-keywords-2 nil
  "Medium level highlighting for Clu mode.")

(defvar clu-font-lock-keywords-3 nil
  "Gaudy level highlighting for Clu mode.")


(defun clu-font-lock-match-namelist-item-and-skip-to-next (limit)
  "Font Lock MATCH-ANCHORED matcher that iterates over the comma
separated list of names in Clu synax constructs.

See `font-lock-keywords' for description."
  ;; ;; debugging
  ;; (let* ((pt (point))
  ;; 	 (sz (buffer-size)))
  ;;   (message ">>> Called at %s with limit %s = \"%s\"+\"%s\""
  ;; 	     pt limit
  ;; 	     (buffer-substring (max (point-min) (- pt 15)) pt)
  ;; 	     (buffer-substring pt (min (point-max) (+ pt 15)))))
  (when (looking-at "\\s-*\\_<\\(\\sw+\\)\\_>")
    (prog1 t
      (goto-char (match-end 1))
      (save-match-data
	(when (looking-at "\\s-*,")
	  (goto-char (match-end 0)))))))

(defun clu-font-lock-namelist (&rest highlight)
  "Syntactic sugar for ANCHORED-HIGHLIGHTER that iterates over a
namelist."
  `(clu-font-lock-match-namelist-item-and-skip-to-next ; anchored-matcher
    (goto-char (match-beginning 1))		       ; pre-form
    (goto-char (match-end 0))			       ; post-form
    (1 ,@highlight)))				       ; subexp-highlighter


(let* ((clu-keywords
	(eval-when-compile
	  (regexp-opt
	   '("begin" "break"
	     "cand" "cluster" "continue" "cor"
	     "do" "down"
	     "else" "elseif" "end" "except" "exit"
	     "for" "force"
	     "has"
	     "if" "in" "is" "iter"
	     "others" "own"
	     "proc" "proctype"
	     "resignal" "return" "returns"
	     "signal" "signals"
	     "tag" "tagcase" "then" "type"
	     "up"
	     "when" "where" "while"
	     "yield" "yields"))))

       (clu-type-names
	(eval-when-compile
	  (regexp-opt
	   '("any" "array" "bool" "char" "int" "itertype" "null" "oneof"
	     "real" "record" "sequence" "string" "struct"
	     "variant"))))

       (comma-list-regexp
	"\\_<\\(\\sw+\\)\\(\\s-*,\\s-*\\sw+\\)*\\_>\\s-*")

       (comma-list-regexp-depth
	(regexp-opt-depth comma-list-regexp)))

  ;;;
  ;;; Subdued level highlighting for Clu mode.
  ;;;
  (setq clu-font-lock-keywords-1
    (list
     ;; keywords
     (concat "\\_<\\(" clu-keywords "\\)\\_>")

     ;; types
     (list
      (concat "\\_<\\(" clu-type-names "\\)\\_>")
      1 'font-lock-type-face)

     ;; rep and cvt
     '("\\_<\\(rep\\|cvt\\)\\_>"
       1 font-lock-builtin-face)

     ;; functions
     '("\\_<\\(\\sw+\\)\\_>\\s-*=\\s-*\\(proc\\|iter\\)\\_>"
       1 font-lock-function-name-face)

     ;; clusters
     '("\\_<\\(\\sw+\\)\\_>\\s-*=\\s-*\\(cluster\\)\\_>"
       1 font-lock-type-face)))


  ;;;
  ;;; Medium level highlighting for Clu mode.
  ;;;
  (setq clu-font-lock-keywords-2
    (append clu-font-lock-keywords-1
      (list
       ;; negation
       '("~"
	 0 font-lock-negation-char-face) ; default face by default

       ;; tags in tagscase
       `(,(concat "\\_<tag\\s-+" comma-list-regexp)
	 ,(clu-font-lock-namelist 'font-lock-constant-face)))))

  ;;;
  ;;; Gaudy level highlighting for Clu mode.
  ;;;
  (setq clu-font-lock-keywords-3
    (append clu-font-lock-keywords-2
      (list
       ;; type$foo
       '("\\_<\\(\\sw+\\)\\_>\\(\\$\\)"
	 (1 font-lock-type-face) (2 font-lock-builtin-face))

       ;; constants
       '("\\_<nil\\|false\\|true\\_>"
	 0 font-lock-constant-face)))))


(defvar clu-font-lock-keywords clu-font-lock-keywords-1
  "Default expressions to highlight in Clu mode.")

;; override default font lock keywords
(add-hook 'clu-mode-hook
  '(lambda ()
     (set (make-local-variable 'font-lock-defaults)
	  (list '(clu-font-lock-keywords
		  clu-font-lock-keywords-1
		  clu-font-lock-keywords-2
		  clu-font-lock-keywords-3)))))
