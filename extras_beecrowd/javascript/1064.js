var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let positivos = [];
let entradas = 0
for (let index = 0; index < 6; index++) {
    entradas = Number(lines.shift())
    if(entradas > 0){
        positivos.push(Number(entradas))
    }    
}
let soma = 0
for (let i = 0; i < positivos.length; i++) {
    soma += positivos[i]
    
}
let media = soma / positivos.length
console.log(`${positivos.length} valores positivos`);
console.log(media.toFixed(1));