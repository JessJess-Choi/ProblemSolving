#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define P pair<int,int>

using namespace std;

int N, ans = 1e9, high, low, height[51][51], cnt, Pi, Pj, di[8] = {0,0,1,-1,1,1,-1,-1}, dj[8] = {1,-1,0,0,1,-1,1,-1};
string g[51];
bool visit[51][51];
vector<int> v;

bool bfs(){
    int kCnt = 0;
    queue<P> q;
    q.push({Pi, Pj});
    visit[Pi][Pj] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second; q.pop();
        if(g[x][y] == 'K')kCnt++;
        if(kCnt == cnt)return false;
        for(int i=0;i<8;i++){
            int nx = x + di[i];
            int ny = y + dj[i];
            if(nx >= 0 && ny >= 0 && nx < N && ny < N)
                if(!visit[nx][ny] && height[nx][ny] >= v[low] && height[nx][ny] <= v[high]){
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> g[i];
        for(int j=0;j<N;j++)
            if(g[i][j] == 'K')cnt++;
            else if(g[i][j] == 'P'){
                Pi = i;
                Pj = j;
            }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> height[i][j];
            v.push_back(height[i][j]);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    while(high < v.size()){
        while(true){
            bool check = true;
            if(v[low] <= height[Pi][Pj] && height[Pi][Pj] <= v[high]){
                check = bfs();
                fill(&visit[0][0],&visit[50][51],false);
            }
            if(check)break;
            ans = min(ans, v[high] - v[low]);
            low++;
        }
        high++;
    }
    cout<<ans;
    return 0;
}
