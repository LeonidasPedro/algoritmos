var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));

let forget;
let forget2;
let soma = 0
let nha =''

while(true){
soma = 0;
	[forget, forget2] = pegarValores(lines.shift())
	if(forget <= 0 || forget2 <= 0 )break; 
	if(forget > forget2){
	let forgetAuxiliar = forget2
    	forget2= forget
    	forget = forgetAuxiliar
	}
	for (let i = forget; i <= forget2; i++) {
    nha += `${i} `
    soma += i
     
	}
console.log(`${nha}SUM=${soma}`);
nha = ''

}