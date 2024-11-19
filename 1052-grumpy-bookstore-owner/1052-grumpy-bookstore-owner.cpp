class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res=0;
        int start = 0;
        int end = 0;
        int maxsum = 0;
        int sum = 0;
        for (int i = 0; i < minutes; i++) {
            sum = sum + customers[i]*grumpy[i];
        }
        if (sum > maxsum) {
            maxsum = sum;
            start = 0;
            end = minutes - 1;
        }
        int i = 0;
        int j = minutes - 1;
        int n = customers.size();
        while (j < n - 1) {
            j++;
            sum = sum + (customers[j]* grumpy[j]);
            sum = sum - (customers[i]* grumpy[i]);
            i++;
            if (sum > maxsum) {
                maxsum = sum;
                start = i;
                end = j;
            }
        }
        for (int i = 0; i < start; i++) {
            res = res + (customers[i] * (grumpy[i] == 1 ? 0 : 1));
        }
        for (int i = end + 1; i < n; i++) {
            res = res + customers[i] * (grumpy[i] == 1 ? 0 : 1);
        }

        for(int i=start;i<=end;i++){
            res= res + customers[i];
        }
        
        
        return res;
    }
}

;