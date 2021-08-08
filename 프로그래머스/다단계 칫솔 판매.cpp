#include<string>
#include <vector>
#include<map>

using namespace std;

int par[10001],money[10001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string,int> m;
    m["-"] = 0;
    for(int i=0;i<enroll.size();i++){
        string str1 = enroll[i], str2 = referral[i];
        m[str1] = i + 1;
        par[i + 1] = m[str2];
    }
    for(int i=0;i<seller.size();i++){
        int now = m[seller[i]];
        money[now] += amount[i] * 100;
        int givemoney = amount[i] * 10;
        while(givemoney > 0 && now != 0){
            money[par[now]] += givemoney;
            money[now] -= givemoney;
            now = par[now];
            givemoney /= 10;
        }
    }
    for(int i=1;i<=enroll.size();i++)answer.push_back(money[i]);
    return answer;
}
