#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int len = answers.size();
    int arr[3][len];
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=0;i<len;i++){
        arr[0][i] = i%5+1;
        if(i%8==0)arr[1][i] = 2;
        else if(i%8==1)arr[1][i] = 1;
        else if(i%8==2)arr[1][i] = 2;
        else if(i%8==3)arr[1][i] = 3;
        else if(i%8==4)arr[1][i] = 2;
        else if(i%8==5)arr[1][i] = 4;
        else if(i%8==6)arr[1][i] = 2;
        else if(i%8==7)arr[1][i] = 5;
        if(i%10==0 || i%10==1)arr[2][i] = 3;
        else if(i%10==2 || i%10==3)arr[2][i] = 1;
         else if(i%10==4 || i%10==5)arr[2][i] = 2;
         else if(i%10==6 || i%10==7)arr[2][i] = 4;
         else if(i%10==8 || i%10==9)arr[2][i] = 5;
    }
    for(int i=0;i<len;i++){
        if(answers[i] == arr[0][i])cnt1++;
        if(answers[i] == arr[1][i])cnt2++;
        if(answers[i] == arr[2][i])cnt3++;
    }
    int check = max(max(cnt1,cnt2),cnt3);
    if(check == cnt1)answer.push_back(1);
    if(check == cnt2)answer.push_back(2);
    if(check == cnt3)answer.push_back(3);
    return answer;
}
