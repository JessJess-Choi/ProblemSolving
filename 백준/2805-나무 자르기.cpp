#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;
        v.push_back(tmp);
    }
    ll low=0,high=2e10;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll value = 0;
        for(int i=0;i<n;i++)
            if(v[i] > mid)
                value += v[i]-mid;
        if(value < m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout<<high;
    return 0;
}
