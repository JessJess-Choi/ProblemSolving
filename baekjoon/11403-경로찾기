#include<iostream>
#include<algorithm>

using namespace std;

int g[101][101];
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    fill(&g[0][0], &g[100][100], INF);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0)g[i][j] = INF;
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (g[i][j] == INF)
                cout << "0 ";
            else
                cout << "1 ";
        cout << '\n';
    }
    return 0;
}
