class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        // left aur right part ko jodkar   miniumum size banana 

        // toh bich vale part ko (sum-x) ko maxium size ka bana do


        int totalsum =0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            totalsum +=nums[i];
        }

        int i=0;
        int j=0;
        int sum =0;

        int maxsize=INT_MIN;

        while(j<n){
            sum+= nums[j];

            while(sum>totalsum-x){
                sum = sum - nums[i];
                i++;
            }
            cout<<sum<<endl;

            if(sum == totalsum-x){
                
                maxsize= max(maxsize, j-i+1);
            }
            j++;

        }
        if(maxsize==INT_MIN) return -1;

        return (n-maxsize );

        
    }
};