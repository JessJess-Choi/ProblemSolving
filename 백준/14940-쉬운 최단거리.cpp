#include<iostream>
#include<queue>

using namespace std;

int g[1001][1001];
const int INF = 2123456789;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
queue<pair<int, int> > que;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m, tmp, x, y, two_x, two_y; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == 0)
				g[i][j] = -INF;
			else if (tmp == 2) {
				two_x = i;
				two_y = j;
				que.push(make_pair(i, j));
			}
		}
	}
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + di[i];
			int ny = y + dj[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
				if (!g[nx][ny]) {
					que.push(make_pair(nx, ny));
					g[nx][ny] = g[x][y] + 1;
				}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] < 0)g[i][j] = 0;
			else if (g[i][j] == 0)g[i][j] = -1;
			if (two_x == i && two_y == j)
				cout << "0 ";
			else
				cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
