//Reverse an Array using Two-Pointer Approach
//Problem: Given an array of n elements, reverse the array using the two-pointer approach and display the reversed array.

#include <stdio.h>

int main() {
    int n, i, temp;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Two-pointer reverse logic
    int start = 0, end = n - 1;
    while(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    // Output reversed array
    printf("Reversed array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
