var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

/*
#include <stdio.h>
 
int main() {
 
    double A, R;
    scanf("%lf", &R);
    A = 3.14159 * R * R;
    printf("A=%.4lf", A);
    printf("\n");
   
    return 0;
}
 */

let A 
let R = Number(lines.shift());
    A = 3.14159 * R * R;

console.log(`A=${A.toFixed(4)}`);