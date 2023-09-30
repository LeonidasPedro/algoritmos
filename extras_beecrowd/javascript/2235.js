/*#include <stdio.h>
 
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a - c == 0 || a-b == 0 || b-c == 0)
    {
        printf("S\n");
    }
    else
    {
        if(a - b - c == 0 || b - a + c == 0 || c - a + b == 0)
        {
         printf("S\n");
        }
        else if(a-b-c == 0 || b - a - c == 0 || c-a-b == 0)
        {
          printf("S\n");  
        }
        else printf("N\n");
    }
    
    return 0;
}*/
var input = require('fs').readFileSync('../dev/stdin', 'utf8');
var lines = input.split('\n');
const pegarValores = (line) => line.split(" ").map(a => Number(a));

let [a, b, c] = pegarValores(lines.shift());

if(a - c == 0 || a-b == 0 || b-c == 0)
{
    console.log("S"); 
}
else
{
    if(a - b - c == 0 || b - a + c == 0 || c - a + b == 0)
    {
     console.log("S"); 
    }
    else if(a-b-c == 0 || b - a - c == 0 || c-a-b == 0)
    {
      console.log("S");  
    }
    else console.log("N"); 
}