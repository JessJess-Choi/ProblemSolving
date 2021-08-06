#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool checkData(int index,char compare,int n){
    if(compare == '=')return index==n;
    else if(compare == '>')return index > n;
    else
        return index < n;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string str = "ACFJMNRT";
    do{
        bool check = true;
        for(auto a : data){
            int tmp = max(str.find(a[0]),str.find(a[2])) - min(str.find(a[0]),str.find(a[2])) - 1;
            if(!checkData(tmp,a[3],a[4]-'0')){
                check = false;
                break;
            }
        }
        if(check)answer++;
    }while(next_permutation(str.begin(),str.end()));
    return answer;
}
