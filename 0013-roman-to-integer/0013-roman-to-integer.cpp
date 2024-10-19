class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mapping;
        int sum = 0;
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;
        int i = 0;
        int n = s.size();
        while (i < n) {
            if (i < n - 1 && mapping[s[i]] < mapping[s[i + 1]]){
                sum +=( mapping[s[i + 1]] - mapping[s[i]] );
                i+=2;
            }
            else{
                sum +=mapping[s[i]] ;
                i+=1;
            }
        }
        return sum;
    }
};