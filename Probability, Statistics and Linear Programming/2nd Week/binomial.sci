n = input("Enter number of observations: ")
p = input("Enter value of p: ")
X = 0:n - 1
disp("Enter the values of frequency")
for i = 1:n
    F(1, i) = input("\")
end
EF = sum(F) * binomial(p, n - 1)
disp("Given frequencies")
disp(F)
disp("Expected frequencies")
disp(EF)
plot2d3(X, F)
plot2d(X, EF)
