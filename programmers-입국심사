#include <string>
#include <vector>
#include<algorithm>

#define ll long long

using namespace std;

long long solution(int n, vector<int> times) {
    ll answer = 0,maxTime = -1,low = 1, high;
    for(auto a : times)maxTime = max(maxTime,(ll)a);
    high = (ll)maxTime * n;
    while(low <= high){
        ll mid = (low + high) / 2;
        ll tmp = 0LL;
        for(int i=0;i<times.size();i++)tmp += mid/times[i];
        if(tmp < n)
            low = mid + 1;
        else{
            answer = mid;
            high = mid - 1;
        }
    }
    return answer;
}
