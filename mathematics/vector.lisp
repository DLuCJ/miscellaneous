;;; Vector operations
;;; Vectors represents as lists

(in-package #:mathematics)

(defun dot( vec1 vec2 )
  "Vector dot product; handles vectors of any size."
  (assert (= (length vec1) 
             (length vec2)))
  (apply #'+ (mapcar #'* vec1 vec2)))

(defun x (vec)
  (first vec))

(defun y (vec)
  (second vec))

(defun z (vec)
  (third vec))

(defun cross (vec1 vec2)
  "Vector cross product"
  (assert (and (= 3 (length vec1))
               (= 3 (length vec2))))
  (let ((i (- (* (y vec1) (z vec2))
              (* (z vec1) (y vec2))))
        (j (- (* (z vec1) (x vec2))
              (* (x vec1) (z vec2))))
        (k (- (* (x vec1) (y vec2))
              (* (y vec1) (x vec2)))))
    (list i j k)))

(defun v.parallel? (vec1 vec2)
  "Checks if two 3D vectors are parallel"
  (equal (cross vec1 vec2)
         '(0 0 0))) 

(defun v.perp? (vec1 vec2)
  "Checks if two vectors are perpendicular"
  (eql (dot vec1 vec2)
       0))

(defun v.scale (vec val)
  "Scale a vector by some number val"
  (labels ((scale (vec)
             (* (car vec) val)))
    (maplist #'scale vec)))

(defun v.add (vec1 vec2)
  "Vector add"
  (mapcar #'+ vec1 vec2))


(defun v.sub (vec1 vec2)
  "Vector subtract"
  (mapcar #'- vec1 vec2))

(defun p-norm (vec p)
  "Generalization of the 2-norm magnitude function.
Any non-number parameter can be used for Chebyshev norm, but
'inf is recommended for clarity." 
  (labels ((get-norms (vec norm)
             (if (null vec)
                 norm
                 (get-norms (cdr vec) (+ norm 
                                         (expt (abs (car vec)) p)))))
           (get-lst (vec) 
             (abs (car vec)))
           (chebyshev-helper () 
             (let ((lst (maplist #'get-lst vec)))
               (if (null lst)
                   nil
                   (reduce #'max lst)))))
    (if (not (typep p 'number))
        (chebyshev-helper)
        (cond ((= p 0) nil)
              ((= p 1) (get-norms vec 0))
              ((= p 2) (sqrt (dot vec vec)))
              (t (nth-root p (get-norms vec 0)))))))

(defun get-magnitude ( vec )
  "Computes the 2-norm of a vector"
  (p-norm vec 2))

(defun normalize (vec) 
  (v.scale vec 
           (/ 1 (get-magnitude vec))))

(defun b-parallel (a b)
  "For some vector b at an angle to vector a:
b parallel component: vec1 scaled by the dot product of a and b"
  (v.scale a 
           (dot a b)))

(defun b-perp (a b)
  "b perpendicular component"
  (v.sub b 
         (b-parallel a b)))

(defun v.angle (vec1 vec2)
  "cos of the angle between two vectors vec1 and vec2
Default result in rads
If want to convert, use rad->deg"
  (/ (dot vec1 vec2)
     (* (get-magnitude vec1)
        (get-magnitude vec2))))

(defun triple-prod (vec1 vec2 vec3)
  "Vector triple product"
  (dot vec1 
       (cross vec2 vec3)))

