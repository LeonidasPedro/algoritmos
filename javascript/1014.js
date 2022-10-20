/*#include <stdio.h>
 
int main() {
 
    int km;
    float totalLitros, kmLtro;
    scanf("%d %f", &km, &totalLitros);
    kmLtro = km / totalLitros;
    printf("%.3f km/l\n", kmLtro);
 
    return 0;
}*/
var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let km = Number(lines.shift());
let totalLitros = Number(lines.shift());
let kmLitro = km / totalLitros;
console.log(`${kmLitro.toFixed(3)} km/l`);


