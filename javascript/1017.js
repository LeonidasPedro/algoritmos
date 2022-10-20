//Gasto de Combustível
var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

var tempo = Number(lines.shift())
var velocidade = Number(lines.shift())

let km =  velocidade * tempo;
km /= 12;
console.log(`${km.toFixed(3)}`);