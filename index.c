#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int i = 0;

void clear_screen(){
    system("cls");
    fflush(stdout);
    // para zerar a tela
}

void print_game(char game[3][3]){
    printf("==================JOGO DA VELHA===================\n");
    printf("==================PARTIDA %d DE 3==================\n\n\n", i+1);
    printf("\t%c\t|\t%c\t|\t%c\t\n", game[0][0], game[0][1], game[0][2]);
    printf("==================================================\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n", game[1][0], game[1][1], game[1][2]);
    printf("==================================================\n");
    printf("\t%c\t|\t%c\t|\t%c\t\n", game[2][0], game[2][1], game[2][2]);
    // para printar o jogo
}

int checar_linhas(char game[3][3]){
    for(int i = 0; i < 3; i++){
        if(game[i][0] == game[i][1] && game[i][1] == game[i][2]){
            return 0;
        }
    }
    return 1;
    // para checar se há vitória em linhas
}

int checar_colunas(char game[3][3]){
    for(int i = 0; i < 3; i++){
        if(game[0][i] == game[1][i] && game[1][i] == game[2][i]){
            return 0;
        }
    }
    return 1;
    // para checar se há vitória em colunas
}

int checar_diagonais(char game[3][3]){
    if(game[0][0] == game[1][1] && game[1][1] == game[2][2]){
        return 0;
    }
    if(game[0][2] == game[1][1] && game[1][1] == game[2][0]){
        return 0;
    }
    return 1;
    // para checar se há vitória em diagonais
}

void marcar(int jogador, char game[3][3], char simbolo){
    switch (jogador)
    {
    case 1:
        game[0][0] = simbolo;
        break;

    case 2: 
        game[0][1] = simbolo;
        break;

    case 3:
        game[0][2] = simbolo;
        break;

    case 4:
        game[1][0] = simbolo;
        break;

    case 5:
        game[1][1] = simbolo;
        break;

    case 6:
        game[1][2] = simbolo;
        break;

    case 7:
        game[2][0] = simbolo;
        break;

    case 8:
        game[2][1] = simbolo;
        break;

    case 9:
        game[2][2] = simbolo;
        break;

    default:
        break;
    }
    // traduz o numero dado e joga o simbolo do jogador na matriz
}

int checar_vitoria(char game[3][3]){
    int linhas, colunas, diagonais;
    linhas = checar_linhas(game);
    colunas = checar_colunas(game);
    diagonais = checar_diagonais(game);

    if (linhas != 0 && colunas != 0 && diagonais != 0)
    {
        return 1;
    }
    else return 0;
    // pega as funções de checar linha, coluna e diagonal. se alguma indicar vitória retorna 0 
}

bool checar_velha(char game[3][3]){
    int soma = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (game[i][j] == 'X' || game[i][j] == 'O')
            {
                soma = soma + 1;
            }
        }
    }

        // a primeira parte checa se todos os espaços foram preenchidos

    if (soma >= 9){
        return true;
    }
    else return false;

        // a segunda checa se ja foram todas as jogadas
}

bool checar_space(int jogador, char game[3][3]){
    switch (jogador)
    {
    case 1:
        if (game[0][0] == '1')
        {
            return true;
        }
        else return false;
        break;

    case 2:
        if (game[0][1] == '2')
        {
            return true;
        }
        else return false;
        break;

    case 3:
        if (game[0][2] == '3')
        {
            return true;
        }
        else return false;
        break;

    case 4:
        if (game[1][0] == '4')
        {
            return true;
        }
        else return false;
        break;

    case 5:
        if (game[1][1] == '5')
        {
            return true;
        }
        else return false;
        break;

    case 6:
        if (game[1][2] == '6')
        {
            return true;
        }
        else return false;
        break;

    case 7:
        if (game[2][0] == '7')
        {
            return true;
        }
        else return false;
        break;

    case 8:
        if (game[2][1] == '8')
        {
            return true;
        }
        else return false;
        break;

    case 9:
        if (game[2][2] == '9')
        {
            return true;
        }
        else return false;
        break;

    default:
        return false;
        break;
    }

    // essa função checa se o espaço está disponível
}

struct Jogador
{
    int score;
};



int main(){

    struct Jogador jogadorn1;
    struct Jogador jogadorn2;

    jogadorn1.score = 0;
    jogadorn2.score = 0;

for (int i = 0; i < 3; i++){
    // o for faz com que haja 3 jogos
    char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int jogador1, jogador2;
    int vitoria = 1;
    char X = 'X';
    char O = 'O';
    bool vitoria_x = false;
    bool vitoria_o = false;
    bool velha = false;
    bool check = false;

    while (vitoria_x == false) {

        print_game(game);
    
            printf("JOGADOR 1 - Escolha um numero: ");

            while (1)
            {
            scanf("%d", &jogador1);
            check = checar_space(jogador1, game);
            if (check == true)
            {
                break;
            }
            printf("\nNumero indisponivel! Escolha novamente: ");             
            }
            
        marcar(jogador1, game, X);

        vitoria = checar_vitoria(game);
        if (vitoria == 0)
        {
            vitoria_x = true;
            break;
        }
        velha = checar_velha(game);
        if (velha == true){
            break;
        }
        
        clear_screen();

        print_game(game);

            printf("JOGADOR 2 - Escolha um numero: ");
            
            while (1)
            {
            scanf("%d", &jogador2);
            check = checar_space(jogador2, game);
            if (check == true)
            {
                break;
            }
            printf("\nNumero indisponivel! Escolha novamente: ");             
            }
            
        
        marcar(jogador2, game, O);


        velha = checar_velha(game);
        if (velha == true){
            break;
        }
        vitoria = checar_vitoria(game);
        if (vitoria == 0)
        {
            vitoria_o = true;
            break;
        }

        clear_screen();

    }

    if (vitoria == 1)
    {
        printf("Fim da rodada! ");
    }


    if (vitoria_x == true)
    {
        jogadorn1.score++;
        printf("%d ponto(s) para o JOGADOR 1\n", jogadorn1.score);
    }
    else if (vitoria_o == true)
    {
        jogadorn2.score++;
        printf("%d ponto(s) para o JOGADOR 2\n", jogadorn2.score);
    }
    else printf("Deu velha :/\n");
   
}

if (jogadorn1.score > jogadorn2.score)
{
    printf("\nJOGADOR NUMERO 1 GANHOU O JOGO de %d x %d", jogadorn1.score, jogadorn2.score);
}
else if (jogadorn2.score > jogadorn1.score)
{
    printf("\nJOGADOR NUMERO 2 GANHOU O JOGO de %d x %d", jogadorn2.score, jogadorn1.score);
}
else printf("\nEmpatou! :/");
    return 0;
}