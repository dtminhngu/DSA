#include <bits/stdc++.h>
using namespace std;

int n,k,x[100];
bool OK = true;

void Init() {
    cin >> n >> k;
    for (int i=1; i<=k; i++) x[i] = i;
}

void Res () {
    for (int i=1; i<=k; i++) cout << x[i] << " ";
    cout << endl;
}

void Next_Combination () {
    int i=k;
    while (i>0 && x[i] == n-k+i) i--;
    if (i>0) {
        x[i] = x[i] + 1;
        for (int j=i+1; j<=k; j++) x[j] = x[i] + j - i;
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
            Next_Combination ();
        }
    }
    return 0;
}