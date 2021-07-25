#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define P pair<int,int>

using namespace std;

const int INF = 1e8;
vector<P> g[810];
int dist1[810],dist2[810],dist3[810],ans,x,y,n,e;

void f(int *arr,int start){
    fill(arr,arr+n+1,INF);
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,start});
    arr[start] = 0;
    while(!pq.empty()){
        int n = pq.top().second;
        int w = pq.top().first;pq.pop();
        if(w > arr[n])continue;
        for(P edge : g[n]){
            int next = edge.first;
            int cost = edge.second;
            if(arr[next] > arr[n] + cost){
                arr[next] = arr[n] + cost;
                pq.push({arr[next],next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    cin>>x>>y;
    f(dist1,1);
    f(dist2,x);
    f(dist3,y);
    ans = min(dist1[x]+dist2[y]+dist3[n],dist1[y]+dist2[n]+dist3[x]);
    if(ans>=INF || ans<0)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
