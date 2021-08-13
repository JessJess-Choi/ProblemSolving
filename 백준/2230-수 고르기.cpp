#include<iostream>
#include<algorithm>

using namespace std;

const int MN = 100101;
const int INF = 2123456789;
int arr[MN];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int result = INF;
	for (int i = 0; i < N; i++) {
		int index = lower_bound(arr, arr + N, arr[i] + M) - arr;
		if (arr[index] - arr[i] < M)continue;
		result = min(result, arr[index] - arr[i]);
	}
	cout << result;
	return 0;
}
