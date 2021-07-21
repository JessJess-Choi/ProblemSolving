#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define P pair<int,int>

using namespace std;

const int INF = 1e9;
vector<P> g[20001];
int dist[20001];
priority_queue<P, vector<P>, greater<P>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, e, k; cin >> v >> e >> k;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ w,v });
    }
    fill(dist, dist + v + 1, INF);
    pq.push({ 0,k });
    dist[k] = 0;
    while (!pq.empty()) {
        P top = pq.top(); pq.pop();
        int n = top.second;
        int w = top.first;
        if (dist[n] < w)continue;
        for (P edge : g[n]) {
            int next = edge.second;
            int cost = edge.first;
            if (dist[next] > dist[n] + cost) {
                dist[next] = dist[n] + cost;
                pq.push({ dist[next],next });
            }
        }
    }
    for (int i = 1; i <= v; i++)
        if (dist[i] == INF)cout << "INF\n";
        else
            cout << dist[i] << '\n';
    return 0;
}
