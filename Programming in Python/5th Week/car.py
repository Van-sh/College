class Car:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year

    def display_details(self):
        print(f"Brand: {self.brand}\nModel: {self.model}\nYear : {self.year}")


car1 = Car("Toyota", "Corolla", 2022)
car2 = Car("Honda", "Civic", 2021)
car3 = Car("Tesla", "Model 3", 2023)
print("Car 1 Details:")
car1.display_details()
print("\nCar 2 Details:")
car2.display_details()
print("\nCar 3 Details:")
car3.display_details()
