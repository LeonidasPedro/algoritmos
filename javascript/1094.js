var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => a);
let c = 0;
let r = 0;
let s = 0;
let cx = 0;
let rx = 0;
let sx = 0;
let num = '';
let tipo = '';
let total = 0;
let numEntradas = Number(lines.shift());

for (let i = 0; i < numEntradas; i++) {
  [num, tipo] = pegarValores(lines.shift());
  num = Number(num);
  total += num
  switch (tipo) {
    case 'C':
      c += num;
      break;
    case 'R':
      r += num;
      break;
    case 'S':
      s += num;
      break;
  }
  num = '',
  tipo = '' 
  cx = (c*100)/total
  rx = (r*100)/total
  sx = (s*100)/total
}
  console.log(`Total: ${total} cobaias`);
  console.log(`Total de coelhos: ${c}`);
  console.log(`Total de ratos: ${r}`);
  console.log(`Total de sapos: ${s}`);
  console.log(`Percentual de coelhos: ${cx.toFixed(2)} %`);
  console.log(`Percentual de ratos: ${rx.toFixed(2)} %`);
  console.log(`Percentual de sapos: ${sx.toFixed(2)} %`);
