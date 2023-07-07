
/*
Uma jardineiro tem um monte de pedaços de granito em forma de paralelepípedo e quer formar uma escultura empilhando dois desses blocos. Ele pode virar convenientemente os
blocos, mas só pode empilhar os dois blocos se a face do bloco que vai ficar em baixo tiver ambas as dimensões maiores que as da face que será empilhada.
Faça um programa para ajudá-lo nessa tarefa.

A entrada consiste de uma série de testes. A primeira linha contém um único inteiro indicando o número n (1 ≤ n ≤ 20) de casos de testes. 
A seguir vêm n linhas contendo, cada uma, um caso de teste. Cada caso de teste se compõe de 6 inteiros: os três primeiros são as dimensões do 
primeiro bloco e, as três últimas, as dimensões do segundo bloco.
Saída

Para cada caso de teste imprima, em uma linha, um inteiro de 0 a 3, com o seguinte significado:

   0, se nenhum bloco pode ser empilhado sobre o outro.
   1, se apenas o primeiro bloco pode ser empilhado sobre o segundo.
   2, se apenas o segundo bloco pode ser empilhado sobre o primeiro.
   3, Se cada bloco pode ser convenientemente empilhado sobre o outro.


*/

var input = require('fs').readFileSync('dev/stdin', 'utf8');
var lines = input.split('\n');

const getLineValues = (line) => line.split(" ").map(a => parseInt(a));

let numeroLinhas = parseInt(lines.shift());
let bloco1 = [];
let bloco2 = [];

for (i = 0; i < numeroLinhas; i++){
  if (i % 2 == 0){
    bloco1.push(getLineValues(lines.shift()));
  }
  else {
    bloco2.push(getLineValues(lines.shift()));
  }
}