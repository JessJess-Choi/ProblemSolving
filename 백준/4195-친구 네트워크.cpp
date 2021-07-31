#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int par[2000002], rnk[2000002];

int find(int x) {
    if (par[x] == x)return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y)return;
    if (rnk[x] > rnk[y])swap(x, y);
    par[x] = y;
    rnk[y] += rnk[x];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;cin>>T;
    while(T--){
        int F;cin>>F;
        map<string,int> m;
        int index = 1;
        for(int i=0;i<200002;i++){
            par[i] = i;
            rnk[i] = 1;
        }
        for(int i=0;i<F;i++){
            string str1,str2;cin>>str1>>str2;
            if(m.find(str1) == m.end())m[str1] = index++;
            if(m.find(str2) == m.end())m[str2] = index++;
            unite(m[str1],m[str2]);
            cout<<max(rnk[find(m[str1])],rnk[find(m[str2])])<<'\n';
        }
    }
    return 0;
}
