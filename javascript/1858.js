
var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');



const pegarValores = (line) => line.split(" ").map(a => Number(a));
let numEntradas = 0 
numEntradas = Number(lines.shift())
let a = []
for (let i = 0; i < numEntradas; i++){


   a = pegarValores(Number(lines.shift()))
   
}