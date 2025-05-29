#include <stdio.h>  
#include <stdlib.h>  

void counting_sort(int *arr, int size) 
{  
    if (size <= 0) return;  

    int max = arr[0];  
    for (int i = 1; i < size; i++) 
    {  
        if (arr[i] > max) 
        {  
            max = arr[i];  
        }  
    }  
    int *count = (int *)calloc(max + 1, sizeof(int));  
    for (int i = 0; i < size; i++) 
    {  
        count[arr[i]]++;  
    }  
    for (int i = 1; i <= max; i++) 
    {  
        count[i] += count[i - 1];  
    }  
    int *output = (int *)malloc(size * sizeof(int));  
    for (int i = size - 1; i >= 0; i--) 
    {  
        output[count[arr[i]] - 1] = arr[i];  
        count[arr[i]]--;  
    }  

    for (int i = 0; i < size; i++) 
    {  
        arr[i] = output[i];  
    }  
    free(count);  
    free(output);  
}  
void print_array(int *arr, int size) 
{  
    for (int i = 0; i < size; i++) 
    {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  

int main() 
{  
    int arr[] = {4, 2, 2, 8, 3, 3, 1};  
    int size = sizeof(arr) / sizeof(arr[0]);  
    printf("Original Array: ");  
    print_array(arr, size);  
    counting_sort(arr, size);  
    printf("Sorted Array: ");  
    print_array(arr, size);  
    return 0;  
}  