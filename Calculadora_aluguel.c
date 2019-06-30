#include <stdio.h>
#include <stdlib.h>

void Header()
{
    printf("RESCISAO DE CONTRATO PREMATURA\n");
    printf("-----------------------------------\n\n");
}

int main()
{
    int diasMes = 99, cicloInicio = 99, cicloFim = 99, resContrato = 99, diasCobrar = 0;
    int deNovo = 0, op = 0;
    double vMensalidade = 0, vDiaria = 0, vFinal = 0;


    do
    {
        if(deNovo == 0)
        {
            diasMes = 99;
            cicloInicio = 99;
            cicloFim = 99;
            resContrato = 99;
            diasCobrar = 0;
            deNovo = 0;
            op = 0;
            vMensalidade = 0;
            vDiaria = 0;
            vFinal = 0;
        }

       do
        {
            system("cls");
            Header();
            printf("Digite a quantidade de dias no mes:\n> ");
            scanf("%d", &diasMes);
            if(diasMes < 28 || diasMes > 31)
            {
                printf("Os meses tem no minimo 28 e no maximo 31 dias.\n\n");
                diasMes = 99;
                system("pause");
            }
        }while(diasMes == 99);

        do
        {
            system("cls");
            Header();
            printf("Digite o valor da mensalidade:\n> ");
            scanf("%lf", &vMensalidade);
            if(vMensalidade <= 0)
            {
                printf("O valor da mensalidade nao pode ser menor ou igual a zero.\n\n");
                vMensalidade = 0;
                system("pause");
            }

        }while(vMensalidade <= 0);

        do
        {
            system("cls");
            Header();
            printf("Digite o dia de inicio do ciclo de cobranca:\n> ");
            scanf("%d", &cicloInicio);
            if(cicloInicio > diasMes || cicloInicio < 1)
            {
                printf("O ciclo deve ser entre os dias 01 e o dia %d.\n\n", diasMes);
                cicloInicio = 99;
                cicloFim = 99;
                system("pause");
            }
            cicloFim = cicloInicio - 1;
            if(cicloFim <= 0)
            {
                cicloFim = diasMes;
            }

        }while(cicloInicio > 31 || cicloInicio < 1);

        do
        {
            system("cls");
            Header();
            printf("Digite o dia do mes da rescisao do contrato:\n> ");
            scanf("%d", &resContrato);
            if(resContrato > diasMes || resContrato < 1)
            {
                printf("A rescisao deve ser entre os dias 01 e o dia %d.\n\n", diasMes);
                resContrato = 99;
                system("pause");
            }
        }while(resContrato > 31 || resContrato < 1);


        //contas
        vDiaria = vMensalidade / diasMes;

        system("cls");
        if(resContrato == cicloFim)
        {
            Header();
            vFinal = vMensalidade;
            printf("O dia de rescisao e o de final do ciclo coincidem.\n Nao ha cobranca extra a fazer.\n");
            printf("VALOR FINAL: R$ %.2lf\n\n", vFinal);
            system("pause");
        }

        if(resContrato != cicloInicio)
        {
            if(resContrato < cicloInicio)
            {
                diasCobrar = (diasMes - cicloInicio) + resContrato;

                vFinal = vMensalidade + (vDiaria * diasCobrar);
                Header();
                printf("MENSALIDADE: R$ %.2lf\n", vMensalidade);
                printf("DIAS NO MES: %d\n", diasMes);
                printf("Diarias a cobrar: %d\n", diasCobrar);
                printf("Valor total das diarias: R$ %.2lf\n\n", vDiaria * diasCobrar);
                printf("VALOR FINAL (MENSALIDADE + DIARIAS): R$ %.2lf\n\n", vFinal);
                system("pause");
            }
            else
            {
                diasCobrar = (resContrato - cicloInicio);

                vFinal = vMensalidade + (vDiaria * diasCobrar);
                Header();
                printf("MENSALIDADE: R$ %.2lf\n", vMensalidade);
                printf("DIAS NO MES: %d\n", diasMes);
                printf("Valor da diaria: R$ %.2lf\n", vDiaria);
                printf("Diarias a cobrar: %d\n", diasCobrar);
                printf("Valor total das diarias: R$ %.2lf\n\n", vDiaria * diasCobrar);
                printf("VALOR FINAL (MENSALIDADE + DIARIAS): R$ %.2lf\n\n", vFinal);
                system("pause");
            }
        }


            system("cls");
            Header();
            printf("Deseja calcular novamente? (1. Sim - 2. Nao)\n> ");
            scanf("%d", &op);

            switch(op)
            {
                case 1:
                    deNovo = 1;
                    break;
                case 2:
                    deNovo = 0;
                    break;

                default:
                    printf("Digite uma opcao valida.\n");
                    break;
            }
    }while(deNovo == 1);

    system("cls");
    Header();
    printf("Ate mais.\n\n");
    system("pause");
}
