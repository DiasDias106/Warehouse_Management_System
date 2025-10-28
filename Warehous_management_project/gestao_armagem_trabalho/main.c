#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <unistd.h>
#include <string.h>
int MENU_CLIENTES();
int MENU_PRODUTOS();
int MENU_VENDAS();
int MENU_INICIAL();
int listar_cliente();
int apagar_cliente();
int criar_clientes();
int alterar_cliente();
int pesquisar_cliente();
int ver_produtos();
int pesquisar_produtos();
int criar_produtos();
int apagar_produtos();
int alterar_produtos();
int inserir_venda();
int ver_vendas();
int pesquisar_venda();
int total_de_vendas();
int opcao;
struct clientes
{
    char nome[20];
    int nif;
    char morada[30];
    int telefone;
};
struct produtos
{
    char nome[30];
    int id;
    int quantidade;
    float preco;
};
struct vendas
{
    int nif;
    int id[20];
    int quantidade[20];
    float preco[20];
    float total[20];

};

int MENU_INICIAL(){
    system("cls");

    printf("=============================================\n");
    printf("           Bem-vindo ao Bazar do Aladino :)   \n");
    printf("=============================================\n\n");
    printf("\n\n");

     printf("  MENU Inicial -------------------\n");
        printf("                                           \n");
        printf("      Clientes    : l                      \n");
        printf("      Produtos    : 2                      \n");
        printf("      Vendas      : 3                      \n");
        printf("      Sair        : -1                     \n");
        printf("                                           \n");
        printf("Introduza uma das opcoes: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
            MENU_CLIENTES();break;
            case 2:
            MENU_PRODUTOS();break;
            case 3:
            MENU_VENDAS();break;
            default :
            return 0;
        }

}
int MENU_CLIENTES(){
    system("cls");
    printf("  MENU CLIENTES -------------------\n");
        printf("                                            \n");
        printf("      CRIAR clientes     : l                \n");
        printf("      LISTAR clientes      : 2              \n");
        printf("      APAGAR clientes      : 3              \n");
        printf("      Pesquisar clientes   : 4              \n");
        printf("      Alterar  clientes    :  5             \n");
        printf("      Menu inicial        : -1              \n");
        printf("                                            \n");
        printf("Introduza uma das opcoes: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
            criar_clientes();break;
            case 2:
            listar_cliente();break;
            case 3:
            apagar_cliente();break;
            case 4:
            pesquisar_cliente();break;
            case 5:
            alterar_cliente();break;
            default :
            MENU_INICIAL();break;
        }
}
int MENU_PRODUTOS(){
    system("cls");
     printf("  MENU PRODUTOS -------------------\n");
        printf("                                           \n");
         printf("     CRIAR produtos   : 1                 \n");
        printf("      VER produtos     : 2                 \n");
        printf("      PESQUISAR produtos : 3               \n");
        printf("      ALTERAR produtos : 4                 \n");
        printf("      APAGAR produtos  : 5                 \n");
        printf("      Menu inicial     : -1                \n");
        printf("                                           \n");
        printf("Introduza uma das opcoes: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
            criar_produtos();break;
            case 2:
            ver_produtos();break;
            case 3:
            pesquisar_produtos();break;
            case 4:
            alterar_produtos();break;
            case 5:
            apagar_produtos();break;
            default :
            MENU_INICIAL();break;
        }
}
int MENU_VENDAS(){
    system("cls");
     printf("  MENU VENDAS -------------------\n");
        printf("                                           \n");
        printf("      inserir venda : l                    \n");
        printf("      ver vendas    : 2                     \n");
        printf("      pesquisar venda  : 3                 \n");
        printf("      total de vendas  : 4                 \n");
        printf("      menu inicial     : -1                \n");
        printf("                                           \n");
        printf("Introduza uma das opcoes: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
            inserir_venda();break;
            case 2:
            ver_vendas();break;
            case 3:
            pesquisar_venda();break;
            case 4:
            total_de_vendas();break;
            default :
            MENU_INICIAL();break;
        }
}

int main(){
setlocale(LC_ALL,"");
MENU_INICIAL();
}

int criar_clientes() {
    struct clientes cliente;

    printf("Nome: ");
    scanf("%s", cliente.nome);
    printf("NIF: ");
    scanf("%d", &cliente.nif);
    printf("Morada: ");
    scanf("%s", cliente.morada);
    printf("Telefone: ");
    scanf("%d", &cliente.telefone);

    FILE *ficheiro = fopen("clientes.txt", "a");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(ficheiro, "Nome: %s\n", cliente.nome);
    fprintf(ficheiro, "NIF: %d\n", cliente.nif);
    fprintf(ficheiro, "Morada: %s\n", cliente.morada);
    fprintf(ficheiro, "Telefone: %d\n", cliente.telefone);

    fclose(ficheiro);

    printf("Guardado com sucesso.\n");

    return MENU_CLIENTES();
}

int listar_cliente() {
    int opcao;
    FILE *ficheiro = fopen("clientes.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    struct clientes cliente_lido;
    while (fscanf(ficheiro, "Nome: %s\nNIF: %d\nMorada: %s\nTelefone: %d\n",
            &cliente_lido.nome, &cliente_lido.nif, &cliente_lido.morada, &cliente_lido.telefone) == 4) {

        printf("Nome: %s\n", cliente_lido.nome);
        printf("NIF: %d\n", cliente_lido.nif);
        printf("Morada: %s\n", cliente_lido.morada);
        printf("Telefone: %d\n", cliente_lido.telefone);
        printf("--------\n");
    }
    fclose(ficheiro);
    printf("voltar digite 1 \n");
    scanf("%d",&opcao);
    if(opcao==1){
     return MENU_CLIENTES();
    }
}

int apagar_cliente(){
    FILE *ficheiro_original = fopen("clientes.txt", "r");

    if (ficheiro_original == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    FILE *ficheiro_temporario = fopen("clientes_temp.txt", "w");

    if (ficheiro_temporario == NULL) {
        printf("Erro ao criar o arquivo temporario.\n");
        fclose(ficheiro_original);
        return 1; 
    }

    int nif_a_remover;
    printf("Digite o NIF a ser removido: ");
    scanf("%d", &nif_a_remover);

    struct clientes cliente_atual;

    int nif_encontrado = 0;

    while (fscanf(ficheiro_original, "Nome: %s\nNIF: %d\nMorada: %s\nTelefone: %d\n",
            &cliente_atual.nome, &cliente_atual.nif, &cliente_atual.morada, &cliente_atual.telefone) == 4) {

        if (cliente_atual.nif == nif_a_remover) {
            nif_encontrado = 1;
            printf("Informacao com NIF %d removida.\n", nif_a_remover);
        } else {
            fprintf(ficheiro_temporario, "Nome: %s\n", cliente_atual.nome);
            fprintf(ficheiro_temporario, "NIF: %d\n", cliente_atual.nif);
            fprintf(ficheiro_temporario, "Morada: %s\n", cliente_atual.morada);
            fprintf(ficheiro_temporario, "Telefone: %d\n", cliente_atual.telefone);
        }
    }

    fclose(ficheiro_original);
    fclose(ficheiro_temporario);

    if (remove("clientes.txt") != 0) {
        printf("Erro ao remover o arquivo original.\n");
        return 1; 
    }
    if (rename("clientes_temp.txt", "clientes.txt") != 0) {
        printf("Erro ao renomear o arquivo tempor�rio.\n");
        return 1; 
    }

    return MENU_CLIENTES();
}

int pesquisar_cliente(){
    int opcao;
    FILE *ficheiro= fopen("clientes.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    int nif_a_encontrar;
    printf("Digite o NIF a ser encontrado: ");
    scanf("%d", &nif_a_encontrar);

    struct clientes cliente_atual;

    int nif_encontrado = 0;

    while (fscanf(ficheiro, "Nome: %s\nNIF: %d\nMorada: %s\nTelefone: %d\n",
            &cliente_atual.nome, &cliente_atual.nif, &cliente_atual.morada, &cliente_atual.telefone) == 4) {
        if (cliente_atual.nif == nif_a_encontrar) {
            nif_encontrado = 1;
            printf("Nome: %s\n", cliente_atual.nome);
            printf("NIF: %d\n", cliente_atual.nif);
            printf("Morada: %s\n", cliente_atual.morada);
            printf("Telefone: %d\n", cliente_atual.telefone);
        }
      }
      if(nif_encontrado==0){
        printf("\nNIF nao encontrado\n");
      }
    fclose(ficheiro);
    printf("voltar digite 1 \n");
    scanf("%d",&opcao);
    if(opcao==1){
        return MENU_CLIENTES();
    }
}

int alterar_cliente() {
    int opcao;
    int sucesso;
    sucesso = 0;
    FILE *ficheiro = fopen("clientes.txt", "r");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int nif_a_encontrar;
    printf("Digite o NIF a ser encontrado: ");
    scanf("%d", &nif_a_encontrar);

    struct clientes cliente_atual;
    FILE *ficheiro_temporario = fopen("clientes_temp.txt", "w");
    if (ficheiro_temporario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    while (fscanf(ficheiro, "Nome: %s\nNIF: %d\nMorada: %s\nTelefone: %d\n",
        &cliente_atual.nome, &cliente_atual.nif, &cliente_atual.morada, &cliente_atual.telefone) == 4) {
        if (cliente_atual.nif == nif_a_encontrar) {

            sucesso = 1;
            printf("Digite o novo nome: ");
            scanf("%s", cliente_atual.nome);
            printf("Digite a nova morada: ");
            scanf("%s", &cliente_atual.morada);
            printf("Digite o novo telefone: ");
            scanf("%d", &cliente_atual.telefone);
        }

        fprintf(ficheiro_temporario, "Nome: %s\n", cliente_atual.nome);
        fprintf(ficheiro_temporario, "NIF: %d\n", cliente_atual.nif);
        fprintf(ficheiro_temporario, "Morada: %s\n", cliente_atual.morada);
        fprintf(ficheiro_temporario, "Telefone: %d\n", cliente_atual.telefone);
    }

    fclose(ficheiro);
    fclose(ficheiro_temporario);

    remove("clientes.txt");
    rename("clientes_temp.txt", "clientes.txt");

    if(sucesso == 1)
    {
        printf("\nCliente atualizado com sucesso!\n");
    }
    else
    {
        printf("Nenhum cliente atualizado!\n");
    }

  printf("Voltar digite 1: ");
  scanf("%d", &opcao);

   if(opcao == 1){
        return MENU_CLIENTES();
    }
}

int criar_produtos(){

    struct produtos produto;

    printf("Nome: ");
    scanf("%s", &produto.nome);
    printf("ID: ");
    scanf("%d", &produto.id);
    printf("Quantidade: ");
    scanf("%d", &produto.quantidade);
    printf("Preco: ");
    scanf("%f", &produto.preco);

    FILE *ficheiro = fopen("produtos.txt", "a");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(ficheiro, "Nome: %s\n", produto.nome);
    fprintf(ficheiro, "ID: %d\n", produto.id);
    fprintf(ficheiro, "Quantidade: %d\n", produto.quantidade);
    fprintf(ficheiro, "Preco: %f\n", produto.preco);


    fclose(ficheiro);

    printf("Guardado com sucesso.\n");

    return MENU_PRODUTOS();
}


int ver_produtos() {
    int opcao;
    FILE *ficheiro = fopen("produtos.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    struct produtos produto;
     while (fscanf(ficheiro, "Nome: %s\nID: %d\nQuantidade: %d\nPreco: %f\n",
                  &produto.nome, &produto.id, &produto.quantidade, &produto.preco) == 4) {

        printf("Nome: %s\n", produto.nome);
        printf("ID: %d\n", produto.id);
        printf("Quantidade: %d\n", produto.quantidade);
        printf("Preco: %.2f\n", produto.preco);
        printf("--------\n");

    }
    fclose(ficheiro);
    printf("voltar digite 1 \n");
    scanf("%d",&opcao);
    if(opcao==1){
     return MENU_PRODUTOS();
    }
}

int pesquisar_produtos(){
    int opcao;
    FILE *ficheiro= fopen("produtos.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // ID a ser encontrado
    int id_a_encontrar;
    printf("Digite o ID a ser encontrado: ");
    scanf("%d", &id_a_encontrar);

    struct produtos produto_atual;

    int id_encontrado = 0;

    while (fscanf(ficheiro, "Nome: %s\nID: %d\nQuantidade: %d\nPreco: %f\n",
                  &produto_atual.nome, &produto_atual.id, &produto_atual.quantidade, &produto_atual.preco) == 4) {
        if (produto_atual.id == id_a_encontrar) {
            id_encontrado = 1;
            printf("\n\nNome: %s\n", produto_atual.nome);
            printf("ID: %d\n", produto_atual.id);
            printf("Quantidade: %d\n", produto_atual.quantidade);
            printf("Preco: %.2f\n", produto_atual.preco);
        }
    }

    fclose(ficheiro);

    if (id_encontrado) {
        printf("Produto encontrado.\n");
    } else {
        printf("Produto com ID %d nao encontrado.\n", id_a_encontrar);
    }

    printf("Voltar? Digite 1\n");
    scanf("%d", &opcao);

    if(opcao == 1){
        return MENU_PRODUTOS();
    }

    return 0;
}


int apagar_produtos(){

    FILE *ficheiro_original = fopen("produtos.txt", "r");

    if (ficheiro_original == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    FILE *ficheiro_temporario = fopen("produtos_temp.txt", "w");

    if (ficheiro_temporario == NULL) {
        printf("Erro ao criar o arquivo temporario.\n");
        fclose(ficheiro_original);
        return 1;
    }

    int id_a_remover;
    printf("Digite o ID a ser removido: ");
    scanf("%d", &id_a_remover);

    struct produtos produto_atual;

    int id_encontrado = 0;

    while (fscanf(ficheiro_original, "Nome: %s\nID: %d\nQuantidade: %d\nPreco: %f\n",
                  &produto_atual.nome, &produto_atual.id, &produto_atual.quantidade, &produto_atual.preco) == 4) {

        if (produto_atual.id == id_a_remover) {
            id_encontrado = 1;
            printf("Informacao com ID %d removida.\n", id_a_remover);
        } else {
            fprintf(ficheiro_temporario, "Nome: %s\n", produto_atual.nome);
            fprintf(ficheiro_temporario, "ID: %d\n", produto_atual.id);
            fprintf(ficheiro_temporario, "Quantidade: %d\n", produto_atual.quantidade);
            fprintf(ficheiro_temporario, "Preco: %f\n", produto_atual.preco);
        }
    }

    fclose(ficheiro_original);
    fclose(ficheiro_temporario);

    if (remove("produtos.txt") != 0) {

        printf("Erro ao remover o arquivo original.\n");
        return 1;
    }
    if (rename("produtos_temp.txt", "produtos.txt") != 0) {
        printf("Erro ao renomear o arquivo temporario.\n");
        return 1; 
    }

    return MENU_PRODUTOS();
}

 int alterar_produtos() {
    int opcao;
    int sucesso = 0;
    FILE *ficheiro = fopen("produtos.txt", "r");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int id_a_encontrar;
    printf("Digite o ID a ser encontrado: ");
    scanf("%d", &id_a_encontrar);

    struct produtos produtos_atual;
    FILE *ficheiro_temporario = fopen("produtos_temp.txt", "w");
    if (ficheiro_temporario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    while (fscanf(ficheiro, "Nome: %s\nID: %d\nQuantidade: %d\nPreco: %f\n",
        &produtos_atual.nome, &produtos_atual.id, &produtos_atual.quantidade, &produtos_atual.preco) == 4) {
        if (produtos_atual.id == id_a_encontrar) {
            sucesso = 1;
            printf("Digite o novo nome: ");
            scanf("%s", produtos_atual.nome);
            printf("Digite a nova quantidade: ");
            scanf("%d", &produtos_atual.quantidade);
            printf("Digite o novo preco: ");
            scanf("%f", &produtos_atual.preco);
        }
    fprintf(ficheiro_temporario, "Nome: %s\n", produtos_atual.nome);
    fprintf(ficheiro_temporario, "ID: %d\n", produtos_atual.id);
    fprintf(ficheiro_temporario, "Quantidade: %d\n", produtos_atual.quantidade);
    fprintf(ficheiro_temporario, "Preco: %f\n", produtos_atual.preco);

    }

    fclose(ficheiro);
    fclose(ficheiro_temporario);

    remove("produtos.txt");
    rename("produtos_temp.txt", "produtos.txt");


    if(sucesso == 1)
    {
        printf("Produto atualizado com sucesso!\n");
    }
    else
    {
        printf("Nenhum produto atualizado!\n");
    }

  printf("Digite 1 para voltar: ");
  scanf("%D", &opcao);

   if(opcao == 1){
        return MENU_PRODUTOS();
    }
 }


int inserir_venda(){
    int i,v;

    int m_nif[100], conta;
    int nif_existente = 0;

    conta=0;
    struct clientes cliente;
    FILE *ficheiro_clientes = fopen("clientes.txt", "r");
    if (ficheiro_clientes == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    struct clientes cliente_lido;
    while (fscanf(ficheiro_clientes, "Nome: %s\nNIF: %d\nMorada: %s\nTelefone: %d\n",
            cliente_lido.nome, &cliente_lido.nif, cliente_lido.morada, &cliente_lido.telefone) == 4) {

        printf("Nome: %s\n", cliente_lido.nome);
        printf("NIF: %d\n", cliente_lido.nif);
        printf("Telefone: %d\n", cliente_lido.telefone);
        printf("--------\n");
        m_nif[conta] = cliente_lido.nif;
        conta += 1;
    }
    fclose(ficheiro_clientes);
    struct vendas venda;
    printf("digite o NIF para o qual vai fazer a venda: \n ");
    scanf("%d",&venda.nif);
    system("cls");

    for (i = 0; i < conta; i++) {
        if (venda.nif == m_nif[i]) {
            nif_existente = 1;
            break;
        }
    }

    if (nif_existente == 1) {
        printf("NIF Encontrado.\n");

    } else {
        printf("NIF nao encontrado.\n");
        sleep(4);
        return MENU_VENDAS();
    }

    printf("\n\n Todos os produtos \n \n");

    int opcao_2;
    do{

        printf("\n\n****Todos os produtos****\n\n");
        struct produtos produto[100];
        FILE *ficheiro_produtos = fopen("produtos.txt", "r");

        if (ficheiro_produtos == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        int contar_p=0;
        while (fscanf(ficheiro_produtos, "Nome: %s\nID: %d\nQuantidade: %d\nPreco: %f\n",
                produto[contar_p].nome, &produto[contar_p].id, &produto[contar_p].quantidade, &produto[contar_p].preco) == 4) {

            if(produto[contar_p].quantidade != 0)
            {
                printf("Nome: %s\n", produto[contar_p].nome);
                printf("ID: %d\n", produto[contar_p].id);
                printf("Quantidade: %d\n", produto[contar_p].quantidade);
                printf("Preco: %.2f\n", produto[contar_p].preco);
                printf("--------\n");
                contar_p++;
            }

        }

        fclose(ficheiro_produtos);
        int id;
        int id_encontrado=0;
        int quantidade;
        int quantidade_encontrada=0;

        int nv=0;
        printf("digite o ID do produto de interesse \n");
        scanf("%d",&id);
        for(int j=0;j<contar_p;j++){
            if(id==produto[j].id){
                id_encontrado=1;
                printf("\nDigite a quantidade desejada: ");
                scanf("%d", &quantidade);
                if (quantidade > produto[j].quantidade) {

                    printf("Quantidade n�o encontrada\n");
                    sleep(5);
                    return MENU_VENDAS();
                }
                else{
                    quantidade_encontrada = 1;
                    venda.id[nv]=id;
                    venda.preco[nv] = produto[j].preco;
                    venda.total[nv] = produto[j].preco * quantidade;
                    venda.quantidade[nv] = quantidade;
                    produto[j].quantidade -= quantidade;
                }

            }
        }

    if(id_encontrado==0){
        printf("ID nao encontrado\n");
        sleep(5);
        return MENU_VENDAS();

    }

    if(quantidade_encontrada==1){
        printf("\nQuantidade encontrada\n");

    }

//venda.total[nv] = (venda.preco[nv] * venda.quantidade[nv]);
//for(j=0;j<20;j++){
    printf("NIF: %d\n",venda.nif);
    printf("ID: %d\n", venda.id[nv]);
    printf("Quantidade: %d\n", venda.quantidade[nv]);
    printf("Preco: %.2f\n", venda.preco[nv]);
    printf("Total: %.2f\n", venda.total[nv]);

    sleep(5);
//}
    FILE *ficheiro_vendas = fopen("vendas.txt", "a");
    if (ficheiro_vendas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(ficheiro_vendas, "NIF: %d\n", venda.nif);
    fprintf(ficheiro_vendas, "ID: %d\n", venda.id[nv]);
    fprintf(ficheiro_vendas, "Quantidade: %d\n", venda.quantidade[nv]);
    fprintf(ficheiro_vendas, "Preco: %f\n", venda.preco[nv]);
    fprintf(ficheiro_vendas, "Total: %f\n", venda.total[nv]);

    fclose(ficheiro_vendas);

    //printf("Deseja adicionar mais vendas? Digite 2\n");
    //scanf("%d", &opcao);

    int opcao;
    FILE *ficheiro = fopen("produtos.txt", "r");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    struct produtos produtos_atual;

    FILE *ficheiro_temporario = fopen("produtos_temp.txt", "w");
    if (ficheiro_temporario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    while (fscanf(ficheiro, "Nome: %s\nID: %d\nQuantidade: %d\nPreco: %f\n",
        &produtos_atual.nome, &produtos_atual.id, &produtos_atual.quantidade, &produtos_atual.preco) == 4) {

        if (produtos_atual.id == id) {

            for(int j=0;j<contar_p;j++){
                if(id==produto[j].id){

                    fprintf(ficheiro_temporario, "Nome: %s\n", produtos_atual.nome);
                    fprintf(ficheiro_temporario, "ID: %d\n", id);
                    fprintf(ficheiro_temporario, "Quantidade: %d\n", produto[j].quantidade);
                    fprintf(ficheiro_temporario, "Preco: %f\n", produtos_atual.preco);
                }

            }
        }
        else{
            fprintf(ficheiro_temporario, "Nome: %s\n", produtos_atual.nome);
            fprintf(ficheiro_temporario, "ID: %d\n", produtos_atual.id);
            fprintf(ficheiro_temporario, "Quantidade: %d\n", produtos_atual.quantidade);
            fprintf(ficheiro_temporario, "Preco: %f\n", produtos_atual.preco);

        }

    }

    fclose(ficheiro);
    fclose(ficheiro_temporario);

    remove("produtos.txt");
    rename("produtos_temp.txt", "produtos.txt");
    printf("\nVenda inserida com sucesso!\n");

    printf("Digite 2 inserir mais vendas: ");
    scanf("%d", &opcao_2);

    system("cls");
    }while(opcao_2 == 2);

    printf("Introduza 1 para retornar ao menu:\n");
    scanf("%d", &opcao);
    if(opcao==1){
        return MENU_VENDAS();
    }

}

int ver_vendas() {
    int opcao;
    FILE *ficheiro = fopen("vendas.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    struct vendas venda;

    while (fscanf(ficheiro, "NIF: %d\nID: %d\nQuantidade: %d\nPreco: %f\nTotal: %f\n",
                  &venda.nif, &venda.id[0], &venda.quantidade[0], &venda.preco[0], &venda.total[0]) == 5) {

        printf("NIF: %d\n", venda.nif);
        printf("ID: %d\n", venda.id[0]);
        printf("Quantidade: %d\n", venda.quantidade[0]);
        printf("Preco: %.2f\n", venda.preco[0]);
        printf("Total: %.2f\n", venda.total[0]);
        printf("--------\n");

    }
    fclose(ficheiro);
    printf("voltar digite 1 \n");
    scanf("%d",&opcao);
    if(opcao==1){
     return MENU_VENDAS();
    }
}

int pesquisar_venda(){
    int opcao;
    FILE *ficheiro= fopen("vendas.txt", "r");

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; 
    }

    int nif_a_encontrar;
    printf("Digite o NIF das a ser encontrado: ");
    scanf("%d", &nif_a_encontrar);

    struct vendas venda;

    int nif_encontrado = 0;

    while (fscanf(ficheiro, "NIF: %d\nID: %d\nQuantidade: %d\nPreco: %f\nTotal: %f\n",
                  &venda.nif, &venda.id[0], &venda.quantidade[0], &venda.preco[0], &venda.total[0]) == 5) {

        if (venda.nif == nif_a_encontrar) {
            nif_encontrado = 1;
            printf("NIF: %d\n", venda.nif);
            printf("ID: %d\n", venda.id[0]);
            printf("Quantidade: %d\n", venda.quantidade[0]);
            //printf("Preco: %.2f\n", venda.preco[0]);
            printf("Total: %.2f\n", venda.total[0]);
            printf("--------\n");
        }
    }

    if(nif_encontrado==0){
    printf("\nNIF nao encontrado\n");
    }

    fclose(ficheiro);
    printf("voltar digite 1 \n");
    scanf("%d",&opcao);
    if(opcao==1){
        return MENU_VENDAS();
    }
}

int total_de_vendas(){
    int opcao;
    float total_vendido;
    int tipo_pesquisa;
    FILE *ficheiro= fopen("vendas.txt", "r");

    printf("\nTipo de pequisa:\n\nTotal de vendas por NIF: 1\n\nTotal de vendas: 2\n\n");
    scanf("%d",&tipo_pesquisa);

    if (ficheiro == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1; /*Sair do programa com codigo de erro*/
    }

    struct vendas venda;
    int nif_a_encontrar;
    if(tipo_pesquisa == 1)
    {

        printf("Digite o NIF das a ser encontrado: ");
        scanf("%d", &nif_a_encontrar);

        int nif_encontrado = 0;

        while (fscanf(ficheiro, "NIF: %d\nID: %d\nQuantidade: %d\nPreco: %f\nTotal: %f\n",
                      &venda.nif, &venda.id[0], &venda.quantidade[0], &venda.preco[0], &venda.total[0]) == 5) {

            if (venda.nif == nif_a_encontrar) {

                nif_encontrado = 1;
                total_vendido += venda.total[0];
            }
        }

        if(nif_encontrado==0){
            printf("\nNIF nao encontrado por favor repita\n");
            return total_de_vendas();
        }
    }
    else if(tipo_pesquisa == 2){

        while (fscanf(ficheiro, "NIF: %d\nID: %d\nQuantidade: %d\nPreco: %f\nTotal: %f\n",
                      &venda.nif, &venda.id[0], &venda.quantidade[0], &venda.preco[0], &venda.total[0]) == 5) {

            total_vendido += venda.total[0];
        }
    }
    else{
        return total_de_vendas();
    }

    if(tipo_pesquisa == 1)
    {
        printf("\nTotal de vendas do nif %d da loja foi %.2f\n\n", nif_a_encontrar, total_vendido);
    }
    else
    {
        printf("\nTotal de vendas da loja foi %.2f\n\n", total_vendido);
    }
    
    fclose(ficheiro);
    printf("voltar digite 1 \n");
    scanf("%d",&opcao);
    if(opcao==1){
        return MENU_VENDAS();
    }
}