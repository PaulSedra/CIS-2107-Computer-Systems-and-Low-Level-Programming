//
// Created by paul on 2/2/2023.
//

#include <stdio.h>
#include <math.h>

int main() {
    double integer, decimal;
    double employeeId;
    double salary;
    double totHrs;
    unsigned int otHrs;
    unsigned int regPay;
    unsigned int otPay = 0;

    printf("%s", "Welcome to TEMPLE \"HUMAN RESOURCES\"\n\n");

    // Employee ID
    printf("%s", "\tEnter Employee Number: ");
    scanf("%lf", &employeeId);

    if ( employeeId < 0 ) {
        printf("%s", "\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        return 0;
    }

    decimal = modf (employeeId, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        return 0;
    }

    // Employee Salary
    printf("%s", "\tEnter Hourly Salary: ");
    scanf("%lf", &salary);

    if ( salary < 0 ) {
        printf("%s", "\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        return 0;
    }

    decimal = modf(salary, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        return 0;
    }

    // Employee Total Work Hours
    printf("%s", "\tEnter Weekly Time: ");
    scanf("%lf", &totHrs);

    if ( totHrs < 0 ) {
        printf("%s", "\n\tThis is not a valid weekly time.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        return 0;
    }

    decimal = modf(totHrs, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid weekly time.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        return 0;
    }


    // Pay Calculation Logic
    if ( totHrs > 40 ) {
        otHrs = totHrs - 40;
        otPay = otHrs * salary * 1.5;
    }
    regPay = (totHrs - otHrs) * salary;

    printf("%s", "\t==============================\n");
    printf("\tEmployee #: %.0lf\n", employeeId);
    printf("\tHourly Salary: $%.1lf\n", salary);
    printf("\tWeekly Time: %.1lf\n", totHrs);
    printf("\tRegular Pay: $%u.0\n", regPay);
    printf("\tOvertime Pay: $%u.0\n", otPay);
    printf("\tNet Pay: $%u.0\n", regPay + otPay);
    printf("%s", "\t==============================\n");
    printf("%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"");

    return 0;
}