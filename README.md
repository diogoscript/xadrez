# Movimentando as Peças do Xadrez - C

## Descrição

Este é um programa em linguagem C que simula um tabuleiro de xadrez 8x8 em modo texto. Permite que dois jogadores movam peças utilizando coordenadas no formato padrão do xadrez (ex.: `e2 e4`).

O programa inclui:

* Inicialização do tabuleiro com posição padrão.
* Impressão do tabuleiro no console.
* Alternância de turnos entre jogador branco e preto.
* Movimento básico de peças com verificação se não está capturando uma peça do mesmo lado.

> Observação: Movimentos não são totalmente validados por tipo de peça nesta versão básica.

## Requisitos

* Compilador C (ex.: `gcc`).
* Terminal ou console para execução.

## Como Compilar

```bash
gcc -o xadrez Movimentando_as_Pecas_do_Xadrez.c
```

## Como Executar

```bash
./xadrez
```

## Como Jogar

* O programa solicitará o movimento de cada jogador.
* Digite o movimento no formato: `<origem> <destino>`

  * Exemplo: `e2 e4`
* Para encerrar o jogo, digite: `sair`
* Alterna automaticamente entre jogadores branco (maiúsculas) e preto (minúsculas).

## Representação das Peças

* Letras maiúsculas: peças brancas (P, R, N, B, Q, K)
* Letras minúsculas: peças pretas (p, r, n, b, q, k)
* `.` : casa vazia

## Exemplo de Uso

```
Movimentando as Pecas do Xadrez - modo texto
Digite movimentos como: e2 e4   (ou 'sair' para encerrar)
  a b c d e f g h
8 r n b q k b n r 8
7 p p p p p p p p 7
6 . . . . . . . . 6
5 . . . . . . . . 5
4 . . . . . . . . 4
3 . . . . . . . . 3
2 P P P P P P P P 2
1 R N B Q K B N R 1
  a b c d e f g h
Vez: Branco (maiúsculas)
Movimento: e2 e4
```

