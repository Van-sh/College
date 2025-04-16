p = input("Enter number of variables in the objective function: ")
q = input("Enter number of constraint equations: ")
disp("Enter coefficients of the objective function:")
A = zeros(1, p)
for i = 1:p
   A(i) = input("Coefficient of variable " + string(i) + ": ")
end
m = input("Enter 1 to minimize or 2 to maximize: ")
disp("Enter constraint equations:")
B = zeros(q, p)
C = zeros(q, 1)
D = zeros(q, 1)
for i = 1:q
   disp("Enter coefficients for equation " + string(i) + ":")
   for j = 1:p
      B(i, j) = input("Coefficient of x" + string(j) + ": ")
   end
   C(i) = input("Enter 1 for <= or 2 for >=: ")
   D(i) = input("Enter RHS constant for equation " + string(i) + ": ")
end
printf("The LPP is:\n")
if m == 1 then
   printf("MIN Z = ")
else
   printf("MAX Z = ")
end
for i = 1:p
   if i == p then
      printf("%dx%d", A(i), i)
   else
      printf("%dx%d + ", A(i), i)
   end
end
printf("\nSubject to:\n")
for i = 1:q
   for j = 1:p
      if j == p then
         printf("%dx%d ", B(i, j), j)
      else
         printf("%dx%d + ", B(i, j), j)
      end
   end
   if C(i) == 1 then
      printf("<= ")
   else
      printf(">= ")
   end
   printf("%d\n", D(i))
end
printf("\n================== SIMPLEX TABLE ==================\n")
printf("\tCJ\t")
for i = 1:p
   printf("x%d\t", i)
end
for i = 1:q
   printf("s%d\t", i)
end
printf("RHS\n")
printf("===================================================\n")
for i = 1:q
   printf("s%d\t0\t", i)
   for j = 1:p
      printf("%d\t", B(i, j))
   end
   for j = 1:q
      if j == i then
         printf("1\t")
      else
         printf("0\t")
      end
   end
   printf("%d\n", D(i))
end
printf("---------------------------------------------------\n")
printf("Zj-Cj ")
for i = 1:p
   printf("-%d ", A(i))
end
for i = 1:q
   printf("0 ")
end
