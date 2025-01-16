class Solution {
public:
    int count_setbits(int n) {
        int c = 0;
        while (n != 0) {
            int val = n & 1;
            if (val != 0) {
                c++;
            }
            n = n >> 1;
        }
        return c;
    }
    int calculate_ith_bit(int i, int num) {
        int val = num;
        val = val >> i;
        int check = val & 1;
        if (check == 0) {
            return 0;
        }
        return 1;
    }
    int minimizeXor(int num1, int num2) {
        // let  us first calculate the number of set bits in nums 2
        int setbitsnum2 = count_setbits(num2);
        int unsetbitsnums2 = 32 - setbitsnum2;
        int res = 0;
        int setbits = 0;
        int zerosbits = 0;
        bool zerosoverflow = false;
        bool onesoveflow = false;

        for (int i = 31; i >= 0; i--) {
            // 32 times we will iterate because number can  be max of 32 bits
            if(zerosoverflow==true){
                res = res + pow(2,i);
                continue;
            }
             if(onesoveflow==true){
                continue;
            }


            int bitvalue = calculate_ith_bit(i, num1);

            if (bitvalue == 0) {
                zerosbits++;
            } else {
                setbits++;
                res = res + pow(2,i);
            }
            if (zerosbits == unsetbitsnums2) {
                zerosoverflow = true;
            }
            if (setbitsnum2 == setbits) {
                onesoveflow = true;
            }
        }
        return res;
    }
};