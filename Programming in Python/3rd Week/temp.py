input_string = input("Enter temperature (eg: 32C or 99F): ")

temp, unit = float(input_string[:-1].strip()), input_string[-1:]

match unit:
    case "C":
        fahrenheit = (temp * 9 / 5) + 32
        print(f"{temp}C in fahrenheit is {fahrenheit:.2f}F")
    case "F":
        celcius = (temp - 32) * 5 / 9
        print(f"{temp}F in celcius is {celcius:.2f}C")
    case _:
        print("Please enter a valid temperature")
        exit()
