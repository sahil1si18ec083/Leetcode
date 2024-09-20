/**
 * @param {number[]} dist
 * @param {number} hour
 * @return {number}
 */
var minSpeedOnTime = function(dist, hour) {
function fun(mid, dist, hour) {
      let totalhours = 0;
      for (let i = 0; i < dist.length - 1; i++) {
          totalhours = totalhours + Math.ceil(dist[i] / mid);

      }
      totalhours = totalhours + (dist[dist.length-1] / mid);
     
      return totalhours
  }
  const n = dist.length;
  let low = 1;
  let high = 10000000;
  console.log(high)
  let res = -1;
  while (low <= high) {
      let mid = Math.floor((low + high) / 2);
     
          let calculatehours = fun(mid, dist, hour);
           
          if (calculatehours <= hour) {
              res = mid;
              high = mid - 1;
          }
          else {
              low = mid + 1;

          }

     

  };
   return res;
    
};