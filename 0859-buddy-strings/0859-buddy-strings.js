/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var buddyStrings = function(s, goal) {

    if(s.length!= goal.length){
        return  false;
    }

    if (s==goal){
      

        const map = new Map();
        for(let i=0;i<s.length;i++){
            if(map.has(s[i])){
                return true
            }
            else{
                map.set(s[i],0)
            }
        }
      return false
    }
    else{
        let countofdifference =0;
        console.log({countofdifference})
        const x=[]
        for(let i=0;i<s.length;i++){
            if(s[i]!=goal[i]){
                countofdifference++;
                x.push(i)
            }
        }
        console.log({countofdifference})
        if (countofdifference==2 && s[x[0]]== goal [x[1]] && s[x[1]]== goal [x[0]]){
            return true
        }
        else{
            return false
        }
    }
    
};