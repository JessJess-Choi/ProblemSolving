#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> v1,v2;
    for(auto a : sizes){
        sort(a.begin(),a.end());
        v1.push_back(a[0]);
        v2.push_back(a[1]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    return v1[v1.size() - 1] * v2[v2.size() - 1];
}
