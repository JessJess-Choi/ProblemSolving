#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int k, tmp, n; cin >> k;
        char ch;
        map<int, int>m;
        priority_queue<int, vector<int>, less<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        while (k--) {
            cin >> ch >> tmp;
            if (ch == 'I') {
                m[tmp] += 1;
                pq1.push(tmp);
                pq2.push(tmp);
            }
            else if (ch == 'D') {
                if (tmp == -1) {
                    while (!pq2.empty() && !m[pq2.top()])pq2.pop();
                    if (!pq2.empty() && m[pq2.top()]) {
                        n = pq2.top();
                        pq2.pop();
                        m[n]--;
                    }
                }
                else if (tmp == 1) {
                    while (!pq1.empty() && !m[pq1.top()])pq1.pop();
                    if (!pq1.empty() && m[pq1.top()]) {
                        n = pq1.top();
                        pq1.pop();
                        m[n]--;
                    }
                }
            }
        }
        while (!pq1.empty() && !m[pq1.top()])pq1.pop();
        while (!pq2.empty() && !m[pq2.top()])pq2.pop();

        if (pq1.empty() && pq2.empty())
            cout << "EMPTY\n";
        else
            cout << pq1.top() << ' ' << pq2.top() << '\n';
    }
    return 0;
}
