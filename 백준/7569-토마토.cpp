#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, h;
int g[101][101][101];
int di[6] = { -1,1,0,0,0,0 };
int dj[6] = { 0,0,0,0,-1,1 };
int dk[6] = { 0,0,-1,1,0,0 };
int visit[101][101][101];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> h;
    int ans = -1;
    queue<pair<pair<int, int>,int>> q;
    
    for (int k = 0; k < h; k++) 
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++){
                cin >> g[i][j][k];
                visit[i][j][k] = -1;
                if (g[i][j][k] == 1) {
                    q.push(make_pair(make_pair(i, j),k));
                    visit[i][j][k] = 0;
                }
            }
            
        }
    while (!q.empty()) {
        int pi = q.front().first.first;
        int pj = q.front().first.second;
        int pk = q.front().second; q.pop();
        for (int i = 0; i < 6; i++) {
            int ni = pi + di[i];
            int nj = pj + dj[i];
            int nk = pk + dk[i];
            if (ni < m && nj < n && nk < h && ni >= 0 && nj >= 0 && nk>=0)
                if (visit[ni][nj][nk] == -1 && !g[ni][nj][nk]) {
                    q.push(make_pair(make_pair(ni, nj),nk));
                    visit[ni][nj][nk] = visit[pi][pj][pk] + 1;
                }
        }
    }
    for (int k = 0; k < h; k++)
        for (int j = 0; j < n; j++) 
            for (int i = 0; i < m; i++) {
                if (visit[i][j][k] == -1 && !g[i][j][k]) {
                    cout << "-1";
                    return 0;
                }
                ans = max(ans, visit[i][j][k]);
            }
    cout << ans;
    return 0;
}
