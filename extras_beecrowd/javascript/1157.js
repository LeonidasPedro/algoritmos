var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n')

//const pegarValores = (line) => line.split(" ").map(a => Number(a));
let entrada = Number(lines.shift())
let divisor = 0
for (let i = 1; i <= entrada; i++) {
	if (entrada % i === 0) {
    divisor = i
		console.log(divisor);   
    }
}