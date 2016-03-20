digits = [i for i in range(256)]

matchlist = [' ', 'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd', 'l', 'u',
             'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'U']


def fixed_xor(b1, b2):
    return bytes([a ^ b for (a, b) in zip(b1, b2)])


def get_sbxor_cipher(b):
    max_xor = 0
    max_val = 0

    for xor in digits:
        val = scoreline(xor, b)

        if val > max_val:
            max_val = val
            max_xor = xor

    return max_xor, max_val


def scoreline(xor, bytez):
    val = 0

    for b in bytez:
        xorchar = chr(b ^ xor)
        if xorchar in matchlist:
            val += 1
    return val


def repeating_key_xor(b, key):
    b_arr = bytearray(b)
    keylen = len(key)
    for i in range(len(b_arr)):
        b_arr[i] ^= ord(key[i % keylen])
    return bytes(b_arr)


def test():

    b1 = bytes.fromhex("1C0111001f010100061a024b53535009181c")
    b2 = bytes.fromhex("686974207468652062756c6c277320657965")

    xorbytes = fixed_xor(b1, b2)
    assert (xorbytes.hex() == "746865206b696420646f6e277420706c6179")

    # ***************************************************************

    # The hex encoded string: 1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
    # ... has been XOR'd against a single character. Find the key, decrypt the message.

    sbxor_str = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
    b3 = bytes.fromhex(sbxor_str)

    sbxor_cipher = get_sbxor_cipher(b3)[0]
    xorbytes = [chr(sbxor_cipher ^ c) for c in b3]
    assert (''.join(xorbytes) == 'Cooking MC\'s like a pound of bacon')

    # ****************************************************************

    # Find the line in scxor.in that has been encrypted by single-character xor

    with open('infiles/scxor.in') as f:
        lines = f.readlines()
    totvals = []
    for line in lines:
        line = line.strip()
        buf = bytes.fromhex(line)

        # b1 ^ cipher = b2  -->  b2 ^ match = (b1 ^ cipher) ^ match
        # = (b1 ^ match) ^ cipher
        # therefore if b2 is encrypted english plaintext, you'd expect its corresponding b1
        # to "cross out" with matches more often than not.

        sbxor_vals = [scoreline(ord(xor), buf) for xor in matchlist]
        totvals.append((sum(sbxor_vals), line))

    goodline = min(totvals, key=lambda item: item[0])[1]

    assert (goodline == '7b5a4215415d544115415d5015455447414c155c46155f4058455c5b523f')

    b4 = bytes.fromhex(goodline)
    sbxor_cipher = get_sbxor_cipher(bytes.fromhex(goodline))
    xorbytes = [chr(sbxor_cipher[0] ^ c) for c in b4]
    assert (''.join(xorbytes) == 'Now that the party is jumping\n')

    # ****************************************************************

    # Repeating-key xor

    with open('infiles/rkxor.in', 'r') as f:
        s = f.read()
    b5 = bytes(s, 'ascii')
    xorbytes = repeating_key_xor(b5, 'ICE')
    encryptstr = xorbytes.hex()

    assert (encryptstr ==
            "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a2622632427276" +
            "5272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f")

if __name__ == "__main__":
    test()
