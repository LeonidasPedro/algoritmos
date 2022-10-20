var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let entrada = lines.shift()

for (let i = 1; i <= entrada; i++) {
    if(!(i % 2 === 0)){console.log(i);} 
}
