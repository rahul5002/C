#include <stdio.h>
#include <pthread.h>
void* print_numbers(void* arg) 
{
    int thread_id = *(int*)arg;
    printf("Thread %d: Printing numbers 1 to 10\n", thread_id);
    for (int i = 1; i <= 10; i++) 
    {
        printf("Thread %d: %d\n", thread_id, i);
    }
    printf("Thread %d: Done\n", thread_id);
    return NULL;
}

int main() 
{
    pthread_t threads[5]; 
    int thread_ids[5];    
    for (int i = 0; i < 5; i++) 
    {
        thread_ids[i] = i + 1; 
        if (pthread_create(&threads[i], NULL, print_numbers, &thread_ids[i]) != 0) 
        {
            perror("Failed to create thread");
            return 1;
        }
    }
    for (int i = 0; i < 5; i++) 
    {
        if (pthread_join(threads[i], NULL) != 0) 
        {
            perror("Failed to join thread");
            return 1;
        }
    }
    printf("All threads have finished execution.\n");
    return 0;
}
