class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorsum=0;
        for(int i=0;i<derived.size();i++){
            xorsum= xorsum ^ derived[i];
        }
        if(xorsum==0) return true;

        return  false;
        
    }
};