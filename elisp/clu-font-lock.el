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
	     "variant")))))

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
     '("\\_<rep\\|cvt\\_>"
       0 font-lock-builtin-face)

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
       '("\\_<tag\\_>\\s-+\\(\\sw+\\)\\_>"
	 1 font-lock-constant-face))))


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
