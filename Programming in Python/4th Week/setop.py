A = {1, 2, 3, 4, 5}
B = {4, 5, 6, 7, 8}
print(f"Set A: {A}")
print(f"Set B: {B}")

print(f"\nUnion (A | B): {A | B}")
print(f"Using union() method: {A.union(B)}")

print(f"\nIntersection (A & B): {A & B}")
print(f"Using intersection() method: {A.intersection(B)}")

print(f"\nDifference (A - B): {A - B}")
print(f"Difference (B - A): {B - A}")
print(f"Using difference() method: {A.difference(B)}")

print(f"\nSymmetric Difference (A ^ B): {A ^ B}")
print(f"Using symmetric_difference() method: {A.symmetric_difference(B)}")

C = {1, 2, 3}
print(f"\nSet C: {C}")
print(f"C is subset of A: {C.issubset(A)}")
print(f"A is subset of B: {A.issubset(B)}")

print(f"\nA is superset of C: {A.issuperset(C)}")
print(f"B is superset of A: {B.issuperset(A)}")

D = {9, 10}
print(f"\nSet D: {D}")
print(f"A and D are disjoint: {A.isdisjoint(D)}")
print(f"A and B are disjoint: {A.isdisjoint(B)}")
