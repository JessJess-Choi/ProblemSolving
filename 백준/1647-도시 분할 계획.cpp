#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int par[100001];

int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    par[y] = x;
}

struct edge{
    int u,v,w;
};

bool compare(edge a,edge b){
    return a.w < b.w;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n>>m;
    long long weight=0LL;
    vector<edge> v;
    int cnt = 0;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++)par[i] = i;
    for(int i=0;i<m;i++){
        if(find(v[i].v) != find(v[i].u)){
            unite(v[i].u,v[i].v);
            weight += v[i].w;
            cnt++;
            if(cnt == n-2)break;
        }
    }
    cout<<weight;
    return 0;
}
