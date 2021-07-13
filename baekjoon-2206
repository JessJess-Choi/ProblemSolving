#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
string g[1001];
int visit[1001][1001][2];
int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    queue<pair<pair<int, int>,int>> q;
    q.push({ { 0,0 },1 });
    visit[0][0][1] = 1;
    while (!q.empty()) {
        int pi = q.front().first.first;
        int pj = q.front().first.second;
        int block = q.front().second; q.pop();
        if (pi == n - 1 && pj == m - 1) {
            cout << visit[pi][pj][block];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int ni = pi + di[i];
            int nj = pj + dj[i];
            if (ni < n && nj < m && ni >= 0 && nj >= 0) {
                if (g[ni][nj]=='1' && block) {
                    visit[ni][nj][block - 1] = visit[pi][pj][block] + 1;
                    q.push({ {ni,nj},block - 1 });
                }
                if (g[ni][nj]=='0' && !visit[ni][nj][block]) {
                    visit[ni][nj][block] = visit[pi][pj][block] + 1;
                    q.push({ {ni,nj},block });
                }
            }
        }
    }
    cout << "-1";
    return 0;
}
