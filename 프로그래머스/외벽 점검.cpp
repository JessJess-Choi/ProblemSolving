#include <vector>
#include<algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    int Weak[31];
    for(int i=0;i<weak.size();i++)Weak[i] = weak[i];
    for(int i=weak.size();i<weak.size()*2;i++)Weak[i] = weak[i-weak.size()] + n;
    sort(dist.begin(),dist.end());
    do{
        for(int i=0;i<weak.size();i++){
            int start = Weak[i];
            int end = Weak[i+weak.size()-1];
            for(int j=0;j<dist.size();j++){
                start += dist[j];
                if(start >= end){
                    answer = min(answer,j+1);
                    break;
                }
                start = Weak[upper_bound(Weak,Weak+31,start) - Weak];
            }
        }
    }while(next_permutation(dist.begin(),dist.end()));
    if(answer == 1e9)return -1;
    return answer;
}
