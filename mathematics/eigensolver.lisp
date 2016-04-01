;;; approximate eigensolver
;;; not written for speed

(in-package #:mathematics)

(setf *read-default-float-format* 'long-float)
(defconstant singularEps (* 2 1.192092896e-7)) ;; *2 gives us a little margin

(defun modified-gram-schmidt (mat3)
  "turn linearly independent set of vectors into orthonormal basis
or orthogonalize a nearly-orthogonal matrix"
  (let* ((in (transpose mat3))
         (out-col[0] (normalize (first in)))
         (out-col[1] (normalize (v.sub (second in)
                                       (v.scale out-col[0]
                                                (dot (second in)
                                                     out-col[0])))))
         (out-col[2] (cross out-col[0]
                            out-col[1])))
    (transpose (list out-col[0] out-col[1] out-col[2]))))

(defun QR (mat3 q)
  "QR factorization using MGS
1/Diag elements in diag of R
In: mat3, q (orthonormal basis from MGS)
Out: R"
  ;;; want to access columns easily
  (setf q (transpose q))
  (setf m (transpose mat3))
  (let* ((d0 (dot (first m) (first q)))
         (d1 (dot (second m) (second q)))
         (d2 (dot (third m) (third q)))
         (maxd (max (max (abs d0) (abs d1))
                    (abs d2)))
         (mind (min (min (abs d0) (abs d1))
                    (abs d2))))
    ;; Check if numerically singular
    (if (not (< (* maxd singularEps)
                mind))
        nil
        ;; store 1/diag in diagonal of R
        (transpose (list (list (/ 1.0 d0) 0.0 0.0)
                         (list (dot (second m) (first q)) 
                               (/ 1.0 d1) 0.0)
                         (list (dot (third m) (first q))        
                               (dot (third m) (second q))         
                               (/ 1.0 d2)))))))

(defun solve-Ux-b (mat3 vec3)
  "In: upper triangular matrix (1/diag elements in diag)"
  (let* ((x2 (* (third vec3) 
                (third (third mat3))))
         (x1 (* (- (second vec3)
                   (* (second (third mat3))
                      x2))
                (second (second mat3))))
         (x0 (* (- (first vec3)
                   (* (first (second mat3))
                      x1)
                   (* (first (third mat3))
                      x2))
                (first (first mat3)))))
    (list x0 x1 x2)))

(defun inverse-iter (mat3 mu x)
  "to find the EV closest to mu"
  (let* ((q (modified-gram-schmidt mat3))
         (r (QR (mat- mat3
                      (populate-mat3 mu))
                q)))
    (labels ((normalize-EVs (x)
               (normalize (solve-Ux-b r
                                      (row-to-vec (AB (rowify x)
                                                      q))))))
      (cond ((null r) (values))
            (t (loop for i from 0 to 3
                  :do (setf x (normalize-EVs x))
                  :finally (return (values x 
                                          (dot x
                                               (column-to-vec (AB mat3
                                                                  (columnify x))))))))))))
               
(defun rayleigh-iter (mat3)
  "rayleigh quotient iteration from Q R matrices"
;; todo
)

(defparameter *testMat* '((1.0 1.0 3.0)
                          (2.0 2.0 2.0)
                          (3.0 1.0 1.0)))

(defparameter mu 0.0)
(defparameter x '(1.0 1.0 1.0))

(defun get-EV() ;;mat3 param
  "Takes 3x3 matrix as arg.
Produces eigenvalue (rayleigh for eigenvalue 
with the largest abs value, inverse iter for EV
closest to 0.  Requires nonsingular matrix."
  
  ;; called twice for extra accuracy
  (setf val (multiple-value-bind (x mu) (inverse-iter *testMat* mu x)
              (list x mu)))
  (setf val (multiple-value-bind (x mu) (inverse-iter *testMat* (second val) (first val))
              (list x mu)))
  
  (format t "mu = ~A~%" (second val))
  (format t "x =  ~A~%" (first val)))


