#include <stdio.h>
#include<stdlib.h>
//global variables
int arr[100]; 
int n;        

void linearSearch(int key, int *result) {
	printf("Enter the element to search: ");
    scanf("%d", &key);
    *result = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            *result = i;
            return;
        }
    }
}

void binarySearch(int key, int *result) {
	printf("Enter the element to search: ");
    scanf("%d", &key);
    int left = 0;
    int right = n - 1;
    *result = -1; 
    
    while (left <= right) 
	{
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) 
		{
            *result = mid;
            return;
        }
        else if (arr[mid] < key) 
		{
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
}



int main() {
    int key;
    int choice;
    int result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
while(1)
{
    printf("Choose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
	printf("3. Exit\n");
	printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            linearSearch(key, &result);
            break;
        case 2:
            binarySearch(key, &result);
            break;
		case 3:
			exit(0);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    if (result != -1) {
        printf("Element found at index: %d\n", result+1);
    } else {
        printf("Element not found\n");
    }
}
    return 0;
}
