var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [abas, numAcoes] = pegarValores(lines.shift())
let acoes = ''
for (let 
    i = 0; i < numAcoes; i++) {
    acoes = lines.shift()
    if(acoes == 'fechou'){
        abas++
    }else if(acoes == 'clicou'){
        abas--
    }
}
console.log(abas);