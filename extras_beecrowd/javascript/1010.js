var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));//coloca os valores de uma linha em um array
let [codUm, qtd1, preco1] = pegarValores(lines.shift())//lines shift pega o primeiro valor de uma array e retorna para a função (12 1 5.30)
let [codDois, qtd2, preco2] = pegarValores(lines.shift())//pegar valores é a função que separa os valores da linha pelo "line.split(" ")"

let total = qtd1 * preco1 + qtd2 * preco2;
console.log(`VALOR A PAGAR: R$ ${total.toFixed(2)}`);
