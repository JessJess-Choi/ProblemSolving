#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, cnt, di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};
bool visit[101][101];
vector<int> v;

int bfs(int x, int y){
    queue<pair<int,int>> q;
    int ret = 1;
    q.push({x,y});
    visit[x][y] = true;
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        int nx = p.first;
        int ny = p.second;
        for(int i=0;i<4;i++){
            int ni = nx + di[i];
            int nj = ny + dj[i];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m)
                if(!visit[ni][nj]){
                    visit[ni][nj] = true;
                    q.push({ni,nj});
                    ret++;
                }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1;i<x2;i++)
            for(int j=y1;j<y2;j++)
                visit[i][j] = true;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!visit[i][j]){
                v.push_back(bfs(i,j));
                cnt++;
            }
    sort(v.begin(),v.end());
    cout << cnt << "\n";
    for(int n : v)cout << n << " ";
    return 0;
}
