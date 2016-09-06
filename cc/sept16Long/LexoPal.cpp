/*
** https://www.codechef.com/SEPT16/problems/LEXOPAL
*/

#include<bits/stdc++.h>

using namespace std;

int main(void){
	int t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		int i;
		int len = s.size();
		bool isValid = true;

		for(i=0;i<len/2;i++){
			if( (s[i] == '.') && (s[len-i-1] =='.'))
				s[i] = s[len-i-1] = 'a';
			else if( (s[i] != '.') && (s[len -i-1] != '.' )){
				if(s[i] != s[len-i-1]){
					isValid = false;
					break;
				}
			}
			else{
				if(s[i] != '.')
					s[len-i-1] = s[i];
				else
					s[i] = s[len-i-1];
			}
		}
		if(len & 1) {
			if(s[len/2] == '.')
				s[len/2] = 'a';
		}
		if(isValid)
			cout<<s<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}

