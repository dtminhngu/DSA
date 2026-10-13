#include <bits/stdc++.h>
using namespace std;

void Row (int arr[], int &n) { //recursion
    if (n==0) return;
    else {
        cout << "[";
        for (int i=0; i<n-1; i++) cout << arr[i] << " ";
        cout << arr[n-1] << "]" << "\n";
        for (int i=0; i<n-1; i++) arr[i] = arr[i] + arr[i+1];
        n--;
        Row (arr,n);
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        //1. Input
        int n;
        cin >> n;
        int arr[n];
        for (int i=0; i<n; i++) cin >> arr[i];
        //2. Process 
        Row (arr, n);
    }
    return 0;
}