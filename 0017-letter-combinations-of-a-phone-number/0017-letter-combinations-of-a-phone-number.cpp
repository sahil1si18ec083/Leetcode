class Solution {
public:
    void helper(string digits, vector<string>& result, int index, string temp,
                map<char, string> myMap) {
        if (index >= digits.size()) {
            result.push_back(temp);
            return;
        }
        string c = myMap[digits[index]];
        for (int i = 0; i < c.size(); i++) {
            // cout << myMap[digits[i]];

           
                temp.push_back(c[i]);
                helper(digits, result, index + 1, temp, myMap);
                temp.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {

        vector<string> result;
        map<char, string> myMap;
        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";

        if (digits.size() == 0)
            return result;
        int index = 0;
        string temp = "";

        helper(digits, result, index, temp, myMap);
        return result;
    }
};