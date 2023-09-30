entradas = gets

def get_values(entradas)
  entradas.split(' ').map(&:to_i)
end
array = get_values(entradas)
puts "#{array.max} eh o maior"

