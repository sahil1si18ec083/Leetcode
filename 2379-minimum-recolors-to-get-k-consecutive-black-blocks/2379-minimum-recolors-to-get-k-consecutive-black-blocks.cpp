class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // fixed window
        int mincount=INT_MAX;
        int whitecount=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                whitecount++;
            }

        }
        mincount= min(mincount, whitecount);
        int i=0;
        int j=k-1;
        int n = blocks.size();
        while(j<n-1){
            if(blocks[i]=='W'){
                whitecount--;
            }
            i++;
            j++;
            if(blocks[j]=='W'){
                whitecount++;
            }
            mincount= min(mincount, whitecount);
        }
        return mincount==INT_MAX?0:mincount;
        
    }
};