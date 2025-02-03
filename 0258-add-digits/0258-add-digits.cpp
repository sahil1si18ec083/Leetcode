class Solution {
public:
    int helper(int n){
        int sum =0;
        while(n!=0){
            sum = sum + n%10;
            n = n/10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num<10) return num;
        int val =0;

        while(num>9){

            num = helper(num);

        }
        return num;
        
    }
};