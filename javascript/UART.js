let databus1= [0, 1, 1, 1, 1, 1, 1, 1]
let databus2= []
let uart1= [];
let uart2=[]
let quantidadeDe1 = 0;

uart1[0] = 0//bit inicial

for(let i = 1; i< 9; i++){
    uart1[i] = databus1[i-1]
    if (uart1[i] == 1) {
        quantidadeDe1++;//contador de bits 1 pra paridade
    }
}

quantidadeDe1 % 2 == 0 ? uart1[9] = 0 : uart1[9]= 1//paridade

if(uart1[9]==0) {//bit final
    uart1[10]=1
}else{
    uart1[10] = 0
    uart1[11] = 1
}

uart2 = uart1;

let i = 0;

if(uart2.length == 11){
    uart2.shift()
    while(i < 3) {
        uart2.pop()
        i++
    }
} else {
    uart2.shift()
    while(i < 2) {
        uart2.pop()
        i++
    }
}

console.log(`entrada:`)
console.log(databus1)
console.log(`uart2`);
console.log(uart1);
