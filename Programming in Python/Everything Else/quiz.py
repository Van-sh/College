try:
    with open("questions.txt", "r") as qf, open("options.txt", "r") as of:
        questions = qf.readlines()
        data = of.readlines()

    score = 0
    index = 0

    for i in range(len(questions)):
        print(f"\nQ{i + 1}: {questions[i].strip()}")

        for j in range(4):
            print(data[index].strip())
            index += 1

        correct_ans = data[index].strip().lower()
        index += 1

        user_ans = input("Enter your answer (a/b/c/d): ").strip().lower()

        if user_ans == correct_ans:
            print("Correct!")
            score += 1
        else:
            print(f"Wrong! Correct answer is {correct_ans}")

    print("\nFinal Score:", score, "/", len(questions))

except FileNotFoundError:
    print("One or more files not found!")
