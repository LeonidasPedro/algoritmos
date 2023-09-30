var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let num = Number(lines.shift());
for(let i=1; i <= num; i++){
    console.log(`${i} ${i*i} ${i*i*i}`);
}
