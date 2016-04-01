;;; matrix operations
;;; matrices represented as list of lists

(in-package #:mathematics)

(defun transpose (matrix)
  "Doesn't work for vectors (i.e '(1 2 3))
but works for 1D matrices (i.e '((1 2 3))"
  (apply #'mapcar #'list matrix))

(defun columnify (vec)
  "Represents some vector as a matrix with one column."
  (transpose (list vec)))

(defun rowify (vec)
  "Represents some vector as a matrix with one row."
  (list vec))

(defun row-to-vec (row)
  "Represents matrix with one row as vector."
  (car row))

(defun column-to-vec (col)
  "Represents matrix with one column as vector."
  (car (transpose col)))

(defun kM (matrix k)
  "Multiplies matrix by some scalar k."
  (labels ((scale (mat) 
             (v.scale (car mat) k)))
    (maplist #'scale matrix)))

(defun AB (matA matB)
  "Multiplies rxn matrix A and nxc matrix B.
Results in rxc matrix AB."
  (assert (= (length (first matA)) 
             (length matB)))
  (labels ((compute-row (row cols)
             (loop
                :for i :in cols
                :collect (dot row i) :into new-row
                :finally (return new-row))))
    (loop
       :for row :in matA 
       :collect (compute-row row (transpose matB)) :into AB
       :finally (return AB))))

(defun mat+ (matA matB)
  (mapcar #'v.add matA matB))

(defun mat- (matA matB)
  (mapcar #'v.sub matA matB))

(defun populate-mat3 (val)
  "Fill 3x3 matrix with val"
  (loop
     :for row :from 0
     :while (< row 3)
     :collect (list val val val) :into mat3
     :finally (return mat3)))
