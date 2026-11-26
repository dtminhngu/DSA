#include <bits/stdc++.h>
using namespace std;

string prefix_infix (string s) {
    stack <string> st; // Khai báo stack kiểu string để lưu lại các toán hạng và các cụm trung tố con tạo thành
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
            //Ghép thành cụm trung tố có bọc ngoặc và đẩy ngược lại vào stack
            string tmp = "(" + s1 + s[i] + s2 + ")";
            st.push (tmp);
        }
    }

    // 3. Sau khi duyệt xong, phần tử duy nhất ở đỉnh stack là kết 
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
        cout << prefix_infix (s) << "\n";
    }
    return 0;
}