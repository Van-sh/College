from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize


def lemmatize_text(text):
    lemmatizer = WordNetLemmatizer()
    words = word_tokenize(text)
    for w in words:
        print(f"{w} -> {lemmatizer.lemmatize(w)}")


if __name__ == "__main__":
    text = input("Enter text: ")
    lemmatize_text(text)
