#include <iostream>
using namespace std;

void bucketSort(int arr[], int n) {

    int bucket[10] = {0};

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Put elements back into array
    int index = 0;

    for (int i = 0; i < 10; i++) {

        while (bucket[i] > 0) {
            arr[index] = i;
            index++;
            bucket[i]--;
        }
    }
}

int main() {

    int arr[] = {5, 2, 8, 3, 2, 1};
    int n = 6;

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
