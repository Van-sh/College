from nltk.stem import PorterStemmer
from nltk.tokenize import word_tokenize


def stem_text(text):
    ps = PorterStemmer()
    words = word_tokenize(text)
    for w in words:
        print(f"{w} -> {ps.stem(w)}")


if __name__ == "__main__":
    text = input("Enter text: ")
    stem_text(text)
