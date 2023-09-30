var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [a, b, c] = pegarValores(lines.shift());

let maiorAB = (a + b + Math.abs(a-b)) / 2;

if(maiorAB < c){
    console.log(`${c} eh o maior`);
}else if(maiorAB == b){
    console.log(`${b} eh o maior`);
}else if(maiorAB == a){
    console.log(`${a} eh o maior`);
}