dictionary = ["nobody", "knows", "the", "troubles", "i've", 
              "seen", "but", "jesus", "and", "these", "are", 
              "some", "filler", "words"]

unsquished = []
squished = "nobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusnobodyknowsthetroublesi'veseennobodyknowsbutjesusohthehumanity"
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


def unsquish(squished, unsquished):

    for i in range(squishlen, 0, -1):
        if squished[:i] in dictionary:
            unsquished.append(squished[:i])
            unsquish(squished[i:], unsquished)
            break
            
    return unsquished


splitwords = unsquish(squished, unsquished)
print(splitwords)
