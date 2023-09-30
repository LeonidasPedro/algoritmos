var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let numEntradas = Number(lines.shift());
let a = 0
let b = 0
const pegarValores = (line) => line.split(" ").map(a => Number(a))
for(let i = 0;i < numEntradas; i++){
    [a, b] = pegarValores(lines.shift());
    if (b === 0){
        console.log("divisao impossivel")
    }else{
        console.log((a / b).toFixed(1))
    }
    
}