//
// Created by paul on 2/12/2023.
// CIS 2107 - Lab 03 ATM
//
/**
 * Problem - Calculate the revenue from a sale based on the unitPrice, and quantity of the product.
 */

// Dependencies
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


// Validations
bool isValidPin(int pin);
bool isValidAmount(long double amount, int limit, bool withdraw);

// ATM functions
void balance();
void withdraw();
void deposit();
void quit();
void printReceipt();

// global variables
unsigned int trans = 0;
long long int bal = 5000;

int main() {

    // variables
    int pin;
    int command;
    int receipt;

    // program start
    puts("Welcome to the ATM");

    // pin
    unsigned short i = 0;
    while ( i < 3 ) {
        printf("%s", "Please enter your pin: ");
        scanf("%d", &pin);      // get pin from user
        if ( isValidPin(pin) ) { break; }       // pin validated
        printf("Invalid Pin you have %d tries left.\n\n", 2-i);
        ++i;
    }
    // user failed to enter a valid pin
    if ( i==3 ) {
        puts("Thank you for using the ATM Machine.");
        exit(0);
    }

    // atm transactions 1-4
    puts("Hello Nana!\n");
    do {
        // transaction
        printf("%s", "Enter a transaction code: ");
        scanf("%d", &command);
        switch ( command ) {
            case 1: { balance(); break; }
            case 2: { withdraw(); break; }
            case 3: { deposit(); break; }
            case 4: { break; }
            default: { command=0; puts("Invalid command. Please try again."); }
        }
        // receipt
        receipt=0;
        while ( receipt!=1 && receipt!=2 && command!=0 ) {
            puts("Would you like a receipt?");
            scanf("%d", &receipt);
            switch ( receipt ) {
                case 1: { printReceipt(); break; }
                case 2: { break; }
                default: { puts("Invalid command. Type 1 for receipt or 2 for no receipt."); }
            }
        }
        puts("");
    } while ( command != 4 );

    quit();
    return 0;
}

bool isValidPin(int pin) {

    if ( pin != 3014 ) {
        return false;
    }

    return true;
}

/**
 * Runs 4 validations on the user input before proceeding with the transaction.
 * Outputs the appropriate error message is necessary.
 * @param amount - user input
 * @param limit - daily limit for the transaction
 * @param withdraw - if this transaction is a withdrawal
 * @return if the amount is valid
 */
bool isValidAmount(long double amount, int limit, bool withdraw) {

    // no negatives
    if ( amount <= 0 ) {
        puts("Invalid amount. Non-positive amounts are not accepted.");
        return false;
    }

    // no coins
    double integer;
    double decimal = modf(amount, &integer);
    if ( decimal != 0 ) {
        puts("Invalid amount. Change is not accepted.");
        return false;
    }

    // only Jacksons
    if ( withdraw && (int)amount%20 != 0 ) {
        puts("Invalid amount. You can only withdraw $20 bills.");
        return false;
    }

    // can not exceed limit
    if ( amount > limit ) {
        puts("Invalid amount. That amount exceeds your daily allowed limit for that transaction type.");
        withdraw?
            printf("Your withdrawal limit is $1000 and you have $%d left.\n", limit):
            printf("Your deposit limit is $10000 and you have $%d left.\n", limit);
        return false;
    }

    return true;
}

/**
 * Handles the balance transaction.
 * Outputs the user's balance on the screen.
 */
void balance() {

    printf("Your balance is $%lld.00\n", bal);
    ++trans;
}

/**
 * Handles the withdraw transaction.
 */
void withdraw() {

    // variables
    static int limit = 1000;
    long double amount;

    // limit reached
    if ( limit==0 ) {
        puts("Unfortunately, you have reached your withdrawal limit for today.");
        return;
    }

    // withdraw
    unsigned short i = 0;
    do {
        puts("How much would you like to withdraw?");
        scanf("%Lf", &amount);
        ++i;
    } while ( !isValidAmount(amount, limit, true) && i<3 );
    // user failed to enter a valid amount
    if ( i==3 ) {
        puts("For your security we have temporarily locked your account.");
        puts("Please try again later or contact support.");
        puts("\nThank you for using the ATM Machine.");
        exit(0);
    }

    // update values
    limit -= amount;
    bal -= amount;
    ++trans;
}

/**
 * Handles the deposit transaction.
 */
void deposit() {

    // variables
    static int limit = 10000;
    long double amount;

    // limit reached
    if ( limit==0 ) {
        puts("Unfortunately, you have reached your deposit limit for today.");
        return;
    }

    // deposit
    unsigned short i=0;
    do {
        puts("How much would you like to deposit?");
        scanf("%Lf", &amount);
        ++i;
    } while ( !isValidAmount(amount, limit, false) && i<3 );
    // user failed to enter a valid amount
    if ( i==3 ) {
        puts("For your security we have temporarily locked your account.");
        puts("Please try again later or contact support.");
        puts("\nThank you for using the ATM Machine.");
        exit(0);
    }

    // update values
    limit -= amount;
    bal += amount;
    ++trans;
}

/**
 * Quits the ATM.
 */
void quit() {
    ++trans;
    printf("Number of Transactions: %u\n", trans);
    puts("Thank you for using the ATM.");
}

/**
 * Prints the receipt after ever transaction if user wants a receipt for that transaction.
 */
void printReceipt() {
    // Unimplemented as per assigment requirements.
}