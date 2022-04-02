#include <vector>
#include <algorithm>
#define P pair<double,int>

using namespace std;

double try_number[501];
double fail[501];

bool compare(P a, P b){
    if(a.first != b.first)return a.first > b.first;
    else
        return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<P> v;
    for(auto a : stages){
        for(int i=1;i<=a;i++)
            try_number[i] += 1.0;
        fail[a] += 1.0;
    }
    for(int i=1;i<=N;i++)
        if(try_number[i])
            v.push_back({fail[i]/try_number[i],i});
        else
            v.push_back({0,i});
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<N;i++)
        answer.push_back(v[i].second);
    return answer;
}
