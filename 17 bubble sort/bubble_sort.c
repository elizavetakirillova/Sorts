// Сортировка пузырьком. Вторая оптимизация
#include <stdio.h>

// мы забыли возвратить еще и индекс минимального компонента
int min(int* arr, int j, int* minimum_index) { 
    int i = j; // важно: i должно начинаться сначала очередного подмассива
    int min_component = arr[j];
    while(*(arr + i) != '\0') {
        if(min_component > *(arr + i)) {
            min_component = *(arr + i);
            *minimum_index = i; // То что мы забыли прописать
        }
        i++;
    }
    return min_component;
}

void swap(int* arr, int minimum, int minimum_index, int j) {
    int temp;
    temp = minimum;
    arr[minimum_index] = arr[j];
    arr[j] = temp;
}

int main() {
    int arr[20] = {50, 2, 24, -55, -10, -32, 64, -70, 92, -61, -81, 48, 12, 66, -59, -25, 19, -51, -38, 28};
    int i = 0;
    int minimum, temp;
    int minimum_index;
    for(int j = 0; j < 20; j++) {
        minimum = min(arr, j, &minimum_index);
        swap(arr, minimum, minimum_index, j);
    }
    
    while(*(arr + i) != '\0') {
        printf("%d ", arr[i]);
        i++;
    }

    return 0;
}
