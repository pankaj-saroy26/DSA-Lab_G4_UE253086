#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int kthSmallest(int arr[], int low, int high, int k) {
    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k - 1) {
        return arr[pivotIndex];
    }

    if (pivotIndex > k - 1) {
        return kthSmallest(arr, low, pivotIndex - 1, k);
    }

    return kthSmallest(arr, pivotIndex + 1, high, k);
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k;

    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid value of k";
        return 0;
    }

    cout << k << "th smallest element: "
         << kthSmallest(arr, 0, n - 1, k);

    return 0;
}
