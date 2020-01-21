#include <iostream>
#include <stdlib.h>

using namespace std;

int gComeco = 0;
char gMatriz[3][3];
bool gGanhou = false, gDiaPrincipal = true ,gDiaSecundaria = true;

void Vitoria()
{
    int contDP = 0, contDS = 0, contLN = 0, contCL = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //Diagonal Principal
            if(i==j && gDiaPrincipal==true && i < 2){
                if(gMatriz[i][j] != ' ' && gMatriz[i + 1][j + 1] != ' '){
                    if(gMatriz[i][j] != gMatriz[i + 1][j + 1])
                    {
                        gDiaPrincipal = false;
                    }
                    else if(gMatriz[i][j] == gMatriz[i + 1][j + 1]){
                        contDP += 1;
                    }

                }
            }

            //Diagonal Secundaria
            if( i + j == 2 && gDiaSecundaria==true && i < 2){
                if(gMatriz[i][j] != ' ' && gMatriz[i + 1][1-i] != ' '){
                    if(gMatriz[i][j] != gMatriz[i + 1][1-i])
                    {
                        gDiaSecundaria = false;
                    }
                    else if(gMatriz[i][j] == gMatriz[i + 1][1-i]){
                        contDS += 1;
                    }

                }
            }

            //linha
            if(gMatriz[i][j] != ' ' && gMatriz[i][j + 1] != ' '){
                if(gMatriz[i][j] == gMatriz[i][j + 1]){
                    contLN += 1;
                }
                if(contLN == 2){
                    gGanhou = true;
                }
            }
            //coluna
            if(gMatriz[j][i] != ' ' && gMatriz[j + 1][i] != ' ' && j < 2){
                if(gMatriz[j][i] == gMatriz[j + 1][i]){
                    contCL += 1;
                }
                if(contCL == 2){
                    gGanhou = true;
                }
            }
        }
        contLN = 0;
        contCL = 0;

    }

    if(contDP == 2 || contDS == 2){
        gGanhou = true;
    }
}

void LimpaMAtriz()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            gMatriz[i][j] = ' ';
        }
    }
}

void mostraNaTela()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout <<gMatriz[i][j];

            if(j < 2)
            {
                cout << " | ";
            }
        }

        cout << endl;

        if(i < 2)
        {
            cout << "----------" << endl;
        }
    }
}

void Matriz(int linha, int coluna, int player)
{

    for( int i = 0; i < 3; i++)
    {
        for (int j= 0; j < 3 ; j++)
        {
            if(i == linha && j == coluna){
                if(player == 1){
                    gMatriz[i][j] = 'X';
                }
                else{
                    gMatriz[i][j] = 'O';
                }
            }
        }
    }

    mostraNaTela();
    Vitoria();
}

 void controleDeJogo()
{
    int player = 1, contJogadas = 0;
    if(gComeco == 0 ){
        LimpaMAtriz();
        gComeco += 1;
        mostraNaTela();
    }
    while(gGanhou != true && contJogadas != 9){
    int linha, coluna;

    cout << "Player " << player << endl << "digite a linha e a coluna: (1 a 3) ";
    cin >> linha >> coluna;
    Matriz(linha - 1, coluna - 1, player);
    contJogadas += 1;

    if(gGanhou == true){
        cout << endl << "O PLAYER " << player << " GANHOU!!!!!!" << endl;
    }

    if(player == 1){
        player = 2;
    }
    else{
        player = 1;
    }
    }

    if(contJogadas == 9){
        cout << "DEU VELHA... :`(" << endl;
    }
}

int main()
{
    controleDeJogo();
    system("pause");
    return 0;
}
