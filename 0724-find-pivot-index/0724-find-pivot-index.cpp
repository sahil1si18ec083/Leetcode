class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int leftsum=0;
    
        int sum=0; int n= arr.size();
        if(n<3){
            return -1;
        }
        for(int i=0;i<n;i++){
            sum +=arr[i];
        }
        leftsum = leftsum ;
        int rightsum = sum - arr[0];
        int i=0;
        while(i<=n-2){
            if(leftsum == rightsum){
                return i;
            }
            leftsum = leftsum +arr[i];
            rightsum= rightsum-arr[i+1];
            i++;
        }
        if(leftsum == rightsum){
                return i;
            }
        return -1;

        
    }
};