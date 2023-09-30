var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let entrada = 0;
let pares = []
for (let i = 0; i < 5; i++) {
    entrada = lines.shift()
    if (entrada % 2 === 0){
        pares.push(entrada)
    }
}
console.log(`${pares.length} numeros pares`);