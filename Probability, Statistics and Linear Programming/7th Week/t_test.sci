x1=[12 15 14 10 16]
x2=[22 25 20 18 21]
mean_x1 = mean(x1)
mean_x2 = mean(x2)
std_x1 = stdev(x1)
std_x2 = stdev(x2)
n1 = length(x1)
n2 = length(x2)
se = sqrt((std_x1 ^ 2 / n1) + std_x2 ^ 2 / n2)
t = (mean_x1 - mean_x2) / se
df = (((std_x1 ^ 2 / n1) + std_x2 ^ 2 / n2) ^ 2) / ((std_x1 ^ 2 / n1) ^ 2 / (n1 - 1) + ((std_x2 ^ 2 / n2) ^ 2 / (n2 - 1)))
disp("t.statistics = " + string(t))
disp("degree of freedom = " + string(df))
p_value = 2 * (1 - cdft("PQ", abs(t), df))
disp("p-value = " + string(p_value))
alpha = 0.05
if p_value<alpha then
   disp("reject the null hypothesis: there is a significant difference between the means")
else
   disp("fail to reject the null hypothesis: no significant difference between the means")
end 
