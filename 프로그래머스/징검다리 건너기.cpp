#include <vector>
#include<algorithm>
using namespace std;
int low=1,high;
bool f(int mid,int& k,vector<int>& v){
    int cnt = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] - mid <= 0)cnt++;
        else
            cnt = 0;
        if(cnt >= k)return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    for(auto a : stones)high = max(a,high);
    while(low <= high){
        int mid = (low + high) / 2;
        if(f(mid,k,stones))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
