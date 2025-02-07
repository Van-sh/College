n = input("Enter number of observations: ")
disp("Enter values of x")
for i = 1:n
    X(1, i) = input("\")
end
disp("Enter values of frequency")
for i = 1:n
    F(1, i) = input("\")
end
disp(f .* X)
M = sum(F .* X) / sum(F)
disp("Mean of the distribution is")
disp(M)
for i = 1:n
    P(1, i) = sum(F) * exp(-M) * M ^ (X(i))/factorial(X(i))
end
disp("Expected frequencies are")
disp(P)
plot2d(X, P)
