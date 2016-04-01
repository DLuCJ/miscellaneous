;;; computes various means

(in-package #:mathematics)

(defun arithmetic-mean (val &rest args)
  "arithmetic mean of val and some arbitrary
number of other values"
  (cond ((null args) val)
        (t (/ (+ val (apply #'+ args))
              (+ (length args) 1)))))
      

(defun geometric-mean (val &rest args)
  "geometric mean of val and some arbitrary
number of other values"
  (cond ((null args) val)
        (t (nth-root (+ (length args) 1)
                     (* val (apply #'* args))))))

(defun harmonic-mean (val &rest args)
  "harmonic mean of val and some arbitrary
number of other values"
  (labels ((inversify (lst)
             (expt (car lst) -1))
           (sum-inverse ()
             (apply #'+ (maplist #'inversify (cons val args)))))
    (cond ((null args) (expt val -1))
          (t (expt (/ (sum-inverse) 
                      (+ (length args) 1))
                   -1)))))

(defun root-mean-square (val &rest args)
  "root mean square of val and some arbitrary
number of other values"
  (labels ((squareify (lst)
             (expt (car lst) 2))
           (sum-square ()
             (apply #'+ (maplist #'squareify (cons val args)))))
    (cond ((null args) val)
          (t (nth-root 2 
                       (/ (sum-square) 
                          (+ (length args) 1)))))))
