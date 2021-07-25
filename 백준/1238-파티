#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define P pair<int,int>

using namespace std;

const int INF = 1e9;
vector<P> g[1001];
int dist[1001][1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,x,ans=0;cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    fill(&dist[0][0],&dist[1000][1000],INF);
    for(int i=1;i<=n;i++){
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({i,0});
        dist[i][i] = 0;
        while(!pq.empty()){
            int e = pq.top().first;
            int w = pq.top().second;pq.pop();
            if(w > dist[i][e])continue;
            for(P edge : g[e]){
                int next = edge.first;
                int cost = edge.second;
                if(dist[i][next] > dist[i][e] + cost){
                    dist[i][next] = dist[i][e] + cost;
                    pq.push({next,dist[i][next]});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans = max(ans,dist[x][i]+dist[i][x]);
    }
    cout<<ans;
    return 0;
}
