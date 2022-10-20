//distancia
var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let distancia = Number(lines.shift())
distancia *= 2
console.log(`${distancia} minutos`);
