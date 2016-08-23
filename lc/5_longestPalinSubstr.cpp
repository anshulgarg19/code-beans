class Solution {

public:

    string longestPalindrome(string s) {

        int i,j,k;

        int maxLen = INT_MIN;

        int start = -1;

        int n = s.size();

        

        //initialisation

        bool table[n][n] = {false};

        maxLen = 1;

        start = 0;

        //length 1

        for(i=0;i<n-1;i++)

        {

            table[i][i] = true;

        }

        

        //length 2

        for(i=0;i<n-1;i++){

            if(s[i] == s[i+1]){

                table[i][i+1] = true;

                maxLen = 2;

                start = i;

            }

        }

        

        for(k=2;k<n;k++){

            for(i=0;i < n-k;i++){

                j = i + k;

                if(table[i+1][j-1] && s[i] == s[j]){

                    table[i][j] = true;

                    if(k +1 > maxLen ){

                        maxLen = k+1;

                        start = i;

                    }

                }

            }

        }

        return s.substr(start,maxLen);

    }

};
