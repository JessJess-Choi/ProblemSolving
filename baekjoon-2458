#include<iostream>
#include<algorithm>

using namespace std;

int g[501][501], check[501], ans;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    fill(&g[0][0], &g[500][500], INF);
    for (int i = 1; i <= n; i++)g[i][i] = 0;
    while (m--) {
        int a, b; cin >> a >> b;
        g[a][b] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)continue;
            if (g[i][j] > 0 && g[i][j] < INF) {
                check[i]++;
                check[j]++;
                if (check[i] == n - 1)ans++;
                if (check[j] == n - 1)ans++;
            }
        }
    cout << ans;
    return 0;
}
