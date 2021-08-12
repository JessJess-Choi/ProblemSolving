#include <string>
#include <vector>
#include<unordered_map>
using namespace std;
int solution(vector<int> a) {
    int answer = -1;
    unordered_map<int,int> m;
    for(auto it : a)m[it]++;
    for(auto it : m){
        int tmp = 0;
        if(it.second*2 <= answer)continue;
        for(int i=0;i<a.size()-1;i++){
            if(a[i] == a[i+1])continue;
            if(a[i] != it.first && a[i+1] != it.first)continue;
            tmp+=2;
            i++;
        }
        answer = max(answer,tmp);
    }
    return answer;
}
