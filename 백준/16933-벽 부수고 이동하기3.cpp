#include <iostream>
#include <string>
#include <queue>
#define DAY 1
#define NIGHT 0

using namespace std;

int n, m, k, visit[1001][1001][11][2], di[4] = {0,0,1,-1}, dj[4] = {1,-1,0,0};
string g[1001];
struct s{
   int x,y,block;
   bool night;
};

int main() {
   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   cin >> n >> m >> k;
   for(int i=0;i<n;i++)
      cin >> g[i];
   queue<s> q;
   q.push({0,0,k,DAY});
   visit[0][0][k][DAY] = 1;
   while(!q.empty()){
      int x = q.front().x;
      int y = q.front().y;
      int block = q.front().block;
      int night = q.front().night; q.pop();
      if(x == n-1 && y == m-1){
         cout<<visit[n-1][m-1][block][night];
         return 0;
      }
      for(int i=0;i<4;i++){
         int ni = x + di[i];
         int nj = y + dj[i];
         if(ni >= 0 && nj >= 0 && ni < n && nj < m){
            if(night == DAY){
               if(g[ni][nj] == '1' && block && !visit[ni][nj][block-1][NIGHT]){
                  visit[ni][nj][block-1][NIGHT] = visit[x][y][block][night] + 1;
                  q.push({ni,nj,block-1,NIGHT});
               }
               if(g[ni][nj] == '0' && !visit[ni][nj][block][NIGHT]){
                  visit[ni][nj][block][NIGHT] = visit[x][y][block][night] + 1;
                  q.push({ni,nj,block,NIGHT});
               }
            }
            else if(night == NIGHT){
               if(g[ni][nj] == '1' && block >= 0 && !visit[x][y][block][DAY]){
                  visit[x][y][block][DAY] = visit[x][y][block][night] + 1;
                  q.push({x,y,block,DAY});
               }
               if(g[ni][nj] == '0' && !visit[ni][nj][block][DAY]){
                  visit[ni][nj][block][DAY] = visit[x][y][block][night] + 1;
                  q.push({ni,nj,block,DAY});
               }
            }
         }
      }
   }
   cout<<"-1";
   return 0;
}
