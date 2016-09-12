/*
** https://www.codechef.com/SEPT16/problems/RESCALC
*/

#include<bits/stdc++.h>

using namespace std;

int main(void){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int i,j,cookie,ele;
		vector<vector<int> > finalGrid;

		vector<int> count;

		for(i=0;i<n;i++){
			cin>>cookie;
			vector<int> arr(6,0);
			for(j=0;j<cookie;j++){
				cin>>ele;
				arr[ele-1]++;					
			}
			finalGrid.push_back(arr);
			count.push_back(cookie);
		}
	
		
		int k;
		int maxCount = INT_MIN;
		bool tie = false;
		int maxIndex = -1;

		for(i=0;i<n;i++){
			vector<int> arr = finalGrid[i];
			sort(arr.begin(), arr.end());
			k = arr[0]*4 + (arr[1]-arr[0])*2 + arr[2]-arr[1];
			count[i] += k;
			if(count[i] > maxCount){
				maxCount = count[i];
				maxIndex = i;
			}
			/*else if(count[i] == maxCount){
				tie = true;
				break;
			}*/
		}
		k=0;
		for(i=0;i< n;i++){
			if(count[i] == maxCount)	
				k++;
		}

		if( k > 1 )
			tie = true;

		if(tie)
			cout<<"tie\n";
		else if( maxIndex == 0 )
			cout<<"chef\n";
		else
			cout<<maxIndex+1<<endl;
				
	}
	return 0;

}
