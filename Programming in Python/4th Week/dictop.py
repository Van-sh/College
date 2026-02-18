student = {"name": "John", "age": 21, "course": "Computer Science"}
print("Initial Dictionary:", student)

print("\nAccessing Elements:")
print(f"Name: {student['name']}")
print(f"Age using get(): {student.get('age')}")

print("\nAdding Elements:")
student["grade"] = "A"
print(f"After adding grade: {student}")

print("\nUpdating Elements:")
student["age"] = 22
student.update({"course": "Data Science"})
print(f"After update: {student}")

print("\nRemoving Elements:")
student.pop("grade")  # Removes specific key
print(f"After pop('grade'): {student}")
student.popitem()  # Removes last inserted item
print(f"After popitem(): {student}")

print("\nChecking Key:")
if "name" in student:
    print("Key 'name' exists")
print(f"\nLength of dictionary: {len(student)}")

print("\nLooping through dictionary:")
for key in student:
    print(f"{key} : {student[key]}")

print("\nUsing items():")
for key, value in student.items():
    print(f"{key} : {value}")

print("\nCopying Dictionary:")
student_copy = student.copy()
print(f"Copied Dictionary: {student_copy}")

print("\nClearing Dictionary:")
student.clear()
print(f"After clear(): {student}")

print("\nUsing fromkeys():")
keys = ["a", "b", "c"]
new_dict = dict.fromkeys(keys, 0)
print(f"New Dictionary: {new_dict}")
