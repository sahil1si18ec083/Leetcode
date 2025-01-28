class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        vector<int> result(n, 0);
        int i=1;
        int j =0;
        while(candies >0){
            result[j%n]+=min(candies,i);
            candies = candies  - i;
            i++;
            j++;

        }
        return result;
        
    }
};