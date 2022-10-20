let s = 0
let x = 2
for (let i = 1; i <= 100; i+=2) {
 s += i/(x*=2)
}
console.log(s);