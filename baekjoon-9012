#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string str; cin >> str;
        stack<char> st;
        bool check = true;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(')st.push(str[i]);
            else if (str[i] == ')')
                if (st.empty()) {
                    cout << "NO\n";
                    check = false;
                    break;
                }
                else
                    st.pop();
        }
        if (!st.empty())cout << "NO\n";
        else if(check)
            cout << "YES\n";
    }
    return 0;
}
