#include <iostream>
using namespace std;

// This simple bin sort works with non-negative integers from 0 to 99.
void binSort(int arr[], int n) {
    int bins[100] = {0};

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 || arr[i] > 99) {
            cout << "Values must be between 0 and 99." << endl;
            return;
        }

        bins[arr[i]]++;
    }

    int index = 0;

    for (int i = 0; i < 100; i++) {
        while (bins[i] > 0) {
            arr[index] = i;
            index++;
            bins[i]--;
        }
    }
}

int main() {
    int arr[] = {42, 7, 19, 7, 3, 90, 12};
    int n = 7;

    binSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
