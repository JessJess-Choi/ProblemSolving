#include <string>
#include <vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>

using namespace std;

vector<int> v;
vector<vector<int>> Board;
set<int> s;
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
bool visit[4][4];
int R,C;

int bfs(int dest){
    queue<pair<pair<int,int>,int>> q;
    memset(visit,0,sizeof(visit));
    q.push({{R,C},0});
    visit[R][C] = true;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;q.pop();
        if(Board[x][y] == dest){
            Board[x][y] = 0;
            R = x;
            C = y;
            return cnt+1;
        }
        for(int i=0;i<4;i++){
            int ni = x + di[i];
            int nj = y + dj[i];
            if(ni>=0 && nj>=0 && ni<4 && nj<4)
                if(!visit[ni][nj]){
                    visit[ni][nj] = true;
                    q.push({{ni,nj},cnt+1});
                }
        }
        for(int i=0;i<4;i++){
            int ni=x,nj=y;
            while(ni+di[i]>=0 && nj+dj[i]>=0 && ni+di[i]<4 && nj+dj[i]<4){
                ni += di[i];
                nj += dj[i];
                if(Board[ni][nj])break;
            }
            if(!visit[ni][nj]){
                    visit[ni][nj] = true;
                    q.push({{ni,nj},cnt+1});
                }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 1e9;
    for(auto a : board)
        for(auto b : a)
            if(b)s.insert(b);
    for(auto a : s)v.push_back(a);
    do{
        Board = board;
        R = r;
        C = c;
        int tmp = 0;
        for(auto a : v){
            tmp += bfs(a);
            tmp += bfs(a);
        }
        answer = min(answer,tmp);
    }while(next_permutation(v.begin(),v.end()));
    return answer;
}
