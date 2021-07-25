#include<iostream>

using namespace std;

int arr[201][201], group[201], trip[1001];

int find(int x) {
    if (group[x] == x)return x;
    return group[x] = find(group[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    group[x] = y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)group[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                if (find(i) != find(j))
                    unite(i, j);
        }
    for (int i = 1; i <= m; i++)cin >> trip[i];
    for (int i = 2; i <= m; i++) {
        int check1 = trip[1];
        int check2 = trip[i];
        if (find(check1) != find(check2)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
