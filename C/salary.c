#include <stdio.h>

void main()
{
    float basic_salary, hra, da, gross_salary;
    printf("Enter basic salary: ");
    scanf("%f", &basic_salary);
    if (basic_salary > 30000)
    {
        hra = basic_salary * 0.3;
        da = basic_salary * 0.95;
    }
    else if (basic_salary >= 20000)
    {
        hra = basic_salary * 0.25;
        da = basic_salary * 0.9;
    }
    else if (basic_salary >= 10000)
    {
        hra = basic_salary * 0.2;
        da = basic_salary * 0.8;
    }
    gross_salary = basic_salary + hra + da;
    printf("Gross salary is %.2f\n", gross_salary);
}