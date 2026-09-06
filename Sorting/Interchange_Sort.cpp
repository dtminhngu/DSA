#include <bits/stdc++.h>
using namespace std;

void Interchange_Sort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) swap (arr[i], arr[j]);
        }
        cout << "Buoc " << i+1  << ": ";
        for (int k=0; k<n; k++) cout << arr[k] << " ";
        cout << endl; 
    }
}

int main () {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    Interchange_Sort (arr, n);
    return 0;
}