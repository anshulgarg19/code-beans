/*
** https://www.codechef.com/SEPT16/problems/LONGSEQ
*/

#include<bits/stdc++.h>

using namespace std;
int main(void) {
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;	
		int i;
		int zeros,ones;
		zeros = ones = 0;
		for(i=0;i < s.size();i++){
			if( s[i] - '0' )
				ones++;	
			else
				zeros++;
		}
		if(zeros == 1 || ones == 1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
