#python/CPUvsGPU.py

x = int(1)
while(x != 0):
    x = x + 1
    print(x)
    if(x==100000):
        print("Fim")
        x = 0
