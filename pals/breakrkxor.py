"""
Breaking repeating-key xor
Decrypt xorbrk.in, which has been base64'd after being encrypted with repeating-key xor

Here's how:

1. Let KEYSIZE be the guessed length of the key; try values from 2 to (say) 40.
2. Write a function to compute the edit distance/Hamming distance between two strings.
3. For each KEYSIZE, take the first KEYSIZE worth of bytes, and the second KEYSIZE worth of bytes, and find the edit distance between them. Normalize this result by dividing by KEYSIZE.
4. The KEYSIZE with the smallest normalized edit distance is probably the key. You could proceed perhaps with the smallest 2-3 KEYSIZE values. Or take 4 KEYSIZE blocks instead of 2 and average the distances.
5. Now that you probably know the KEYSIZE: break the ciphertext into blocks of KEYSIZE length.
6. Now transpose the blocks: make a block that is the first byte of every block, and a block that is the second byte of every block, and so on.
7. Solve each block as if it was single-character XOR. You already have code to do this.
8. For each block, the single-byte XOR key that produces the best looking histogram is the repeating-key XOR key byte for that block. Put them together and you have the key.
"""

KEYSIZES = [i for i in range(2, 41)]


def hamming_dist(b1, b2):
    num = 0
    xorlist = bytes([a ^ b for (a, b) in zip(b1, b2)])
    for xor in xorlist:
        for i in range(8):
            num += (1 & (xor >> i))
    return num


def transpose(blocks, keysize):
    tblocks = [[] for i in range(keysize)]

    for b in blocks:
        for i in range(keysize):
            if i < len(b):
                tblocks[i].append(b[i])
    return tblocks


def test():
    with open('infiles/xorbrk.in', 'r') as f:
        enc = f.read()

    b1 = bytes("this is a test", 'ascii')
    b2 = bytes("wokka wokka!!!", 'ascii')

    assert(hamming_dist(b1, b2) is 37)

    import base64
    s = base64.b64decode(enc)

    vals = []
    for ks in KEYSIZES:
        # ks * 2 , since 2 hex vals per byte
        ksize = ks * 2
        v1 = hamming_dist(s[0:ksize], s[ksize:ksize * 2]) / ksize
        v2 = hamming_dist(s[ksize*2:ksize*4], s[ksize*4:ksize*6]) / ksize
        vals.append(((v1 + v2) / 2, ks))

    dist = min(vals, key=lambda item: item[0])[1]
    blocks = [s[i:i + dist] for i in range(0, len(s), dist)]
    tblocks = transpose(blocks, dist)

    import xorgalor
    ciphers = [chr(xorgalor.get_sbxor_cipher(b)[0]) for b in tblocks]
    print(''.join(ciphers))

if __name__ == "__main__":
    test()

