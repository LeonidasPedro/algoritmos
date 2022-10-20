var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let numEntradas = lines.shift();
let entrada = 0;
let contIn = 0;
let contOut = 0;

for(let i = 0; i < numEntradas; i++){
    entrada = lines.shift();
    if (entrada >= 10 && entrada <= 20){
        contIn++;
    }else{
        contOut++;
    }

}
console.log(`${contIn} in`);
console.log(`${contOut} out`)