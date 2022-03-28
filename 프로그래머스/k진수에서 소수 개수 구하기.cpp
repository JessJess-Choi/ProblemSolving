#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool f(string str){
    long long l = stoll(str);
    if(l == 0 || l == 1)return false;
    for(long long i = 2;i*i<=l;i++)
        if(l % i == 0)return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str = "", tmp = "";
    vector<string> v;
    while(n){
        str += n % k + '0';
        n /= k;
    }
    reverse(str.begin(),str.end());
    for(auto a : str){
        if(a == '0'){
            if(tmp != "")
                v.push_back(tmp);
            tmp = "";
        }
        else
            tmp += a;
    }
    if(tmp != "")
        v.push_back(tmp);
    for(auto a : v)
        if(f(a))
            answer++;
    return answer;
}
