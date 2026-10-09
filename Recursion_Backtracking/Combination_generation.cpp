#include <bits/stdc++.h>
using namespace std;

int n, k, x[100];

void Print () {
    for (int i=0; i<k; i++) cout << x[i] << " ";
    cout << endl;
}

void Try (int i) {
    if (i==k) {
        Print ();
        return;
    }

    int start;
    if (i==0) start = 1;
    else start = x[i-1] + 1;

    for (int j=start; j<=n; j++) {
        x[i] = j;
        Try (i+1);
    }
}

int main () {
    cin >> n >> k;
    Try (0);
    return 0;
}
