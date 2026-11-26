#include <bits/stdc++.h>
using namespace std;

string prefix_suffix (string s) {
    stack <string> st; // Khai báo stack kiểu string để lưu lại các toán hạng và các cụm hậu tố con tạo thành
    for (int i=s.length()-1; i>=0; i--) {
        //1. Nếu s[i] là toán hạng -> ép thành string và push vào stack
        // *string (size, char) -> Ép một kí tự char thành string hoặc tạo nhanh một chuỗi gồm nhiều kí tự giống nhau
        if (isalnum (s[i])) st.push (string (1, s[i])); 

        //2. Nếu s[i] là toán tử
        else {
            // Lấy hai toán hạng (hoặc cụm biểu thức) trên đỉnh stack ra
            string s1 = st.top ();
            st.pop();
            string s2 = st.top ();
            st.pop();
            //Ghép thành cụm hậu tố với toán tử ở cuối và đẩy ngược lại vào stack
            string tmp = s1 + s2 + s[i];
            st.push (tmp);
        }
    }

    // 3. Sau khi duyệt xong, phần tử duy nhất ở đỉnh stack là kết quả
    return st.top ();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << prefix_suffix (s) << "\n";
    }
    return 0;
}