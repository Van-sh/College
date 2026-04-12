from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize


def remove_stopwords(file_path):
    with open(file_path, "r") as f:
        text = f.read()

        words = word_tokenize(text)
        stop_words = set(stopwords.words("english"))

        filtered = [w for w in words if w.lower() not in stop_words]

        print("Original Length:", len(words))
        print("Filtered Length:", len(filtered))
        print("\nFiltered Text:\n", " ".join(filtered))


if __name__ == "__main__":
    remove_stopwords("input.txt")
