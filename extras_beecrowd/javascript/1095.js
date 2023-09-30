var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let I = 1;
let J = 60;
console.log(`I=${I} J=${J}`);
for(let i = 0; i < 3; i++){
    I += 3;
    J -= 5;
    console.log(`I=${I} J=${J}`);
}
