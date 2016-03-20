# The string: 49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
# Should produce: SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t

b64charset = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
b64 = [c for c in b64charset]
digits = [i for i in range(64)]
bin2b64 = dict(zip(digits, b64))


def convert3(b):
    binval = (b[0] * (1 << 16) + b[1] * (1 << 8) + b[2])
    b64vals = []
    while binval != 0:
        qr = divmod(binval, 64)
        binval >>= 6
        b64vals = [bin2b64[qr[1]]] + b64vals

    return ''.join(b64vals)


def hex2b64(s):
    sb = bytes.fromhex(s)
    sb = bytearray(sb)

    missing = len(sb) % 3
    misflg = 0
    if missing is not 0:
        misflg = 1
        for i in range(3-missing):
            sb.append(0)

    split3 = [sb[i:i+3] for i in range(0, len(sb), 3)]
    convertedbytes = [convert3(b) for b in split3]
    b64str = ''.join(convertedbytes)

    if misflg:
        eq2add = 3 - missing
        for i in range(eq2add):
            b64str = b64str[:len(b64str)-1]
        for i in range(eq2add):
            b64str += '='

    return b64str


def test():
    s = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
    assert(hex2b64(s) ==
           "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t")

    # testing case where there aren't enough bytes to form whole groups-of-three
    # ie strlen % 3 is not 0

    s2 = """Man is distinguished, not only by his reason, but by this singular passion from
other animals, which is a lust of the mind, that by a perseverance of delight
in the continued and indefatigable generation of knowledge, exceeds the short
vehemence of any carnal pleasure."""

    sb = bytes(s2, 'ascii')
    sh = sb.hex()
    mytestcase = bytes(hex2b64(sh), 'ascii')
    import base64
    b64testcase = base64.b64encode(sb)

    assert(mytestcase == b64testcase)

if __name__ == "__main__":
    test()
