var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a))
let a = 0, b = 0
let soma = 0
let numEnradas = Number(lines.shift())
for (let i = 0; i < numEnradas; i++) {
  [a, b] = pegarValores(lines.shift())
  if (a < b) {
    for (let i = a + 1; i < b; i++) {
        if (i % 2 !== 0) {
            soma += i;
        }
    }
} else {
    for (let i = b + 1; i < a; i++) {
        if (i % 2 !== 0) {
            soma += i;
        }
    }
}
console.log(soma);
soma = 0
}
   