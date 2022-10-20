var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');

let vertebra = lines.shift();
let classe = lines.shift();
let grupo = lines.shift(); 

let objeto = {
    vertebrado: {
        ave: {
            carnivoro: 'aguia',
            onivoro: 'pomba'
        },
        mamifero: {
            onivoro: 'homem',
            herbivoro: 'vaca' 
        }
    },
    invertebrado: {
        inseto: {
            hematofago: 'pulga',
            herbivoro: 'lagarta'
        },
        anelideo: {
            hematofago: 'sanguessuga',
            onivoro: 'minhoca'
        } 
    }
}

console.log(objeto[vertebra][classe][grupo])