var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

 let segundos = Number(lines.shift());
 let h = 0;
 let resto = 0;
 let min = 0;
 let seg = 0;

 h = parseInt(segundos / 3600);
 resto = parseInt(segundos % 3600);
 min = parseInt(resto / 60) ;
 seg = parseInt(resto % 60);

console.log(`${h}:${min}:${seg}`);



