;;;; Mathematics.lisp

(in-package #:mathematics)

;;; Odds and ends
;;; Most likely stray examples from ConCrete mathematics will go here
;;; Plan may change


;; these two transformations lose a little bit of accuracy per call
(defun deg->rad (deg)
  (* deg (/ pi 180)))

(defun rad->deg (rad)
  (* rad (/ 180 pi)))

;;; Nth root newton method
(defun nth-root (n val)
  (labels ((better-guess (guess)
             (/ (+ (* guess ( - n 1))
                   (/ val (expt guess (- n 1))))
                n))
           (good-enough?(guess oldguess)
             (< (abs (- guess oldguess))
                (* guess 0.0001)))
           (nth-root-iter (guess oldguess)
             (if (good-enough? guess oldguess)
                 guess
                 (nth-root-iter (better-guess guess )
                                guess))))
    (cond ((= n 0) nil)
          (t (nth-root-iter 1.0 val)))))

;;; end Nth root newton method

;;; calculates the number of steps for n disks
;;; represents recurrence relation, not closed relation 

(defun tower-of-hanoi (n)
  (labels ((hanoi-iter (n total) 
             (if (= n 0)
                 total 
                 (hanoi-iter (- n 1) (+ (* 2 total)
                                        1)))))
    (hanoi-iter n 0)))

;;; end hanoi

