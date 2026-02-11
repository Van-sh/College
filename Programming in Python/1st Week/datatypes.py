name = input("Enter your name: ")
age = int(input("Enter your age: "))
marks = float(input("Enter your marks: "))

next_age = age + 1

age_float = float(age)
marks_int = int(marks)
age_string = str(age)

is_adult = age >= 18
is_pass = marks >= 40

print(f"Name: {name}")
print(f"Current Age: {age}")
print(f"Age next year: {next_age}")
print(f"Marks: {marks}")

print("\nType Casting:")
print(f"Age to float: {age_float}")
print(f"Marks to int: {marks_int}")
print(f"Age to string: {age_string}")

print("\nBoolean Results:")
print(f"Is Adult: {is_adult}")
print(f"Is Pass: {is_pass}")
print(f"Adult AND Pass: {is_adult and is_pass}")
