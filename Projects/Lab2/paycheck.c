//
// Created by paul on 2/2/2023.
//
/**
 * Problem - Calculate the paycheck for Temple Employees based on the hourlySalary, weeklyTime, and overtime.
 */

#include <stdio.h>
#include <math.h>

int main() {
    double integer, decimal;
    double employeeId;
    double hourlySalary;
    double weeklyTime;
    unsigned int overtime = 0;
    unsigned int regPay;
    unsigned int otPay = 0;

    printf("%s", "Welcome to TEMPLE \"HUMAN RESOURCES\"\n\n");

    // Employee ID
    printf("%s", "\tEnter Employee Number: ");
    scanf("%lf", &employeeId);

    if ( employeeId <= 0 ) {
        printf("%s", "\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }

    decimal = modf(employeeId, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }

    // Employee Salary
    printf("%s", "\tEnter Hourly Salary: ");
    scanf("%lf", &hourlySalary);

    if ( hourlySalary <= 0 ) {
        printf("%s", "\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }

    decimal = modf(hourlySalary, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }

    // Employee Total Work Hours
    printf("%s", "\tEnter Weekly Time: ");
    scanf("%lf", &weeklyTime);

    if ( weeklyTime <= 0 ) {
        printf("%s", "\n\tThis is not a valid weekly time.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }

    decimal = modf(weeklyTime, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid weekly time.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        return 0;
    }


    // Pay Calculation Logic
    if ( weeklyTime > 40 ) {
        overtime = weeklyTime - 40;
        otPay = overtime * hourlySalary * 1.5;
    }
    regPay = (weeklyTime - overtime) * hourlySalary;

    printf("%s", "\t==============================\n");
    printf("\tEmployee #: %.0lf\n", employeeId);
    printf("\tHourly Salary: $%.1lf\n", hourlySalary);
    printf("\tWeekly Time: %.1lf\n", weeklyTime);
    printf("\tRegular Pay: $%u.0\n", regPay);
    printf("\tOvertime Pay: $%u.0\n", otPay);
    printf("\tNet Pay: $%u.0\n", regPay + otPay);
    printf("%s", "\t==============================\n");
    printf("%s", "Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    return 0;
}