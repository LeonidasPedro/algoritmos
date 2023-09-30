var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a))
let a = 0
let b = 0
let saida = ''
while(1 == 1) {
  [a, b] = pegarValores(lines.shift())
  if(a == b){return }
  saida = a > b ?  'Decrescente': 'Crescente' 
  console.log(saida)
}

