#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define P pair<int,int>

using namespace std;

const int INF = 1e8;
vector<P> graph[2001];
int n,m,t,s,g,h;
int dist1[2001],dist2[2001],dist3[2001];

void f(int *arr,int start){
    fill(arr,arr+n+1,INF);
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,start});
    arr[start] = 0;
    while(!pq.empty()){
        int n = pq.top().second;
        int w = pq.top().first;pq.pop();
        if(w > arr[n])continue;
        for(P edge : graph[n]){
            int next = edge.first;
            int cost = edge.second;
            if(arr[next] > w + cost){
                arr[next] = w + cost;
                pq.push({arr[next],next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;cin>>T;
    while(T--){
        vector<int> v;
        vector<int> v2;
        memset(graph,0,sizeof(graph));
        cin>>n>>m>>t;
        cin>>s>>g>>h;
        while(m--){
            int a,b,d;cin>>a>>b>>d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
        }
        while(t--){
            int x;cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        f(dist1,s);
        f(dist2,g);
        f(dist3,h);
        for(int i=1;i<=n;i++){
            if(dist1[i]==dist1[g]+dist2[h]+dist3[i] || dist1[i]==dist1[h]+dist3[g]+dist2[i])
                v2.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v[i] == v2[j])
                    cout<<v[i]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}
