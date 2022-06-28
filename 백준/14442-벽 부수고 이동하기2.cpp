#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m, k, visit[1001][1001][11], di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};
string g[1001];

int main() {
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   cin >> n >> m >> k;
   for(int i=0;i<n;i++)
      cin >> g[i];
   queue<pair<pair<int,int>,int>> q;
   q.push({{0,0},k});
   visit[0][0][k] = 1;
   while(!q.empty()){
      int x = q.front().first.first;
      int y = q.front().first.second;
      int block = q.front().second; q.pop();
      if(x == n-1 && y == m-1){
         cout<<visit[n-1][m-1][block];
         return 0;
      }
      for(int i=0;i<4;i++){
         int ni = x + di[i];
         int nj = y + dj[i];
         if(ni >= 0 && nj >= 0 && ni < n && nj < m){
            if(g[ni][nj] == '1' && block && !visit[ni][nj][block-1]){
               visit[ni][nj][block-1] = visit[x][y][block] + 1;
               q.push({{ni,nj},block-1});
            }
            if(g[ni][nj] == '0' && !visit[ni][nj][block]){
               visit[ni][nj][block] = visit[x][y][block] + 1;
               q.push({{ni,nj},block});
            }
         }
      }
   }
   cout<<"-1";
   return 0;
}
