var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let salario = Number(lines.shift())
if (salario < 2000.01) {
    console.log("Isento");
}else if (salario >= 2000.01 && salario <= 3000.00){
    console.log(`R$ ${((salario.toFixed(2)-2000)*0.08).toFixed(2) }`);
}else if (salario >= 3000.01 && salario <= 4500.00){
    console.log(`R$ ${((salario.toFixed(2)-3000)*0.18 + 1000*0.08).toFixed(2) }`);
}else if (salario >= 4500.01){
    console.log(`R$ ${((salario.toFixed(2)-4500)*0.28 + 1500*0.18 + 1000*0.08).toFixed(2) }`);
}