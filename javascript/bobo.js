var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let contLines = 0
contLines = Number(lines.shift())
let ganhou = ''
let candidatos = []
let maisVotado = {
  'posicao':0,
  'contVotos':0
}
for (let i = 0; i < contLines; i++){
  candidatos[i] = Number(lines.shift())
  if(candidatos[i] > maisVotado.contVotos){
    maisVotado.contVotos = candidatos[i]
    maisVotado.posicao = i;
  }
}
if(maisVotado.posicao === 0){
  ganhou = "S"
}else{
  ganhou = "N"
}
console.log(ganhou);

