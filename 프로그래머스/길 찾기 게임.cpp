#include <vector>
#include<algorithm>
using namespace std;
struct node{
    int x,y,number;
    node *left,*right;
};

bool compare(node a,node b){
    if(a.y != b.y)return a.y > b.y;
    return a.x < b.x;
}
void add(node* parent,node* child){
    if(parent -> x > child -> x){
        if(parent -> left == NULL)parent->left = child;
        else
            add(parent -> left,child);
    }
    else{
        if(parent -> right == NULL)parent -> right = child;
        else
            add(parent -> right,child);
    }
}
void pre(vector<int>& vec,node* n){
    if(n == NULL)return;
    vec.push_back(n -> number);
    pre(vec,n -> left);
    pre(vec,n -> right);
}
void post(vector<int>& vec,node* n){
    if(n == NULL)return;
    post(vec,n -> left);
    post(vec,n -> right);
    vec.push_back(n -> number);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{},{}};
    vector<node> v;
    node* root;
    for(int i=0;i<nodeinfo.size();i++){
        node tmp;
        tmp.x = nodeinfo[i][0];
        tmp.y = nodeinfo[i][1];
        tmp.number = i+1;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),compare);
    root = &v[0];
    for(int i=1;i<v.size();i++)add(root,&v[i]);
    pre(answer[0],root);
    post(answer[1],root);
    return answer;
}
