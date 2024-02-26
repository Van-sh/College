// 10. Calculate gross salary of en employee according to input values by the following:
// basic salary >= 10000:
//     HRA = 20%
//     DA = 80%
// basic salary >= 20000:
//     HRA = 25%
//     DA = 90%
// basic salary > 30000:
//     HRA = 30%
//     DA = 95%
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