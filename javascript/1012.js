var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));

let [a, b, c] = pegarValores(lines.shift());
//lines shift pega o primeiro valor de uma array e retorna para a função (3.0 4.0 5.2)
//pegar valores é a função que separa os valores da linha pelo "line.split(" ")"

let triangle, trapezium, circle, square, rectangle;
    triangle = a * c / 2;
    circle = 3.14159 * c * c;
    trapezium = (a + b) * c / 2;
    square = b * b;
    rectangle = a * b;
console.log(`TRIANGULO: ${triangle.toFixed(3)}`);
console.log(`CIRCULO: ${circle.toFixed(3)}`)
console.log(`TRAPEZIO: ${trapezium.toFixed(3)}`);
console.log(`QUADRADO: ${square.toFixed(3)}`);
console.log(`RETANGULO: ${rectangle.toFixed(3)}`);
