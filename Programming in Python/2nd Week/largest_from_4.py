a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
c = int(input("Enter third number: "))
d = int(input("Enter fourth number: "))

if a >= b and a >= c and a >= d:
    largest = a
elif b >= a and b >= c and b >= c:
    largest = b
elif c >= a and c >= b and c >= d:
    largest = c
else:
    largest = d

print(f"The largest number is {largest}")
