#include <bits/stdc++.h>
using namespace std;

// (A+(B+C)

// Hàm xét mức độ ưu tiên giữa các toán tử
int priority (char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1; 
}

string TrungTo_HauTo (string s) {
    //1. Khai báo 
    stack <char> st;// stack dùng để lưu tạm các dấu ngoặc mở và các toán tử chưa đến lượt xuất 
    string out = "";// chuỗi lưu biểu thức hậu tố hoàn chỉnh

    //2. Chạy vòng lặp để xét từng kí tự s[i] của xâu s
    for (int i=0; i<s.length(); i++) {
        //2.1:Nếu s[i] = '(', push s[i] -> stack
        if (s[i] == '(') st.push (s[i]);

        //2.2:Nếu s[i] là toán hạng (số, chữ cái): ghép s[i] vào xâu out
        else if (isalnum (s[i])) out += s[i];

        //2.3:Nếu s[i] = ')'
        else if (s[i] == ')') {
            // Lấy các toán tử ở đỉnh ngăn xếp nối vào xâu out và xóa các toán tử đó khỏi stack cho đến khi chạm tới dấu '(' tương ứng
            while (!st.empty () && st.top () != '(') {
                out+=st.top ();
                st.pop ();
            }
            st.pop ();// xóa dấu '(' ra khỏi stack vì biểu thức hậu tố k dùng ngoặc
        }

        //2.4: Nếu s[i] là toán tử (dấu)
        else {
            //Đẩy các toán tử có độ ưu tiên >= s[i] từ đỉnh stack ra và nối vào xâu out
            while (!st.empty() && priority (s[i]) <= priority(st.top())) {
                // Nối st.top () vào xâu out và pop st.top () ra khỏi stack
                out += st.top ();
                st.pop ();
            }
            st.push (s[i]); //Nếu stack rỗng hoặc đỉnh stack là dấu mở  -> push s[i] -> stack
        }
    }

    //3. Xả hết các toán tử sót lại trong ngăn xếp và nối vào xâu out (trừ dấu '(')
    while (!st.empty()) {
        char c = st.top ();
        if (c != '(') out += c;
        st.pop ();
    }
    return out;
}

int main  () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << TrungTo_HauTo (s) << "\n";
    }
    return 0;
}
