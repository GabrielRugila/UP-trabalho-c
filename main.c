#include <stdio.h>

struct boletim{
    float notas[2][2]; // 2t, 2p // valido: t0.0 a 2.0 , p0.0 a 3.0
    float media;
    int passou; // 0 = reprovado (media < 6) || 1 = aprovado // boolean seria +memory efficient?
};

struct alunos{
    char nome[50];
    int serie;
    struct boletim b; //alunos -> aluno -> [i] -> b -> (notas, media, passou)
};

int lerQtdAlunos();
struct alunos lerAlunos(int numAluno);
struct boletim lerNotas();
float calcularMedia(struct boletim b);
int validarPassou(struct boletim b);
void mostraAlunos(struct alunos aluno);
// N modificar acima
int main(){

    int i;
    int qtdAlunos = lerQtdAlunos();
    struct alunos aluno[qtdAlunos];

    for(i = 0; i < qtdAlunos; i++){ //implementar l14 a l19
        //função lerQtdAlunos() deveria ser construida fora do for

        aluno[i] = lerAlunos(i);
        lerNotas();
        calcularMedia(aluno[i].b);
        validarPassou(aluno[i].b);
        mostraAlunos(aluno[i]);

    }
    for(i=0; i<qtdAlunos; i++){
        mostraAlunos(aluno[i]);
    };

    return 0;
}

int lerQtdAlunos(){
    int quantidadeDAlunos;
    printf("Insira a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &quantidadeDAlunos);
    return quantidadeDAlunos;
};

struct alunos lerAlunos(int numAluno){
    struct alunos aluno;
    printf("\n%d - Insira nome do aluno: ", numAluno+1); //i = n do aluno atual
    scanf("%s",aluno.nome);

    printf("\n%d - Insira a serie do aluno: ", numAluno+1);
    scanf("%d", &aluno.serie);

    return aluno;
};

struct boletim lerNotas() {
    struct alunos aluno;
    for (int lin = 0; lin < 2; lin++) {
        printf("\nNotas de trabalho devem ser de 0 a 2 e notas de prova de 0 a 3");

        for (int col = 0; col < 2; col++) {
            do {
            if (lin == 0) {
                printf("\nInsira a nota do trabalho %d do aluno: ", col+1);
            } else {
                printf("\nInsira a nota %d de prova: ", col+1);
            }
                float notaTemp = 0;
                scanf("%f", &notaTemp);
                aluno.b.notas[lin][col] = notaTemp;
                printf("\n%f", notaTemp);
                printf("\n%f", aluno.b.notas[lin][col]);
            } while (aluno.b.notas[0][col] > 2 || aluno.b.notas[1][col] > 3 || aluno.b.notas[lin][col] <= 0);
//            return aluno.b.notas[lin][col];
        }
    }
};

float calcularMedia(struct boletim b){
    struct alunos aluno;
    float mediaTemp = 0;
    for (int lin = 0; lin < 2; lin++){
        for(int col = 0; col < 2; col++){
            mediaTemp += aluno.b.notas[lin][col];
            printf("%f", mediaTemp);
            aluno.b.media += mediaTemp;
            printf("%f", aluno.b.media);
        }
    }
return b.media;
};

int validarPassou(struct boletim b){
    struct alunos aluno;

    float mediaTemp = b.media;
    if(mediaTemp >= 6){
        aluno.b.passou = 1;
        return aluno.b.passou;
    } else {
        aluno.b.passou = 0;
        return aluno.b.passou;
    }
};

void mostraAlunos(struct alunos aluno){
        printf("\n\t %s", aluno.nome);
        printf("\n\t %d", aluno.serie);
        if(aluno.b.passou == 1){
            printf("\nO aluno PASSOU com media %.1f", aluno.b.media);
        } else {
            printf("\nO aluno REPROVOU com media %.1f", aluno.b.media);
        }
};