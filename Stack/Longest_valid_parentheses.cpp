#include <bits/stdc++.h>
using namespace std;

int Longest_valid_parentheses (string s) {
    stack <int> st;
    int ans = 0;
    st.push (-1); //Cột mốc ranh giới ban đầu ngay trc chỉ số idx 0

    for (int i=0; i<s.length(); i++) {
       //1. Gặp ngoặc mở -> push i -> stack
       if (s[i] == '(') st.push (i);

       //2. Gặp ngoặc đóng
       else {
        st.pop();
        //2.1 Nếu stack còn phần tử ->tính độ dài từ st.top () đến i
        if (!st.empty ()) ans = max (ans, i-st.top ());
        //2.2 Nếu stack rỗng -> dấu ')' bị thừa, lấy i làm mốc mới
        else st.push (i);
       }
    }
    return ans;
} 

int main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << Longest_valid_parentheses (s) << "\n";
    }
    return 0;
}

// 