#include <bits/stdc++.h>
using namespace std;

int n, x[100];
bool visited [100] = {false};

void Print () {
    for (int i=0; i<n; i++) cout << x[i] << " ";
    cout << endl;
}
//n=3
void Try (int i) {
    if (i==n) {
        Print ();
        return;
    }
    for (int j=1; j<=n; j++) {
        if (!visited[j]) {
            x[i] = j;
            visited[j] = true;
            Try (i+1);
            visited[j] = false;
        }
    }
}

int main () {
    cin >> n;
    Try (0);
    return 0;
}
