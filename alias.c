#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ./alias arg1 arg2 ... executa o programa q le os argumentos 
// q sao strings o ultimo sendo o nome do alias.
// e monta um alias na estrutura certa, insere no arquivo .bash_aliases
// e executa o comando(alias) aply. e retorna se a operação deu certo


// montaalias recebe dois vetores, um com o comando do alias e um com o nome e retorna um vetor
// com o alias pronto para ser escrito em arquivo

void montaalias(char arg[1000], char **argv){
    int i, j, k;
    char alias[100];

    arg[0]='a';
    arg[1]='l';
    arg[2]='i';
    arg[3]='a';
    arg[4]='s';
    arg[5]=' ';
    printf("digite o nome do alias\n");
    scanf("%s", alias);
    k=6;
   
    for (i = 0; alias[i] != '\0'; i++){
        arg[k] = alias[i];
        k++;
    }
    
    arg[k]='=';
    k++;
    arg[k]='\'';
    k++;

    for (i = 1; argv[i] != NULL; i++){
        for (j = 0; argv[i][j] != '\0'; j++){
            arg[k]=argv[i][j];
            k++;
        }
        arg[k]=' ';
        k++;
    }

    arg[k]='\'';
    arg[k+1]='\0';

    printf("%s\n", arg);

}

// escrevealias recebe um vetor, abre o arquivo ~/.bash_aliases e escreve o conteudo do vetor
// na ultima linha. Se a operação falhar ele printa uma msg de erro e retorna um codigo de erro.
// em caso de sucesos ele informa e acaba normalmente.

void escrevealias(char alias[1000]){
    FILE* arq;

    arq=fopen("/home/ladp17/.bash_aliases", "a");
    fputs(alias, arq);
    fputs("\n", arq);
    fclose(arq);
}

// main recebe os parametros, passa os primeiros args(antes do nome do alias) para um vetor.
// entao envia ambus para a função montaalias que retorna um vetor q entao vai para escrevealias
// q retorna um inteiro q indica se foi sucesso ou n.

int main(int argc, char **argv){
        char arg[1000];
    
    montaalias(arg, argv);
    escrevealias(arg);

   return 0;
}
