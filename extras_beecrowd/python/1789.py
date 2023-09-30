numLesmas = int(input())
values = list(map(int, input().split(" ")))
maisVeloz = max(values)
if maisVeloz < 10:
    print(1)
elif maisVeloz > 9 and maisVeloz < 20:
    print(2)
else:
    print(3)


