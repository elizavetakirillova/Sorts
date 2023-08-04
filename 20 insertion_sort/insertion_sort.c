#include <stdio.h>
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

int main()
{
    int* arr = NULL;
    arr = arr_generate(arr);
    int m = 0;
    
    while(m < NUM) {
        printf("%d ", arr[m]);
        m++;
    }
    
    for(int i = 1; i < NUM; i++)
    {
        int temp = arr[i];
        int j = i;
        while(temp < arr[j - 1] && j > 0) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
        printf("\n");
    
        m = 0;
        while(m < NUM) {
            printf("%d ", arr[m]);
            m++;
        }
    }
    
    printf("\n");
    
    m = 0;
    while(m < NUM) {
        printf("%d ", arr[m]);
        m++;
    }
    

    return 0;
}
