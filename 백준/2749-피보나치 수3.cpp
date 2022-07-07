#include <iostream>
#include <vector>
#define ll long long
#define mat vector<vector<ll>>
#define MOD 1000000

using namespace std;

mat mul(mat a, mat b){
    mat ret(a.size(), vector<ll>(b.size()));
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b[0].size();j++)
            for(int k=0;k<b.size();k++)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    return ret;
}

mat pow(mat a, ll n){
    if(n == 1)return a;
    if(n % 2)return mul(pow(a, n - 1), a);
    mat m = pow(a,n/2);
    return mul(m, m);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    if(n == 1 || n == 2){
        cout<<1;
        return 0;
    }
    mat a(2, vector<ll>(2));
    a[0][0] = a[0][1] = a[1][0] = 1;
    mat b(2, vector<ll>(1));
    b[0][0] = 1;
    mat p = mul(pow(a, n - 1), b);
    cout << p[0][0];
    return 0;
}
