class Solution {
public:
    int minChanges(string s) {
        int count=1;
        int n = s.size();
        int correction=0;
        int i=1;

        while(i<n){
            if(s[i]==s[i-1]){
                count++;
                i++;
            }
            else{
                if(count%2==1){
                    // count odd hai then we need a coreection
                    correction++;
                    i=i+2;
                    count=1;
                }
                else{
                    i=i+1;
                    count=1;

                }


            }

        }
        return correction;
        
    }
};