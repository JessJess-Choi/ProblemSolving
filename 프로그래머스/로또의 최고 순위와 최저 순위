#include <string>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
int right,no;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> s;
    int arr[7] = {6,6,5,4,3,2,1};
    for(auto a : win_nums)s.insert(a);
    for(auto a : lottos){
        if(a == 0)no++;
        else if(s.find(a) != s.end())right++;
    }
    answer.push_back(arr[right + no]);
    answer.push_back(arr[right]);
    return answer;
}
