## Trabalho Prático DCC059 - Teoria dos Grafos - 2024/3

## Aluno:
  - Lucas Henrique Ferreira

## Objetivo: 
  Implementar uma classe genérica de grafo, com implementações específicas usando matriz de adjacência e listas encadeadas, a fim de estudar suas propriedades como conectividade e bipartição. Este trabalho foi desenvolvido em C++, utilizando as propriedades de orientação a objetos e bibliotecas da linguagem.

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

### Arquivo descrição: `descricao.txt`
```
3 // Grau
3 // Ordem
1 // Direcionado
2 // Componentes conexas
1 // Vertices ponderados
1 // Arestas ponderadas
0 // Completo
1 // Bipartido
0 // Arvore
1 // Aresta Ponte
1 // Vertice de Articulação
```
### 1. Imprime propriedades do grafo após carregá-lo como matriz de adjacência:
   ```bash
   g++ *.cpp -o main.out && ./main.out -d -m ../grafo.txt
   ```
### Saída esperada :
  
```
Grau: 6
Ordem: 3
Direcionado: Sim
Componentes conexas: 1
Vertices ponderados: Sim
Arestas ponderadas: Sim
Completo: Não
Bipartido: Sim
Arvore: Não
Aresta Ponte: Sim
Vertice de Articulação: Sim
```
### 2. Carrega um arquivo de descrição, cria um grafo aleatório na estrutura de matriz e salva em outro arquivo:
   ```bash
   g++ *.cpp -o main.out && ./main.out -c -m ../descricao.txt
   ```
### Saída esperada :
  
```
0 1 0 
1 0 1
0 1 0
Grau: 1
Ordem: 3
Direcionado: Não
Componentes conexas: 1
Vertices ponderados: Não
Arestas ponderadas: Não
Completo: Não
Bipartido: Sim
Arvore: Sim
Aresta Ponte: Sim
Vertice de Articulação: Sim
```
## Organização dos arquivos
  - grafo.h: Declaração da classe base `grafo`.
  - grafo_matriz.h: Declaração da classe `grafo_matriz`.
  - grafo_matriz.cpp: Implementação das funções da classe `grafo_matriz`.
  - grafo_lista.h: Declaração da classe `grafo_lista`.
  - grafo_lista.cpp: Implementação das funções da classe `grafo_lista`.
  - main.cpp: Programa principal que executa as entradas.

### Representação gráfica e matriz de adjacência
![imagem_grafo](https://github.com/user-attachments/assets/c1b63128-84db-4691-9542-8724ceea9973)

![matriz](https://github.com/user-attachments/assets/59c35379-17be-4b1c-930f-6a1934e2ac52)



