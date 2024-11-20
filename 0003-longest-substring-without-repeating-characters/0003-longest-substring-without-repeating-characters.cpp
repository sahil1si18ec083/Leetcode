class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<2) return n;

        int i=0;
        int j=0;
        int maxlength =0;
        map<int, int>mymap;

        while(j<n){

            while(mymap.find(s[j])!=mymap.end()){
                mymap[s[i]]--;
                if(mymap[s[i]]==0){
                    mymap.erase(s[i]);
                }
                i++;
            }
            mymap[s[j]]++;
            maxlength= max(maxlength, j-i+1);
            j++;

        }
        return maxlength;
    }
};