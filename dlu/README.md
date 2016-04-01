# dlu

A basic raytracer  
This is my introduction to Python

Cpp version: Andrew Kensler's business card raytracer  
The spheres now read DLu instead of aek.  
It executes in approximately 30 seconds.  
  
to run:  
  
make  
card > card.ppm  
    
Python version: a port of the aek raytracer  
The rendering time is currently around 3 hours, so don't bother.  
A sample render is included as card.ppm  
It was rendered by shooting 8 rays per pixel as opposed to the original 64, so the image is a little darker.  
  
Goal is to optimize (octree? k-d tree?) until the process is not criminally slow.  
According to the profiler, most of the time spent is in trace, and most of the time  
in trace is spent doing vector operations, which are necessary as far as I can tell.  So, I suppose the way to go is to limit the number of times trace is called.  
  
  
This is on hiatus until I have time for some research.  
Don't wait up honey  
