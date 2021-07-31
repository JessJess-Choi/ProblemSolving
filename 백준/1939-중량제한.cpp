#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define P pair<int,int>
using namespace std;
int n,m,low,high,Start,End;
vector<P> g[100001];
bool visit[100001];

bool bfs(int mid){
    visit[Start] = true;
    queue<int> q;
    q.push(Start);
    while(!q.empty()){
        int now = q.front();q.pop();
        if(now == End)return true;
        for(auto a : g[now]){
            int next = a.first;
            int cost = a.second;
            if(!visit[next] && mid <= cost){
                visit[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        high = max(high,c);
    }
    cin>>Start>>End;
    while(low <= high){
        int mid = (low + high) / 2;
        memset(visit,0,sizeof(visit));
        if(bfs(mid))low = mid + 1;
        else
            high = mid - 1;
    }
    cout<<high;
    return 0;
}
