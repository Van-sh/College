num = int(input("Enter a positive integer: "))

if num < 0:
    print("Factorial does not exist for negative numbers.")
    exit()

factorial = 1

for i in range(2, num + 1):
    factorial *= i

print(f"Factorial of {num} is {factorial}")
