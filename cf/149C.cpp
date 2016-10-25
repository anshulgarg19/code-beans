#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define PAIR pair<int,int>

bool sortSkill( PAIR a, PAIR b){
	return a.first < b.first;
}

int main(void){
	int n;
	cin>>n;
	PAIR p;
	int i,skill;
	vector<PAIR > arr;

 	for(i=0;i<n;i++){
		cin>>skill;
		p = mp(skill, i+1);
		arr.push_back(p);				
	}

	sort(arr.begin(), arr.end(), sortSkill);

	int x,y;
	y = n/2;
	x = n - y;
	int count = 0;

	cout<<x<<endl;

	for(i=0;i<n && count <=x ;i+=2, count++){
		p = arr[i];
		cout<<p.second<<" ";
	}
	cout<<endl;

	cout<<y<<endl;

	count = 0;
	for(i=1; i<n && count <= y; i+=2 , count++){
		p = arr[i];
		cout<<p.second<<" ";
	}
	
	return 0;
}
