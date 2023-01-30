import os

caminho = './javascript'

for nomeArquivo in os.listdir(caminho):
    with open(os.path.join(caminho, nomeArquivo), 'r') as file:
        content = file.read()
    
    content = content.replace('../dev/stdin', '/dev/stdin')
    
    with open(os.path.join(caminho, nomeArquivo), 'w') as file:
        file.write(content)
