#include<iostream>

using namespace std;

int par[1000001], rnk[1000001];

int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    if (rnk[x] > rnk[y])swap(x, y);
    par[x] = y;
    if (rnk[x] == rnk[y])rnk[y]++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)par[i] = i, rnk[i] = 1;
    while (m--) {
        int a, b, A; cin >> A >> a >> b;
        if (A == 1)
            if (find(a) == find(b))cout << "YES\n";
            else
                cout << "NO\n";
        else
            unite(a, b);
    }
    return 0;
}
