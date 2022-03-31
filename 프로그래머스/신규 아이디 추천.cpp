#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string tmp1 = "", tmp2 = "";
    for(int i=0;i<new_id.size();i++)
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 'a' - 'A';
    for(auto a : new_id)
        if(a == '-' || a == '_' || a == '.' || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9'))
            tmp1 += a;
    for(int i=0;i<tmp1.size();i++){
        tmp2 += tmp1[i];
        while(tmp1[i] == tmp1[i+1] && tmp1[i] == '.')i++;
    }
    tmp1 = "";
    if(tmp2[0] == '.')tmp2.erase(0,1);
    if(tmp2[tmp2.size() - 1] == '.')tmp2.erase(tmp2.size()-1,1);
    if(tmp2.size() == 0)tmp2 = "a";
    if(tmp2.size() >= 16)tmp2.erase(15,tmp2.size());
    if(tmp2[tmp2.size() - 1] == '.')tmp2.erase(tmp2.size()-1,1);
    if(tmp2.size() <= 2)
        while(tmp2.size() != 3)
            tmp2 += tmp2[tmp2.size()-1];
    return tmp2;
}
