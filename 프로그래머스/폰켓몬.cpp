#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int,int> m;
    for(auto a : nums)m[a] += 1;
    return min(m.size(),nums.size()/2);
}
