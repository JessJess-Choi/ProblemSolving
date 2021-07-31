#include<iostream>

using namespace std;

int par[500001],ans;
int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return false;
    par[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)par[i] = i;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(find(a) == find(b)){
            ans = i+1;
            break;
        }
        unite(a,b);
    }
    cout<<ans;
    return 0;
}
