#include <vector>
#include<cstdlib>
#define ll long long
using namespace std;
vector<ll> g[300001];
ll answer;
void dfs(vector<ll>& v,int now,int parent){
    for(int i=0;i<g[now].size();i++)
        if(g[now][i] != parent)
            dfs(v,g[now][i],now);
    v[parent] += v[now];
    answer += abs(v[now]);
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    for(int i=0;i<edges.size();i++){
        g[edges[i][0]].push_back(edges[i][1]);
        g[edges[i][1]].push_back(edges[i][0]);
    }
    vector<ll> a1;
    for(auto it : a)a1.push_back((ll)it);
    dfs(a1,0,0);
    if(a1[0])return -1;
    return answer;
}
