from cs50 import get_string


def letters_per_100_words(letters, words):
    return (letters / words) * 100


def sentences_per_100_words(sentences, words):
    return (sentences / words) * 100


def coleman_liau_index(L, S):
    return round(0.0588 * L - 0.296 * S - 15.8)


text = get_string("Text: ")

letters = 0
words = 0
sentences = 0

for char in text:
    if char.isalnum():
        letters += 1
    elif char.isspace():
        words += 1
    elif char in ['.', '!', '?']:
        sentences += 1

if letters > 0 or sentences > 0:
    words += 1

L = letters_per_100_words(letters, words)
S = sentences_per_100_words(sentences, words)

index = coleman_liau_index(L, S)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
