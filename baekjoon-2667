#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int g[50][50];
int visit[50][50];
int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };
int n, cnt;
vector<int> v;

void dfs(int pi,int pj) {
    visit[pi][pj] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int ni = pi + di[i];
        int nj = pj + dj[i];
        if (ni < n && nj < n && ni >= 0 && nj >= 0)
            if (!visit[ni][nj] && g[ni][nj])
                dfs(ni, nj);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m; cin >> n;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < str.size(); j++)
            g[i][j] = str[j] - '0';
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (!visit[i][j] && g[i][j]) {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto a : v)cout << a << '\n';
    return 0;
}
