#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int g[101][101];
int visit[101][101];
int n;
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };


void dfs(int pi, int pj, int h) {
    visit[pi][pj] = 1;
    for (int i = 0; i < 4; i++) {
        int ni = pi + di[i];
        int nj = pj + dj[i];
        if (ni < n && nj < n && ni >= 0 && nj >= 0)
            if (!visit[ni][nj] && g[ni][nj] > h)
                dfs(ni, nj, h);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int maxN = -2123456789, minN = 2123456789, answer = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            maxN = max(maxN, g[i][j]);
            minN = min(minN, g[i][j]);
        }
    for (int i = 1; i < maxN; i++) {
        int cnt = 0;
        memset(visit, 0, sizeof(visit));
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (g[j][k] > i && !visit[j][k]) {
                    cnt++;
                    dfs(j, k, i);
                }
        answer = max(answer, cnt);
    }
    cout << answer;
    return 0;
}
