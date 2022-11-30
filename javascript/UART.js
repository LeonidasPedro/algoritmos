let databus1= [0, 1, 1, 1, 1, 1, 1, 1]//informação a ser transmitida
let databus2= []//informação a ser recebida
let uart1= [];//transmissor
let uart2=[]//receptor
let quantidadeDe1 = 0;//contador de bits 1 pra paridade


uart1.unshift(0)//adiciona o start bit

for(let i = 1; i< 9; i++){//pula o bit inicial
    uart1[i] = databus1[i-1]
    if (uart1[i] == 1) {
        quantidadeDe1++;//contador de bits 1 pra paridade
    }
}

quantidadeDe1 % 2 == 0 ? uart1.push(0) : uart1.push(1)//adiciona o bit de paridade

if(uart1[9]==0) {//bit final
    uart1[10]=1
}else{
    uart1[10] = 0
    uart1[11] = 1
}

uart2 = uart1;//recebe a informação

let i = 0;

console.log("Entrada: " + databus1)
console.log("Transmissor: " + uart1);
console.log("Receptor: " + uart2);
databus2 = uart2.slice(1, 9);//slice percorre o array e pega só o databus2 que está entre o start bit e o bit de paridade
console.log("Databus: " + databus2);