var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
const num = pegarValores(lines.shift())
const numX = []

for (let i = 0; i < num.length; i++) {
    numX[i] = num[i]   
}
num.sort(ordenarNum)
for (let i = 0; i < num.length; i++) {
    console.log(num[i]);
    
}
console.log();
for (let i = 0; i < numX.length; i++) {
    console.log(numX[i]);
    
}

function ordenarNum(a, b) {
  return a > b ? 1 : a < b ? -1 : 0;
}
