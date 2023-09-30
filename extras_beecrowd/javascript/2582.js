var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

const pegarValores = (line) => line.split(" ").map(a => Number(a));

let c = pegarValores(lines.shift());

let music = 0;

let a = 0;
let b = 0;
let nome = "";

for (let i = 0; i < c; i++) {
    [a, b] = pegarValores(lines.shift());
    music = a + b;
        switch (music) {
        case 0:
            nome = "PROXYCITY";
            break;
        case 1:
            nome = "P.Y.N.G.";
            break;
        case 2:
            nome = "DNSUEY!";
            break;
        case 3:
            nome = "SERVERS";
            break;
        case 4:
            nome = "HOST!";
            break;
        case 5:
            nome = "CRIPTONIZE";
            break;
        case 6:
            nome = "OFFLINE DAY";
            break;
        case 7:
            nome = "SALT";
            break;
        case 8:
            nome = "ANSWER!";
            break;
        case 9:
            nome = "RAR?";
        break;
        case 10:
            nome = "WIFI ANTENNAS";
        break;
    }
    console.log(nome);
}