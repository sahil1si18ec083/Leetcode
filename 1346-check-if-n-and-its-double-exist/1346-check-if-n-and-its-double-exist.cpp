class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        map<int,int>hashmap;
        int n = arr.size();
        for(int i=0;i<n;i++){
            
            hashmap.insert({arr[i],i});
        }
        for(int i=0;i<n;i++){
            if(hashmap.find(arr[i]*2)!=hashmap.end()){
               
                if(hashmap[arr[i]*2]!=i){
                    return true;
                }
                
            }
        }
        return false;
        
    }
};