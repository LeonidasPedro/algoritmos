var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');
//const pegarValores = (line) => line.split(" ").map(a => Number(a));

let valor = Number(lines.shift());
console.log("NOTAS:");

let notas = [100, 50, 20, 10, 5, 2];
let moedas = [1,0.50,0.25,0.10,0.05,0.01]

notas.forEach(nota =>{
    let qtdCedulas = parseInt(valor/nota);
    console.log(`${qtdCedulas} nota(s) de R$ ${nota},00`);
    valor = valor % nota;   
})

console.log("MOEDAS:");

moedas.forEach(moeda =>{
    let qtdMoedas = parseInt(valor/moeda);
    console.log(`${qtdMoedas} moeda(s) de R$ ${moeda.toFixed(2)}`);
    valor = valor % moeda;
})