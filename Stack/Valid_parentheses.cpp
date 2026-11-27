#include <bits/stdc++.h>
using namespace std;

bool check (string s) {
    if (s == "") return true;
    stack <char> st;
    for (int i=0; i<s.length(); i++) {
        //1. Gap ngoac mo -> push -> stack
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') st.push (s[i]);

        //2. Gap ngoac dong -> Kiem tra rong va doi chieu cac cap dau
        else {
            if (st.empty ()) return false;// st.empty -> k co ngoac mo nao,suy ra ngoac dong bi thua
            if (s[i] == ')' && st.top () == '(' || s[i] == ']' && st.top () == '[' || s[i] == '}' && st.top () == '{') st.pop ();
            else return false; // Sai loai ngoac (vd: "(]") 
        }
    }
    return true;
} 

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (check(s) == true) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
