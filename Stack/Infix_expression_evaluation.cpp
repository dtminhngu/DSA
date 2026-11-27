#include <bits/stdc++.h>
using namespace std;

//Ham xet muc do uu tien giua cac toan tu
int priority (char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if  (c == '^') return 3;
    return -1;//Neu c la dau '('
}

//Ham thuc hien phep tinh giua 2 so a va b
long long calc (long long a, long long b, char operation) {
    if (operation == '+') return a+b;
    else if (operation == '-') return a-b;
    else if (operation == '*') return a*b;
    else if (operation == '%') return a%b;
    else return a/b;
}

//Ham rut 1 toan tu tu ops va 2 toan hang tu vals de tinh 
void process (stack <long long> &vals, stack <char> &ops)  {
    long long s2 = vals.top ();
    vals.pop ();
    long long s1 = vals.top ();
    vals.pop ();
    char c = ops.top ();
    ops.pop ();
    // Dung ham calc de tinh ket qua giua s1 va s2 sau do push lai vao vals
    vals.push (calc (s1, s2, c));
}

long long evaluate (string s) {
    stack <long long> vals; //Ngan xep luu cac so (toan hang)
    stack <char> ops; //Ngan xep luu cac toan tu (+,-,*,/) va dau '('

    for (int i=0; i<s.length(); i++) {
        //1.Neu s[i] la dau '(', push s[i] -> ops
        if (s[i] == '(') ops.push (s[i]);

        //2.Neu s[i] la chu so
        else if (isdigit (s[i])) {
            long long num = 0;
            //Dung vong lap de doc so co nhieu chu so roi push -> vals
            while (i<s.length() && isdigit (s[i]))  {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;//Lui lai 1 buoc vi vong lap for ben ngoai se tu tang i++
            vals.push (num);
        }

        //3.Neu s[i] la dau ')'
        else if (s[i] == ')') {
            while (!ops.empty () && ops.top () != '(') process (vals, ops);
            if (!ops.empty()) ops.pop ();//Xoa dau '(' con sot lai
        }

        //4. Neu s[i] la toan tu -> Tinh truoc cac phep toan o dinh co priority >= s[i]
        else {
            while (!ops.empty () && priority (ops.top ()) >= priority (s[i])) process (vals, ops);
            ops.push (s[i]); //Nếu stack rỗng hoặc đỉnh stack là dấu mở -> push s[i] -> ops
        }
    }
    // 5.Tinh not cac phep toan con sot lai trong stack
    while (!ops.empty()) process (vals, ops);
    return vals.top ();
}

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << evaluate (s) << "\n";
    }
    return 0;
}