from pprint import pprint

student_data = {
    "name": "Vansh",
    "age": 20,
    "course": "Computer Science",
    "subjects": {"Compiler Design": 95, "Java": 90, "Python": 92},
}
print("Normal Print:")
print(student_data)
print("\nPretty Print:")
pprint(student_data)
