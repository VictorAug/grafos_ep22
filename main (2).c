#include "grafos_ep22adj.h"
#include "grafos_ep22m.h"

int main()
{
	int m1,m2,m3,v,w,x1 = 0,d1 = 0,d2 = 0,x2 = 0;
	int cst_negativo;
	double cost;
	adj_Digraph AG, AD;
	m_Digraph MG, MD;
	do{
        system("cls");
	    printf("--------------------------------------------------------------\n");
        printf("--------------Menu Principal: Teoria dos grafos---------------\n");
        printf("--------------------------------------------------------------\n\n");
        printf("1 - Nao Orientado (Grafo)\n");
        printf("2 - Orientado (Digrafo)\n");
        printf("3 - Reset\n");
        printf("4 - Main Test\n");
        printf("9 - Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&m1);
        switch(m1)
        {
            case 4:
                system("cls");
                printf("----------------------------------\n");
                printf("------------Main Test-------------\n");
                printf("----------------------------------\n\n");
                MD = Matriz_DIGRAPHInit(5);
                Matriz_DIGRAPHInsertA(MD, 0, 1, 3);
                Matriz_DIGRAPHInsertA(MD, 0, 3, 6);
                Matriz_DIGRAPHInsertA(MD, 1, 2, 0);
                Matriz_DIGRAPHInsertA(MD, 1, 4, -2);
                Matriz_DIGRAPHInsertA(MD, 3, 1, -1);
                Matriz_DIGRAPHInsertA(MD, 3, 4, -7);
                Matriz_DIGRAPHInsertA(MD, 4, 2, 3);
                printf("\n\nMATRIZ DIGRAPH DIJKSTRA\n\n");
                Matriz_dijkstra(MD, 0);
                printf("\n\nBELLMAN MATRIZ DIGRAPH FORD 2\n\n");
                Matriz_BELLMAN_ford2(MD, 0);
                printf("\n\nFLOYD MATRIZ DIGRAPH WARSHALL\n\n");
                Matriz_FLOYD_WARSHALL(MD);
                MG = Matriz_DIGRAPHInit(7);
                Matriz_GRAPHInsertE(MG, 0, 2, 5);
                Matriz_GRAPHInsertE(MG, 0, 3, 8);
                Matriz_GRAPHInsertE(MG, 2, 1, 16);
                Matriz_GRAPHInsertE(MG, 2, 3, 10);
                Matriz_GRAPHInsertE(MG, 2, 4, 3);
                Matriz_GRAPHInsertE(MG, 3, 5, 18);
                Matriz_GRAPHInsertE(MG, 3, 4, 2);
                Matriz_GRAPHInsertE(MG, 4, 5, 12);
                Matriz_GRAPHInsertE(MG, 4, 6, 14);
                Matriz_GRAPHInsertE(MG, 4, 1, 30);
                Matriz_GRAPHInsertE(MG, 1, 6, 26);
                Matriz_GRAPHInsertE(MG, 5, 6, 4);
                printf("\n\n\n");
                printf("ARVORES GERADORAS - MATRIZ GRAPH\n\n");
                Matriz_DIGRAPHShow(MG);
                Matriz_prim1(MG);
                printf("\n\n\n");
                AG = adj_DIGRAPHInit(7);
                adj_GRAPHInsertE(AG, 0, 2, 5);
                adj_GRAPHInsertE(AG, 0, 3, 8);
                adj_GRAPHInsertE(AG, 2, 1, 16);
                adj_GRAPHInsertE(AG, 2, 3, 10);
                adj_GRAPHInsertE(AG, 2, 4, 3);
                adj_GRAPHInsertE(AG, 3, 5, 18);
                adj_GRAPHInsertE(AG, 3, 4, 2);
                adj_GRAPHInsertE(AG, 4, 5, 12);
                adj_GRAPHInsertE(AG, 4, 6, 14);
                adj_GRAPHInsertE(AG, 4, 1, 30);
                adj_GRAPHInsertE(AG, 1, 6, 26);
                adj_GRAPHInsertE(AG, 5, 6, 4);
                printf("\n\n\n");
                printf("ARVORES GERADORAS - ADJ GRAPH\n\n");
                adj_DIGRAPHShow(AG);
                adj_prim2(AG);
                printf("\n\nADJ DIGRAPH\n\n");
                AD = adj_DIGRAPHInit(6);
                adj_DIGRAPHInsertA(AD, 0, 2, 2);
                adj_DIGRAPHInsertA(AD, 0, 4, 3);
                adj_DIGRAPHInsertA(AD, 0, 3, 4);
                adj_DIGRAPHInsertA(AD, 2, 1, 1);
                adj_DIGRAPHInsertA(AD, 2, 4, -1);
                adj_DIGRAPHInsertA(AD, 3, 4, -2);
                adj_DIGRAPHInsertA(AD, 3, 5, 1);
                adj_DIGRAPHInsertA(AD, 4, 1, 0);
                adj_DIGRAPHInsertA(AD, 4, 5, 1);
                adj_DIGRAPHInsertA(AD, 5, 1, 2);
                printf("\n\n");
                adj_DIGRAPHShow(AD);
                printf("\n\nADJ DIJKSTRA DIGRAPH\n\n");
                adj_dijkstra(AD,0);
                adj_DAGtsf(AD);
                printf("\n\nADJ DAGMIN DIGRAPH\n\n");
                adj_DAGmin(AD,0);
                printf("\n\nADJ BELLMAN DIGRAPH FORD\n\n");
                if(adj_BELLMAN_ford(AD, 0) == 1)
                {
                    adj_DIGRAPHShowPARENT(AD);
                    adj_DIGRAPHShowCST(AD);
                }
                getch();
                break;
            case 1://grafos
                do{
                    system("cls");
                    printf("-------------------------------\n");
                    printf("------------Grafos-------------\n");
                    printf("-------------------------------\n\n");
                    printf("1 - Matriz de adjacencias\n");
                    printf("2 - Lista de adjacencias\n");
                    printf("9 - Voltar\n\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d",&m2);
                    switch(m2)
                    {
                        case 1://Matriz de adjacencia
                            do{
                                printf("\n");
                                printf("-------------------------------------\n");
                                printf("----Grafos: Matriz de Adjacencias----\n");
                                printf("-------------------------------------\n\n");
                                printf("1 - Criar grafo\n");
                                printf("2 - Inserir aresta\n");
                                printf("3 - Mostrar grafo\n");
                                printf("4 - Dijkstra\n");
                                printf("5 - Bellman Ford\n");
                                printf("6 - Floyd Warshall\n");
                                printf("7 - Prim1\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Criar Grafo------------\n");
                                        printf("--------------------------------\n");
                                        if(d1 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("\nInforme o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            MG = Matriz_DIGRAPHInit(v);
                                            Matriz_DIGRAPHShow(MG);
                                            printf("\n");
                                            d1 = 1;
                                        }
                                        else
                                            printf("Nao foi possivel criar um novo conjunto de vertices!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("-----------------------------------\n");
                                        printf("---------Inserir Aresta------------\n");
                                        printf("-----------------------------------\n\n");
                                        if(d1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MG);
                                            v = w = -1;
                                            while(v < 0 || v >= MG->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= MG->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            cost = -101;
                                            while(cost < -100 || cost > 100){
                                                printf("\nInforme um valor de -99.99 ate 99.99 para o custo da aresta %d - %d: ",v,w);
                                                scanf("%lf",&cost);
                                            }
                                            printf("\n");
                                            if(cost < 0)
                                                cst_negativo = -1;
                                            Matriz_GRAPHInsertE(MG,v,w,cost);
                                        }
                                        else printf("V(G) inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("------------Mostrar Grafo------------\n");
                                        printf("-------------------------------------\n\n");
                                        if(d1 == 1)
                                            Matriz_DIGRAPHShow(MG);
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("---------------------------------\n");
                                        printf("-------------Dijkstra------------\n");
                                        printf("---------------------------------\n\n");
                                        if(d1 == 1 && cst_negativo == 1)
                                        {
                                            Matriz_DIGRAPHShow(MG);
                                            v = -1;
                                            while(v < 0 || v >= MG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_dijkstra(MG, v);
                                        }
                                        else if(cst_negativo < 0)
                                            printf("O grafo contem aresta com custo negativo!\n");
                                        else if(d1 == 0)
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 5:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("-------------Bellman Ford------------\n");
                                        printf("-------------------------------------\n\n");
                                        if(d1 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= MG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n\n------------------------------------------------------------\n");
                                            printf("----------Vetor Custo a Partir do Vertice de Origem---------\n");
                                            printf("------------------------------------------------------------\n\n");
                                            Matriz_BELLMAN_ford2(MG,v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("--------------------------------------\n");
                                        printf("------------Floyd Warshall------------\n");
                                        printf("--------------------------------------\n\n");
                                        if(d1 == 1)
                                            Matriz_FLOYD_WARSHALL(MG);
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 7:
                                        system("cls");
                                        printf("-----------------------------------\n");
                                        printf("---------------Prim1---------------\n");
                                        printf("-----------------------------------\n\n");
                                        if(d1 == 1)
                                            Matriz_prim1(MG);
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("\nOpcao invalida!\n\n");
                                        getch();
                                }
                            }while(m3 != 9);
                            break;
                        case 2://Lista de adjacencias
                            do{
                                printf("\n");
                                printf("--------------------------------------\n");
                                printf("-----Grafos: Lista de Adjacencias-----\n");
                                printf("--------------------------------------\n\n");
                                printf("1 - Criar grafo\n");
                                printf("2 - Inserir aresta\n");
                                printf("3 - Mostrar grafo\n");
                                printf("4 - Dijkstra\n");
                                printf("5 - Bellman Ford\n");
                                printf("6 - Prim2\n");
                                printf("7 - Kruskal\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Criar Grafo------------\n");
                                        printf("--------------------------------\n");
                                        if(d2 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("\nInforme o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            AG = adj_DIGRAPHInit(v);
                                            adj_DIGRAPHShow(AG);
                                            printf("\n");
                                            d2 = 1;
                                        }
                                        else
                                            printf("Nao foi possivel criar um novo conjunto de vertices!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Inserir Aresta---------\n");
                                        printf("--------------------------------\n\n");
                                        if(d2 == 1)
                                        {
                                            adj_DIGRAPHShow(AG);
                                            v = w = -1;
                                            while(v < 0 || v >= AG->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= AG->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            cost = -101;
                                            while(cost < -100 || cost > 100){
                                                printf("\nInforme um valor para o custo da aresta %d - %d: ",v,w);
                                                scanf("%lf",&cost);
                                            }
                                            if(cost < 0)
                                                cst_negativo = -1;
                                            else
                                                cst_negativo = 2;
                                            adj_GRAPHInsertE(AG, w, v, cost);
                                            adj_DIGRAPHShow(AG);
                                        }
                                        else printf("Grafo inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("----------Mostrar Grafo-----------\n");
                                        printf("----------------------------------\n\n");
                                        if(d2 == 1)
                                        {
                                            adj_DIGRAPHShow(AG);
                                            printf("\n");
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("---------------Dijkstra--------------\n");
                                        printf("-------------------------------------\n");
                                        if(d2 == 1 && cst_negativo == 2)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_dijkstra(AG, v);
                                        }
                                        else if(cst_negativo == -1)
                                            printf("O grafo contem aresta com custo negativo!\n");
                                        else if(d2 == 0)
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 5:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("-------------Bellman Ford------------\n");
                                        printf("-------------------------------------\n");
                                        if(d2 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AG->V){
                                                printf("\nInforme um vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            if(adj_BELLMAN_ford(AG, v) == 1){
                                                adj_DIGRAPHShowCST(AG);
                                                adj_DIGRAPHShowPARENT(AG);
                                            }
                                            else printf("\nO grafo tem ciclo negativo acessivel a partir de %d!\n",v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("----------------Prim2----------------\n");
                                        printf("-------------------------------------\n\n");
                                        if(d2 == 1)
                                            adj_prim2(AG);
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 7:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("---------------Kruskal---------------\n");
                                        printf("-------------------------------------\n\n");
                                        if(d2 == 1)
                                            adj_Kruskal(AG);
                                        else
                                            printf("Grafo inexistente!\n");
                                    case 9:
                                        break;
                                    default:
                                        printf("\nOpcao invalida!\n");
                                        getch();
                                }
                            }while(m3 != 9);
                            break;
                        case 9://voltar
                            break;
                        default:
                            printf("\nOpcao invalida!\n\n");
                            getch();
                    }
                }while(m2 != 9);
                break;
            case 2://Digrafos
                do{
                    system("cls");
                    printf("---------------------------------------\n");
                    printf("----------------Digrafos---------------\n");
                    printf("---------------------------------------\n\n");
                    printf("1 - Matriz de adjacencias\n");
                    printf("2 - Lista de adjacencias\n");
                    printf("9 - Voltar\n\n");
                    printf("Escolha uma das opcoes: ");
                    scanf("%d",&m2);
                    switch(m2)
                    {
                        case 1://Matriz de adjacencia
                            do{
                                printf("\n");
                                printf("--------------------------------------\n");
                                printf("----Digrafos: Matriz de Adjacencia----\n");
                                printf("--------------------------------------\n\n");
                                printf("1 - Criar digrafo\n");
                                printf("2 - Inserir arco\n");
                                printf("3 - Mostrar digrafo\n");
                                printf("4 - Dijkstra\n");
                                printf("5 - Bellman Ford\n");
                                printf("6 - Floyd Warshall\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("---------Criar Digrafo------------\n");
                                        printf("----------------------------------\n");
                                        if(x1 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX){
                                                printf("\nInforme o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            MD = Matriz_DIGRAPHInit(v);
                                            Matriz_DIGRAPHShow(MD);
                                            printf("\n");
                                            x1 = 1;
                                        }
                                        else
                                            printf("V(G) jah definido!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("---------Inserir Arco-------------\n");
                                        printf("----------------------------------\n\n");
                                        if(x1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MD);
                                            v = w = -1;
                                            while(v < 0 || v >= MD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= MD->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            cost = -101;
                                            while(cost < -100 || cost >= 100)
                                            {
                                                printf("\nInforme o custo do arco: ");
                                                scanf("%lf",&cost);
                                            }
                                            if(cost < 0)
                                                cst_negativo = -1;
                                            else cst_negativo = 3;
                                            Matriz_DIGRAPHInsertA(MD, v, w, cost);
                                            printf("\n");
                                            Matriz_DIGRAPHShow(MD);
                                            printf("\n");
                                        }
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("-----------Mostrar Digrafo-----------\n");
                                        printf("-------------------------------------\n\n");
                                        if(x1 == 1)
                                            Matriz_DIGRAPHShow(MD);
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("-------------Dijkstra-----------\n");
                                        printf("--------------------------------\n");
                                        if(x1 == 1 && cst_negativo == 3)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= MD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_dijkstra(MD,v);
                                        }
                                        else if(cst_negativo == -1)
                                            printf("\nO digrafo contem arco com custo negativo!\n");
                                        else if(x1 == 0)
                                            printf("\nDigrafo inexistente!\n");
                                        break;
                                    case 5:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("------------Bellman Ford-------------\n");
                                        printf("-------------------------------------\n");
                                        if(x1 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= MD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_BELLMAN_ford2(MD,v);
                                        }
                                        else
                                            printf("\nDigrafo inexistente!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("------------Floyd Warshall-----------\n");
                                        printf("-------------------------------------\n\n");
                                        if(x1 == 1)
                                            Matriz_FLOYD_WARSHALL(MD);
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("\nOpcao invalida!\n\n");
                                        getch();
                                }
                            }while(m3 != 9);
                            break;
                        case 2://Lista de adjacencias
                            do{
                                printf("\n");
                                printf("--------------------------------------\n");
                                printf("----Digrafos: Lista de Adjacencias----\n");
                                printf("--------------------------------------\n\n");
                                printf("1 - Criar digrafo\n");
                                printf("2 - Inserir arco\n");
                                printf("3 - Mostrar digrafo\n");
                                printf("4 - DAGmin\n");
                                printf("5 - Dijkstra\n");
                                printf("6 - Bellman Ford\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("---------Criar Digrafo------------\n");
                                        printf("----------------------------------\n\n");
                                        if(x2 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("\nInforme o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            AD = adj_DIGRAPHInit(v);
                                            adj_DIGRAPHShow(AD);
                                            printf("\n");
                                            x2 = 1;
                                        }
                                        else
                                            printf("Nao foi possivel criar um novo conjunto de vertices!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Inserir Arco-----------\n");
                                        printf("--------------------------------\n\n");
                                        if(x2 == 1)
                                        {
                                            adj_DIGRAPHShow(AD);
                                            v = w = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= AD->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            cost = -101;
                                            while(cost < -100 || cost >= 100)
                                            {
                                                printf("\nInforme o custo do arco: ");
                                                scanf("%lf",&cost);
                                            }
                                            if(cost < 0)
                                                cst_negativo = -1;
                                            else
                                                cst_negativo = 4;
                                            adj_DIGRAPHInsertA(AD, v, w, cost);
                                            adj_DIGRAPHShow(AD);
                                            printf("\n");
                                        }
                                        else printf("Digrafo inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("---------Mostrar Digrafo-------------\n");
                                        printf("-------------------------------------\n\n");
                                        if(x2 == 1)
                                            adj_DIGRAPHShow(AD);
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("---------------DAGmin----------------\n");
                                        printf("-------------------------------------\n");
                                        v = -1;
                                        if(x2 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_DAGtsf(AD);
                                            adj_DAGmin(AD,v);
                                        }
                                        else
                                            printf("\nDigrafo inexistente!\n");
                                        break;
                                    case 5:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("--------------Dijkstra---------------\n");
                                        printf("-------------------------------------\n");
                                        if(x2 == 1 && cst_negativo == 4)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_dijkstra(AD,v);
                                        }
                                        else if(cst_negativo == -1)
                                            printf("\nO digrafo contem arco com custo negativo!\n");
                                        else if(x2 == 0)
                                            printf("\nDigrafo inexistente!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("-------------Bellman Ford------------\n");
                                        printf("-------------------------------------\n");
                                        if(x2 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            if(adj_BELLMAN_ford(AD,v) == 1)
                                            {
                                                printf("\n\n------------------------------------------------------------\n");
                                                printf("----------Vetor Custo a Partir do Vertice de Origem---------\n");
                                                printf("------------------------------------------------------------\n\n");
                                                adj_DIGRAPHShowCST(AD);
                                                adj_DIGRAPHShowPARENT(AD);
                                                printf("\n");
                                            }
                                        }
                                        else
                                            printf("\nDigrafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("\nOpcao invalida!\n\n");
                                        getch();
                                }
                            }while(m3 != 9);
                            break;
                        case 9://voltar
                            break;
                        default:
                            printf("\nOpcao invalida!\n\n");
                            getch();
                    }
                }while(m2 != 9);
                break;
            case 3:
                system("cls");
                printf("----------------------\n");
                printf("---------Reset--------\n");
                printf("----------------------\n\n");
                printf("1 - Deletar Grafo\n");
                printf("2 - Deletar Digrafo\n");
                printf("9 - Voltar\n\n");
                printf("Escolha uma opcao: ");
                scanf("%d",&m2);
                switch(m2)
                {
                    case 1:
                        do{
                            system("cls");
                            printf("-----------------------\n");
                            printf("------Deletar Grafo----\n");
                            printf("-----------------------\n\n");
                            printf("1 - Deletar Matriz\n");
                            printf("2 - Deletar Lista\n");
                            printf("9 - Voltar\n\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d",&m3);
                            switch(m3)
                            {
                                case 1:
                                    //Matriz_DIGRAPHdel(MG);
                                    d1 = 0;
                                    printf("Matriz deletada!\n\n");
                                    getch();
                                    break;
                                case 2:
                                    adj_DIGRAPHdel(AG);
                                    d2 = 0;
                                    printf("Lista deletada!\n\n");
                                    getch();
                                    break;
                                case 9:
                                    break;
                                default:
                                    printf("\nOpcao invalida!\n\n");
                                    getch();
                            }
                        }while(m3 != 9);
                        break;
                    case 2:
                        do{
                            system("cls");
                            printf("-------------------------\n");
                            printf("------Deletar Digrafo----\n");
                            printf("-------------------------\n\n");
                            printf("1 - Deletar Matriz\n");
                            printf("2 - Deletar Lista\n");
                            printf("9 - Voltar\n\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d",&m3);
                            switch(m3)
                            {
                                case 1:
                                    //Matriz_DIGRAPHdel(MD);
                                    x1 = 0;
                                    printf("\nMatriz deletada!\n\n");
                                    getch();
                                    break;
                                case 2:
                                    adj_DIGRAPHdel(AD);
                                    x2 = 0;
                                    printf("\nLista deletada!\n\n");
                                    getch();
                                    break;
                                case 9:
                                    break;
                                default:
                                    printf("\nOpcao invalida!\n\n");
                                    getch();
                            }
                        }while(m3 != 9);
                        break;
                    default:
                        printf("\nOpcao invalida!\n\n");
                        getch();
                }
                break;
            case 9://voltar para menu 1
                break;
            default:
                printf("\nOpcao invalida!\n\n");
                getch();
        }
    }while(m1 != 9);
    return 0;
}
