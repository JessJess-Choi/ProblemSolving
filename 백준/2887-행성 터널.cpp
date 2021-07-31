#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define P pair<int,int>
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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;cin>>n;
    long long ans = 0LL;
    vector<P> X,Y,Z;
    vector<pair<int,P>> v;
    for(int i=0;i<n;i++){
        int x,y,z;cin>>x>>y>>z;
        X.push_back({x,i});
        Y.push_back({y,i});
        Z.push_back({z,i});
    }
    for(int i=0;i<100001;i++)par[i] = i;
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());
    for(int i=0;i<n-1;i++){
        v.push_back(make_pair(X[i+1].first-X[i].first,make_pair(X[i].second,X[i+1].second)));
        v.push_back(make_pair(Y[i+1].first-Y[i].first,make_pair(Y[i].second,Y[i+1].second)));
        v.push_back(make_pair(Z[i+1].first-Z[i].first,make_pair(Z[i].second,Z[i+1].second)));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;
        int w = v[i].first;
        if(find(n1) != find(n2)){
            unite(n1,n2);
            ans += w;
        }
    }
    cout<<ans;
    return 0;
}
