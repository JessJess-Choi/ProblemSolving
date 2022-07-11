#include <iostream>
#include <string>
#define P pair<int,int>

using namespace std;

int N, M;
int par[100001];
long long dist[100001];

int find(int x){
    if(x == par[x])return x;
    int parent = find(par[x]);
    dist[x] += dist[par[x]];
    return par[x] = parent;
}

void unite(int x, int y, int w){
    int X = find(x);
    int Y = find(y);
    if(X == Y)return;
    dist[Y] = dist[x] - dist[y] + w;
    par[Y] = X;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0)break;
        for(int i=0;i<=N;i++)par[i] = i, dist[i] = 0;
        for(int i=0;i<M;i++){
            string str;
            int a, b, w; 
            cin >> str;
            if(str == "!"){
                cin >> a >> b >> w;
                unite(a, b, w);
            }
            else if(str == "?"){
                cin >> a >> b;
                if(find(a) != find(b))cout<<"UNKNOWN\n";
                else cout<<dist[b] - dist[a]<<"\n";
            }
        }
    }
    return 0;
}
