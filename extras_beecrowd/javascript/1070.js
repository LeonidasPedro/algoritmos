var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let num = Number(lines.shift())
let i =0;
while(i < 6){
    if(num % 2 !== 0){
        console.log(num);
        i++
    }
    num++
}