#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;  
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;  
            }
        }
        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void generateRandomNumbers(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;  
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);  

    if (n <= 5000)
    {
        printf("Please enter a value greater than 5000\n");
        return 1;  
    }

    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;  
    }

    
    generateRandomNumbers(arr, n);

    
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    
    free(arr);
    return 0;
}
/*import matplotlib.pyplot as plt

# data collected
n_values = [6000, 7000, 8000, 9000, 10000]
time_taken = [0.031000, 0.034000, 0.047000, 0.052000, 0.077000]  # replace with actual times recorded

plt.plot(n_values, time_taken, marker='o')
plt.title('Selection Sort Time Complexity')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time taken (seconds)')
plt.grid(True)
plt.show()*/