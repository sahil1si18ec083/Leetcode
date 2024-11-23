class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;

        if(arr[0]>arr[1]) return 0;

        if(arr[n-1]> arr[n-2]) return (n-1);

        int low=0;
        int high = n-1;
        while(low<=high){
            int mid =(low+high)/2;

            if( (mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1])){
                return mid;
            }
            else if ((mid==0 || arr[mid]>arr[mid-1])){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};