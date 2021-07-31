#include<iostream>
#include<queue>

using namespace std;

int F, S, G, U, D;
int visit[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    queue<pair<int,int>> q;
    q.push({ S,0 });
    visit[S] = 1;
    while (!q.empty()) {
        int p = q.front().first;
        int cnt = q.front().second; q.pop();
        if (p == G) {
            cout << cnt;
            return 0;
        }
        if (p + U <= F && !visit[p + U]) {
            q.push(make_pair(p + U, cnt + 1));
            visit[p + U] = 1;
        }
        if (p - D > 0 && !visit[p - D]) {
            q.push(make_pair(p - D, cnt + 1));
            visit[p - D] = 1;
        }
    }
    cout << "use the stairs";
    return 0;
}
