#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#define P pair<int,int>
using namespace std;
vector<int> v;
vector<P> v2;
unordered_map<int,int> m;
int n,tmp;
double sum;
bool compare(P a,P b){
    if(a.second != b.second)return a.second > b.second;
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
        m[tmp] += 1;
        sum += (double)tmp;
    }
    cout<<floor(sum/n + 0.5)<<'\n';
    sort(v.begin(),v.end());
    cout<<v[n/2]<<'\n';
    for(auto a : m)v2.push_back({a.first,a.second});
    sort(v2.begin(),v2.end(),compare);
    if(v2[0].second != v2[1].second)cout<<v2[0].first<<'\n';
    else
        cout<<v2[1].first<<'\n';
    cout<<v[v.size()-1] - v[0];
    return 0;
}
