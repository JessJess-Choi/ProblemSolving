#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define INF 2000000000

using namespace std;

int n, m, start, last, dist[1001], visit[1001];
vector<P> g[1001];
vector<int> visitCity;
priority_queue<P,vector<P>,greater<P>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        g[u].push_back({w,v});
    }
    cin >> start >> last;
    fill(dist,dist + 1001, INF);
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        P now = pq.top(); pq.pop();
        int u = now.second;
        int w = now.first;
        if(dist[u] < w)continue;
        for(P edge : g[u]){
            int next = edge.second;
            int weight = edge.first;
            if(dist[next] > dist[u] + weight){
                dist[next] = dist[u] + weight;
                pq.push({dist[next],next});
                visit[next] = u;
            }
        }
    }
    cout<<dist[last]<<"\n";
    int tmp = last;
    while(tmp){
        visitCity.push_back(tmp);
        tmp = visit[tmp];
    }
    reverse(visitCity.begin(),visitCity.end());
    cout<<visitCity.size()<<"\n";
    for(int n : visitCity)cout<<n<<" ";
    return 0;
}
