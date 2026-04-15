filename = input("Enter file name: ")

try:
    with open(filename, "r") as file:
        content = file.read()

    spaces = 0
    tabs = 0
    newlines = 0

    for ch in content:
        if ch == " ":
            spaces += 1
        elif ch == "\t":
            tabs += 1
        elif ch == "\n":
            newlines += 1

    print("Number of spaces:", spaces)
    print("Number of tabs:", tabs)
    print("Number of newline characters:", newlines)

except FileNotFoundError:
    print("File not found!")
