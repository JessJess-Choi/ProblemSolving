#include<iostream>
#include<string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str1, str2, ans; cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++) {
        ans += str1[i];
        if (str1[i] == str2[str2.size() - 1]) {
            bool check = true;
            for (int j = 1; j <= str2.size(); j++)
                if (ans[ans.size() - j] != str2[str2.size()-j]) {
                    check = false;
                    break;
                }
            if (check)
                for (int j = 0; j < str2.size(); j++)
                    ans.pop_back();
        }
    }
    if (ans.size())
        cout << ans;
    else
        cout << "FRULA";
    return 0;
}
