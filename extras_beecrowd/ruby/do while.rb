x = 10000

loop do
  if x % 2
    puts x
    x -= 78
  end
  break if x.negative?
end
