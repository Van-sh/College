import random

WORDS = ["python", "game", "hangman", "test", "winning"]
HANGMAN_STAGES = [
    "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
    "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========",
]


def choose_word():
    return random.choice(WORDS)


def display_word(word, guessed):
    return " ".join([letter if letter in guessed else "_" for letter in word])


def play():
    word = choose_word()
    guessed_letters = set()
    attempts = len(HANGMAN_STAGES) - 1
    while attempts > 0:
        print(HANGMAN_STAGES[len(HANGMAN_STAGES) - 1 - attempts])
        print("Word:", display_word(word, guessed_letters))
        print("Guessed Letters:", " ".join(sorted(guessed_letters)))
        guess = input("Enter a letter: ").lower()
        if not guess.isalpha() or len(guess) != 1:
            print("Invalid input. Enter a single letter.")
            continue
        if guess in guessed_letters:
            print("Already guessed.")
            continue
        guessed_letters.add(guess)
        if guess not in word:
            attempts -= 1
            print("Wrong guess!")
        if all(letter in guessed_letters for letter in word):
            print("\nYou Win! Word was:", word)
            return

    print(HANGMAN_STAGES[-1])
    print("\nYou Lost! Word was:", word)


if __name__ == "__main__":
    play()
