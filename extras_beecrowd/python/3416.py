import math
values = list(map(int, input().split(" ")))
sus = values[0] * values[2] / (values[1] * 1000)
lil = int(math.ceil(sus))
print(lil * values[1])

