#include<bits/stdc++.h>

using namespace std;

int main(void){
	string s;
	cin>>s;
	int i;
	int len = s.size();
	stack<int> left;
	queue<int> right;	

	for(i=0;i< len;i++){
		switch( s[i] ){
			case 'l': left.push(i+1);
				break;
			case 'r': right.push(i+1);
				break;
		}
	}

	while( !right.empty() ){
		//cout<<right.front()<<endl;
		printf("%d\n",right.front());
		right.pop();
	}

	while( !left.empty()) {
		//cout<<left.top()<<endl;
		printf("%d\n",left.top());
		left.pop();
	}
	return 0;
}
