import string

filename = input("Enter file name: ")

try:
    with open(filename, "r") as file:
        text = file.read()
    text = text.lower()
    for ch in string.punctuation:
        text = text.replace(ch, "")

    words = text.split()
    unique_words = set(words)
    sorted_words = sorted(unique_words)

    print("Unique words in alphabetical order:")
    for word in sorted_words:
        print(word)

except FileNotFoundError:
    print("File not found!")
