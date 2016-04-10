#lang racket
(define (my-sqrt x)
  (define (sqrt-iter guess prev x)
    (define (good-enough? guess)
      (if (null? prev) #f
          (< (/ (abs (- guess prev))
                guess)
             0.000001)))
    (define (improve-guess guess)
      (define (average x y) (/ (+ x y) 2))
      (average guess (/ x guess)))
    
    (if (good-enough? guess)
        guess
        (sqrt-iter (improve-guess guess) guess x)))
  
  (sqrt-iter 1.0 null x))

(define (my-cbrt x)
  (define (cbrt-iter guess prev x)
    (define (good-enough? guess)
      (if (null? prev) #f
          (< (/ (abs (- guess prev))
                guess)
             0.000001)))
    (define (improve-guess guess)
      (define (average x y) (/ (+ x y) 3))
      (average (* guess 2)
               (/ x (sqr guess))))
    
    (if (good-enough? guess)
        guess
        (cbrt-iter (improve-guess guess) guess x)))
  
  (cbrt-iter 1.0 null x))

(define (1p11-recursive n)
  (cond ((< n 3) n)
        (else (+ (1p11-recursive (- n 1))
                 (* 2 (1p11-recursive (- n 2)))
                 (* 3 (1p11-recursive (- n 3)))))))

(define (1p11-iterative n)
  (define (1p11-iter a b c count)
    (cond ((= count 0) c)
          (else (1p11-iter (+ a (* 2 b) (* 3 c))
                           a
                           b
                           (- count 1)))))
  (1p11-iter 2 1 0 n))

(define (pascal-recursive n idx)  ; idx : element 0..n of nth row 
  (cond ((= n 0) 1)
        ((or (= idx 0) (= idx n)) 1)
        (else (+ (pascal-recursive (- n 1) (- idx 1))
                 (pascal-recursive (- n 1) idx)))))

; note: 1p13 , prove by expanding out fib(n+1) = fib(n) + fib(n-1)
; into the corresponding phi / psi expressions
; to show equality

(define (ss-expt b n) ; base b, exponent n
  (define (expt-iter xpt base a)
    (cond ((= xpt 0) a)
          ((= (remainder xpt 2) 0)
           (expt-iter (/ xpt 2) (sqr base) a))
          (else (expt-iter (- xpt 1) base (* a base)))))
  (expt-iter n b 1))

