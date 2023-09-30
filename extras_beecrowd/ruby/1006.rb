# Leia 3 valores, no caso, variáveis A, B e C, que são as três notas de um aluno. A seguir,
# calcule a média do aluno, sabendo que a nota A tem peso 2, a nota B tem peso 3 
# e a nota C tem peso 5. Considere que cada nota pode ir de 0 até 10.0, sempre com uma casa decimal.

a = gets.to_f
b = gets.to_f
c = gets.to_f
# gpa = grade poin average
gpa = (a * 2 + b * 3 + c * 5) / 10

puts "MEDIA = #{format('%.1f', gpa)}"







