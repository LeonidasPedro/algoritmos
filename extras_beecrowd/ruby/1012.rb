# Escreva um programa que leia três valores com ponto flutuante de dupla precisão: A, B e C.
#  Em seguida, calcule e mostre:
# a) a área do triângulo retângulo que tem A por base e C por altura.
# b) a área do círculo de raio C. (pi = 3.14159)
# c) a área do trapézio que tem A e B por bases e C por altura.
# d) a área do quadrado que tem lado B.
# e) a área do retângulo que tem lados A e B.
# Entrada

# O arquivo de entrada contém três valores com um dígito após o ponto decimal.
# Saída

# O arquivo de saída deverá conter 5 linhas de dados. Cada linha corresponde a uma das áreas descritas acima,
#  sempre com mensagem correspondente e um espaço entre os dois pontos e o valor. 
#  O valor calculado deve ser apresentado com 3 dígitos após o ponto decimal.


entradas = gets

def setValues(lines)
    lines.split(' ').map(&:to_f)
end

a, b, c = setValues(entradas)

triangulo = a * c / 2
circulo = 3.14159 * c**2
trapezio = (a + b) * c / 2
quadrado = b * b
retangulo = a * b

puts "TRIANGULO: #{format('%.3f', triangulo)}"
puts "CIRCULO: #{format('%.3f', circulo)}"
puts "TRAPEZIO: #{format('%.3f', trapezio)}"
puts "QUADRADO: #{format('%.3f', quadrado)}"
puts "RETANGULO: #{format('%.3f', retangulo)}"
