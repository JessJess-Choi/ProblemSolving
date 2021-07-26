#include<iostream>
#include<cstring>

using namespace std;

int par[10001];

int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    par[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;cin>>T;
    while(T--){
        int ans = 0;
        int n,m;cin>>n>>m;
        memset(par,0,sizeof(par));
        for(int i=0;i<n;i++)par[i] = i;
        while(m--){
            int a,b;cin>>a>>b;
            if(find(a) != find(b)){
                ans++;
                unite(a,b);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
