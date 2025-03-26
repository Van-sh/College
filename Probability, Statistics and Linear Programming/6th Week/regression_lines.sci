n = input("Enter number of data points: ")
printf("Enter the values of xi")
for i = 1:n
    x(i) = input("\")
end
printf("Enter the values of yi")
for i = 1:n
    y(i) = input("\")
end
sumx = 0
sumy = 0
sumxy = 0
sumx2 = 0
for i = 1:n
    sumx = sumx + x(i)
    sumx2 = sumx2 + x(i) * x(i)
    sumy = sumy + y(i)
    sumxy = sumxy + x(i) * y(i)
end
a = ((sumx2 * sumy - sumx * sumxy) * 1.0 / (n * sumx2 - sumx * sumx) * 1.0)
b = ((n * sumxy - sumx * sumy) * 1.0 / (n * sumx2 - sumx * sumx) * 1.0)
printf("The line is Y = %3.3f + %3.3fX", a, b)
x = (0:2:20)
plot(x, a + b * x)
