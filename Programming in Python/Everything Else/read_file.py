def read_file_line_by_line(filename):
    try:
        with open(filename, "r") as file:
            for line in file:
                print(line, end="")
    except FileNotFoundError:
        print("File not found!")


fname = input("Enter file name: ")
read_file_line_by_line(fname)
