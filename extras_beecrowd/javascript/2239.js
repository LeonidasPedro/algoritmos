var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n')

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [a, b, c] = pegarValores(lines.shift());
let saida = [];
saida =  b/c >= a ? 'S': 'N'
console.log(saida);

