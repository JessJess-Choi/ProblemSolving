#include<iostream>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x,y;cin>>x>>y;
    ll z = y*100/x;
    if(z>=99){
        cout<<-1;
        return 0;
    }
    ll low = 0,high = 2e10;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll value = (y+mid)*100/(x+mid);
        if(value <= z)low = mid + 1;
        else
            high = mid - 1;
    }
    cout<<low;
    return 0;
}
