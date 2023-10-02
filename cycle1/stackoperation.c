#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int top = -1, a[SIZE];
void push();
void pop();
void show();

int main()
{
    int choice;
    while (1)
    {
        printf("\n\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show the element\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{
    int x;
    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        a[top] = x;
        printf("\nThe pushed element is :%d",x);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element is: %d", a[top]);
        top = top - 1;
    }
}

void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", a[i]);
    }
}