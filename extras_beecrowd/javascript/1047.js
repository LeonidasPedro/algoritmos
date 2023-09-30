var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));
let [hi, mi, hf, mf ] = pegarValores(lines.shift());

mi += hi*60
mf += hf*60
tempo = mf-mi

if (tempo<=0){
  tempo += 24*60}
h = tempo/60
m = tempo%60

console.log(`O JOGO DUROU ${Math.floor(h)} HORA(S) E ${m} MINUTO(S)`);