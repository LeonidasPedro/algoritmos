var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let num = lines.shift()
for(let i=num; i > 1; i--){
    num *= i - 1
}
console.log(num);