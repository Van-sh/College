import tkinter as tk


def calculate():
    result = int(entry1.get()) + int(entry2.get())
    label_result.config(text="Result: " + str(result))


root = tk.Tk()
root.title("Simple Calculator")

entry1 = tk.Entry(root)
entry1.pack()
entry2 = tk.Entry(root)
entry2.pack()

btn = tk.Button(root, text="Add", command=calculate)
btn.pack()
label_result = tk.Label(root, text="Result:")
label_result.pack()
root.mainloop()
