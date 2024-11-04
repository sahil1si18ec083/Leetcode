class Solution {
public:
    string compressedString(string word) {
        string comp="";
        char ch= word[0];
        int n = word.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                count++;
            }
            else{

                int rem = count%9;
                int factor = count/9;
                if(factor>0){
                    int n = 9;
                    for(int i=1;i<=factor;i++){
                        comp+= to_string(n)+ch;
                    }
                }
                if(rem>0){
                    comp += to_string(rem)+ch;
                }
                ch= word[i];
                count=1;
            }
        }
        if(count>0){
            int rem = count%9;
                int factor = count/9;
                if(factor>0){
                    int n = 9;
                    for(int i=1;i<=factor;i++){
                       comp+= to_string(n)+ch;
                    }
                }
                if(rem>0){
                    comp += to_string(rem)+ch;
                }
        }
        return comp;
        
    }
};