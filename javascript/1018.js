var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');


let valor = Number(lines.shift());
console.log(valor);

let notas = [100, 50, 20, 10, 5, 2, 1];

notas.forEach(nota =>{
    let qtdCedulas = parseInt(valor/nota);
    console.log(`${qtdCedulas} nota(s) de R$ ${nota},00`);
    valor = valor % nota;
})
