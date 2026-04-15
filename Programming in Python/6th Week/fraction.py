class Fraction:
    def __init__(self, num, den):
        self.numerator = num
        self.denominator = den

    def gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a

    def simplify(self):
        g = self.gcd(self.numerator, self.denominator)
        self.numerator //= g
        self.denominator //= g

    def display(self):
        print(f"Simplified Fraction: {self.numerator}/{self.denominator}")


num = int(input("Enter numerator: "))
den = int(input("Enter denominator: "))

if den == 0:
    print("Denominator cannot be zero!")
else:
    f = Fraction(num, den)
    f.simplify()
    f.display()
