var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let N = lines.shift();
for (let i = 1; i <= N; i++) {
    if (i % 2 == 0) console.log(i + "^2 = " + (i * i));
}


    	
    	