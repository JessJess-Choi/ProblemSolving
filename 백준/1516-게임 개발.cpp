#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, arr[501], ans[501];
vector<int> g[501], v;
bool visit[501];

void dfs(int i){
    visit[i] = true;
    for(int next : g[i])
        if(!visit[next])
            dfs(next);
    v.push_back(i);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
        for(int j=1;j<=N;j++){
            int a; cin >> a;
            if(a == -1)break;
            g[a].push_back(i);
        }
    }
    for(int i=1;i<=N;i++)
        if(!visit[i])
            dfs(i);
    reverse(v.begin(),v.end());
    for(int n : v){
        ans[n] += arr[n];
        for(int next : g[n])
            ans[next] = max(ans[next], ans[n]);
    }
    for(int i=1;i<=N;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
