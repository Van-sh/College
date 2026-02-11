numbers = [1, 2, 3]

numbers.append(4)
print(f"After append(4): {numbers}")

numbers.insert(2, 15)
print(f"After insert(2, 15): {numbers}")

numbers.extend([5, 6])
print(f"After extend([5, 6]): {numbers}")

numbers.remove(2)
print(f"After remove(2): {numbers}")

removed_item = numbers.pop(2)
print(f"After pop(2) - removed {removed_item}: {numbers}")

del numbers[0]
print(f"After del numbers[0]: {numbers}")

numbers.clear()
print(f"After clear(): {numbers}")
