class Solution {
public:
    string reverse(string s){
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            temp+=s[i];
        }
        return temp;
    }
    string inverse(string binary){
        for (int i = 0; i < binary.length(); i++) {
        // Flip '0' to '1' and '1' to '0'
        if (binary[i] == '0') {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
    }
    return binary;
    }
    string solve(int n){
        if (n==1){
            string temp="0";
            return temp;
        }
        return solve(n-1)+"1"+reverse(inverse(solve(n-1)));
    }
    char findKthBit(int n, int k) {

        string s = solve(n);
        

        char result = s[k-1];
        return result;
        
    }
};