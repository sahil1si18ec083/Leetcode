class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long  result =0;
        for(int i=0;i<32;i++){
            int setsbits_at_i_th_position =0;
            for(auto num: nums){
                int mask = 1 << i;
                int val = mask & num;
                if(val!=0){
                    setsbits_at_i_th_position++;
                }
            }
            setsbits_at_i_th_position = setsbits_at_i_th_position % 3;
            if(setsbits_at_i_th_position==0){
                continue;
            }
            result = result + pow(2,i);

        }
        return result;
        
    }
};
