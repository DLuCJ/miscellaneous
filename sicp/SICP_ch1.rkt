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

(define (sd-mul x y)  ; x_1 + x_2 + ... + x_y
  (define (double n) (+ n n))
  (define (halve n) (/ n 2))
  (define (mul-iter num times a)  
    (cond ((= times 0) a)
          ((= (remainder times 2) 0)
           (mul-iter (double num) (halve times) a))
          (else (mul-iter num (- times 1) (+ a num)))))
  (mul-iter x y 0))

(define (fib n)
  (fib-iter 1 0 0 1 n))

(define (fib-iter a b p q count)
  (cond ((= count 0) b)
        ((even? count)
         (fib-iter a
                   b
                   (+ (sqr q) (sqr p))
                   (+ (* 2 q p) (sqr q))
                   (/ count 2)))
        (else (fib-iter (+ (* b q) (* a q) (* a p))
                        (+ (* b p) (* a q))
                        p
                        q
                        (- count 1)))))

(define (test-fib n)
  (define (fib-iter a b count)
    (if (= count 0)
        b
        (fib-iter (+ a b) a (- count 1))))
  (fib-iter 1 0 n))

(define (assertfib n)
  (cond ((= n 0) #t)
        ((not (= (fib n) (test-fib n))) #f)
        (else (assertfib (- n 1)))))
                