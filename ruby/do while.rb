x = 10000

loop do
  if x % 2
    print x
    x -= 999
  end
  break if x < 0
end