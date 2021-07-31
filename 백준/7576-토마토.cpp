#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int g[1001][1001];
int visit[1001][1001];
int n, m;
int di[4] = { 1,-1,0,0 };
int dj[4] = { 0,0,1,-1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    int ans = -1;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            visit[i][j] = -1;
            if (g[i][j] == 1) {
                q.push(make_pair(i, j));
                visit[i][j] = 0;
            }
            
        }
    while (!q.empty()) {
        int pi = q.front().first;
        int pj = q.front().second; q.pop();
        for (int i = 0; i < 4; i++) {
            int ni = pi + di[i];
            int nj = pj + dj[i];
            if (ni < n && nj < m && ni >= 0 && nj >= 0)
                if (visit[ni][nj] == -1 && !g[ni][nj]) {
                    q.push(make_pair(ni, nj));
                    visit[ni][nj] = visit[pi][pj] + 1;
                }
        }
    }
    for(int i=0;i<n;i++)
        for (int j = 0; j < m; j++) {
            if (visit[i][j] == -1 && !g[i][j]) {
                cout << "-1";
                return 0;
            }
            ans = max(ans, visit[i][j]);
        }
    cout << ans;
    return 0;
}
