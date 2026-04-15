source = input("Enter source Python file: ")
destination = input("Enter destination file: ")

try:
    with open(source, "r") as f1, open(destination, "w") as f2:
        for line in f1:
            if line.strip().startswith("#"):
                continue
            f2.write(line)

    print("File copied successfully without comments!")

except FileNotFoundError:
    print("Source file not found!")
except Exception as e:
    print("Error:", e)
