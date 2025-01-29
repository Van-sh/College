m = input("Enter number of rows in the first matrix: ");
n = input("Enter number of columns in the first matrix: ");
p = input("Enter number of rows in the second matrix: ");
q = input("Enter number of columns in the second matrix: ");
if n == p
    disp("Matrices are comfortable for multiplication");
else
    disp("Matrices are nto comfortable for multiplication");
    break;
end
disp("Enter the first matrix")
for i = 1:m
    for j = 1:n
        A(i, j) = input("\")
    end
end
disp("Enter the second matrix")
for i = 1:p
    for j = 1:q
        B(i, j) = input("\")
    end
end
C = zeros(m, q)
for i = 1:m
    for j = 1:q
        for k = 1:n
            C(i, j) = C(i, j) + A(i, k) * B(k, j);
        end
    end
end
disp("The first matrix is")
disp(A)
disp("The second matrix is")
disp(B)
disp("The product of the two matrices is")
disp(C)
