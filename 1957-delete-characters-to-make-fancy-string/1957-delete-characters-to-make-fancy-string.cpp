class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int i=1;
        int j=2;
        while(j<n){
            if(s[j]==s[i] && s[j]==s[i-1]){
                j++;
            }
            else{
                i++;
                s[i]=s[j];
                j++;
            }

        }
        return s.substr(0,i+1);
        
    }
};