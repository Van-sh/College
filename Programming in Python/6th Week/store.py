class Store:
    def __init__(self, code, price):
        self.code = code
        self.price = price


products = {
    1: Store(1, 50),
    2: Store(2, 30),
    3: Store(3, 20),
}

total_bill = 0

print("---- MENU ----")
for key in products:
    print(f"Code: {products[key].code}  Price: Rs.{products[key].price}")

while True:
    code = int(input("Enter product code: "))
    qty = int(input("Enter quantity: "))

    if code in products:
        cost = products[code].price * qty
        total_bill += cost
        print(f"Added Rs.{cost} to bill")
    else:
        print("Invalid product code!")

    choice = input("Do you want to buy more items? (y/n): ")
    if choice.lower() != "y":
        break

print("\nFinal Bill: Rs.", total_bill)
