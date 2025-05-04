#include<iostream>
using namespace std;

void maxheapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void maxheapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        maxheapify(arr, i, 0);
    }
}

void minheapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void minheapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minheapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        minheapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array: ";
    printArray(arr1, n);

    maxheapsort(arr1, n); 
    cout << "Array after Max Heap Sort (Ascending): ";
    printArray(arr1, n);

    minheapsort(arr2, n); 
    cout << "Array after Min Heap Sort (Descending): ";
    printArray(arr2, n);

    return 0;
}


// Original array: 12 11 13 5 6 7 
// Array after Max Heap Sort (Ascending): 5 6 7 11 12 13 
// Array after Min Heap Sort (Descending): 13 12 11 7 6 5 