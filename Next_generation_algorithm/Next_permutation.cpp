#include <bits/stdc++.h>
using namespace std;

int n, x[100];
bool OK = true;

void Init () { 
    cin >> n;
    for (int i=0; i<n; i++) x[i] = i+1;
    OK = true;
}

void Res () {
    for (int i=0; i<n; i++) cout << x[i];
    cout << " ";
}

void Next_Permutation () {
    int i = n-2;
    while (i>=0 && x[i] >= x[i+1]) i--;
    if (i>=0) {
        int k=n-1;
        while (x[k] <= x[i]) k--;
        swap (x[i], x[k]);
        reverse (x+i+1, x+n);
    }
    else OK = false;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        Init ();
        while (OK) {
            Res ();
            Next_Permutation ();
        }
        cout << endl;
    }
    return 0;
}