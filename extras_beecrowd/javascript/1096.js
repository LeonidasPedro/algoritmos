let j = 7
for(let i = 1; i <=9;){
    console.log(`I=${i} J=${j}`)
    j--;
    if(j < 5){
        j = 7;
        i += 2;
    }
}