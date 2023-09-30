var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let a = Number(lines.shift());
let b = Number(lines.shift());
let soma = 0
if (a < b) {
    for (let i = a + 1; i < b; i++) {
        if (i % 2 !== 0) {
            soma += i;
        }
    }
} else {
    for (let i = b + 1; i < a; i++) {
        if (i % 2 !== 0) {
            soma += i;
        }
    }
}
console.log(soma);