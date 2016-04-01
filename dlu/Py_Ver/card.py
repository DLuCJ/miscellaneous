# Port of AEK business card raytracer
# Author: Daniel Lu

import math
import random
import Image

###################### Vector Class / Operations ###################

class Vec (object):
    """Defines a vector class
       Takes either 0 arguments or 3 floats (x,y,z)"""
    def __init__(self, float1, float2, float3):
        self.x = float1
        self.y = float2
        self.z = float3

    #vector dot prod
    def __mod__(self, vec2):
        return (self.x * vec2.x) + (self.y * vec2.y) + (self.z * vec2.z)

    #vector scale
    def __mul__(self, val):
        assert type(val) == float or type(val) == int
        return Vec(self.x*val, self.y*val, self.z*val)

    #vector add
    def __add__(self, vec2):
        return Vec(self.x + vec2.x, self.y+vec2.y, self.z+vec2.z)

    #vector subtract
    def __sub__(self, vec2):
        return Vec(self.x-vec2.x, self.y-vec2.y, self.z-vec2.z)

    #vector cross prod
    def __xor__(self, vec2):
        i = self.y * vec2.z - self.z * vec2.y
        j = self.z * vec2.x - self.x * vec2.z
        k = self.x * vec2.y - self.y * vec2.x
        return Vec(i,j,k)

    #For normalizing vectors
    def normal(self):
        magnitude = math.sqrt( self%self )
        return self*(1/magnitude)

    #For unit testing
    def __eq__(self,vec2):
        if isinstance(vec2, self.__class__):
            return self.__dict__ == vec2.__dict__
        else:
            return False
    def __ne__(self,vec2):
        return not self.__eq__(vec2)

###################### Unit Tests ##################################

def test():
    "A set of unit tests"

    a = Vec(3,-3,1)
    b = Vec(4,9,2)
    c = Vec(0,0,9)
    d = Vec(9,0,0)

    assert a%b == -13
    assert a*2 == Vec(6,-6,2)
    assert a+b == Vec(7, 6, 3)
    assert a-b == Vec(-1,-12,-1)
    assert a^b == Vec(-15,-2,39)
    assert c.normal() == Vec(0,0,1)
    assert d.normal() == Vec(1,0,0)

    print 'All tests pass.'

    
###################### Sphere Coordinates ##########################

bitmap = [230285,296979,280593,280593,280593,280593,280593,296960,460800]

# 460800 111    1
# 296960 1  1   1
# 280593 1   1  1      1   1
# 280593 1   1  1      1   1
# 280593 1   1  1      1   1
# 280593 1   1  1      1   1
# 280593 1   1  1      1   1
# 296979 1  1   1      1  11
# 230285 111     111    11 1

def rng():
    return random.uniform(0,1)

###################### Tracer ######################################

class TraceGlobals:
    "Keeps vector and float information for trace calls"
    pass
    t = 1e9
    n = Vec(0,0,1)

def trace(origin, direction, globals):
    """Intersection test for line [o,v]
    Return 2 if hit was found, and return distance t and bouncing ray n
    Return 0 if no hit was found but ray goes upward
    Return 1 if no hit was found but ray goes downward"""

    globals.t = 1e9
    m = 0
    p =-origin.z/direction.z
    if( .01 < p ):
        globals.t = p
        globals.n = Vec(0,0,1)
        m = 1

    #The world is encoded in G, with 9 rows and 19 columns
    for k in range(18,-1,-1):
        for j in range(8,-1,-1):

            if( bitmap[j]&1<<k):  #Check if there is sphere at k for this j
                #There is a sphere but does the ray hit it?
                vec_p = origin + Vec(-k, 0, -j-4)

                b = vec_p%direction
                c = vec_p%vec_p - 1
                q = b*b-c

                #Does the ray hit the sphere?
                if( q > 0 ):
                    #If yes, compute the distance camera-sphere
                    s = -b-math.sqrt(q)

                    if( (s < globals.t) and (s > 0.01) ):
                        #This the min distance so far - save it
                        #Compute the bouncing ray vector into 'n'
                        globals.t = s
                        temp_n = vec_p + direction*globals.t
                        globals.n = temp_n.normal()

                        m = 2

    return m

###################### Sampler #####################################

def sample(origin, direction):
    """Samples the world and returns the pixel color for
        a ray passing by point origin and direction"""

    globals = TraceGlobals()
    m = trace( origin, direction, globals )

    if(m == 0):
        #No sphere found and the ray goes upward: Generate a sky color
        return Vec(0.7, 0.6, 1) * math.pow(1 - direction.z, 4)

    #Sphere may have been hit
    intersect_coord = origin + direction * globals.t

    #direction to light with random delta for soft-shadows
    l_vec = Vec(9 + rng(), 9 + rng(), 16) + intersect_coord * -1
    dir_to_light = l_vec.normal()

    half_vector = direction + globals.n * (globals.n % direction * -2)

    #Calculate the lambertian factor
    l_factor = dir_to_light % globals.n

    #Calculate illumination factor
    #(Lambertian coefficient > 0 or in shadow) ?
    if( l_factor < 0 or trace(intersect_coord, dir_to_light, globals)):
        l_factor = 0

    #Calculate the color p with diffuse and specular component
    p = math.pow( dir_to_light % half_vector * (l_factor > 0), 99)

    if(m == 1):
        #If m == 1, no sphere was hit and the ray was going downward: generate a floor color
        new_intersect_coord = intersect_coord * 0.2
        ceilings = int( math.ceil(new_intersect_coord.x) + math.ceil(new_intersect_coord.y) )
        if (ceilings & 1):
            return Vec(3,1,1) * ( l_factor * .2 + .1)
        else:
            return Vec(3,3,3) * ( l_factor * .2 + .1)

    #m == 2, so a sphere was hit. Cast a ray bouncing from the sphere surface.
    #Attenuate color by 50% since it is bouncing (* .5)
    return Vec(p,p,p) + sample(intersect_coord, half_vector) * 0.5

#Generates PPM image to stdout
if __name__ == '__main__':

    img = Image.new("RGB", (512,512))

    #Camera direction
    camera_dir = Vec(-6, -16, 0).normal()
    #Camera up vector, z is pointing up
    camera_up = (Vec(0,0,1) ^ camera_dir).normal() * 0.002
    #The right vector
    right_vec = (camera_dir ^ camera_up).normal() * 0.002

    c = (camera_up + right_vec) * -256 + camera_dir #WTF?

    for y in range(512):
        print y
        for x in range(512):

            #Store default RGB pixel color (almost pitch black) in a vector
            p = Vec(13,13,13)

            #Cast 64 rays per pixel (for blur (stochastic sampling) and soft-shadows

            for r in range(8):

                # The delta to apply to the origin of the view (For Depth of View blur).

                t = ( camera_up * (rng() - 0.5) * 99 ) + ( right_vec * (rng() - 0.5) * 99 )

                p = sample(Vec(17,16,8) + t,
                           (t * -1 + (camera_up * (rng() + x) + right_vec * (y + rng()) + c) * 16).normal()
                )*3.5 + p

            img.putpixel( (511 - x, 511 - y),(int(p.x), int(p.y), int(p.z)) )
    img.save("card.ppm","PPM")
