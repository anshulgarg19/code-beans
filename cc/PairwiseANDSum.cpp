/*
**link: https://www.codechef.com/problems/AND
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define gi(i) scanf("%d",&i)
#define gl(i) scanf("%lld",&i)
#define BITS 32

int main(void){
	ll n;
	ll i;
	gl(n);
	ll ele;
	ll bitCount[BITS] = {0};
	ll bit,count;

	for(i=0;i<n;i++){
		gl(ele);
		count = 0;
		while(ele > 0 ){
			bit = ele & 1;
			
			if(bit){
				bitCount[count]++;
			}
			count++;
			ele >>= 1;
		}
	}

	ll val,ans=0;
	ll twoPower = 1;
	for(i=0;i< BITS;i++){
		val = 0;
		if( bitCount[i] ){
			val = (bitCount[i]*(bitCount[i]-1)*twoPower)/2;
		}
		ans += val;
		twoPower *= 2;
	}
	printf("%lld",ans);
	return 0;
}
