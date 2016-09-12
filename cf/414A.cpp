#include<bits/stdc++.h>

using namespace std;

int main(void){
	int n,k;
	cin>>n>>k;
	if( k < n/2 )
		cout<<"-1";
	else if(n==1 && k == 0)
		cout<<"1";
	else if(n==1)
		cout<<"-1";
	else{
		int x = k - (n-2)/2;
		cout<<x<<" "<<2*x<<" ";
//		return 0;
		int y = 2;
		int count = (n-2)/2;
		bool valid = false;
		while(count--){
			valid = true;
			while(1){
				y+=2;
				if(y==x || (y+1)==x || y ==2*x || (y+1)==2*x)
					valid = false;
				else
					valid = true;
				if(valid){
					cout<<y<<" "<<y+1<<" ";
					break;
				}
			}
		}
		if( n & 1)	
		{
			valid = true;
			while(1){
				y+=2;
				if(y==x || (y+1)==x || y==2*x || (y+1)==2*x)
					valid = false;
				else
					valid = true;
				if(valid)
				{
					cout<<y;
					break;
				}
			}
		}
	}
	return 0;
}
