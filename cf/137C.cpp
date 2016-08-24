#include<bits/stdc++.h>

using namespace std;
#define PAIR pair<int,int >

bool sortFunc(const PAIR& a, const PAIR& b){
	return a.first < b.first;
}

int main(void){
	int n,a,b,i;
	scanf("%d",&n);
	PAIR p;
	vector<PAIR > arr;
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		p.first = a;
		p.second = b;
		arr.push_back(p);
	}

	sort(arr.begin(), arr.end(), sortFunc);

	p = arr[0];
	int maxEle = p.second;
	int count = 0;
	for(i=1;i<n;i++){
		p = arr[i];
		if(p.second < maxEle)
			count++;
		else
			maxEle = p.second;
	}
	printf("%d",count);
}
