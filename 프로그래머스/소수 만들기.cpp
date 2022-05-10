#include <vector>

using namespace std;

bool arr[50001];

int solution(vector<int> nums) {
    int answer = 0;
    arr[0] = arr[1] = true;
    for(int i=2;i*i<50001;i++){
        if(arr[i])continue;
        for(int j=i*i;j<50001;j+=i)
            arr[j] = true;
    }
    vector<int> v;
    for(auto a : nums)
        for(auto b : nums){
            if(a == b)break;
            for(auto c : nums){
                if(b == c)break;
                v.push_back(a+b+c);
            }
        }
    for(auto a : v)
        if(!arr[a])
            answer++;
    return answer;
}
