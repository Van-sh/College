import nltk
from nltk.tokenize import word_tokenize


def pos_tagging(text):
    words = word_tokenize(text)
    tags = nltk.pos_tag(words)
    for word, tag in tags:
        print(f"{word}: {tag}")


if __name__ == "__main__":
    text = input("Enter sentence: ")
    pos_tagging(text)
