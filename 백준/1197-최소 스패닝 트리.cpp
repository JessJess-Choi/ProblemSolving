#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int par[10001], rnk[10001];

struct edge {
    int u, v, w;
};

int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    if (rnk[x] > rnk[y])swap(x, y);
    par[x] = y;
    if (rnk[x] == rnk[y])rnk[y]++;
}

bool compare(edge a,edge b) {
    return a.w < b.w;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int v, e; cin >> v >> e;
    long long weight = 0LL;
    vector<edge> vec;
    for(int i=0;i<e;i++) {
        int a, b, c; cin >> a >> b >> c;
        vec.push_back({ a,b,c });
    }
    sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < v; i++)par[i] = i, rnk[i] = 1;
    for(int i=0;i<e;i++)
        if (find(vec[i].v) != find(vec[i].u)) {
            unite(vec[i].v, vec[i].u);
            weight += vec[i].w;
        }
    cout << weight;
    return 0;
}
