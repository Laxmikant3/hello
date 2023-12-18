#include <stdio.h>

#define MAX_SIZE 100

// Function declarations
void enqueue(int queue[], int *rear, int element);
int dequeue(int queue[], int *front,int *rear);
void bubbleSort(int arr[], int n);

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;
    int n, i;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get elements from the user and enqueue them
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        enqueue(queue, &rear, element);
    }

    // Dequeue elements into an array
    int arr[MAX_SIZE];
    for (i = 0; i < n; i++) {
        arr[i] = dequeue(queue, &front,&rear);
    }

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Display the sorted elements
    printf("\nSorted Elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Function to enqueue an element into the queue
void enqueue(int queue[], int *rear, int element) {
    if (*rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (*rear == -1) {
        *rear = 0;
    }

    queue[++(*rear)] = element;
}

// Function to dequeue an element from the queue
int dequeue(int queue[], int *front,int *rear) {
    if (*front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int element = queue[(*front)++];
    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }

    return element;
}

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
