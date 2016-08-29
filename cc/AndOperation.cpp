/*
** https://www.codechef.com/problems/TAAND
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define gi(x) scanf("%d",&x)
#define BITS 32

int findHighest(vector<int> arr, ll* result){
	int bitCount[BITS] = {0};
	int n = arr.size();
	int i, bit,mask;
	for(i=0;i < n ;i++){
		for(bit =0;bit< BITS;bit++){	//bit
			mask = 1 << bit;	//mask
			if(arr[i] & mask){
				bitCount[bit]++;
			}
//			if(arr[i]==6 || arr[i] == 4){
//				if(arr[i]&mask)
//					cout<<1<<endl;
//				else
//					cout<<0<<endl;
//			}
		}
	}	
	int maxBits = 2;
	ll maxAns = 0;
	int bitPosition = -1;
	ll factor = 1;

	for(i=0;i<BITS;i++){
		if(bitCount[i] > 1 ){	//maxBits,maxAns,factor
			maxBits = bitCount[i];
			maxAns = factor;
			bitPosition = i;
		}
		factor *= 2;
	}
	
	*result += maxAns;
	return bitPosition;
	
}

int calcResult(vector<int>& arr, ll*result, int setBit){
	int i;
	int n = arr.size();
	int mask = 1 << setBit;
	int bitCount[BITS] = {0};
	int bit,m;
	for(i=0; i < n;i++){
		if( arr[i] & mask ){
			for(bit=0; bit < setBit;bit++){
				m = 1 << bit;
				if( arr[i] & m ){
					bitCount[bit]++;	//bit,m,bitCount[]
				}
			}
		}
		else
			arr[i] = 0;
	}
	//maxBits,maxAns,bitPosition
	int maxBits = 2;
	ll maxAns = 0;
	int bitPosition = -1;
	ll factor = 1;
	for(i=0;i<setBit;i++){
		if(bitCount[i] >= 2){
			maxBits = bitCount[i];
			maxAns = factor;
			bitPosition = i;
		}
		factor *= 2;
	}
	*result += maxAns;
	return bitPosition;
}

int main(void){
	int n;
	vector<int> arr;
	int ele,i;
	gi(n);
	for(i=0;i<n;i++){
		gi(ele);
		arr.push_back(ele);
	}

	ll result=0;
	int setBit;

	setBit = findHighest(arr, &result);	//ll result,int setBit
//	cout<<setBit<<" "<<result<<endl;
	
	while(setBit > -1){
		setBit = calcResult(arr, &result, setBit);
//		cout<<setBit<<" "<<result<<endl;
	}
	printf("%lld",result);
	return 0;
}
