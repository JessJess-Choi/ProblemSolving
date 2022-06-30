#include<iostream>
#include<vector>

using namespace std;

vector<int> g[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, q, t, x; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t >> x;
        if (t == 1) {
            int cnt = 0;
            for (int tmp : g[x])
                cnt++;
            if (cnt >= 2)
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else if(t==2)
            cout << "yes\n";
    }
    return 0;
}
