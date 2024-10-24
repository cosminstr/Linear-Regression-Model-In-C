#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // y = weight * x + bias


    //training data
    int *x = (int *) malloc (5 * sizeof(int)); //independent variable
    int *y = (int *) malloc (5 * sizeof(int)); //dependent variable


    int rn;
    srand(time(NULL)); //changes the seed of rand() with the current time


    //populate the training dataset
    //the scenario is number of hours of study related to the grade the student got
    for(int i = 1; i <= 5; i++){
        *(x + i) = 2 * i;
        
        //adds randomness to the training data (a number between 0 and 15)
        rn = rand() % 15;

        if((10 * (2 * i) + rn) > 100){
            *(y + i) = 100;
        }
        else{
            *(y + i) = 10 * (2 * i) + rn;
        }
    }

    for(int i = 1; i <= 5; i++){
        printf("%d ", *(x + i));
        printf("%d ", *(y + i));
    }


    int weight = 0;
    int bias = 0;


    
    return 0;
}