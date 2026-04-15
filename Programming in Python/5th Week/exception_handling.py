while True:
    try:
        a = float(input("First number:  "))
        b = float(input("Second number: "))
        print("Result:", a / b)
        break
    except ValueError:
        print("Enter valid numbers.")
    except ZeroDivisionError:
        print("Can’t divide by zero.")
