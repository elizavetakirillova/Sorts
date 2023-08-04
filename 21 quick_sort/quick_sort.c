/* Быстрая сортировка */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10

int* arr_generate (int* arr) {
    srand(time(NULL));
    for(int i = 0; i < NUM; i++)
    {
        arr = realloc(arr, (i + 1) * sizeof(int));
        arr[i] = - 9 + rand()%19;
    }
    
    return arr;
}

int support_finder (int* arr, int l, int r) {
    int sup = arr[r];
    int support_idx = l;
    int temp;
    for(int i = l; i < r; i++) {
        if(arr[i] <= sup) {
            temp = arr[i];
            arr[i] = arr[support_idx];
            arr[support_idx] = temp;
            support_idx++;
        }
    }
    temp = arr[r];
    arr[r] = arr[support_idx];
    arr[support_idx] = temp;
    
    return support_idx;
}

void quick_sort (int* arr, int l, int r) {
    if (l < r) {
        int s = support_finder(arr, l, r);
        quick_sort(arr, l, s-1);
        quick_sort(arr, s+1, r);
    }
}

int main()
{
    int* arr = NULL;
    arr = arr_generate(arr);
    int m = 0;
    
    while(m < NUM) {
        printf("%d ", arr[m]);
        m++;
    }
    
    quick_sort(arr, 0, NUM-1);
    printf("\n");
    
    m = 0;
    while(m < NUM) {
        printf("%d ", arr[m]);
        m++;
    }
    

    return 0;
}
