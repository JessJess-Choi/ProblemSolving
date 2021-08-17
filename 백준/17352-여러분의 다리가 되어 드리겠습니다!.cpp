#include<iostream>
#include<queue>

using namespace std;

vector<int>vec[300001];
bool visit[300001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n - 2; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<int>que;
	visit[1] = 1;
	que.push(1);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int i = 0; i < vec[v].size(); i++) {
			if (!visit[vec[v][i]]) {
				visit[vec[v][i]] = 1;
				que.push(vec[v][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!visit[i]) {
			cout << "1 " << i;
			break;
		}
	return 0;
}
