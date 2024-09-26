class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int n = people.size();
        sort(people.begin(), people.end());
        int i=0;
        int j= n-1;
        int count=0;
        while(i<=j){
            if(i==j){
                return count+1;
            }
            int weight = people[i]+ people[j];
            if (weight<=limit){
                i++;
                j--;
                count++;
            }
            else if (people[i]>people[j]){
                i++;
                count++;
            }
            else{
                j--;
                count++;
            }
        }
        return count;
        
    }
};