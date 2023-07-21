=begin
var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

let a = Number(lines.shift());
let b = Number(lines.shift());
let media = (a * 3.5 + b*7.5) / 11;
console.log(`MEDIA = ${media.toFixed(5)}`);

=end

a = gets.to_f
b = gets.to_f


media = (a * 3.5 + b * 7.5) / 11

puts "MEDIA = #{format('%.5f', media)}"
