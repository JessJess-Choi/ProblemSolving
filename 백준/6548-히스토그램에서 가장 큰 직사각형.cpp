#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MN = 100101;
long long arr[MN];


long long dnc(long long L, long long R) {
    if (L == R) return arr[L];

    long long mid = (L + R) / 2;
    long long ret = max(dnc(L, mid), dnc(mid + 1, R));

    long long l = mid, r = mid + 1;
    long long h = min(arr[l], arr[r]);
    ret = max(ret, h * (r - l + 1));
    while (L < l || r < R) {
        if (L == l) h = min(h, arr[++r]);
        else if (R == r) h = min(h, arr[--l]);
        else if (arr[l - 1] > arr[r + 1]) h = min(h, arr[--l]);
        else h = min(h, arr[++r]);

        ret = max(ret, h * (r - l + 1));
    }

    return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        int n; cin >> n;
        if (n == 0)break;
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        cout << dnc(1, n) << "\n";
    }
	return 0;
}
