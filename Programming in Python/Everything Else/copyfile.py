source = input("Enter source file name: ")
destination = input("Enter destination file name: ")

try:
    with open(source, "r") as f1:
        content = f1.read()

    with open(destination, "w") as f2:
        f2.write(content)

    print("File copied successfully!")

except FileNotFoundError:
    print("Source file does not exist!")
except Exception as e:
    print("Error:", e)
