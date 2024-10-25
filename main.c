#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void predict(int *predictions, int *hoursOfStudy, int size, int weight, int bias){

    for(int i = 0; i <= size - 1; ++i){

        *(predictions + i) = weight * (*(hoursOfStudy + i)) + bias;
    }
}


// Mean Squared Error (MSE)
float costFunction(int *predictions, int *testGrades, int size){

    int cost = 0;

    for(int i = 0; i <= size - 1; ++i){
        
        cost += pow(*(predictions + i) - *(testGrades + i), 2);
    }

    return (float) cost / (2 * size);
}

float weightGradient(int *predictions, int*hoursOfStudy, int *testGrades, int size){

    int grad = 0;

    for(int i = 0; i <= size - 1; ++i){

        grad += (*(predictions + i) - *(testGrades + i)) * *(predictions + i);
    }

    return (float) grad / size;
}

float biasGradient(int *predictions, int *testGrades, int size){

    int grad = 0;

    for(int i = 0; i <= size - 1; ++i){

        grad += *(predictions + i) - *(testGrades + i);
    }

    return (float) grad / size;
}


int main(){

    // y = weight * x + bias


    //training data
    int *x = (int *) malloc (5 * sizeof(int)); //hours of study
    int *y = (int *) malloc (5 * sizeof(int)); //grade received by the student

    int *modelPredictions = (int *) malloc (5 * sizeof(int));


    int rn;
    srand(time(NULL)); //changes the seed of rand() with the current time


    //populate the training dataset
    //the scenario is number of hours of study related to the grade the student got
    for(int i = 0; i <= 4; i++){
        *(x + i) = 2 * i;
        
        //adds randomness to the training data (a number between 0 and 10)
        rn = rand() % 10;

        if((10 * (2 * i) + rn) > 100){
            *(y + i) = 100;
        }
        else{
            *(y + i) = 10 * (2 * i) + rn;
            // the model will 'learn' that the weight is 10 and the bias is an aggregate of all random values that 'rn' takes
        }
    }

    // for(int i = 1; i <= 5; i++){
    //     printf("%d %d\n", *(x + i), *(y + i));
    // }

    int weight = 0;
    int bias = 0;


    
    return 0;
}