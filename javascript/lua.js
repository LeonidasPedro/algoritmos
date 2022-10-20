var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');
const getValues = (line) => line.split(" ").map(a => Number(a));

let [a, b] = getValues(lines.shift());
if (a > b) {
  if (b <= 96 && b >= 3) {
    console.log("minguante");
  }else if(b >= 97 && b <= 100){
    console.log('cheia');
  }else{
    console.log('nova');
  }
} else {
  if (b >= 0 && b <= 2) {
    console.log("nova");
  } else if (b <= 96 && b >= 3) {
    console.log("crescente");
  } else {
    console.log('cheia');
  }
}
