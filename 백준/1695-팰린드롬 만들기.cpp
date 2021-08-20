#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[5001][5001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int>vec1,vec2;
	vec1.push_back(0);
	vec2.push_back(0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec1.push_back(tmp);
	}
	for (int i = n; i > 0; i--)
		vec2.push_back(vec1[i]);
	for (int i = 1; i < vec1.size(); i++) {
		for (int j = 1; j < vec2.size(); j++) {
			if (vec1[i] == vec2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << n - dp[vec1.size() - 1][vec2.size() - 1];
	return 0;
}
