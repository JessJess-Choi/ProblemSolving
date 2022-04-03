#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string f(int size,int n){
    string ret = "";
    while(n){
        ret += n % 2 + '0';
        n /= 2;
    }
    while(ret.size() != size)ret += '0';
    reverse(ret.begin(),ret.end());
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        string str1,str2,tmp = "";
        str1 = f(n,arr1[i]);
        str2 = f(n,arr2[i]);
        for(int j=0;j<n;j++){
            if(str1[j] == '1' || str2[j] == '1')tmp += '#';
            else
                tmp += ' ';
        }
        answer.push_back(tmp);
    }
    return answer;
}
