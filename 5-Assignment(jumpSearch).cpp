//
// Created by DELL on 01/01/2023.
//
//
// Created by DELL on 31/12/2022.
//
#include "stdio.h"
#include "math.h"
int nextStep = 4;

int min(int first, int second){
    if(second>first) {
        return first;
    }else{
        return second;
    }
}
int jumpSearch(int arr[],int size,int key){

   int jumpSize = size/nextStep;
    int previous = 0;
    while ( arr[min(jumpSize, size)-1] < key){

        previous = jumpSize;

        jumpSize = jumpSize+size/nextStep;

        if(previous>= size){
            return -1;
        }


    }
    if(arr[previous] == key)
    {
        printf("if loop enter:");
        return previous;
    }
    for(int j = previous; j< jumpSize; j++){

        if (arr[j] == key) {
            return j;
        }
    }


    return -1;


}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,100,101,102};
    int size= sizeof(arr)/sizeof(arr[0]);
    int toFind = 7;

    int indexNumber = jumpSearch(arr,size,toFind);
    if( indexNumber !=-1){
        printf("We found\n");
        printf("found at index %d  data : %d" ,indexNumber , arr[indexNumber]);
    }else{
        printf("Not found\n");
    }



    return 0;
}