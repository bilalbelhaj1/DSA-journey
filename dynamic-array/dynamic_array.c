#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray {
    int* data;
    int size;
    int capacity;
} DynamicArray;

int initArray(DynamicArray* arr);
int get(DynamicArray*arr, int i);
int set(DynamicArray*arr, int i, int value);
void push_back(DynamicArray*arr, int value);
void removee(DynamicArray*arr, int i);
int pop_back(DynamicArray*arr);
void print_dynamic_array(DynamicArray* arr);

int main() {
    DynamicArray da;
    if (initArray(&da) == 0) {
        return 1;
    }
    push_back(&da, 10);
    push_back(&da, 20);
    push_back(&da, 30);
    push_back(&da, 40);
    push_back(&da, 50);
    print_dynamic_array(&da);
    removee(&da, 1);
    print_dynamic_array(&da);
    return 0;
}

int initArray(DynamicArray* arr) {
    arr->size = 0;
    arr->capacity = 2;
    arr->data = malloc(arr->capacity*sizeof(int));
    if (arr->data == NULL) {
        printf("Afailled to allocate Memory\n");
        return 0;
    }
    return 1;
}

int get(DynamicArray*arr, int i) {
    if (i < 0 ||  i >= arr->size) {
        printf("Invalid index\n");
        exit(1);
    }
    return arr->data[i];
}
int set(DynamicArray*arr, int i, int value) {
    if (i < 0 ||  i >= arr->size) {
        printf("Invalid index\n");
        return 0;
    }
    arr->data[i] = value;
    return 1;

}
void push_back(DynamicArray*arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        int* tmp = realloc(arr->data, arr->capacity*sizeof(int)); {
            if (tmp == NULL) {
                printf("failled to resize the array\n");
                arr->capacity /= 2;
                return;
            }
            arr->data = tmp;
        }
    }
    arr->data[arr->size] = value;
    arr->size++;
}
void removee(DynamicArray *arr, int i) {
    if (i < 0 || i >= arr->size) {
        printf("Invalid index\n");
        return;
    }
    for (int j = i; j <= arr->size - 2; j++) {
        arr->data[j] = arr->data[j+1];
    }
    arr->size--;
}
int pop_back(DynamicArray* arr) {
    
    if (arr->size == 0) {
        printf("Array is empty\n");
        return -1;
    }

    int value = arr->data[arr->size - 1];
    arr->size--;

    if (arr->size <= arr->capacity / 4 && arr->capacity > 2) {

        int new_capacity = arr->capacity / 2;

        int* tmp = realloc(
            arr->data,
            new_capacity * sizeof(int)
        );

        if (tmp != NULL) {
            arr->data = tmp;
            arr->capacity = new_capacity;
        }
    }

    return value;
}

void print_dynamic_array(DynamicArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}