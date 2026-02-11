input_string = input("Enter numbers: ")

nums = list(map(int, input_string.split()))
nums.sort()

print(f"Sorted list in ascending order: {nums}")
