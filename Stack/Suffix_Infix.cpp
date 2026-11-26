#include <bits/stdc++.h>
using namespace std;

string Suffix_Infix (string s) {
    stack <string> st;// Lưu các toán hạng và cụm biểu thức trung tố con
    for (int i=0; i<s.length(); i++) {
        //1. Gặp toán hạng -> ép sang string độ dài 1 và đẩy vào stack
        if (isalnum (s[i])) st.push (string(1,s[i]));

        // 2. Gặp toán tử -> rút 2 phần tử trên đỉnh (s2 bên phải trước, s1 bên trái sau), bọc ngoặc và đẩy lại vào stack
        else {
            string s2 = st.top ();
            st.pop ();
            string s1 = st.top ();
            st.pop ();
            string tmp = "(" + s1 + s[i] + s2 + ")";
            st.push (tmp);
        }
    }
    
    // 3. Phần tử duy nhất còn lại trên đỉnh stack là kết quả
    return st.top ();
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << Suffix_Infix (s) << "\n";
    }
    return 0;
}