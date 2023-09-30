var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let resultado;
let entrada = lines.shift();
for (let i = 1; i < 11; i++){
    resultado = entrada * i
    console.log(`${i} x ${entrada} = ${resultado}`);
}
