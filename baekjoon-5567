#include<iostream>
#include<queue>

using namespace std;

int g[501][501];
int visit[501];
int m, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        g[tmp1][tmp2] = g[tmp2][tmp1] = 1;
    }
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    int cnt = 0;
    for(int i=1;i<=n;i++)
        if (g[1][i] && !visit[i]) {
            q.push(i);
            cnt++;
            visit[i] = 1;
        }
    while (!q.empty()) {
        int vertex = q.front(); q.pop();
        for(int i=1;i<=n;i++)
            if (!visit[i] && g[vertex][i]) {
                visit[i] = 1;
                cnt++;
            }
    }
    cout << cnt;
    return 0;
}
