m = input("Enter number of rows of the matrix: ")
n = input("Enter number of columns of the matrix: ")
disp("Enter the matrix")
for i = 1:m
    for j = 1:n
        A(i, j) = input("\")
    end
end
B = zeros(n, m)
for i = 1:n
    for j = 1:m
        B(i, j) = A(j, i)
    end
end
disp("Entered matrix is")
disp(A)
disp("Transposed matrix is")
disp(B)
