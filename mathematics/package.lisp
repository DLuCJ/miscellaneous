;;;; package.lisp

(defpackage #:mathematics
  (:use #:cl)
  (:nicknames #:mth)
  (:export #:dot               ;; vector.lisp begins here
           #:cross
           #:v.perp?
           #:v.parallel?
           #:v.scale
           #:v.add
           #:v.sub
           #:p-norm
           #:get-magnitude
           #:normalize
           #:b-parallel
           #:b-perp
           #:v.angle
           #:triple-prod        ;; vector.lisp ends here
           #:arithmetic-mean    ;; averages.lisp begins here
           #:geometric-mean     
           #:root-mean-square
           #:harmonic-mean      ;; averages.lisp ends here
           #:transpose          ;; matrix.lisp begins here
           #:AB
           #:columnify
           #:rowify
           #:column-to-vec
           #:row-to-vec
           #:mat+
           #:mat-
           #:populate-mat3
           #:kM                 ;; matrix.lisp ends here
           #:modified-gram-schmidt ;; eigensolver.lisp begins here
           #:QR  
           #:inverse-iter
           #:get-EV             ;; eigensolver.lisp ends here
           #:tower-of-hanoi     ;; mathematics.lisp begins here
           #:nth-root
           #:deg->rad
           #:rad->deg))         ;; mathematics.lisp ends here 

