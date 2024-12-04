class Solution {
public:
    static bool mycomparator(int a, int b) {
        string astr = to_string(a);
        string bstr = to_string(b);
        string p1 = astr + bstr;
        string p2 = bstr + astr;

        if (p1 > p2) {
            return true;
        } else {
            return false;
        }
    }
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), mycomparator);

        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        while(res.size()>1 && res[0]=='0'){
            res= res.substr(1);
        }
        return res;
    }
};