#include<iostream>

using namespace std;

long long pow(int n) {
	if (n == 0)return 1;
	if (n == 1)return 2;
	if (n % 2)return (pow(n - 1) * 2) % 1000000007;
	long long tmp = pow(n / 2);
	return tmp * tmp % 1000000007;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 1)
			cout << "1\n";
		else
			cout << pow(n-2) << "\n";
	}
	return 0;
}
