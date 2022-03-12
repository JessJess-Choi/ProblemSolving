#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[101][101];
int cnt;

void bfs(int x, int y, vector<vector<int>>& picture, int m, int n){
    queue<pair<int,int>> q;
    int di[4] = {0, 0, 1, -1}, dj[4] = {1, -1, 0, 0};
    q.push({x,y});
    visit[x][y] = true;
    int check = 0;
    while(!q.empty()){
        check++;
        int nx = q.front().first;
        int ny = q.front().second; q.pop();
        for(int i=0;i<4;i++){
            int ni = nx + di[i];
            int nj = ny + dj[i];
            if(ni >= 0 && nj >= 0 && ni < m && nj < n)
                if(!visit[ni][nj] && picture[ni][nj] == picture[nx][ny]){
                    visit[ni][nj] = true;
                    q.push({ni,nj});
                }
        }
    }
    cnt = max(cnt, check);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> ans;
    fill(&visit[0][0], &visit[100][101], false);
    cnt = 0;
    int number = 0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(picture[i][j] && !visit[i][j]){
                number++;
                bfs(i,j,picture,m,n);
            }
    ans.push_back(number);
    ans.push_back(cnt);
    return ans;
}
