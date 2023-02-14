=begin
estados = []

estados.push('sc') # push da um push 👍
estados.push('rs')
puts estados
puts "---------------------------"
estados.insert(0, 'PA', 'PB', 'MS', 'BA', 'RJ') # insere passando index
puts estados
puts "---------------------------"
puts estados.count
puts "---------------------------"
puts estados.first
puts "---------------------------"
puts estados.last
puts "---------------------------"
puts estados.pop ## remove o último
puts "---------------------------"
puts estados.shift ## remove o primeiro
puts "---------------------------"
puts estados
estados[0..2] = 'forget'
puts estados
puts "---------------------------"
puts estados.empty?
puts "---------------------------"
puts estados.include?('forget')
=end

cores = {lapis:"preto", caneta:"azul"}

puts cores[:lapis]

puts cores.values
cores.delete(:lapis)
puts "---------------------------"
puts cores






