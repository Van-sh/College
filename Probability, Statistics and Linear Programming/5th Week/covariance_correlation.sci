X = [1 2 3 4 5]
Y = [2 4 6 8 10]
n = length(X)
mean_X = mean(X)
mean_Y = mean(Y)
covariance = sum((X - mean_X) .* (Y - mean_Y)) / (n - 1)
std_X = stdev(X)
std_Y = stdev(Y)
correlation = covariance / (std_X * std_Y)
disp("Covariance", covariance)
disp("Correlation", correlation)
