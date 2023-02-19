//
// Created by paul on 2/4/2023.
// CIS 2107 - Lab 02 Revenue
//
/**
 * Problem - Calculate the revenue from a sale based on the unitPrice, and quantity of the product.
 */

#include <stdio.h>
#include <math.h>

int main() {
    double decimal, integer;
    double price;
    double quantity;
    unsigned int cost;
    unsigned int discount;

    printf("%s", "Welcome to \"Temple\" store\n\n");

    // Price
    printf("%s", "\tEnter item price: ");
    scanf("%lf", &price);

    if ( price <= 0 ) {
        printf("%s", "\n\tThis is not a valid item price.\n\tPlease run the program again\n\nThank You for using \"Temple\" store\n");
        return 0;
    }

    decimal = modf(price, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid item price.\n\tPlease run the program again\n\nThank You for using \"Temple\" store\n");
        return 0;
    }

    // Quantity
    printf("%s", "\tEnter quantity: ");
    scanf("%lf", &quantity);

    if ( quantity <= 0 ) {
        printf("%s", "\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\nThank You for using \"Temple\" store\n");
        return 0;
    }

    decimal = modf(quantity, &integer);
    if ( decimal > 0 ) {
        printf("%s", "\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\nThank You for using \"Temple\" store\n");
        return 0;
    }

    // Cost & Discount Logic
    cost = (int) price * (int) quantity;

    discount = (( (int) quantity - ( (int) quantity % 50 )) / 50) * 5;
    discount += quantity >= 50? 5 : 0;
    discount = quantity >= 150? 25 : discount + 0;

    printf("\n\tThe item price is: $%.1lf\n", price);
    printf("\tThe order is: %.0lf item(s)\n", quantity);
    printf("\tThe cost is: $%u.0\n", cost);
    printf("\tThe discount is: %u.0%%\n", discount);
    printf("\tThe discount amount is: $%.1lf\n", (double) discount/100* (double) cost);
    printf("\tThe total is: $%.1lf\n\n", cost - (double) discount/100* (double) cost);
    printf("Thank You for using \"Temple\" store\n");

    return 0;
}