import re

with open("data.txt", "r") as file:
    text = file.read()

pattern = r"\S+@\S+"
matches = re.findall(pattern, text)

print("Found patterns:")
for m in matches:
    print(m)
