#include <string>
#include <vector>

using namespace std;

int N,answer;

void dfs(vector<int>&v,int count,int now){
    if(count == v.size()){
        if(now == N)
            answer++;
            return;
    }
    dfs(v,count+1,now+v[count]);
    dfs(v,count+1,now-v[count]);
}

int solution(vector<int> numbers, int target) {
    N = target;
    dfs(numbers,0,0);
    return answer;
}
