#include <vector>
#include <queue>

using namespace std;

int visit[101][101], di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    int n = maps.size(), m = maps[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = 1;
    while(!q.empty()){
        auto a = q.front(); q.pop();
        int x = a.first;
        int y = a.second;
        for(int i=0;i<4;i++){
            int nx = x + di[i];
            int ny = y + dj[i];
            if(nx >= 0 && ny >=0 && nx < n && ny < m)
                if(!visit[nx][ny] && maps[nx][ny]){
                    q.push({nx,ny});
                    visit[nx][ny] = visit[x][y] + 1;
                }
        }
    }
    return visit[n - 1][m - 1] ? visit[n - 1][m - 1] : -1;
}
