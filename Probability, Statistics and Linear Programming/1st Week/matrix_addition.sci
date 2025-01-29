m = input("Enter number of rows of the matrix: ")
n = input("Enter number of columns of the matrix: ")
disp("Enter the first matrix")
for i = 1:m
    for j = 1:n
        A(i, j) = input("\ ")
    end
end
disp("Enter the second matrix")
for i = 1:m
    for j = 1:n
        B(i, j) = input("\ ")
    end
end
for i = 1:m
    for j = 1:n
        C(i, j) = A(i, j) + B(i, j)
    end
end
disp("The first matrix is")
disp(A)
disp("The second matrix is")
disp(B)
disp("The sum of the two matrices is")
disp(C)
