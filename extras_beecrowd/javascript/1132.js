var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let forget = Number(lines.shift())
let forget2 = Number(lines.shift())
let soma = 0

if(forget > forget2){
    letforgetAuxiliar = forget2
    forget2= forget
    forget = forgetAuxiliar
}
for (let i = forget; i <= forget2; i++) {
   if (i % 13 !== 0) {
    soma += i
   }    
}
console.log(soma);
