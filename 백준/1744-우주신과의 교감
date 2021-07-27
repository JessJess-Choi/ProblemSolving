#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int par[1001];

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
    int u,v;
    double w;
};

bool compare(edge a,edge b){
    return a.w < b.w;
}

double distance(int x1,int y1,int x2,int y2){
    double x = pow(double(x1-x2),2);
    double y = pow(double(y1-y2),2);
    double dist =  sqrt(x+y);
    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n>>m;
    double ans = 0.0;
    vector<edge> v;
    vector<pair<int,int>> tmp;
    cout.precision(2);
    cout<<fixed;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        tmp.push_back({x,y});
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double dist = distance(tmp[i].first,tmp[i].second,tmp[j].first,tmp[j].second);
            v.push_back({i+1,j+1,dist});
        }
    }
    for(int i=0;i<=n;i++)par[i] = i;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(find(a) != find(b))
            unite(a,b);
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        if(find(v[i].u) != find(v[i].v)){
            unite(v[i].u,v[i].v);
            ans+=v[i].w;
        }
    }
    cout<<ans;
    return 0;
}
