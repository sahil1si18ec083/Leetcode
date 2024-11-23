class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();    // 3
        int n = box[0].size(); // 6
        vector<vector<char>> temp(n, vector<char>(m, '.'));

        for (int i = 0; i <= n - 1; i++) {
            for (int j = m - 1; j >= 0; j--) {
                temp[i][m - 1 - j] = box[j][i];
            }
        }


        for (int i = 0; i < m; i++) {
            int obstacle = n;
            int bluecount = 0;

            for (int j = n - 1; j >= 0; j--) {
                if (temp[j][i] == '.' || temp[j][i]=='#') {
                    if (temp[j][i] == '#') {
                        bluecount++;
                    }

                } else {
                   
                    int diff =  obstacle - j-1;
                    int newpos= obstacle-1;
                    for (int k = 0; k < bluecount; k++) {
                        temp[newpos][i] = '#';
                        newpos--;
                    }
                    for (int k = bluecount; k < diff; k++) {
                        temp[newpos][i] = '.';
                        newpos--;
                    }
                    obstacle = j;
                    bluecount=0;
                }
            }
            if(bluecount==0){
                continue;
            }
            int j= obstacle - 1;
            int diff= obstacle ;
            for(int k=0;k<bluecount;k++){
                temp[j][i]='#';
                j--;
            }
            for(int k=bluecount;k<obstacle;k++){
                temp[j][i]='.';
                j--;
            }

           
        }
        return temp;
    }
};