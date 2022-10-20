var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));

let numEntradas = Number(lines.shift())
let a = 0, b = 0, c = 0, nota = 0;
for (let i = 0; i < numEntradas; i++) {
  [a, b, c] = pegarValores(lines.shift());
  nota = ((a*2) + (b*3) + (c * 5)) / 10;
  console.log(nota.toFixed(1));
}