#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct f{
    string head,number,tail;
};

bool compare(f a, f b){
    for(int i=0;i<a.head.size();i++)
        if(a.head[i] >= 'A' && a.head[i] <= 'Z')a.head[i] += 'a' - 'A';
    for(int i=0;i<b.head.size();i++)
        if(b.head[i] >= 'A' && b.head[i] <= 'Z')b.head[i] += 'a' - 'A';
    if(a.head != b.head)return a.head < b.head;
    else if(stoi(a.number) != stoi(b.number))return stoi(a.number) < stoi(b.number);
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<f> v;
    for(string str : files){
        f tmp;
        for(int i=0;i<str.size();i++)
            if(str[i] >= '0' && str[i] <= '9'){
                bool check = true;
                tmp.head = str.substr(0,i);
                for(int j=i;j<i+5;j++){
                    if(j == str.size()){
                        tmp.number = str.substr(i,str.size()-i);
                        tmp.tail = "";
                        check = false;
                        break;
                    }
                    if(str[j] < '0' || str[j] > '9'){
                        tmp.number = str.substr(i,j-i);
                        tmp.tail = str.substr(j,str.size()-j);
                        check = false;
                        break;
                    }
                }
                if(check){
                    tmp.number = str.substr(i,5);
                    tmp.tail = str.substr(i+5,str.size()-i-5);
                }
                break;
            }
        v.push_back(tmp);
    }
    stable_sort(v.begin(),v.end(),compare);
    for(auto a : v)
        answer.push_back(a.head + a.number + a.tail);
    return answer;
}
