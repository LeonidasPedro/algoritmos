var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

  
    let num = Number(lines.shift());
    let horas = Number(lines.shift());
    let valorhora = Number(lines.shift());
    let salario = valorhora * horas;  
    
    console.log(`NUMBER = ${num}`);
    console.log(`SALARY = U$ ${salario.toFixed(2)}`);