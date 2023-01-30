const internal = require('stream');

var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let golsI = 0;
let golsG = 0;
let empates = 0;
let vitI = 0;
let vitG = 0;
let win = ''
let cont = 0
let novo = 1
const pegarValores = (line) => line.split(" ").map(a => Number(a))

while (novo == 1) {
    cont++
    [golsI, golsG] = pegarValores(lines.shift())
    if (golsI == golsG){
        empates++
    }else if(golsI > golsG){
        vitI++
    }else if(golsI < golsG){
        vitG++
    }
    console.log("Novo grenal (1-sim 2-nao)")
    novo = lines.shift();
}
console.log(`${cont} grenais`);
console.log(`Inter:${vitI}`);
console.log(`Gremio:${vitG}`);
console.log(`Empates:${empates}`);
if(vitG === 0 && vitI === 0){
    console.log("Nao houve vencedor");
}else{
    win = vitI > vitG ? 'Inter' : 'Gremio'
   console.log(`${win} venceu mais`);
}
