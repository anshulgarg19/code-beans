/*
** https://www.codechef.com/problems/POUR1
*/

#include<bits/stdc++.h>

using namespace std;

#define gi(x) scanf("%d",&x)

int min(int a ,int b){
	if( a < b )
		return a;
	return b;
}
int main(void){
	int t,a,b,c;
	gi(t);
	while(t--){
		gi(a);
		gi(b);
		gi(c);
		if( a < c && b < c )
			cout<<"-1\n";
		else if( a== c || b ==c )
			cout<<"1\n";
		else{
			int res = INT_MAX;
			if( (c % a) == 0 )
				res = 2*(c/a);
			if((c % b) == 0 )
				res = min( res, 2* (c/b));
			int diff = abs(a-b);
			if( diff && ((c % diff) == 0 ))
				res = min( res, 2*(c/diff));
			if( (a-diff == c) || (b-diff == c))
				res = min(res, 4);
			if( res == INT_MAX)
				cout<<"-1\n";
			else
				cout<<res<<endl;
		}
	}
	return 0;
}
