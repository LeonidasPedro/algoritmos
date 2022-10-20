var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n')



let entrada = pegarValores(lines.shift());
for (let index = 0; index < lines.length; index++) {
    
    console.log(entrada);

    
}
