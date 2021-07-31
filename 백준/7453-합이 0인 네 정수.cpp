#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,A[4001],B[4001],C[4001],D[4001],arr1[4001*4001],arr2[4001*4001],cnt;
int indx;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)cin>>A[i]>>B[i]>>C[i]>>D[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            arr1[indx] = A[i] + B[j];
            arr2[indx++] = C[i] + D[j];
        }
    sort(arr1,arr1+n*n);
    sort(arr2,arr2+n*n);
    for(int i=0;i<n*n;i++){
        long long tmp = -arr1[i];
        cnt += upper_bound(arr2,arr2+n*n,tmp) - lower_bound(arr2,arr2+n*n,tmp);
    }
    cout<<cnt;
    return 0;
}
