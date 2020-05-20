#include "stdio.h"

void downAdjust(int arr[], int parentIndex, int length) {
    int temp = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;
    while (childIndex < length) {
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
            childIndex++;
        }
        if (temp >= arr[childIndex]) {
            break;
        }
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    arr[parentIndex] = temp;
}

int main() {
    int arr[10] = {2, 4, 1, 3, 6, 7, 9, 0, 8, 5};
    int length = (sizeof arr) / (sizeof arr[0]);

    // Construir un triángulo
    for (int i = (length - 2) / 2; i >= 0; i--) {
        downAdjust(arr, i, length);
    }
    // El ciclo elimina el elemento de la cúpula, se mueve a la cola del Grupo, 
    // el reactor regulador genera una nueva cúpula.
    for (int i = length - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        downAdjust(arr, 0, i);
    }

    printf("Heap sort:");
    for (int i = 0; i < 10; i++) {
        printf("%2d", arr[i]);
    }

    return 0;
}