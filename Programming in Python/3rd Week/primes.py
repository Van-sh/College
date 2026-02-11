import math


n = int(input("Enter a number: "))
print("Prime numbers up to", n, "are:")
for num in range(2, n + 1):
    is_prime = True
    for i in range(2, min(num, math.ceil(math.sqrt(num)) + 1)):
        if num % i == 0:
            is_prime = False
            break
    if is_prime:
        print(num)
