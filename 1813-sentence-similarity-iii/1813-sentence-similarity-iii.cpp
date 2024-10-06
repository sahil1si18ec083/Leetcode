class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1 == sentence2) {
            return true;
        }

        vector<string> v1;
        vector<string> v2;
        string temp = "";
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == 32) {
                v1.push_back(temp);
                temp = "";
            } else {
                temp = temp + sentence1[i];
            }
        }
        v1.push_back(temp);
        temp = "";
        for (int i = 0; i < sentence2.size(); i++) {
            if (sentence2[i] == 32) {
                v2.push_back(temp);
                temp = "";
            } else {
                temp = temp + sentence2[i];
            }
        }
        v2.push_back(temp);
        if(v1.size()<v2.size()){
            swap(v1,v2);
        }

        
        // check if sentence 2 is part of sentence 1
        int i = 0;
        int j = 0;
        int n1 = v1.size();
        int n2 = v2.size();
        

        while (i < n2 && v1[i] == v2[i]) {
            i++;
        }

        while (j < n2 && v1[n1 - 1 - j] == v2[n2 - 1 - j]) {
            j++;
        }

        if(i+j==n2){
            return true;
        }
        return false;
    }
};