from string import ascii_lowercase


def is_palindrome(s: list | str) -> bool:
    for i in range(len(s) // 2):
        if s[i] != s[~i]:
            return False
    return True


def solution(word: str) -> bool:
    vowels = "aeiou"
    good_letters = list(filter(lambda l: l not in vowels, ascii_lowercase))
    return is_palindrome(list(filter(lambda l: l in good_letters, word)))


if __name__ == '__main__':
    if solution(input()):
        print("YES")
    else:
        print("NO")
