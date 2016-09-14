#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define gi(x) cin>>x

int main(void){
	ll l1,r1,l2,r2,k;
	gi(l1);
	gi(r1);
	gi(l2);
	gi(r2);
	gi(k);

	ll lmax = max(l1,l2);
	ll rmin = min(r1,r2);

	if(lmax > rmin ){
		cout<<"0";
	} else {
		ll res = rmin - lmax +1;
		if( k >= lmax && k <= rmin )
			res--;
		cout<<res;
	}
	return 0;
}
