#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        printf("Linear Search: Key found at index %d\n", linearResult);
    } else {
        printf("Linear Search: Key not found\n");
    }

    int binaryResult = binarySearch(arr, n, key);
    if (binaryResult != -1) {
        printf("Binary Search: Key found at index %d\n", binaryResult);
    } else {
        printf("Binary Search: Key not found\n");
    }

    return 0;
}
