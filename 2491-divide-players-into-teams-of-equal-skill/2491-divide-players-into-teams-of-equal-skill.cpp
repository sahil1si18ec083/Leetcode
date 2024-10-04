class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long int chemistry = 0;
        int n = skill.size();
        int target = skill[0]+ skill[n-1];
        int i=0;
        int j=n-1;
        while(i<j){
            if (skill[i]+ skill[j]!=target){
                return -1;

            }
            chemistry= chemistry + skill[i]* skill[j];
            i++;
            j--;

        }
        return chemistry;
        
    }
};