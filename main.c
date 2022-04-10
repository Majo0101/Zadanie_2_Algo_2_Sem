#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZERO 0

int arr[9999];

void randomArraySorted();            // sorted array without duplications
int findMe();                        // return existing number from array
int linearSearchCount(int findMe);   // linear search in array, return number of searches
int binarySearchCount(int findMe);   // binary search with array, return number of searches

int main() {

    char stop = CHAR_MAX;

    srand((time)NULL);

    while(stop != 'n'){

        randomArraySorted();

        float linearCount = ZERO;
        float binaryCount = ZERO;

        for (int i = 0; i < 1000; i++) {

            int tmp = findMe();

            linearCount += (float)linearSearchCount(tmp);
            binaryCount += (float)binarySearchCount(tmp);
        }

        printf("Number of searches per number: %.2f Linear  %.2f Binary", (linearCount/1000), (binaryCount/1000));

        printf("\n\nREPEAT? (y/n)\n");
        stop = (char)getchar();
        fflush(stdin);
    }
}

void randomArraySorted(){
    for (int i = 0, result = 0; i < 10000 ; i++) {

        arr[i] = (result += rand() % 5);

        if(i > 0){
            while(arr[i -1] == arr[i]){
                arr[i] = (result += rand() % 5);
            }
        }
    }
}

int findMe(){
    return arr[rand() % 10000];
}

int linearSearchCount(int findMe){

    int counter = 0;

    for (int i = 0; i < 10000; ++i) {

        counter++;

        if(findMe == arr[i]){
            break;
        }
    }

    return counter;

}

int binarySearchCount(int findMe){

    int counter = 0;
    int begin = 0;
    int end = (sizeof (arr) / sizeof (int));
    int middle;

    while(begin <= end){

        counter++;

        middle = (begin + end) / 2;

        if(arr[middle] == findMe){
            break;
        }

        if(arr[middle] < findMe){
            begin = middle + 1;
        }else{
            end = middle - 1;
        }
    }

    return counter;
}






