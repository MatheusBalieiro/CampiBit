#include <stdio.h>
#include <stdlib.h>

typedef struct atletica CampiBit;
struct atletica
{
    char nome[20];
    char curso[20];
    char instituicao[20];
    int codigo;
    int pontuacao_geral;
    int modalidade_atletismo;
    int modalidade_basquete;
    int modalidade_futebolcampo;
    int modalidade_futsal;
    int modalidade_handebol;
    int modalidade_natacao;
    int modalidade_peteca;
    int modalidade_volei;
};

void receber_dados(CampiBit *al)
{
    printf(" \nInforme o nome da atletica: ");
    scanf(" %s", &al->nome);
    printf(" \nInforme o curso: ");
    scanf(" %s", &al->curso);
    printf("\nInforme a instituicao: ");
    scanf(" %s", &al->instituicao);
    printf("\nInforme o codigo da atletica: ");
    scanf("%d", &al->codigo);
    printf("\nInforme a pontuacao nas modalidades: ");
        printf("\n Atletismo       : ");
        scanf("%d", &al->modalidade_atletismo);

        printf("\n Basquete        : ");
        scanf("%d", &al->modalidade_basquete);

        printf("\n Futebol de campo: ");
        scanf("%d", &al->modalidade_futebolcampo);

        printf("\n Futsal          : ");
        scanf("%d", &al->modalidade_futsal);

        printf("\n Handebol        : ");
        scanf("%d", &al->modalidade_handebol);

        printf("\n Natacao         : ");
        scanf("%d", &al->modalidade_natacao);

        printf("\n Peteca          : ");
        scanf("%d", &al->modalidade_peteca);

        printf("\n Volei           : ");
        scanf("%d", &al->modalidade_volei);
}

void cadastro_atletica(CampiBit *al)
{
     FILE *p;
    if((p = fopen("Cad_Atletica.bin", "a+b")) == NULL)
    {
        printf("Arquivo nao pode ser aberto\n");
    }
    else
    {
        fwrite(al,sizeof(CampiBit),1,p);
        fclose(p);
    }
    system("cls");

}

void relatorio_modalidade(CampiBit *al)
{
    int modalidade;
    system("cls");
    printf("Informe a modalidade: \n");
    printf("1 - Atletismo\n");
    printf("2 - Basquete\n");
    printf("3 - Futebol de campo\n");
    printf("4 - Futsal\n");
    printf("5 - Handebol\n");
    printf("6 - Natacao\n");
    printf("7 - Peteca\n");
    printf("8 - Volei\n");
    printf("Opcao: ");
    scanf("%d", &modalidade);

    switch(modalidade){
    case 1:
        printf("\nAtletismo: %d\n", al->modalidade_atletismo);
        break;

    case 2:
        printf("Basquete: %d\n", al->modalidade_basquete);
        break;

    case 3:
        printf("Futebol de campo: %d\n", al->modalidade_futebolcampo);
        break;

    case 4:
        printf("Futsal: %d\n", al->modalidade_futsal);
        break;

    case 5:
        printf("Handebol: %d\n", al->modalidade_handebol);
        break;

    case 6:
        printf("Natacao: %d\n", al->modalidade_natacao);
        break;

    case 7:
        printf("Peteca: %d\n", al->modalidade_peteca);
        break;

    case 8:
        printf("Volei: %d\n\n", al->modalidade_volei);
        break;}
}

CampiBit * atualizar_pontuacao(int cod)
{
    FILE *p;
    CampiBit *a = malloc(sizeof(CampiBit));

    if((p = fopen("Cad_Atletica.bin", "rb")) == NULL)
    {
        printf("Arquivo nao pode ser aberto\n");
    }
    else
    {
        while( fread(a,sizeof(CampiBit),1,p) != 0)
        {
            if(a->codigo == cod)
            {
                return a;
            }
        }
        fclose(p);
        free(a);
        return NULL;
    }
}

void alterar_pontuacao(CampiBit *al)
{
    int opcao;
    do{
        printf("\n1 - Atletismo\n");
        printf("2 - Basquete\n");
        printf("3 - Futebol de campo\n");
        printf("4 - Futsal\n");
        printf("5 - Handebol\n");
        printf("6 - Natacao\n");
        printf("7 - Peteca\n");
        printf("8 - Volei\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_atletismo);
                break;

            case 2:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_basquete);
                break;

            case 3:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_futebolcampo);
                break;

            case 4:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_futsal);
                break;

            case 5:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_handebol);
                break;

            case 6:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_natacao);
                break;

            case 7:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_peteca);
                break;

            case 8:
                printf("\nDigite nova pontuacao: ");
                scanf("%d",&al->modalidade_volei);
                break;

            default:
                printf("\nOpcao invalida\n");
        }

    }while(opcao > 0 && opcao < 9);
}

void gravar_pontuacao(CampiBit *al)
{
    FILE *p;
    CampiBit *a = (CampiBit*) malloc(sizeof(CampiBit));

    if((p = fopen("Cad_Atletica.bin", "r+b")) == NULL)
    {
        printf("Arquivo nao pode ser aberto\n");
    }
    else
    {
        while( fread(a,sizeof(CampiBit),1,p) != 0)
        {
            if(a->codigo == al->codigo)
            {
                fseek(p, sizeof(CampiBit)*-1, SEEK_CUR);
                fwrite(al, sizeof(CampiBit),1,p);
                break;
            }
        }
        fclose(p);
        free(a);
    }
}




void imprimir_atletica(CampiBit *al)
{
    printf("Nome: %s\n",al->nome);
    printf("Curso: %s\n",al->curso);
    printf("instituicao: %s\n",al->instituicao);
    printf("Codigo: %d\n",al->codigo);
    printf("   Atletismo: %d\n", al->modalidade_atletismo);
    printf("   Basquete: %d\n", al->modalidade_basquete);
    printf("   Futebol de Campo: %d\n", al->modalidade_futebolcampo);
    printf("   Futsal: %d\n", al->modalidade_futsal);
    printf("   Handebol: %d\n", al->modalidade_handebol);
    printf("   Natacao: %d\n", al->modalidade_natacao);
    printf("   Peteca: %d\n", al->modalidade_peteca);
    printf("   Volei: %d\n\n\n", al->modalidade_volei);
}

void relatorio_geral()
{
    FILE *p;
    CampiBit *a = (CampiBit*) malloc(sizeof(CampiBit));

    if((p = fopen("Cad_Atletica.bin", "rb")) == NULL)
    {
        printf("Arquivo nao pode ser aberto\n");
    }
    else
    {
        while( fread(a,sizeof(CampiBit),1,p) != 0)
        {
           imprimir_atletica(a);
        }
        fclose(p);
        free(a);
    }
}

void pontuacao_modalidade(CampiBit *al)
{
    int opcao;
    do{
        printf("\n1 - Atletismo\n");
        printf("2 - Basquete\n");
        printf("3 - Futebol de campo\n");
        printf("4 - Futsal\n");
        printf("5 - Handebol\n");
        printf("6 - Natacao\n");
        printf("7 - Peteca\n");
        printf("8 - Volei\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("\nAtletismo: %d\n", al->modalidade_atletismo);
                break;

            case 2:
                printf("\nBasquete: %d\n", al->modalidade_basquete);
                break;

            case 3:
                printf("\nFutebol de Campo: %d\n", al->modalidade_futebolcampo);
                break;

            case 4:
                printf("\nFutsal: %d\n", al->modalidade_futsal);
                break;

            case 5:
                printf("\nHandebol: %d\n", al->modalidade_handebol);
                break;

            case 6:
                printf("\nNatacao: %d\n", al->modalidade_natacao);
                break;

            case 7:
                printf("\nPeteca: %d\n", al->modalidade_peteca);
                break;

            case 8:
                printf("\nVolei: %d\n", al->modalidade_volei);
                break;

            default:
                printf("\nOpcao invalida\n");
        }

    }while(opcao > 0 && opcao < 9);
}

void pontuacao_atletica(CampiBit *al)
{
    al->pontuacao_geral = al->modalidade_atletismo + al->modalidade_basquete +
    al->modalidade_futebolcampo + al->modalidade_futsal + al->modalidade_handebol +
    al->modalidade_natacao + al->modalidade_peteca + al->modalidade_volei;

    printf("\n\nAtletismo: %d\n", al->modalidade_atletismo);
    printf("\nBasquete: %d\n", al->modalidade_basquete);
    printf("\nFutebol de Campo: %d\n", al->modalidade_futebolcampo);
    printf("\nFutsal: %d\n", al->modalidade_futsal);
    printf("\nHandebol: %d\n", al->modalidade_handebol);
    printf("\nNatacao: %d\n", al->modalidade_natacao);
    printf("\nPeteca: %d\n", al->modalidade_peteca);
    printf("\nVolei: %d\n", al->modalidade_volei);

    printf("\nPontuacao geral %s: %d\n\n", al->nome, al->pontuacao_geral);
}

int main()
{
    int opcao, cod;
    CampiBit *a;

    do{

        system("cls");
        printf("(1)-Cadastro de nova atletica\n\n");
        printf("(2)-Atualizar pontuacao de atletica\n\n");
        printf("(3)-Exibir pontuacao de atletica por modalidade\n\n");
        printf("(4)-Exibit pontuacao geral da atletica\n\n");
        printf("(5)-Relatorio geral com todas as atleticas\n\n");
        printf("(0)-Encerrar processamento\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            a = (CampiBit*) malloc(sizeof(CampiBit));
            receber_dados(a);
            cadastro_atletica(a);
            free(a);
            break;

        case 2:
            printf("\nDigite o codigo da atletica: ");
            scanf("%d", &cod);
            a = atualizar_pontuacao(cod);
            if( a != NULL )
            {
              alterar_pontuacao(a);
              gravar_pontuacao(a);
              free(a);
            }
            else
            {
                printf("\nAtletica nao encontrada!!!!\n\n");
            }
            break;

        case 3:
            printf("\nDigite o codigo da atletica: ");
            scanf("%d", &cod);
            a = atualizar_pontuacao(cod);
            if( a != NULL )
            {
              pontuacao_modalidade(a);
              free(a);
            }
            else
            {
                printf("\nAtletica nao encontrada!!!!\n\n");
            }
            break;

        case 4:
            printf("\nDigite o codigo da atletica: ");
            scanf("%d", &cod);
            a = atualizar_pontuacao(cod);
            if( a != NULL )
            {
              pontuacao_atletica(a);
              free(a);
            }
            else
            {
                printf("\nAtletica nao encontrada!!!!\n\n");
            }
            system("pause");
            break;

        case 5:
            relatorio_geral(a);
            system("pause");
            break;

        }
    }while(opcao > 0 && opcao <=6 );
    
    return 0;
}

    return 0;
}