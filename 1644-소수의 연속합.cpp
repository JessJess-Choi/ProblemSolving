#include <iostream>
#include <vector>

using namespace std;

int N, low, high, sum, ans;
bool arr[4000001];
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=2;i*i<=N;i++){
        if(arr[i])continue;
        for(int j=i*i;j<=N;j+=i)
            arr[j] = true;
    }
    for(int i=2;i<=N;i++)
        if(!arr[i])v.push_back(i);
    while(low <= high && high <= (int)v.size()){
        if(sum >= N){
            if(sum == N)ans++;
            sum -= v[low++];
        }
        else{
            if(high == (int)v.size())break;
            sum += v[high++];
        }
    }
    cout<<ans;
    return 0;
}
