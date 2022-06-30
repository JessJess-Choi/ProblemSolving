#include<iostream>
#include<algorithm>

using namespace std;

const int MN = 100101;
int arr[MN];

int dnc(int L, int R) {
    if (L == R) return arr[L];

    int mid = (L + R) / 2;
    int ret = max(dnc(L, mid), dnc(mid + 1, R));

    int l = mid, r = mid + 1;
    int h = min(arr[l], arr[r]);
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
    int N;  cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cout << dnc(1, N);
	return 0;
}
