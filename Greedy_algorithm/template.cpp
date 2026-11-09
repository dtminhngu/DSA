#include <bits/stdc++.h>
using namespace std;

int N;
int a[] = {1,2,5,10,20,50,100,200,500,1000};

int Greedy () { // min f(x) sao cho x1+x2+...xn = N
    int cnt = 0;
    for (int i=9; i>=0; i--) {
        cnt += N/a[i];
        N%=a[i];
        if (N==0) break;
    }
    return cnt;
}

int  main () {
    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        int min_val = Greedy ();
        cout << min_val << "\n";
    }
    return 0;
}