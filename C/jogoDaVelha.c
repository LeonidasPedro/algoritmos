#include <stdio.h>

#define player_x 'X'

#define player_o 'O'

#define vazio '*'

#define clear system("clear")

 

/*

    [0][1][2]

[0]  7  8  9

[1]  4  5  6

[2]  1  2  3

 

*/

//player 1 X

//player 2 O

int main(void) {

  char v[3][3];

  char player;

  int l, c; //linha coluna

  int posi; //posição / coordenada

  char playerAtual;

  int jogadas; //quantidade de jogadas

  char fim = 'e'; //e = empate, x = x, o = o

  l = c = 0;

  //mensagem inicial----------------------------------

  printf("**Jogo Da velha em C**\n\n");

  printf("Para jogar utilize o teclado numérico da seguinte forma:\n");

  printf("\n 7 | 8 | 9\n");

  printf("---+---+---\n");

  printf(" 4 | 5 | 6\n");

  printf("---+---+---\n");

  printf(" 1 | 2 | 3\n\n");

  //--------------------------------------------------

  //laço pra deixar o tabuleiro com os espaços vazios (-)

  for(l = 0; l < 3; l++)

    {

      for(c = 0; c < 3; c++)

      {

        v[l][c] = vazio;

      }

    }

  //tabuleiro vazio

  printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

  printf("---+---+---\n");

  printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

  printf("---+---+---\n");

  printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);





  //while (1){} loop infinito

  while(1){

  if(jogadas % 2 != 0){playerAtual = player_x;}

  else{playerAtual = player_o;}

    //if(fim)



      printf("\nJogador %c é a sua vez\n", playerAtual);

      scanf("%d", &posi);



      //dando valor ao vetor de acordo com a coordenada

       /*

          [0][1][2]

      [0]  7  8  9

      [1]  4  5  6

      [2]  1  2  3



    */

            //linhas x

            if(v[0][0] == player_x && v[0][1] == player_x && v[0][2] == player_x){

              fim = 'X';

              }

            if(v[1][0] == player_x && v[1][1] == player_x && v[1][2] == player_x){

              fim = 'X';

              }

            if(v[2][0] == player_x && v[2][1] == player_x && v[2][2] == player_x){

              fim = 'X';

              }

            //colunas x

            if(v[0][0] == player_x && v[1][0] == player_x && v[2][0] == player_x){

            fim = 'X';

             }

            if(v[0][1] == player_x && v[1][1] == player_x && v[2][1] == player_x){

            fim = 'X';

            }

            if(v[0][2] == player_x && v[1][2] == player_x && v[2][2] == player_x){

            fim = 'X';

            }

            //linhas O

            if(v[0][0] == player_o && v[0][1] == player_o && v[0][2] == player_o){

              fim = 'O';

              }

            if(v[1][0] == player_o && v[1][1] == player_o && v[1][2] == player_o){

              fim = 'O';

              }

            if(v[2][0] == player_o && v[2][1] == player_o && v[2][2] == player_o){

              fim = 'O';

              }

            //colunas O

             if(v[0][0] == player_o && v[1][0] == player_o && v[2][0] == player_o){

            fim = 'O';

             }

            if(v[0][1] == player_o && v[1][1] == player_o && v[2][1] == player_o){

            fim = 'O';

            }

            if(v[0][2] == player_o && v[1][2] == player_o && v[2][2] == player_o){

            fim = 'O';

            }

            //Diagonal 1 X

            if(v[0][0] == player_x && v[1][1] == player_x && v[2][2] == player_x){

              fim = 'X';}

            //Diagonal 1 O

            if(v[0][0] == player_o && v[1][1] == player_o && v[2][2] == player_o){

              fim = 'O';

              }

            //diagonal 2 X

            if(v[0][2] == player_x && v[1][1] == player_x && v[2][0] == player_x){

              fim = 'X';}

            //diagonal 2 O

            if(v[0][2] == player_o && v[1][1] == player_o && v[2][0] == player_o){

              fim = 'O';}

            //empate

            if(v[0][0] != vazio && v[0][1] != vazio && v[0][2] != vazio && v[1][0] != vazio && v[1][1] != vazio && v[1][2] != vazio && v[2][0] != vazio && v[2][1] != vazio && v[2][2] != vazio){printf("O jogo Empatou");

              break;

              }





      clear;

      switch(posi)

      {

        case 1:

        if(v[2][0] != vazio){printf("\nPosição inválida\n");}/*verifica se ja foi

                                                            jogada nessa posição e só então continua o jogo*/

        else{v[2][0] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 2:

        if(v[2][1] != vazio){printf("\nPosição inválida\n");}

        else{v[2][1] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 3:

        if(v[2][2] != vazio){printf("\nPosição inválida\n");}

        else{v[2][2] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 4:

        if(v[1][0] != vazio){printf("\nPosição inválida\n");}

        else{v[1][0] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 5:

        if(v[1][1] != vazio){printf("\nPosição inválida\n");}

        else{v[1][1] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 6:

        if(v[1][2] != vazio){printf("\nPosição inválida\n");}

        else{v[1][2] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 7:

        if(v[0][0] != vazio){printf("\nPosição inválida\n");}

        else{v[0][0] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 8:

        if(v[0][1] != vazio){printf("\nPosição inválida\n");}

        else{v[0][1] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

        case 9:

        if(v[0][2] != vazio){printf("\nPosição inválida\n");}

        else{v[0][2] = playerAtual;

              printf("\n %c | %c | %c\n", v[0][0], v[0][1], v[0][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[1][0], v[1][1], v[1][2]);

              printf("---+---+---\n");

              printf(" %c | %c | %c\n", v[2][0], v[2][1], v[2][2]);

              jogadas++;

            }

        break;

      }

    if(fim != 'e')

    {

    printf("\n\n***Fim de jogo***\n\nVencedor %c", fim);

    break;

    }

  }





  return 0;




}