#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v;
    for(int i=0;i<n;i++)v.push_back(1);
    for(auto a : reserve)v[a-1]++;
    for(auto a : lost)v[a-1]--;
    for(int i=0;i<n;i++){
        if(v[i] == 2){
            if(i>0 && v[i-1] == 0)v[i] = v[i-1] = 1;
            if(i<n-1 && v[i+1]==0 && v[i]==2)v[i] = v[i+1] = 1;
        }
    }
    for(int i=0;i<n;i++)if(v[i])answer++;
    return answer;
}
