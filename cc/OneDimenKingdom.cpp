
/*
**link : https://www.codechef.com/problems/ONEKING
*/

#include<bits/stdc++.h>

using namespace std;
#define PAIR pair<int,int>
#define gi(i) scanf("%d",&i)
#define mp make_pair

bool decFunc(const PAIR& a, const PAIR& b){
	if( a.first == b.first )
		return a.second < b.second;
	return a.first < b.first;
}

int main(void){
	int t;	
	gi(t)	;
	while(t--){
		int n;
		gi(n);
		int i,a,b,rightMin;
		PAIR p;
		vector<PAIR > arr;
		for(i=0;i<n;i++){
			gi(a);
			gi(b);
			p = mp(a,b);	
			arr.push_back(p);	//p,arr
		}
		sort(arr.begin(), arr.end(), decFunc);	//decFunc

		int count = 1;
		p = arr[0];
		rightMin = p.second;	//rightMin
		for(i=1;i<n;i++){
			p = arr[i];
			if( p.first > rightMin )
			{
				count++;
			
				rightMin = p.second;
			}
			else if(p.second < rightMin){
				rightMin = p.second;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
