#include<iostream>
#include<cstring>

using namespace std;

int g[51][51];
int visit[51][51];
int di[8] = { 0,1,0,-1,-1,-1,1,1 };
int dj[8] = { 1,0,-1,0,-1,1,-1,1 };
int w, h;

void dfs(int pi,int pj) {
    visit[pi][pj] = 1;
    for (int i = 0; i < 8; i++) {
        int ni = pi + di[i];
        int nj = pj + dj[i];
        if (ni < h && nj < w && ni >= 0 && nj >= 0)
            if (!visit[ni][nj] && g[ni][nj])
                dfs(ni, nj);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        memset(g, 0, sizeof(g));
        memset(visit, 0, sizeof(visit));
        cin >> w >> h;
        if (!w && !h)break;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> g[i][j];
        int cnt = 0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if (!visit[i][j] && g[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
        cout << cnt << '\n';
    }
    return 0;
}
