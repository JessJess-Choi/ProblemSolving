#include <iostream>
#include <queue>
#define P pair<int,int>

using namespace std;

int g[301][301], N, M, year, di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};
bool visit[301][301];

bool checkAllZero(){
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(g[i][j])
                return false;
    return true;
}

void bfs(int x, int y){
    queue<P> q;
    q.push({x, y});
    visit[x][y] = true;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second; q.pop();
        for(int i=0;i<4;i++){
            int ni = nx + di[i];
            int nj = ny + dj[i];
            if(ni >= 0 && nj >= 0 && ni < N && nj < M){
                if(g[x][y] && g[ni][nj] && !visit[ni][nj]){
                    visit[ni][nj] = true;
                    q.push({ni, nj});
                }
                else if(!g[x][y] && !g[ni][nj] && !visit[ni][nj]){
                    visit[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }
}

void melt(){
    int m[301][301];
    fill(&m[0][0],&m[300][301],0);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            int cnt = 0;
            for(int k=0;k<4;k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 && nj >= 0 && ni < N && nj < M && !g[ni][nj])
                    cnt++;
            }
            m[i][j] = cnt;
        }
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(g[i][j] >= m[i][j])g[i][j] -= m[i][j];
            else if(m[i][j])
                g[i][j] = 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> g[i][j];
    while(true){
        if(checkAllZero()){
            cout<<0;
            break;
        }
        fill(&visit[0][0], &visit[300][301], false);
        int cnt = 0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                if(cnt == 2){
                    cout<<year;
                    return 0;
                }
                if(g[i][j] && !visit[i][j]){
                    bfs(i,j);
                    cnt++;
                }
                else if(!g[i][j] && !visit[i][j])
                    bfs(i,j);
            }
        melt();
        year++;
    }
    return 0;
}
