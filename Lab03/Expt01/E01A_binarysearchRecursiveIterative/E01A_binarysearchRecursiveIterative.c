#include <stdio.h>

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;  // Key found
        else if (arr[mid] > key)
            return binarySearchRecursive(arr, left, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1;  // Key not found
}

// Iterative (Non-Recursive) Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;  // Key found
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;  // Key not found
}

int main() {
    int n, key, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("\nChoose Search Method:\n");
    printf("1. Recursive Binary Search\n");
    printf("2. Iterative Binary Search\n");
    scanf("%d", &choice);

    int result;
    if (choice == 1)
        result = binarySearchRecursive(arr, 0, n - 1, key);
    else
        result = binarySearchIterative(arr, n, key);

    if (result != -1)
        printf("Key %d found at position %d (0-based index).\n", key, result);
    else
        printf("Key %d not found in the list.\n", key);

    return 0;
}
