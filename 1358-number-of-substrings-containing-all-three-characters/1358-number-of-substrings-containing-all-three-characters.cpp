class Solution {
public:
    int numberOfSubstrings(string s) {

        int count=0;
        int n = s.size();
        int i=0;
        int j=0;
        
        unordered_map<int, int>myMap;

        while(j<n){
            myMap[s[j]]++;
            while(myMap.size()==3){
                // window invalid ho gayi hai
                count = count + (n-j);
                myMap[s[i]]--;
                if(myMap[s[i]]==0){
                    myMap.erase(s[i]);
                }
                i++;
            }
            j++;
        }

        return count;
        
    }
};