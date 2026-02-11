import math


def area_of_circle(radius: float) -> float:
    return math.pi * radius * radius


r = float(input("Enter radius of the circle: "))
area = area_of_circle(r)
print(f"Area of the circle: {area:.2f}")
