var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [a, b] = pegarValores(lines.shift());
let time = 0;
if(a<b){
    time=b-a}
else{
    time=b+24-a}
console.log(`O JOGO DUROU ${time} HORA(S)`);