puts 'digite o mês que você nasceu:'

month = gets.chomp.to_i

case month
when 1..3
  puts 'Você nasceu no início do ano.'
when 4..6
  puts 'Nasceu na primeira metade'
else
  puts 'nasceu do mês 6 pra frente. Estou com preguiça.'
end