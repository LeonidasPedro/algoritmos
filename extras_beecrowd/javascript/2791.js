var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n')

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [a, b, c, d] = pegarValores(lines.shift());
if(a === 1)console.log(1)
if(b === 1)console.log(2)
if(c === 1)console.log(3)
if(d === 1)console.log(4)