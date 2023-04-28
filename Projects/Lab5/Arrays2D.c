//
// Created by paul on 2/26/2023.
// CIS 2107 - Lab 05 Arrays2D
//
/**
 * Problem - Design and implement processGrades to process 2D arrays.
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int max( int arr[], unsigned int size );
int rowSum( int arr[], unsigned int row, unsigned int cols );
int columnSum( int arr[], unsigned int col, unsigned int rows, unsigned int cols );
bool isSquare( unsigned int rows, unsigned int cols );
void displayOutputs( int arr[], unsigned int rows, unsigned int cols);

int main() {

    // initialize size
    unsigned int rows;
    unsigned int cols;

    // get 2D array size
    puts("\nLet's create a 2Dim array!");
    printf("%s", "\tHow many rows? ");
    scanf("%u", &rows);
    printf("%s", "\tHow many columns? ");
    scanf("%u", &cols);

    // initialize array
    int linearArr[rows * cols];

    // populate array
    for ( size_t i=0; i < rows; ++i ) {
        for ( size_t j=0; j < cols; ++j ) {
            printf("\tenter [%zu][%zu]: ", i, j);
            scanf("%d", &linearArr[i*cols + j]);
        }
    }

    // max value
    printf("\nThe max value of the array is %d\n\n", max(linearArr, rows*cols));

    // row sums
    for ( size_t row=0; row<rows; ++row ) {
        printf("Sum of row %zu = %d\n", row, rowSum(linearArr, row, cols));
    }
    puts("");

    // column sums
    for ( size_t col=0; col<cols; ++col ) {
        printf("Sum of column %zu = %d\n", col, columnSum(linearArr, col, rows, cols));
    }
    puts("");

    // array shape
    isSquare(rows, cols) ?
        puts("This is a square array.\n") :
        puts("This is a rectangular array.\n");

    // visualize 2D array
    displayOutputs(linearArr, rows, cols);
    puts("");

    return 0;
}

/**
 * Visualizes a 2D array and outputs to console.
 * @param arr the array in linear form
 * @param rows the number of rows in the 2D array
 * @param cols the number of columns in the 2D array
 */
void displayOutputs( int arr[], unsigned int rows, unsigned int cols ) {

    puts("Here is your 2Dim array:");
    for ( size_t i=0; i<rows; ++i ) {
        printf("%s", "[");
        for ( size_t j=0; j<cols; ++j ) {
            j == cols-1 ?
                printf("%d", arr[i*cols + j]) :   // last element
                printf("%d, ", arr[i*cols + j]);  // all other elements
        }
        puts("]");
    }
}

/**
 * Determines if 2D array is a square.
 * @param rows the number of rows in the 2D array
 * @param cols the number of columns in the 2D array
 * @return true/false if 2D array is square
 */
bool isSquare( unsigned int rows, unsigned int cols ) {
    return rows == cols;
}

/**
 * Calculates the sum of elements in the ith column of each row of a 2D array.
 * @param arr the array in linear form
 * @param col the column to consider
 * @param rows the number of rows in the 2D array
 * @param cols the number of columns in the 2D array
 * @return the sum of the elements in the ith column of each row of the 2D array
 */
int columnSum( int arr[], unsigned int col, unsigned int rows, unsigned int cols ) {

    int sum = 0;
    for ( size_t i=0; i<rows; ++i ) {
        sum += arr[i*cols + col];
    }

    return sum;
}

/**
 * Calculates the sum of elements in the ith if a 2D array.
 * @param arr the array in linear form
 * @param row the row to consider
 * @param cols the number of columns in the 2D array
 * @return the sum of the elements in the ith row of the 2D array
 */
int rowSum( int arr[], unsigned int row, unsigned int cols ) {

    int sum = 0;
    for ( size_t i=0; i<cols; ++i ) {
        sum += arr[row*cols + i];
    }

    return sum;
}

/**
 * Find the max value in a 2D array
 * @param arr the array in linear form
 * @param size the number of elements in the array
 * @return the max value of the array
 */
int max( int arr[], unsigned int size ) {

    int max = INT_MIN;
    for ( size_t i=0; i<size; ++i ) {
        if ( arr[i] > max ) {
            max = arr[i];
        }
    }

    return max;
}
