#include <stdio.h>
//#define N 9

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void window (int arr[], int i, int N) {
    int max = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < N && arr[left] > arr[max])
        max = left;
    if(right < N && arr[right] > arr[max])
        max = right;
    if(max != i) {
        swap(&arr[i], &arr[max]);
        window(arr, max, N);
    }
}

void pyramid_sort (int arr[], int N) {
    for(int i = N/2; i >= 0; i--) {
        window(arr, i, N);
    }
    
    for(int i = N-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        window(arr, 0, i);
    }
}

int main()
{
    int arr[9] = { -5, -6, 30, 5, 2, 1, 10, 7, 6 };
    int m = 0;
    
    pyramid_sort(arr, 9);
    
    while(m < 9) {
        printf("%d ", arr[m]);
        m++;
    }
    
    return 0;
}