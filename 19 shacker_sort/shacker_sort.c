// Шейкер-сортировка
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10

int* arr_generate (int* arr)
{
    srand(time(NULL));
    for(int i = 0; i < NUM; i++)
    {
        arr = realloc(arr, (i + 1) * sizeof(int));
        arr[i] = - 9 + rand()%19;
    }
    
    return arr;
}

int main() {
    
    int* arr = NULL;
    arr = arr_generate(arr);
    int left = 0;
    int m = 0;
    int count = 0;
    int right = NUM - 1;
    
    while(m < NUM) {
        printf("%d ", arr[m]);
        m++;
    }
    printf("\n");
    
    while(left < right)
    {
        for(int i = left; i < right; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            
        }
        right--;
        for(int i = right; i > left; i--)
        {
            if(arr[i - 1] > arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
    
    m = 0;
    
    while(m < NUM) {
        printf("%d ", arr[m]);
        m++;
    }

    return 0;
}
