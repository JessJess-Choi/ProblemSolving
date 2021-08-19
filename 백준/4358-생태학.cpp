#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    map<string, int>m;
    int cnt = 0;
    while (getline(cin, str)) {
        m[str] += 1;
        cnt++;
    }
    vector<pair<string, int>>v(m.begin(), m.end());
    sort(v.begin(), v.end());
    cout.precision(4);
    cout << fixed;
    for (auto a : v)
        cout << a.first << ' ' << (double)(a.second*100) / (double)cnt << '\n';
    return 0;
}
