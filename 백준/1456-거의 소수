#include<iostream>
#include<vector>

using namespace std;

bool arr[10000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<long long>v;
    long long cnt = 0LL;
    for (int i = 2; i * i < 10000001; i++) {
        if (arr[i])continue;
        for (int j = i * i; j < 10000001; j += i)
            arr[j] = true;
    }
    arr[0] = arr[1] = true;
    for (long long i = 2; i < 10000001; i++)
        if (!arr[i])v.push_back(i);
    long long A, B; cin >> A >> B;
    for (long long i = 0; i < v.size(); i++) {
        long long tmp = v[i];
        while (tmp <= B/v[i]) {
            tmp *= v[i];
            if (tmp >= A)cnt++;
        }
    }
    cout << cnt;
    return 0;
}
