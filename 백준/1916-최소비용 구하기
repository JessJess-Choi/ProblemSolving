#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define P pair<int,int>

using namespace std;

const int INF = 1e8;
vector<P> g[1001];
int dist[1001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n>>m;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({c,b});
    }
    int start,end;cin>>start>>end;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,start});
    fill(dist,dist+n+1,INF);
    dist[start] = 0;
    while(!pq.empty()){
        int n = pq.top().second;
        int w = pq.top().first;pq.pop();
        if(w > dist[n])continue;
        for(P edge : g[n]){
            int next = edge.second;
            int cost = edge.first;
            if(dist[next] > dist[n] + cost){
                dist[next] = dist[n] + cost;
                pq.push({dist[next],next});
            }
        }
    }
    cout<<dist[end];
    return 0;
}
