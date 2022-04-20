#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto a : skill_trees){
        bool check = false;
        for(int i=0;i<skill.size();i++){
            int t1 = a.find(skill[i]);
            for(int j=i+1;j<skill.size();j++){
                int t2 = a.find(skill[j]);
                if(t2 == string::npos)continue;
                if(t1 > t2 || (t1 == string::npos && t2 != string::npos)){
                    check = true;
                    break;
                }
            }
            if(check)break;
        }
        if(!check)answer++;
    }
    return answer;
}
