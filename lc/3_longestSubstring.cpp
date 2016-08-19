#define CHAR_SET 256



class Solution {

public:

    int occurence[CHAR_SET];

    

    int lengthOfLongestSubstring(string s) {

        if(!s.size())

            return 0;

            

        int i,len=0;

        int maxLen = INT_MIN;

        for(i=0;i<CHAR_SET;i++)

            occurence[i] = -1;

        int start,end;

        start = end = 0;

        occurence[s[0]] = 0;

        for(i=1;i< s.size();i++){

            if( occurence[s[i]] < start ){

                occurence[s[i]] = i;

            }

            else{

                start = occurence[s[i]]+1;

                occurence[s[i]] = i;

            }

            len = i-start+1;

            //cout<<start<<" "<<i<<endl;

            if( len > maxLen )

                maxLen = len;

            

        }

        len = i-start;

            //cout<<start<<" "<<i<<endl;

            if( len > maxLen )

                maxLen = len;

        return maxLen;

    }

};
