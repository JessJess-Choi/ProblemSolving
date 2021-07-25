#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int visit[301][301];
int n, m;
int di[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dj[8] = { 2,-2,1,-1,2,-2,1,-1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        memset(visit, 0, sizeof(visit));
        int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visit[x][y] = 1;
        while (!q.empty()) {
            int pi = q.front().first;
            int pj = q.front().second; q.pop();
            if (pi == x1 && pj == y1) {
                cout << visit[pi][pj] - 1 << '\n';
                break;
            }
            for (int i = 0; i < 8; i++) {
                int ni = pi + di[i];
                int nj = pj + dj[i];
                if(ni<n && nj<n && ni>=0 && nj>=0)
                    if (!visit[ni][nj]) {
                        visit[ni][nj] = visit[pi][pj] + 1;
                        q.push(make_pair(ni, nj));
                    }
            }
        }
    }
    return 0;
}
