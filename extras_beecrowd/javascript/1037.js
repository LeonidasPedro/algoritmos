var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let Num = Number(lines.shift())
if(Num<0 || A>100.0){
console.log("Fora de intervalo");}

    else if(Num<=25.0){

    console.log("Intervalo [0,25]");}

    else if(Num<=50.0){

    console.log("Intervalo (25,50]");}

    else if(Num<=75.0){
    console.log("Intervalo (50,75]");}

    else if(Num<=100.0){
    console.log("Intervalo (75,100]");}



