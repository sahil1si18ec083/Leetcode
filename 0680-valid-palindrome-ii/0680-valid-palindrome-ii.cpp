class Solution {
public:
    bool checkpallindrome(int i, int j, string s){
        while(j>i){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {

        int n = s.size();
        int i=0;
        int j= n-1;
        while(j>i){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                bool possibility1 = checkpallindrome(i+1,j,s);
                bool possibility2= checkpallindrome(i,j-1,s);
                return (possibility1 || possibility2);
            }
        }
        return true;
        
    }
};