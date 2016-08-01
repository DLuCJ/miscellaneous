dictionary = ["nobody", "knows", "the", "troubles", "i've", 
              "seen", "but", "jesus", "and", "these", "are", 
              "some", "filler", "words"]

unsquished = []
squished = "nobodyknowstheTroublesi'veseennobodyknowsbutjesus"
squishlen = len(squished)

#def unsquish(squished, unsquished, slicepos):
#    if slicepos == 0:
#        return unsquished
#
#    if squished[:slicepos] in dictionary:
#        unsquished.append(squished[:slicepos])
#        return unsquish(squished[slicepos:], unsquished, squishlen)
#
#    return unsquish(squished, unsquished, slicepos - 1)


def unsquish(squished, unsquished, slicepos):
    for i in range(squishlen, 0, -1):
        if squished[:i] in dictionary:
            unsquished.append(squished[:i])
            unsquish(squished[i:], unsquished, i)
            break

    return unsquished


lo = 0
prevsz = -1
squishtemp = squished

while True:
    sz = 0
    
    unsquished = unsquish(squishtemp, unsquished, lo)
    words = [word for word in unsquished]

    for word in words:
        sz = sz + len(word)

    if sz == squishlen or lo == squishlen:
        break

    if prevsz >= 0 and sz == prevsz:
        lo = lo + 1
    else:
        lo = sz + 1

    prevsz = sz

    squishtemp = squished[lo:]

print(unsquished)

