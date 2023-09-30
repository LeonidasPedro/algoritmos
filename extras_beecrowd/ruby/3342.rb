base = gets.to_i

total = base * base
pretas = total / 2
brancas = total - pretas

puts "#{brancas.to_i} casas brancas e #{pretas.to_i} casas pretas"
