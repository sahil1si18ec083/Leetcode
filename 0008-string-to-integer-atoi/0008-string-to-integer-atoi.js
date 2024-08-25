/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    let result=0;
    let signpositive = true;
    if(s.length==0){
        return 0;
    }
    while(s[0]==" "){
        s= s.slice(1)
    }
    console.log(s)

    for(let i=0;i<s.length;i++){
        if (s[i]=="-"){
            if (i==0){
            signpositive= false
            }
            else{
               break
            }
        }
        else if (s[i]=="0" && result==0 ){
            continue;
        }
          else if (s[i]=="+"  ){
            if (i!=0){
                break
            }
            continue;
        }
        else if (s.charCodeAt(i)>=48 && s.charCodeAt(i)<=57 ){
            
            result = result * 10 + (s.charCodeAt(i)-48);
            let resultwithsign = signpositive? result : result*-1;
            if (resultwithsign>Math.pow(2,31)-1){
                return Math.pow(2,31)-1
            }
            if (resultwithsign<-Math.pow(2,31)){
                return -Math.pow(2,31)

            }
        }
        else{
            break;
        }

    }

   return (signpositive?result:result*-1)



    
};