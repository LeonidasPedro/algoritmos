var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [a, b, c] = pegarValores(lines.shift());
let per = 0;
let area = 0;

if (a < b + c && b < a + c && c < a + b)
    {
        per = a + b + c;
        console.log(`Perimetro = ${per.toFixed(1)}`);
    }
    else
    { 
        area = c * (a + b) / 2;
        console.log(`Area = ${area.toFixed(1)}`);
    }