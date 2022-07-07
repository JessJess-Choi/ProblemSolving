#include <iostream>
#include <set>
using namespace std;

int N, K, ans;
string g[51];
bool alpha[26];

void dfs(int start, int n){
    if(n == K){
        int tmp = 0;
        for(int i=0;i<N;i++){
            bool check = true;
            for(char ch : g[i])
                if(!alpha[ch - 'a']){
                    check = false;
                    break;
                }
            if(check)tmp++;
        }
        ans = max(tmp, ans);
    }
    else{
        for(int i=start;i<26;i++)
            if(!alpha[i]){
                alpha[i] = true;
                dfs(i,n + 1);
                alpha[i] = false;
            }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i=0;i<N;i++)cin >> g[i];
    if(K < 5){
        cout<<0;
        return 0;
    }
    alpha['a' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['c' - 'a'] = true;
    K -= 5;
    dfs(0,0);
    cout<<ans;
    return 0;
}
