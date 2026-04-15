import sys

if len(sys.argv) != 3:
    print("Usage: python script.py source.txt destination.txt")
    sys.exit()

source = sys.argv[1]
destination = sys.argv[2]

try:
    with open(source, "r") as f1:
        content = f1.read()

    content = content.lower()

    with open(destination, "w") as f2:
        f2.write(content)

    print("File copied successfully with lowercase conversion!")

except FileNotFoundError:
    print("Source file not found!")
except Exception as e:
    print("Error:", e)
