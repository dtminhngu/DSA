#include <bits/stdc++.h>
using namespace std;

int n, x[100];
bool OK = true;

void Initialization () { // X = {x1,x2,...,xn} = {0,0,0,0}
    cin >> n;
    for (int i=1; i<=n; i++)  x[i] = 0;
}

void Result () { // X = {x1,x2,..xn}
    for (int i=1; i<=n; i++) cout << x[i] << " ";
}

void Next_bits_string () {
    int i=n;
    while (i>0 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if (i>0) x[i] = 1;
    else OK = false;
}


int main () {
    Initialization (); //initialize first configuration
    while (OK) { //run a loop -> generate remaining configuration
        Result ();
        Next_bits_string ();
        cout << endl;
    }
    return 0;
}
