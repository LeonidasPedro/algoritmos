var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let maior = 0;
let posicao = 0;
let num = 0
for (let i = 1; i < 101; i++){
    num = Number(lines.shift());
    if (num > maior) {
        maior = num;
        posicao = i
    }
}
console.log(maior);
console.log(posicao);