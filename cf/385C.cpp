#include<bits/stdc++.h>

using namespace std;

#define UPPER_RANGE 10000001
#define ll long long 

int arr[UPPER_RANGE];
bool prime[UPPER_RANGE];

int main(void){
	int n;
//	cin>>n;
	scanf("%d",&n);
	int i,val;
	//for(i=0;i<UPPER_RANGE;i++){
	//	prime[i] = true;
	//	arr[i] = 0;
	//}

	for(i=0;i< n;i++){
	//	cin>>val;
		scanf("%d",&val);
		arr[val]++;
	}
	int j;
	for(i=2;i<UPPER_RANGE;i++){
		if( !prime[i] )	{
			for(j=2*i;j< UPPER_RANGE; j+=i){
				prime[j] = true;
				arr[i] += arr[j];
			}
			arr[i]+= arr[i-1];
		}else{
			arr[i] = arr[i-1];
		}
	}

	int m,l,r;
	//cin>>m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		if(l > r){
			printf("0\n");
			continue;
		}
		if(l >= UPPER_RANGE){
			l = UPPER_RANGE-1;
		}
		if( r >= UPPER_RANGE){
			r = UPPER_RANGE-1;
		}
		printf("%d\n",arr[r]-arr[l-1]);
	}
	return 0;
}

