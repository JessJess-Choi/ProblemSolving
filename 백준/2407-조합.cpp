#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string dp[101][101];
int n, m;
string Add(string a, string b) {
    string str = "";
    int sum = 0;
    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.erase(a.end()-1,a.end());
        }
        if (!b.empty()) {
            sum += b.back() - '0';
            b.erase(b.end()-1,b.end());
        }
        str += to_string(sum % 10);
        sum /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}
string combination(int a, int b) {
    if (a == b || b == 0)return "1";
    if (dp[a][b].size())return dp[a][b];
    return dp[a][b] = Add(combination(a - 1, b), combination(a - 1, b - 1));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cout << combination(n, m);
    return 0;
}
