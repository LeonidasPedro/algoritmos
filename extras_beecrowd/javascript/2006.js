var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a))
let cha = Number(lines.shift());
let nha = 0
let [a,b,c,d,e] = pegarValores(lines.shift())

if(cha == a){
    nha++
}
if(cha == b){
    nha++
}
if(cha == c){
    nha++
}
if(cha == d){
    nha++
}
if(cha == e){
    nha++
}
console.log(nha);