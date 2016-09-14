#include<bits/stdc++.h>


using namespace std;

#define gi(x) scanf("%d",&x)

int main(void){
	int n;
	vector<int> arr;
	int i,ele;
	gi(n);
	for(i=0;i< n;i++){
		gi(ele);	//ele
		arr.push_back(ele);
	}

	sort(arr.begin(), arr.end());

	int a = -1;
	int b=-1;
	int c = -1;
	int count = 0;
	count = 1;
	a = arr[0];
	bool impossible = false;
	for(i=1;i<n;i++){
		if(arr[i] != arr[i-1] ){
			switch(count){
				case 1: b = arr[i];
					break;
				case 2: c = arr[i];
					break;
				case 3: impossible = true;
			}
			count++;
			if( impossible ){
				break;
			}
		}
	}

	if( impossible )
		cout<<"NO";
	else{
		switch(count) {
			
			case 1: cout<<"YES";
				break;
			case 2: cout<<"YES";
				break;
			case 3: if(b-a == c-b)
					cout<<"YES";
				else
					cout<<"NO";
		
		}
	}
	return 0;
}
