var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a))
let a = 0
let b = 0 
while(1 == 1){
    [a, b] = pegarValores(lines.shift())
    if(a === 0 || b === 0)break;
    if (a >=0 && b >=0){
        console.log("primeiro");
    }else if(a < 0 && b < 0){
        console.log("terceiro");
    }else if(a > -1 && b < 0){
        console.log("quarto");
    }else{
        console.log("segundo");
    }

}