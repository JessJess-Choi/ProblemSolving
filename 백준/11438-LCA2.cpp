#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MN = 100101;
vector<int> g[MN];
int h[MN], dp[20][MN];

void dfs(int n, int prev) {
    for (int next : g[n]) {
        if (next == prev)continue;
        h[next] = h[n] + 1;
        dp[0][next] = n;
        dfs(next, n);
    }
}

int LCA(int a, int b) {
    if (h[a] < h[b]) swap(a, b);
    int gap = h[a] - h[b];
    for (int i = 0; i < 20 ; i++)
        if (gap & (1 << i))
            a = dp[i][a];
    if (a == b)return a;
    for (int i = 19; i >= 0; i--)
        if (dp[i][a] != dp[i][b])
            a = dp[i][a], b = dp[i][b];
    return dp[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i < 20; i++) 
        for (int j = 1; j <= n; j++) 
            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    int m; cin >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
    return 0;
}
