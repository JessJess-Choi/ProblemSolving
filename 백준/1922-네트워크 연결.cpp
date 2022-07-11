#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int u,v,w;
};

vector<edge> v;
int N, M, par[1000001];
long long ans;

bool cmp(edge a, edge b){
    return a.w < b.w;
}

int find(int x){
    if(x == par[x])return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    par[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<=N;i++)par[i] = i;
    for(int i=0;i<M;i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),cmp);
    for(edge e : v){
        if(find(e.u) != find(e.v)){
            unite(e.u, e.v);
            ans += e.w;
        }
    }
    cout<<ans;
    return 0;
}
