#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray {
    int* data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray* arr);
int get(DynamicArray*arr, int i);
int set(DynamicArray*arr, int i, int value);
void push_back(DynamicArray*arr, int value);
void removee(DynamicArray*arr, int i);
int pop_back(DynamicArray*arr);
void print_dynamic_array(DynamicArray* arr);

int main() {
    DynamicArray da;
    initArray(&da);
    push_back(&da, 3);
    set(&da,0,1);
    push_back(&da, 2);
    print_dynamic_array(&da);
    push_back(&da, 3);
    push_back(&da, 4);
    printf("Poped %d \n", pop_back(&da));
    print_dynamic_array(&da);
    printf("value at 1: %d\n", get(&da, 1));
    return 0;
}

void initArray(DynamicArray* arr) {
    arr->size = 0;
    arr->capacity = 2;
    arr->data = malloc(arr->capacity*sizeof(int));
    if (arr->data == NULL) {
        printf("Afailled to allocate Memory\n");
        return;
    }
}

int get(DynamicArray*arr, int i) {
    if (i < 0 ||  i >= arr->size) {
        printf("Invalid index\n");
        exit(1);
    }
    return arr->data[i];
}
int set(DynamicArray*arr, int i, int value) {
    if (i < 0 ||  i > arr->size) {
        printf("Invalid index\n");
        return 0;
    }
    arr->data[i] = value;
    if (arr->size == i) {
        arr->size++;
    }
    return 1;

}
void push_back(DynamicArray*arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        int* tmp = realloc(arr->data, arr->capacity); {
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
    for (int j = i; j < arr->size - 2; j++) {
        arr->data[j] = arr->data[j+1];
    }
    arr->size--;
}
int pop_back(DynamicArray* arr) {
    if (arr->size == 0) {
        printf("Array is empty\n");
        exit(1);
    }
    arr->size--;
    return arr->data[arr->size];
}

void print_dynamic_array(DynamicArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}