#include <bits/stdc++.h>
using namespace std;

void SelectionSort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int min_index = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min_index]) min_index = j;
        }
        if (min_index != i) swap (arr[min_index], arr[i]);
    }
}

void Printing (int arr[], int n) {
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];
        SelectionSort (arr,n);
        Printing (arr,n);
    }
    return 0;
}