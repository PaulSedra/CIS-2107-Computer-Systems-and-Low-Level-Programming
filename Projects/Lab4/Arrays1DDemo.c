//
// Created by paul on 2/19/2023.
// CIS 2107 - Lab 04 Arrays1DDemo
//
/**
 * Problem - Design and implement functions to process 1D arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 40
#define RAND_MIN 0
#define RAND_MAX 100

// declarations
void fillArray();
void findWithRange(unsigned int lowSelectedRange, unsigned int highSelectedRange);
void reverseArray();
void reverseSelectedRangeWithinArray(unsigned int startRange, unsigned int endRange);
void findSequence();

// arrays
int array[ARR_SIZE];    // original array
int arrayR[ARR_SIZE];   // reversed array
int arrayRS[ARR_SIZE];  // reversed selected array

int main() {

    // set time-based seed
    srand(time(NULL));

    // demos
    puts("");
    fillArray();
    puts("\n");
    findWithRange(10, 19);
    puts("\n");
    reverseArray();
    puts("\n");
    reverseSelectedRangeWithinArray(10, 19);
    puts("\n");
    findSequence();
    puts("");

    return 0;
}

/**
 * Looks for a sequence of two numbers in the original array.
 * Outputs the index of the first element if the sequence is found.
 */
void findSequence() {

    // variables
    int tom;
    int jerry;

    // user input
    printf("%s", "Enter two numbers: ");
    scanf("%d %d", &tom, &jerry);

    // edge cases
    if (
        RAND_MIN >= tom ||
        RAND_MAX <= tom ||
        RAND_MIN >= jerry ||
        RAND_MAX <= jerry
    ) {
        puts("Sequence not found");  // numbers not in range
        return;
    }

    // iterate through array
    for ( size_t i=0; i<ARR_SIZE-1; ++i ) {
        // sequence found
        if ( array[i]==tom && array[i+1]==jerry ) {
            printf("Sequence found at index %zu", i);
            return;
        }
    }
    puts("Sequence not found");
}

/**
 * Reverses the original array within a given range and populated the reversed selected array.
 * @param startRange range lower bound
 * @param endRange range upper bound
 */
void reverseSelectedRangeWithinArray(unsigned int startRange, unsigned int endRange) {

    // edge cases
    if ( startRange > endRange ) { return; }  // range impossible
    if ( startRange > ARR_SIZE-1 || endRange > ARR_SIZE-1 ) { return; }  // out of bounds

    // reverse selected range
    printf("REVERSED SELECTED [%u-%u]\n", startRange, endRange);
    for ( size_t i=0; i<ARR_SIZE; ++i ) {
        if ( i!=0 && i%10==0 ) { puts(""); }
        arrayRS[i] = startRange <= i && i <= endRange ? array[endRange + startRange - i] : array[i];
        printf("%3d  ", arrayRS[i]);
    }
}

/**
 * Reverses the original array and populates the reversed array.
 */
void reverseArray() {

    puts("REVERSED");
    for ( size_t i=0; i<ARR_SIZE; ++i ) {
        if ( i!=0 && i%10==0 ) { puts(""); }
        arrayR[i] = array[ARR_SIZE-1 - i];
        printf("%3d  ", arrayR[i]);
    }
}

/**
 * Finds the highest integer in the original array within a given range.
 * @param lowSelectedRange range lower bound
 * @param highSelectedRange range upper bound
 */
void findWithRange(unsigned int lowSelectedRange, unsigned int highSelectedRange) {

    int max;

    //edge cases
    if ( lowSelectedRange > highSelectedRange ) { return; }  // range impossible
    if ( lowSelectedRange > ARR_SIZE-1 || highSelectedRange > ARR_SIZE-1 ) { return; }  // out of bounds

    printf("%s", "max(");
    for ( size_t i=lowSelectedRange; i<highSelectedRange+1; ++i ) {
        // update max
        if ( array[i] > max ) {
            max = array[i];
        }
        // print
        i==highSelectedRange?
            printf("%d", array[i]):    // last element w/out comma
            printf("%d, ", array[i]);  // element w/ comma
    }
    printf(") = %d", max);
}

/**
 * Fills the original array with random integers within a given range.
 * @param rand_min rand lower bound
 * @param rand_max rand upper bound
 */
void fillArray() {

    puts("ORIGINAL");
    for ( size_t i=0; i<ARR_SIZE; ++i ) {
        if ( i!=0 && i%10==0 ) { puts(""); }  // split output into chunks of 10 elements
        array[i] = RAND_MIN + rand() % (RAND_MAX+1 - RAND_MIN);  // assign random int
        printf("%3d  ", array[i]);  // print element
    }
}
