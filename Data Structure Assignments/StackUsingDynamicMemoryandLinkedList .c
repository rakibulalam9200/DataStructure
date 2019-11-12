/*
 Program:  Implement Stack Operations using Dynamic MemoryAllocation
 author: Rakibul Alam
 ID: 181-16-285
 */
 // Header file
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// Declare a structure
struct Student_Node
{
    int std_Roll;
    int std_Age;
    struct Student_Node *link;
}*top = NULL;

#define SIZE 10

// function prototypes
void push();
void pop();
void empty();
void stack_full();
void stack_count();
void print_top();

void main()
{
    int choice;
    printf("Choose option:\n===============================\n");

    while (1)
    {
        printf("1. Push an Student Information \n");
        printf("2. Pop an Student Information \n");
        printf("3. Check if stack is empty \n");
        printf("4.Check if stack is full \n");
        printf("5. Display Number of Student Information present in stack \n");
        printf("6. Print top of the stack \n");
        printf("7. exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            empty();
            break;
        case 4:
            stack_full();
            break;
        case 5:
            stack_count();
            break;
        case 6:
            print_top();
            break;
        case 7:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}

// to insert Student information  in stack
void push()
{
    int roll,age,count;
    struct Student_Node *std;
    std = (struct Student_Node*)malloc(sizeof(struct Student_Node));
    count = st_count();
    if (count <= SIZE - 1)
    {
         printf("\n===========================================\n");
        printf("Enter Student Info to push into the stack :\n");
        printf("Student Roll No.: ");
        scanf("%d",&roll);
        printf("Student Age: ");
        scanf("%d",&age);
        std->std_Age = age;
        std->std_Roll = roll;
        std->link = top;
        top = std;
    }
    else
        printf("\n=============================\nWARNING: STACK OVERFLOW\n=============================\n");
}
// to delete Student information from stack
void pop()
{
    struct Student_Node *std;
    if (top == NULL)
        printf("\n*****************\nStack is empty\n*****************\n");
    else
    {
        std = top;
        printf("\n====================================================\n");
        printf("Value popped out of Student Info: Roll: %d  Age: %d\n",std->std_Roll,std->std_Age);
        printf("=====================================================\n");
        top = top->link;
        free(std);
    }
}

// to check if stack is empty
void empty()
{
    if (top == NULL)
        printf("\n========================\nSTACK IS EMPTY\n========================\n");
    else
    {
        printf("\n==============================================\n");
         printf("Student Info. are present, stack is not empty \n");
         printf("==============================================\n");
    }

}

// to check if stack is full
void stack_full()
{
    int count;

    count = st_count();
    if (count == SIZE)
    {
         printf("\n==========================\n");
        printf("stack is full\n");
         printf("==========================\n");
    }
    else
    {
         printf("\n==========================\n");
         printf("stack is not full \n");
          printf("==========================\n");
    }

}

// to count the number of Student information contains
void stack_count()
{
    int count = 0;
    struct Student_Node *std;

    std = top;
    while (std != NULL)
    {
        printf(" %d\n",std->std_Age);
        std = std->link;
        count++;
    }
    printf("\n=====================\nSize of stack is %d \n\n=====================\n",count);
}

int st_count()
{
    int count = 0;
    struct Student_Node *std;
    std = top;
    while (std != NULL)
    {
        std = std->link;
        count++;
    }
    return count;
}

// to print top student information  of stack
void print_top()
{
    if (top == NULL)
        printf("\n**Top is not available for an EMPTY stack**\n");
    else
    {
        printf("\n==============================================\n");
        printf("Top of the stack is:\nStudent Info-> Roll: %d Age: %d",top->std_Roll,top->std_Age);
        printf("\n==============================================\n");

    }

}
