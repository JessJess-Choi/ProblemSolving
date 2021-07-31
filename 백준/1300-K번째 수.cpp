#include<iostream>
using namespace std;
int n,k,low,high;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    low = 1,high = k;
    while(low <= high){
        int cnt = 0;
        int mid = (low + high) / 2;
        for(int i=1;i<=n;i++)
            cnt += min(mid/i,n);
        if(cnt < k)low = mid + 1;
        else
            high = mid - 1;
    }
    cout<<low;
    return 0;
}
