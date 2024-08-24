/**
 * @param {number[][]} mat
 * @param {number[][]} target
 * @return {boolean}
 */
var findRotation = function (mat, target) {
    function checktwomatrix(first,second){
        if (first.length!=second.length){
            return false;
        }
        for(let i=0;i<first.length;i++){
            for(let j=0;j<first[0].length;j++){
                if (first[i][j]!= second[i][j]){
                    return false
                }
            }
        }
        return true
    }
    function rotate(mat){
        for(let i=0;i<mat.length;i++){
            for(let j=i;j<mat.length;j++){
                let temp = mat[i][j];
                mat[i][j]= mat[j][i];
                mat[j][i]= temp;
            }
        }
        for(let i=0;i<mat.length;i++){
            let j=0;
            let k=mat.length-1;
            while(j<=k){
                let temp = mat[i][j];
                mat[i][j]= mat[i][k];
                mat[i][k]= temp;

                j++;
                k--;
            }
        }
        return mat
    }
    let zeroscountmat = 0;
    let onescountmat = 0;
    let zeroscounttarget = 0;
    let onescounttarget = 0;
    const n = mat.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                zeroscountmat++;
            }
            if (mat[i][j] == 1) {
                onescountmat++;
            }
            if (target[i][j] == 0) {
                zeroscounttarget++;
            }
            if (target[i][j] == 1) {
                onescounttarget++;
            }
        }
    }
    if ((zeroscountmat != zeroscounttarget) || (onescounttarget != onescountmat)) {
        return false
    }

    let firstrotate = rotate(mat);
    if (checktwomatrix(firstrotate, target)) {
        return true;
    }
    let secondrotate = rotate(firstrotate);
    if (checktwomatrix(secondrotate, target)) {
        return true;
    }
    let thirdrotate = rotate(secondrotate);
    if (checktwomatrix(thirdrotate, target)) {
        return true;
    }
     let fourthrotate = rotate(thirdrotate);
    if (checktwomatrix(fourthrotate, target)) {
        return true;
    }
   
    return false;


};