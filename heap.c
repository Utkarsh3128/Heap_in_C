// Max-Heap data structure in C

#include <stdio.h>
#include <math.h>

int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;   // set i as largest
        int l = 2 * i + 1; // set left child
        int r = 2 * i + 2; // set right child
        if (l < size && array[l] > array[largest])
            largest = l;
        if (r < size && array[r] > array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}
void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--) // loop from first index of non leaf node down to zero
        {
            heapify(array, size, i);
        }
    }
}
void deleteRoot(int array[], int num)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}

void printArray(int arr[], int n)
{
    int height = (int)(log2(n)) + 1;
    int maxNodes = (int)pow(2, height) - 1;
    int nodeWidth = 3;
    int levelWidth = maxNodes * nodeWidth;
    int i, j, k;

    for (i = 0; i < height; i++)
    {
        int nodesInLevel = (int)pow(2, i);
        int spaceWidth = levelWidth / nodesInLevel / 2;
        for (j = 0; j < nodesInLevel; j++)
        {
            int index = (int)pow(2, i) - 1 + j;
            if (index >= n)
            {
                break;
            }
            printf("%*c%d%*c", spaceWidth, ' ', arr[index], spaceWidth, ' ');
            for (k = 0; k < nodeWidth - 1; k++)
            {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }
}

int main()
{
    int array[10];

    insert(array, 50);
    insert(array, 30);
    insert(array, 20);
    insert(array, 15);
    insert(array, 10);
    insert(array, 8);
    insert(array, 16);

    printf("Max-Heap array: \n");
    printArray(array, size);

    int choice;
    printf("enter your choice\n");
    printf("1. Insert an element\n");
    printf("2. Delete the element\n");
    scanf("%d", &choice);

    int num;
    switch (choice)
    {
    case 1:
        printf("Enter the number to be inserted\n");
        scanf("%d", &num);
        insert(array, num);
        printArray(array, size);
        break;

    case 2:
        printf("Enter the number to be deleted\n");
        scanf("%d", &num);
        deleteRoot(array, num);
        printArray(array, size);
    default:
        break;
    }
}