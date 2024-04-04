#include <stdio.h>
#include <stdlib.h>

// Jogo das opera��es


// struct contendo os valores, a opera��o e a resposta
typedef struct{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostraInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);

int score = 0;


int main(){
    // deve ser chamado apenas uma vez
    srand(time(NULL)); // inicializando com o tempo padr�o do computador

    jogar(); // chamando a fun��o para iniciar o jogo



}


void jogar(){
    // a ser implementado
    Calcular calc;
    int dificuldade;

    printf("informe o nivel de dificuldade desejado.\n");
    printf("1-> Facil\n2 -> Medio\n3 -> Dificil\n4 -> Muito dificil\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;

    calc.operacao = rand() % 3; // gera numeros randomicos entre 0 e 2

    if(calc.dificuldade == 1){
        printf("Bem vindo a dificulade 1\n");
        // f�cil
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }else if(calc.dificuldade == 2){
        printf("Bem vindo a dificulade 2\n");
        // m�dia
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }else if(calc.dificuldade == 3){
        printf("Bem vindo a dificulade 3\n");
        // dif�cil
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }else if(calc.dificuldade == 4){
        printf("Bem vindo a dificulade 4\n");
        // muito dif�cil
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    } else{
        printf("Bem vindo a dificulade ultra\n");
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }
    int resposta;
    printf("informe o resutado para a seguinte questao: \n");

    // somar
    if(calc.operacao == 0){
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if(somar(resposta, calc)){
            score += 10;
            printf("voce tem %d ponto(s)\n", score);
        }
    }//subtrair
    else if(calc.operacao == 1){
        printf("%d - %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(diminuir(resposta, calc)){
            score += 10;
            printf("voce tem %d ponto(s)\n", score);
        }
    }//multiplicar
    else if(calc.operacao == 2){
        printf("%d * %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(multiplicar(resposta, calc)){
            score += 10;
            printf("voce tem %d ponto(s)\n", score);
        }
    }// Desconhecida
    else{
        printf("operacao desconhecida");
    }
    // recome�ar o jogo?
    int continuar;
    printf("Deseja continuar jogando?\n");
    scanf("%d", &continuar);

    if(continuar){
        jogar();
    }else{
        printf("Pontuacao final: %d pontos\n", score);
        printf("Ate a proxima\n");
    }


}


// Mostra as informa��es na tela
void mostraInfo(Calcular calc){
    char op[25];

    if(calc.operacao == 0){ // 0 == somar
        sprintf(op, "Somar"); // adicionando a string no vetor de caracteres
    }else if(calc.operacao == 1){ // 1 == subtrair
        sprintf(op, "Subtrair"); // adicionando a string no vetor de caracteres
    }else if(calc.operacao == 2){ // 2 == multiplica��o
        sprintf(op, "Multiplicar"); // adicionando a string no vetor de caracteres
    }else{
        sprintf(op, "Opera��o desconhecida");
    }
    printf("valor 1: %d\nValor 2: %d\nDificulade: %d\nOpera��o: %s",
            calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc){
    // a ser implementado
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // flag -> 0 == errado | 1 == certo

    if(resposta == calc.resultado){
        printf("Resposta correta\n");
        certo = 1;
    } else{
        printf("Resposta errada\n");
    }
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

int diminuir(int resposta, Calcular calc){

    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // flag -> 0 == errado | 1 == certo

    if(resposta == calc.resultado){
        printf("Resposta correta\n");
        certo = 1;
    } else{
        printf("Resposta errada\n");
    }
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

int multiplicar(int resposta, Calcular calc){
    // a ser implementado
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // flag -> 0 == errado | 1 == certo

    if(resposta == calc.resultado){
        printf("Resposta correta\n");
        certo = 1;
    } else{
        printf("Resposta errada\n");
    }
    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}
