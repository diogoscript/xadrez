#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define ROWS 8
#define COLS 8


char board[ROWS][COLS+1]; // +1 para terminador de string por linha


int is_white(char p) { return p >= 'A' && p <= 'Z'; }
int is_black(char p) { return p >= 'a' && p <= 'z'; }
int is_empty(char p) { return p == '.'; }


void init_board() {
const char *init[8] = {
"rnbqkbnr",
"pppppppp",
"........",
"........",
"........",
"........",
"PPPPPPPP",
"RNBQKBNR"
};
for (int i = 0; i < 8; ++i) {
strncpy(board[i], init[i], COLS);
board[i][COLS] = '\0';
}
}


void print_board() {
printf(" a b c d e f g h\n");
for (int r = 0; r < 8; ++r) {
printf("%d ", 8 - r);
for (int c = 0; c < 8; ++c) {
printf("%c", board[r][c]);
if (c < 7) printf(" ");
}
printf(" %d\n", 8 - r);
}
printf(" a b c d e f g h\n");
}


int same_side(char a, char b) {
if (is_empty(a) || is_empty(b)) return 0;
return (is_white(a) && is_white(b)) || (is_black(a) && is_black(b));
}


// Converte coordenada como 'a'..'h' e '1'..'8' para índices (row, col)
int coord_to_index(const char *coord, int *row, int *col) {
if (!coord || strlen(coord) < 2) return 0;
char file = coord[0];
char rank = coord[1];
if (file < 'a' || file > 'h') return 0;
if (rank < '1' || rank > '8') return 0;
*col = file - 'a';
*row = 8 - (rank - '0');
return 1;
}


void make_move(int r1, int c1, int r2, int c2) {
board[r2][c2] = board[r1][c1];
board[r1][c1] = '.';
}


int main() {
init_board();
char from[8], to[8];
int white_turn = 1;


printf("Movimentando as Pecas do Xadrez - modo texto\n");
printf("Digite movimentos como: e2 e4 (ou 'sair' para encerrar)\n\n");


while (1) {
print_board();
printf("Vez: %s\n", white_turn ? "Branco (maiúsculas)" : "Preto (minúsculas)");
printf("Movimento: ");
if (scanf("%7s", from) != 1) break;
if (strcmp(from, "sair") == 0) break;
if (scanf("%7s", to) != 1) break;


int r1, c1, r2, c2;
if (!coord_to_index(from, &r1, &c1) || !coord_to_index(to, &r2, &c2)) {
printf("Coordenada invalida. Use formato a1..h8.\n");
while (getchar() != '\n');
continue;
}


// Movimentação simples sem validação detalhada ainda
if (same_side(board[r1][c1], board[r2][c2])) {
printf("Nao pode capturar sua propria peca!\n");
continue;
}


make_move(r1, c1, r2, c2);
white_turn = !white_turn;
while (getchar() != '\n');
}


printf("Jogo encerrado.\n");
return 0;
}