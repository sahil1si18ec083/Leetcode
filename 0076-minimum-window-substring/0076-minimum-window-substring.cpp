class Solution {
public:
    string minWindow(string s, string t) {

        int start=-1;
        int minlength = INT_MAX;
        int n = s.size();
        map<int, int>tmapping;

        // create a mapping of characters of t
        for(int i=0;i<t.size();i++){
            tmapping[t[i]]++;
        }

        int makezeroscount = tmapping.size();
        int i=0;
        int j=0;
        while(j<n){
            if(tmapping.find(s[j])!=tmapping.end() ){
                 tmapping[s[j]]--;
                 if (tmapping[s[j]]==0){
                    makezeroscount--;
                 }
            }
            while(makezeroscount==0){
                // shrink karo kyu ki mujay mil chuka hai meri window
                int size = j-i+1;
                if(size<minlength){
                    minlength= size;
                    start=i;
                }
                if(tmapping.find(s[i])!=tmapping.end() ){
                 tmapping[s[i]]++;
                 if (tmapping[s[i]]==1){
                    makezeroscount++;
                 }
            }
            i++;

            }
            j++;

        }

        if(minlength==INT_MAX) return "";

        return s.substr(start,minlength );
        
    }
};