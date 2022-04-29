#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int ans = 1e9, k, w, h, g[201][201], visit[201][201][31], di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0}, hi[8] = {2,2,-2,-2,1,1,-1,-1}, hj[8] = {1,-1,1,-1,2,-2,2,-2};

struct s{
    int x,y,k;
};

void bfs(){
    queue<s> q;
    q.push({0,0,0});
    visit[0][0][0] = 0;
    while(!q.empty()){
        s now = q.front(); q.pop();
        if(now.k < k){
            for(int i=0;i<8;i++){
                int ni = now.x + hi[i];
                int nj = now.y + hj[i];
                if(ni >= 0 && nj >= 0 && ni < h && nj < w)
                    if(!g[ni][nj] && visit[ni][nj][now.k+1] > visit[now.x][now.y][now.k] + 1){
                        q.push({ni,nj,now.k+1});
                        visit[ni][nj][now.k+1] = visit[now.x][now.y][now.k] + 1;
                    }
            }
        }
        for(int i=0;i<4;i++){
            int ni = now.x + di[i];
            int nj = now.y + dj[i];
            if(ni >= 0 && nj >= 0 && ni < h && nj < w)
                if(!g[ni][nj] && visit[ni][nj][now.k] > visit[now.x][now.y][now.k] + 1){
                    q.push({ni,nj,now.k});
                    visit[ni][nj][now.k] = visit[now.x][now.y][now.k] + 1;
                }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> w >> h;
    fill(&visit[0][0][0],&visit[200][200][31],1e9);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin >> g[i][j];
    bfs();
    for(int i=0;i<=k;i++)ans = min(ans, visit[h-1][w-1][i]);

    if(ans != 1e9)cout << ans;
    else
        cout << -1;
    return 0;
}
