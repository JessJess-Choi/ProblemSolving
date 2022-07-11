#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visit[32001];
vector<int> g[32001];
vector<int> ans;

void dfs(int i){
    visit[i] = true;
    for(int next : g[i])
        if(!visit[next])
            dfs(next);
    ans.push_back(i);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i=1;i<=N;i++)
        if(!visit[i])
            dfs(i);
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
    return 0;
}
