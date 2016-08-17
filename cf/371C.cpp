#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll maxA(ll a, ll b){
	if( a>= b)
		return a;
	return b;
}

int main(void){
	string s;
	cin>>s;
	int i;
	ll nb,ns,nc;
	nb = ns = nc = 0;
	for(i=0;i<s.size();i++){
		switch(s[i]){
			case 'B': nb++;
				break;
			case 'S': ns++;
				break;
			case 'C': nc++;
				break;
		}
	}	
	//cout<<nb<<" "<<ns<<" "<<nc<<endl;
	ll cb,cs,cc;
	ll pb,ps,pc;
	cb = cs = cc = pb = ps = pc = 0;
	cin>>cb>>cs>>cc;
	cin>>pb>>ps>>pc;
	ll r;
	cin>>r;

	ll low = 1, high = 1000000000000, mid;
	while( low <=  high ){
		mid = (low+high)/2;
		ll reqb = maxA(0ll,nb*mid-cb);
		ll reqs = maxA(0ll,ns*mid-cs);
		ll reqc = maxA(0ll,nc*mid-cc);

		if( (reqb*pb) + (reqs*ps)+ (reqc*pc) <= r ){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	cout<<high;
	return 0;
}
