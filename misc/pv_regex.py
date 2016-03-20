# Per Vognsen's regex engine ( http://paste.lisp.org/display/24849 )
# star doesn't handle nullable expressions ( fix described here: http://t.co/oEVI5c8BqY )
# see https://twitter.com/drmaciver/status/631395737620901888
# for storage


def iconcat(xs, ys):
    """ yields elements in xs one at a time, then everything in ys
        if e.g. xs has nothing, will yield nothing and then process ys
        if ys has nothing, the second loop will yield nothing
        so that's why it works for alt
        will process one transform or the other or both"""
    for x in xs: yield x
    for y in ys: yield y


def nil(s):
    """ string to generator yielding string """
    yield s


def alt(l, r):
    """ this becomes self explanatory with the iconcat explanation """
    return lambda s: iconcat(l(s), r(s))


def seq(l, r):
    """ sends s through l transform, then sends the output of that through
        r transform, then passes on s"""
    return lambda s: (sr for sl in l(s) for sr in r(sl))


def star(e):
    """ the e transform is applied as many times as possible to the 
        string s.  Before each application, s is given to nil.
        Then when there are no more transforms possible, each nil 
        yields its copy of s.  The key here is that the first nil
        is given a non-transformed s, so that even if no transforms
        are possible, star still yields some s."""
    
    return lambda s: iconcat(nil(s), seq(e, star(e))(s))


def plus(e):
    """ e transform is guaranteed at least once """
    return seq(e, star(e))


def char(c):
    """ transform that eats s if the first character of s is c
        then passes on s"""
    def match(s):
        if s and s[0] == c: yield s[1:]
    return match

# c(a|d)+r
# e is a func that basically applies a bunch of nested transforms to a string s
# it eats s until only r is left.  If it can't eat at any point, no r is produced.
# seq "glues" the transforms together
# because no s[1:] is yielded.

e = seq(char('c'), seq(plus(alt(char('a'), char('d'))), char('r')))

import sys
s = sys.stdin.readline()[:-1]

for r in e(s):
    print("Match with remainder: %s" %r)
