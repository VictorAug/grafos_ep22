#include "grafos_ep22adj.h"
#include "grafos_ep22m.h"
//oisahfap
int main()
{
	int m1,m2,m3,v,w,x1 = 0,d1 = 0,d2 = 0,x2 = 0;
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
        printf("9 - Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&m1);
        switch(m1)
        {
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
                                printf("6 - Floyd Warchall\n");
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
                                            printf("\n\n");
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
                                        if(d1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MG);
                                            v = -1;
                                            while(v < 0 || v >= MG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_dijkstra(MG, v);
                                        }
                                        else
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
                                            Matriz_BELLMAN_ford2(MG, v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 6:
                                        system("cls");
                                        printf("--------------------------------------\n");
                                        printf("------------Floyd Warchall------------\n");
                                        printf("--------------------------------------\n\n");
                                        if(d1 == 1)
                                            Matriz_FLOYD_WARCHALL(MG);
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 7:
                                        system("cls");
                                        printf("-----------------------------------\n");
                                        printf("---------------Prim1---------------\n");
                                        printf("-----------------------------------\n\n");

                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("Opcao invalida!\n\n");
                                        system("pause");
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
                                                printf("\nInforme um valor de -99.99 ate 99.99 para o custo da aresta %d - %d: ",v,w);
                                                scanf("%lf",&cost);
                                            }
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
                                        if(d2 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_dijkstra(AG, v);
                                        }
                                        else
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
                                            w = adj_BELLMAN_ford(AG, v);
                                            if(w == 1){
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
                                        printf("Opcao invalida!\n");
                                }
                            }while(m3 != 9);
                            break;
                        case 9://voltar
                            break;
                        default:
                            printf("Opcao invalida!\n\n");
                            system("pause");
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
                                printf("6 - Floyd Warchall\n");
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
                                        if(x1 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= MD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_dijkstra(MD,v);
                                        }
                                        else
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
                                        printf("------------Floyd Warchall-----------\n");
                                        printf("-------------------------------------\n\n");
                                        if(x1 == 1)
                                            Matriz_FLOYD_WARCHALL(MD);
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("Opcao invalida!\n\n");
                                        system("pause");
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
                                        if(x2 == 1)
                                        {
                                            v = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_dijkstra(AD,v);
                                            adj_DIGRAPHShowCST(AD);
                                            adj_DIGRAPHShowPARENT(AD);
                                        }
                                        else
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
                                                printf("\n\n");
                                                printf("---------------------------------------\n");
                                                printf("---------Custo Caminhos Minimos--------\n");
                                                printf("---------------------------------------\n");
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
                                        printf("Opcao invalida!\n\n");
                                        system("pause");
                                }
                            }while(m3 != 9);
                            break;
                        case 9://voltar
                            break;
                        default:
                            printf("Opcao invalida!\n\n");
                            system("pause");
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
                                    if(d1 == 1)
                                    {
                                        //Matriz_DIGRAPHdel(MG);
                                        d1 = 0;
                                        printf("Matriz deletada!\n\n");
                                    }

                                    system("pause");
                                    break;
                                case 2:
                                    adj_DIGRAPHdel(AG);
                                    d2 = 0;
                                    printf("Lista deletada!\n\n");
                                    system("pause");
                                    break;
                                case 9:
                                    break;
                                default:
                                    printf("Opcao invalida!\n\n");
                                    system("pause");
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
                                    system("pause");
                                    break;
                                case 2:
                                    adj_DIGRAPHdel(AD);
                                    x2 = 0;
                                    printf("\nLista deletada!\n\n");
                                    system("pause");
                                    break;
                                case 9:
                                    break;
                                default:
                                    printf("Opcao invalida!\n\n");
                                    system("pause");
                            }
                        }while(m3 != 9);
                        break;
                    default:
                        printf("Opcao invalida!\n\n");
                        system("pause");
                }
                break;
            case 9://voltar para menu 1
                break;
            default:
                printf("Opcao invalida!\n\n");
                system("pause");
        }
    }while(m1 != 9);
    return 0;
}
