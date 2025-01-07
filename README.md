## Trabalho Prático DCC059 - Teoria dos Grafos - 2024/3

## Aluno:
  - Lucas Henrique Ferreira

## Execução 
Certifique-se de que você tenha um compilador C++ instalado, como o **g++**.

### Grafo de exemplo: arquivo `grafo.txt`

```
3 1 1 1
2 3 7
1 2 6
2 1 4
2 3 -5
```
- Linha 1: `nós, direcionado, ponderado_vertices, ponderado_arestas`
- Linha 2: Pesos dos vértices (opcional, dependendo do grafo)
- Linhas seguintes: `origem destino peso`

### 1. Imprime propriedades do grafo após carregá-lo como matriz de adjacência:
   ```bash
   g++ *.cpp -o main.out && ./main.out -d -m ../grafo.txt
   ```
### 2. Carrega um arquivo de descrição, cria um grafo aleatório na estrutura de matriz e salva em outro arquivo:
   ```bash
   g++ *.cpp -o main.out && ./main.out -c -m ../descricao.txt
   ```
