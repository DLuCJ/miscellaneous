def get_repetitions(bytes):
    score = 0
    seen = []
    matchbytes = [bytes[i:i + 16] for i in range(0, len(bytes), 16)]
    for match in matchbytes:
        for cand in seen:
            if match == cand:
                score += 1
        seen.append(match)
    return score


def detect_ecb(lines, mod=0):
    if mod:
        from xorgalor import scoreline
    scorez = []
    for line in lines:
        line = line.strip()
        bs = bytes.fromhex(line)
        if mod:
            scorez.append((scoreline(0, bs), line))
            continue
        scorez.append((get_repetitions(bs), line))
    print(max(scorez, key=lambda item: item[0])[0])
    return max(scorez, key=lambda item: item[0])[1]


def decrypt_aes128ecb(bs, key):
    from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
    from cryptography.hazmat.backends import default_backend
    backend = default_backend()
    cipher = Cipher(algorithms.AES(key), modes.ECB(), backend=backend)
    decryptor = cipher.decryptor()
    return decryptor.update(bs) + decryptor.finalize()


# decrypt AES-encrypted file, given key
def test():
    with open('infiles/AESinECB.in', 'r') as f:
        enc = f.read()

    import base64
    bs = base64.b64decode(enc)
    key = bytes("YELLOW SUBMARINE", 'ascii')

    decrypted = decrypt_aes128ecb(bs, key)
    print(''.join([chr(b) for b in decrypted]))


# detect which hex-encoded ciphertext in file is ECB-encrypted
def test2():
    with open('infiles/detectAESinECB.in', 'r') as f:
        lines = f.readlines()

    # ECB doesn't hide data patterns well, so we check for repeating 16-byte blocks
    assert (detect_ecb(lines) == "d880619740a8a19b7840a8a31c810a3d08649af70dc06f4fd5d2d69c744" +
            "cd283e2dd052f6b641dbf9d11b0348542bb5708649af70dc06f4fd5d2" +
            "d69c744cd2839475c9dfdbc1d46597949d9c7e82bf5a08649af70dc06f" +
            "4fd5d2d69c744cd28397a93eab8d6aecd566489154789a6b0308649af70" +
            "dc06f4fd5d2d69c744cd283d403180c98c8f6db1f2a3f9c4040deb0ab51" +
            "b29933f2c123c58386b06fba186a")

    # but maybe can also check other patterns?
    assert (detect_ecb(lines, 1) == "d880619740a8a19b7840a8a31c810a3d08649af70dc06f4fd5d2d69c744" +
            "cd283e2dd052f6b641dbf9d11b0348542bb5708649af70dc06f4fd5d2" +
            "d69c744cd2839475c9dfdbc1d46597949d9c7e82bf5a08649af70dc06f" +
            "4fd5d2d69c744cd28397a93eab8d6aecd566489154789a6b0308649af70" +
            "dc06f4fd5d2d69c744cd283d403180c98c8f6db1f2a3f9c4040deb0ab51" +
            "b29933f2c123c58386b06fba186a")

    print("****")
    print("All tests pass")


if __name__ == "__main__":
    test()
    test2()
