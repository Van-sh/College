observed = [50 30 20]
expected = [40 40 20]
if size(observed, "*") <> size(expected, "*") then
    error("The observed and expected frequencies must have same size.")
end
chi_square_stat = sum(((observed - expected).^2)./expected)
n = length(observed)
df = n - 1
alpha = 0.05
chi_square_critical= cdfchi("PQ", 1 - alpha, df)
disp("Chi-Square Statistic: " + string(chi_square_stat))
disp("Degrees of Freedom: " + string(df))
disp("Critical Value: " + string(chi_square_critical))
if chi_square_stat > chi_square_critical then
    disp("Reject the null hypothesis (H0): The data does not fit the expected distribution")
else
    disp("Fail to reject the null hypothesis (H0): The data fits the expected distribution")
end
