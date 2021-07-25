#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> g[20001];
int visit[20001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    queue<int> q;
    int distance = -1;
    vector<int> v;
    cin >> n >> m;
    while (m--) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        g[tmp1].push_back(tmp2);
        g[tmp2].push_back(tmp1);
    }
    visit[1] = 1;
    for (int next : g[1]) {
        if (!visit[next]) {
            q.push(next);
            visit[next] = 2;
        }
    }
    while (!q.empty()) {
        int vertex = q.front(); q.pop();
        for(int next : g[vertex])
            if (!visit[next]) {
                visit[next] = visit[vertex] + 1;
                q.push(next);
            }
    }
    for (int i = 1; i <= n; i++)distance = max(distance, visit[i]);
    for (int i = 1; i <= n; i++)if (distance == visit[i])v.push_back(i);
    sort(v.begin(), v.end());
    cout << v[0] << ' ' << distance - 1 << ' ' << v.size();
    return 0;
}
