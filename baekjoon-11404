#include<iostream>
#include<algorithm>

using namespace std;

int g[101][101];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(&g[0][0], &g[100][100], INF);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)g[i][i] = 0;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (g[i][j] == INF)cout << "0 ";
            else
                cout << g[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
