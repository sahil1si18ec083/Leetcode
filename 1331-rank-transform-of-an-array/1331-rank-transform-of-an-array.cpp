class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp;
        map<int, int> mapping;
        for (int i = 0; i < arr.size(); i++) {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        mapping[temp[0]] = 1;
        int count = 1;
        int val = temp[0];
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] == val) {
                mapping[val]= count;

            } else {
                count++;
                val = temp[i];
                mapping[val]= count;

            }
        }
        for(int i=0;i<arr.size();i++){
            if(mapping.find(arr[i])!=mapping.end()){
                
                arr[i]= mapping[arr[i]];
            }
        }
        return arr;
    }
};