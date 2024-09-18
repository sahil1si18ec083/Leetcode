/**
 * @param {number} num
 * @return {number}
 */
var smallestNumber = function (num) {
    if (num==0) return 0;
    let isnegative = false;
    const arr = []
    if (num < 0) {
        isnegative = true;
        num = - num;
    }

    while(num!=0){
        arr.push(num%10)
        num=Math.floor( num/10);
    }


    if (isnegative==true){
        arr.sort((a,b)=>b-a)
    }


    else{
        arr.sort((a,b)=>a-b)
        let countzeros=0
        if (arr[0]==0){
            haszero=true;
        }
        let firstnonzeroindex;
        if (haszero==true){
            for(let i=0;i<arr.length;i++){
                if (arr[i]==0){
                    countzeros++;
                }
                else{
                    firstnonzeroindex=i;
                    break;
                }
            }
            arr[0]= arr[firstnonzeroindex]
            for(let j=1;j<=countzeros;j++){
                arr[j]=0;
            }


        }

    }
    
    var result =0;
    for(let i=0;i<=arr.length-1;i++){
        result = result * 10 + arr[i]
    }
    return (isnegative?result*-1: result)

};