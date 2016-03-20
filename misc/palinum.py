# number of palindromes in a word
# for example wowe has 5 palindromes, one for each letter and one for "wow"


def is_palindrome(s, hi):
    i = 0

    while i < hi:
        if s[i] is not s[hi]:
            return False
        i += 1
        hi -= 1
    return True


def num_palindromes(s):
    strlen = len(s)
    permlist = [s[i:j] for i in range(strlen+1) for j in range(i+2, strlen+1, 1)
                if s[i] is s[j-1] and is_palindrome(s[i+1:j-1], j-i-3)]
    return len(permlist) + strlen


def test():
    assert(num_palindromes("s") is 1)
    assert(num_palindromes("www") is 6)
    assert(num_palindromes("") is 0)
    assert(num_palindromes("wowe") is 5)
    assert(num_palindromes("bowser") is 6)
    assert(num_palindromes("dadisinaboat") is 14)
    assert(num_palindromes("momisalsoinaboat") is 17)

    print("All tests pass")


def main():
    test()

if __name__ == "__main__":
    main()
