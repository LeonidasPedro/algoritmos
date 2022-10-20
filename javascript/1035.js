
var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');
const pegarValores = (line) => line.split(" ").map(a => Number(a));

let [a, b, c, d] = pegarValores(lines.shift());

if (b > c && d > a && c > 0 && d > 0 && (c + d) > (a + b) && a % 2 == 0) {
    console.log("Valores aceitos");
} else { 
    console.log("Valores nao aceitos");
}