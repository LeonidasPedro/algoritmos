var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const  pegarValores = (line) => line.split(" ").map(a => Number(a));
let numVariaveis = Number(lines.shift());
let num = 0
let [par, positivo] = ''
let saida = []
for (let i = 0; i < numVariaveis; i++){
        num = Number(lines.shift())
        if(num === 0){
            console.log('NULL')  
        } else{
            positivo = num >= 0 ?  'POSITIVE' : 'NEGATIVE'
            par = num % 2 == 0 ? 'EVEN' : 'ODD'
            console.log(`${par} ${positivo}`)
        }
    }



