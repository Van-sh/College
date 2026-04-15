class StringDetails:
    def __init__(self, text):
        self.text = text

    def analyze(self):
        upper = 0
        vowels = 0
        consonants = 0

        for ch in self.text:
            if ch.isupper():
                upper += 1

            if ch.isalpha():
                if ch.lower() in "aeiou":
                    vowels += 1
                else:
                    consonants += 1

        print("Uppercase letters:", upper)
        print("Vowels:", vowels)
        print("Consonants:", consonants)


s = input("Enter a string: ")

obj = StringDetails(s)
obj.analyze()
