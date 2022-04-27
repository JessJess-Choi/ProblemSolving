#include <iostream>
#include <cmath>
#define MAX 9*9*9*9*9*5 + 1

using namespace std;

int a, p, visit[MAX], ans;

void dfs(int n){
    visit[n]++;
    if(visit[n] == 3)return;
    int next = 0;
    while(n){
        next += pow(n % 10, p);
        n /= 10;
    }
    dfs(next);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> p;
    dfs(a);
    for(int i=0;i<MAX;i++)
        if(visit[i] == 1)
            ans++;
    cout<<ans;
    return 0;
}
