/*
program: Quick Sort
Author: Rakibul Alam
ID: 181-16-285
*/
#include<stdio.h>
int size,array[100],i,j;  // Declare global variable

void swap(int* p,int* q)// swapping values of array
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int array[],int start, int end)
// declare partition function with Integer return type and three parameter
// one is array, one start of the array index and another end of the array
{
    int pivot = array[end];         // declare pivot at the last index of array

    i = start - 1;             // Initialize i as array index -1
    for(j = start;j<end;j++)  // check and increment every index value of array
    {
        if(array[j]<=pivot)       // Compare every array values with pivot
        {
            i++;              // increment index i only when condition true
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i + 1], &array[end]);
    return (i + 1);
}

void quickSort(int array[], int start,int end)
{
    int pi;
    if(start<end)
    {
        pi = partition(array,start,end); // call partition function
        quickSort(array,start,pi - 1);  // recursion
        quickSort(array,pi + 1,end);    // recursion
    }
}
void printArray()  // Function for print array
{
    printf("Sorted Array: ");
    for(i = 0;i<size;i++)

    {
        printf("%d ",array[i]);
    }
}
int main()
{
    printf("Enter your array size: ");
    scanf("%d",&size);
    printf("Enter your array values: \n");
    for(i = 0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    quickSort(array,0,size-1); // call quickSort function
    printArray();       // call printArray function
    return 0;
}

