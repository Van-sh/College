from nltk.classify import NaiveBayesClassifier


def extract_features(text):
    return {word: True for word in text.lower().split()}


def train_model():
    data = [
        ("I love this product", "positive"),
        ("This is amazing", "positive"),
        ("I hate this", "negative"),
        ("This is terrible", "negative"),
        ("Very good experience", "positive"),
        ("Worst service ever", "negative"),
    ]
    training = [(extract_features(text), label) for text, label in data]
    return NaiveBayesClassifier.train(training)


def classify_text(classifier, text):
    return classifier.classify(extract_features(text))


if __name__ == "__main__":
    classifier = train_model()
    while True:
        text = input("\nEnter sentence (or 'exit'): ")
        if text.lower() == "exit":
            break
        print("Prediction:", classify_text(classifier, text))
