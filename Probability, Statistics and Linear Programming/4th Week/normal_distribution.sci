x = [5.1 5.5 5.8 6.0 6.1 6.2 6.3 6.5 6.6 6.8]
n = length(x)
mu = mean(x)
sigma = stdev(x)
xmin = min(x) - 1
xmax = max(x) + 1
x_fit = linspace(xmin, xmax, 100)
pdf_fit = (1 / (sigma * sqrt(2 * %pi))) * exp(-((x_fit - mu) .^ 2) / (2 * sigma ^ 2))

histplot(10, x)
plot(x_fit, pdf_fit * n * (xmax - xmin) / 10 , "black", "LineWidth", 2)
xlabel("Data")
ylabel("Frequency")
title("Fitting a Normal Distribution")
legend(["Histogram", "Fitted Normal Distribution"], "location", "upper_right")
