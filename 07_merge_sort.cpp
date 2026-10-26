#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {

    int temp[100];

    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {

        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {

    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}