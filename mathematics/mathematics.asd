;;;; Mathematics.asd

(asdf:defsystem #:mathematics
  :description "A library for mathematical means."
  :author "Daniel Lu"
  :license "Public Domain"
  :serial t
  :components ((:file "package")
               (:file "mathematics")
               (:file "averages")
               (:file "matrix")
               (:file "fft")
               (:file "vector")
               (:file "eigensolver")))

