class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int index =0;
        int value =1;
        int oldk=k;
        while(index <n && k>0){
            if (arr[index]== value){
                index++;
                value++;
            }
            else{
                value++;
                k--;
            }
        }
       
        if(k>0){
            int diff = arr[n-1]- n;
            return arr[n-1] - diff + oldk;
        }
        return value-1;
    }
};