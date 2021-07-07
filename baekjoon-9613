#include<iostream>

using namespace std;

long long gcd(long long a, long long b) { return b ? gcd(b,a % b) : a; }

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long answer = 0LL;
        long long arr[101];
        for (int i = 0; i < n; i++)cin >> arr[i];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                answer += gcd(arr[i], arr[j]);
        cout << answer << '\n';
    }
    return 0;
}
