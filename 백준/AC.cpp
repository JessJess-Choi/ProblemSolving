#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(){
	int T;
	deque<int> dq;
	cin >> T;
	string p;
	for(int i=0;i<T;i++){
		
		bool find = true;
		int n;
		int a=0;
		char tmp;
		cin >> p >> n >> tmp;
		for(int i=0;i<n;i++){
			int get;
			cin >> get >> tmp;
			dq.push_back(get);
		}
		
		for(int j=0;j<p.size();j++){
			if(p.at(j) == 'D'){
				if(!dq.empty()){
					if(a%2 == 0)
						dq.pop_front();
					else
						dq.pop_back();
				}
				else{
					find = false;
				}
			}
			
			else if(p.at(j) == 'R'){
				a++;
	
			}
			
			else
				;
		}
		
		if(find){
			cout << "[";
			n=dq.size();
			for(int j=0;j<n;j++){
				if(a%2 == 0){
					cout << dq.front();
					dq.pop_front();
					if(!dq.empty())
						cout << ",";
				}

				else{
						cout << dq.back();
						dq.pop_back();
						if(!dq.empty())
							cout << ",";
					}
			}
			cout << "]\n";
		}
		
		else
			cout << "error\n";
		dq.clear();
		p.clear();
		cin.ignore(1000,'\n');
	}
	return 0;
}
