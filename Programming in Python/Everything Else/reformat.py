with open("input.txt", "r") as file:
    data = file.read()

modified_data = data.upper()

with open("output.txt", "w") as file:
    file.write(modified_data)

print("Data successfully written to output.txt")
