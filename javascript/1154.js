
var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');
let num = 0;
let cont = 0;
let nha = 0;
let forget = 0
while(true){

    num = Number(lines.shift());
    if(num < 0)break;
    cont++
    nha += num
}
forget = nha / cont
console.log(forget.toFixed(2));
