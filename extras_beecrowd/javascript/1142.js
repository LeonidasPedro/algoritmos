var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let numLinhas = Number(lines.shift());
let nha = [];
let num = 0;
let log = '';
for (let i = 0; i < numLinhas; i++) {
  for (let j = 0; j < 3; j++) {
    num++
    nha.push(num)
  }
  nha.push("PUM")
  num ++
  log = nha.join(" ")
  console.log(log);
  nha = []
}