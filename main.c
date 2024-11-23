#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();//menu do trabalho mercado digital
int escolhaTelefone();//função de escolha de qual tipo de telefone o usuario quer usar
int codigoCliente(double cpf);//função que faz o codigo do cliente ser os 6 primeiros digitos

int geradorCodProd(char nomeProd[20]); /*função que gera codigo produto*/
//int voltarMenu();

typedef struct{ //struct de telefone, que vai ser usada dentro da struct dados clientes
    char fixo[15];
    char movel[16];
}telefones;

typedef struct{ //struct com nome dadosCliente, com suas variaveis
    int codigo;
    char nome[100];
    double cpf;
    char sexo;
    telefones tel; //chamando a função do tipo telefones com nome tel
}dadosCliente;

typedef struct{ //struct modelos, que é usada dentro da struc produtoz
    char marca[20];
    char modelo[20];
}modelos;

typedef struct{ //struct com nome produtos, com suas variaveis
    int codigo;
    char nome[100];
    modelos mode;
    double valor;
}produtos;

typedef struct{ //struct de carrinhos
    dadosCliente dC;
    produtos produt[10];
    int quantidade[10];
    double subtotal;
    double desconto;
    double total;
}carrinhos;


dadosCliente/* <- tipo da função*/lerClientes();//crio uma função do tipo que vou retornar é a struct chamada (dados clientes), com nome de ler clientes

void exibirCliente(dadosCliente dC); //função sem retorno chamada (exibirCliente) para retornar todos dados lidos, e recebe os parametros de dadosCliente

/*Funções do produto*/

produtos lerProdutos();//função do tipo que returna struct chamada (produtos)
void exibirProdutos(produtos prod);
void exibirCarrinho(carrinhos carrinho);

/*Funções da venda*/
void efetuarVenda(dadosCliente dC[3], produtos prod[10], carrinhos carrinho); //EFETUAR VENDA CASE 5
void finalizarVenda(carrinhos carrinho, dadosCliente dC, produtos prod[]);
void listarCarrinho(carrinhos carrinho, dadosCliente dC, produtos prod[]);

int main(){
    dadosCliente dadosCliente[3]; //crio uma vetor do tipo struct(dadosCliente) e chamo ela de dadosClientes
    produtos dadosaProdutos[10];
    carrinhos dadosCarrinho;

    int respostaMenu = 0;//retorno da função menu guardado nessa variavel
    int i = 0;//contador
    int respVoltaMenu = 0;
    int contCliente = 0, contProdutos = 0;

    printf("Ola, esse eh o programa do seu mercado digital!!\n\n");
        do{
        respostaMenu = menu();

        switch(respostaMenu){

            case 1:
                //for(contCliente=0; contCliente < 3; contCliente++){//for para capturar os dados de cada cliente de uma vez guardando em vetor
                        do{
                        if(contCliente < 3){
                    printf("\n--------------CADASTRAR CLIENTE %d--------------\n", contCliente);
                    printf("\n\tInforme os dados do cliente %d", contCliente);
                    dadosCliente[contCliente] = lerClientes(); //variavel dadosCliente recebe todas informações da função lerClientes do tipo dadosCliente(struct)
                    printf("\n\t--------------------------------------");
                    printf("\n\t| Cliente %d, CADASTRADO COM SUCESSO! |", contCliente);
                    printf("\n\t--------------------------------------\n");

                    contCliente++;

                    printf("\nVoce deseja voltar ao menu?\n(1 - Sim, 2 - Nao.)\n");
                    printf("Sua resposta: ");
                    scanf("%d", &respVoltaMenu);

                }else printf("\n\tVoce ja cadastrou o maximo de  clientes permitidos!!! Volte ao menu\n");

                        }while(respVoltaMenu == 2);
                break;

            case 2:

                do{
                if(contProdutos < 10){
                printf("\n--------------OPCAO CADASTRAR PRODUTO--------------\n");
                    printf("\n\tInforme os dados do produto %d", contProdutos);
                    dadosaProdutos[contProdutos] =  lerProdutos();
                    printf("-------------------------------------------\n");

                    contProdutos++;

                    printf("Voce deseja voltar ao menu?\n(1 - Sim, 2 - Nao.)\n");
                    printf("Sua resposta: ");
                    scanf("%d", &respVoltaMenu);


                }else if(contProdutos >= 10){
                        respVoltaMenu = 1;//RESOLVER ISSO AQUI
                        printf("Voce ja cadastrou o numero maximo de produtos!!");
                    }

                    }while(respVoltaMenu == 2);
                break;

            case 3:
                for(i=0; i < contCliente; i++){//for para mostrar os dados de cada cliente de uma vez que estavam em um vetor
                    printf("\n--------------DADOS CLIENTE %d--------------\n", i);
                    exibirCliente(dadosCliente[i]); //chamo a função exibirClientes e ela mostra as informações que esta em dadosCliente
                    printf("----------------------------\n");
                }

                printf("Essa eh a lista de clientes cadastrados, agora vamos te direcionar para o menu!\n");
                /*printf("Sua resposta: ");
                scanf("%d", &respVoltaMenu); */
                break;

            case 4:
                 printf("\n------------Lista de produtos para compra------------\n", i);
                    for(i=0; i < contProdutos; i++){
                        printf("\n\t\tProduto %d", i);
                        exibirProdutos(dadosaProdutos[i]);
                        printf("\n----------------------------\n");
                    }

                    printf("\nEssa eh a lista de produtos para compra, agora vamos te direcionar para o menu!\n");
                break;

            case 5:
                printf("\n------------Lista de produtos para compra------------\n", i);
                    for(i=0; i < contProdutos; i++){
                        printf("\n\t\tProduto %d", i);
                        exibirProdutos(dadosaProdutos[i]);
                        printf("\n----------------------------\n");
                    }

                    efetuarVenda(dadosCliente, dadosaProdutos, dadosCarrinho);

                    printf("Voce deseja voltar ao menu?\n(1 - Sim, 2 - Nao.)\n");
                    printf("Sua resposta: ");
                    scanf("%d", &respVoltaMenu);
                break;

            case 0:

                return 0;

            break;
        }

        }while(respVoltaMenu == 1);
    return 0;
}

//menu do trabalho mercado digital
int menu(){
    int escolhaMenuUsuario = 0;
    do{
    printf("\n--------------Menu mercado digital--------------\n\n");
    printf("\t1 - para cadastrar cliente.\n");
    printf("\t2 - para cadastrar produto.\n");
    printf("\t3 - para listar cliente cadastrados.\n");
    printf("\t4 - para listar produtos cadastrados.\n");
    printf("\t5 - para efetuar uma venda.\n");
    printf("\t0 - para finalizar o programa.\n\n");
    printf("-------------------------------------------------\n\n");
    printf("\nOque voce gostaria de fazer?\n Escolha uma das opcoes acima: ");
    scanf("%d", &escolhaMenuUsuario);
        if(escolhaMenuUsuario >= 6 || escolhaMenuUsuario < 0){
            printf("\nAtencao:\nESSA OPCAO NAO EH VALIDA, TENTE NOVAMENTE!!\n\n");
        }
    }while(escolhaMenuUsuario >= 6 || escolhaMenuUsuario < 0);

    return escolhaMenuUsuario;
}
//funçao do tipo dadosCliente(struct) com nome lerClientes guardado todas informações da struct e retorno ela dps pra quem chamar
dadosCliente lerClientes(){

    int tipoTelUsuario, invalido;

    dadosCliente dC;
    printf("\n\ndigite o seu nome: ");
    getchar();
    gets(dC.nome);
    //do{//protegendo que o cpf tenha onze digitos, para o codigo do cliente sempre estar certo.

    printf("Digite o cpf: ");
    scanf("%lf", &dC.cpf);

    dC.codigo = codigoCliente(dC.cpf);// chamando a função que faz o calculo do codigo do cliente e guardando dentro da variavel codigo
    printf(" ------------------------");
    printf("\n| Seu codigo eh: %d |", dC.codigo);
    printf("\n -----------------------");
    getchar();
    do{

    	printf("\nDigite [F] se voce eh do sexo feminino, OU [M] se voce eh do sexo masculino: \n");
    	printf("Sua escolha: ");
    	scanf(" %c", &dC.sexo);
        getchar();

   	 	if(dC.sexo == 'M' || dC.sexo == 'm' || dC.sexo == 'F' || dC.sexo == 'f'){
       		printf("Voce digitou: %c, voce eh do sexo Masculino!\n", dC.sexo);
    	}//else if(dC.sexo == 'F' || dC.sexo == 'f'){
         	//printf("Voce digitou: %c, voce eh do sexo Feminino! \n", dC.sexo);
    	//}else{
        //	printf("Valor invalido!");
    	//}
    	} while(dC.sexo != 'M' && dC.sexo != 'm' && dC.sexo && 'F' && dC.sexo != 'f'); // condição para repetir enquanto o valor for inválido.

    //dC.codigo = codigoCliente(dC.cpf);// chamando a função que faz o calculo do codigo do cliente e guardando dentro da variavel codigo
    tipoTelUsuario = escolhaTelefone();//chamando o menu para que o usuario informe qual tipo de tel ele vai cadastrar
    switch(tipoTelUsuario){ //switch com as opções de telefone

    case 1:
    getchar();
    do {
        invalido = 0;
        printf("\nInforme o seu telefone movel (Somente numeros!): ");
        fgets(dC.tel.movel, sizeof(dC.tel.movel), stdin); // Lê a entrada como string

        // Remove o caractere de nova linha (\n) se existir
        dC.tel.movel[strcspn(dC.tel.movel, "\n")] = '\0';  // Remove o '\n' se existir

        // Verifica se o número tem exatamente 11 dígitos e é composto apenas de números
        if (strlen(dC.tel.movel) == 11) {
            int i;
            int valido = 1;

            // Verifica se todos os caracteres são dígitos
            for (i = 0; i < 11; i++) {
                if (dC.tel.movel[i] < '0' || dC.tel.movel[i] > '9') {
                    valido = 0;
                    break;
                }
            }

            if (valido) {
                // Formatação do telefone (XXX) XXXXX-XXXX
                char formatado[20];
                sprintf(formatado, "(%c%c) %c%c%c%c%c-%c%c%c%c",
                       dC.tel.movel[0], dC.tel.movel[1],   // DDD
                       dC.tel.movel[2], dC.tel.movel[3], dC.tel.movel[4], dC.tel.movel[5], dC.tel.movel[6], // Primeira parte
                       dC.tel.movel[7], dC.tel.movel[8], dC.tel.movel[9], dC.tel.movel[10]); // Segunda parte
                strcpy(dC.tel.movel, formatado); // Atualiza a string com o formato
                //printf("\tTelefone movel: %s\n", dC.tel.movel);
            } else {
                printf("Erro: O telefone deve conter apenas números. Tente novamente.\n");
                invalido = 1; // Indica que a entrada foi inválida
            }
        } else {
            printf("Erro: O telefone deve ter exatamente 11 dígitos. Tente novamente.\n");
            invalido = 1; // Indica que a entrada foi inválida
        }

    } while (invalido == 1); // Repete até o telefone ser válido
    break;


    case 2:
    getchar();
    do{
        invalido = 0;
        printf("\nInforme o numero do seu telefone fixo (Somente numeros!): ");
        fgets(dC.tel.fixo, sizeof(dC.tel.fixo), stdin); // Lê a entrada como string


        // Remove o caractere de nova linha (\n) se existir
        dC.tel.fixo[strcspn(dC.tel.fixo, "\n")] = '\0';  // Remove o '\n' se existir

        if (strlen(dC.tel.fixo) == 10) {
            int i;
            int valido = 1;

            // Verifica se todos os caracteres são dígitos
            for (i = 0; i < 10; i++) {
                if (dC.tel.fixo[i] < '0' || dC.tel.fixo[i] > '9') {
                    valido = 0;
                    break;
                }
            }

            if (valido == 1) {
                // Formatação do telefone (XXX) XXXXX-XXXX
                char formatado[20];
                sprintf(formatado, "(%c%c) %c%c%c%c-%c%c%c%c",
                       dC.tel.fixo[0], dC.tel.fixo[1],   // DDD
                       dC.tel.fixo[2], dC.tel.fixo[3], dC.tel.fixo[4], dC.tel.fixo[5], dC.tel.fixo[6], // Primeira parte
                       dC.tel.fixo[7], dC.tel.fixo[8], dC.tel.fixo[9]/*, dC.tel.fixo[10]*/); // Segunda parte
                strcpy(dC.tel.fixo, formatado); // Atualiza a string com o formato
              //  printf("\tTelefone fixo: %s\n", dC.tel.fixo);
            } else {
                printf("Erro: O telefone deve conter apenas números. Tente novamente.\n");
                invalido = 1; // Indica que a entrada foi inválida
            }
        }else {
            printf("Erro: O telefone deve ter exatamente 10 dígitos. Tente novamente.\n");
            invalido = 1; // Indica que a entrada foi inválida
        }

        } while (invalido == 1); // Repete até o telefone ser válido


        break;
    }
    return dC;
}

//como não consigo exibir uma struct no printf, criei uma função que exibi item por item da struct, que recebe o parametros de dadosClientes, e dps exibo
void exibirCliente(dadosCliente dC){

    printf("\n\tNome: %s", dC.nome);
    printf("\tCodigo: %d", dC.codigo);
    printf("\n\tCpf: %0.0lf", dC.cpf);
    printf("\n\tSexo: %c\n", dC.sexo);
    if (strcmp(dC.tel.fixo, "") != 0){
            printf("\tTelefone fixo: %s\n", dC.tel.fixo);
      }else{
            dC.tel.movel[strcspn(dC.tel.movel, "\n")] = '\0';
            if (strlen(dC.tel.movel) == 11) {
                char formatado[20];
                sprintf(formatado, "(%c%c) %c%c%c%c%c-%c%c%c%c",
                       dC.tel.movel[0], dC.tel.movel[1],   // DDD
                        dC.tel.movel[2], dC.tel.movel[3], dC.tel.movel[4], dC.tel.movel[5], dC.tel.movel[6], // Primeira parte
                        dC.tel.movel[7], dC.tel.movel[8], dC.tel.movel[9], dC.tel.movel[10]); // Segunda parte
                       strcpy(dC.tel.movel, formatado); // Atualiza a string com o formato
                        printf("\tTelefone movel: %s\n", dC.tel.movel);
          }
    }
}

int escolhaTelefone(){//função de escolha de qual tipo de telefone o usuario quer usar

    int tipoTelUsuario = 0;
    do{
    printf("\n-----------------\n");
    printf("Qual tipo de telefone deseja adicionar ?\n");
    printf("1 - para movel\n");
    printf("2 - para fixo\n");
    printf("-----------------\n");
    printf("Sua escolha: ");
    scanf("%d", &tipoTelUsuario);
    if(tipoTelUsuario < 1 || tipoTelUsuario > 2){
        printf("ESSA NAO EH UMA OPCAO VALIDA!!\n Tente novamento");
    }
    }while(tipoTelUsuario < 1 || tipoTelUsuario > 2);

    return tipoTelUsuario;
}

int codigoCliente(double cpf){ //função que faz o codigo do cliente ser os 6 primeiros digitos

    int codCliente = 0;
    codCliente = cpf / 100000;

    return codCliente;
}

produtos lerProdutos(){ //codigo da função que recolhe os dados do produto

        produtos prod;

        printf("\n\nInforme o nome do produto: ");
        getchar();
        gets(prod.nome);
        prod.codigo = geradorCodProd(prod.nome);
        printf("Nos informe a marca do produto: ");
        scanf(" %20[^\n]", prod.mode.marca);
        printf("Informe o modelo do produto: ");
        scanf(" %20[^\n]", prod.mode.modelo);
        printf("Agora para finalizar informe o valor: ");
        scanf("%lf", &prod.valor);
        getchar();

        return prod;
}

void exibirProdutos(produtos prod){
    //printf("\n\tO codigo do produto: %d", prod.codigo);
    printf("\n\tO nome do produto: %s", prod.nome);
    printf("\n\tO marca do produto: %s", prod.mode.marca);
    printf("\n\tO modelo do produto: %s", prod.mode.modelo);
    printf("\n\tValor do produto: %0.2lf", prod.valor);
    printf("\n\tO codigo do produto: %d", prod.codigo);
}

void efetuarVenda(dadosCliente dC[3], produtos prod[10], carrinhos carrinho){

    int compararCodProd = 0, comparadorcodCliente  = 0;
    int i;
    int proximoProd = 0, produtoNoCarrinho = 0;
    int validarCliente, validarProduto;

    printf("\nComo foi visto a cima esta eh nossa lista de produtos.");

    do{
    validarCliente = 0;
    printf("\n----------------------");
    printf("\nInforme seu codigo antes de prosseguirmos: ");
    scanf("%d", &comparadorcodCliente);
    printf("\n----------------------");
    for(i=0; i < 3; i++){
        if(dC[i].codigo == comparadorcodCliente){
            printf("\n\tEsse eh seu carrinho %s\n", dC[i].nome);
            validarCliente = 1;

        }
    }
        if(validarCliente == 0){
       printf("\nInforme um codigo valido!!\n");
    }
    }while(validarCliente == 0);

    for(i=0; i < 10; i++){ //for para colocar valor 0 dentro da variavel
        carrinho.quantidade[i] = 0;
    }


    do{
    if(produtoNoCarrinho < 10){
    printf("\nQual item deseja colocar no carrinho?\n");
    do{
    validarProduto = 0;
    printf("Informe o codigo do produto: ");
    scanf("%d", &compararCodProd);
    for(i=0; i < 10 ; i++){//alterar dps pro tanto de produto
       if(prod[i].codigo == compararCodProd){
            printf("Deseja adicionar quantos %s, ao seu carrinho?\n Quantidade produtos: ", prod[i].nome);
            scanf("%d", &carrinho.quantidade[i]);
            printf("%d %s foram adicionados ao carrinho", carrinho.quantidade[i], prod[i].nome);
            carrinho.subtotal += prod[i].valor * carrinho.quantidade[i];
            printf("\n\nsubtotal: %0.2lf\n", carrinho.subtotal);
            produtoNoCarrinho++;
            validarProduto = 1;
            }
       }
        if(validarProduto == 0){
            printf("\n------------------------\n");
            printf("Informe um codigo de produto valido!!");
            printf("\n------------------------\n");
        }
    }while(validarProduto == 0);
            printf("\nDeseja adicionar mais um produto??");
            printf("\n(1 - Sim, 2 - Nao)\n");
            scanf("%d", &proximoProd);

    }else printf("\n\tVoce ja cadastrou o maximo de produtos permitidos!!! \n");

    }while(proximoProd == 1);

    if(proximoProd != 1){

            for(i=0; i<3; i++){
                if(dC[i].codigo == comparadorcodCliente){
                    finalizarVenda(carrinho, dC[i], prod);
                }
            }
    }
}

int geradorCodProd(char nomeProd[20]){

    return nomeProd[0] + nomeProd[1];
}


void finalizarVenda(carrinhos carrinho, dadosCliente dC, produtos prod[]){

    char cupomDesconto[15] = "10Off";

    listarCarrinho(carrinho, dC, prod);


printf("\n\nO valor final da sua compra foi: %0.2lf\n", carrinho.subtotal);

}


void listarCarrinho(carrinhos carrinho, dadosCliente dC, produtos prod[]){



int i = 0;

printf("\t\t\t\t -----------------------\n");
printf("\t\t\t\t| Carrinho de: %s   |", dC.nome);
printf("\n\t\t\t\t| Codigo: %d       |", dC.codigo);
printf("\n\t\t\t\t| Cpf: %0.0lf      |", dC.cpf);
printf("\n\t\t\t\t| Sexo: %c               |", dC.sexo);
printf("\n\t     ---------------------------------------------------------\n");

for(i=0; i< 10; i++){
        if(carrinho.quantidade[i] != 0){
        printf("\t     | %s (Qntd: %d) - preço unitario: %0.2lf - Total: %0.2lf  |\n", prod[i].nome, carrinho.quantidade[i], prod[i].valor, prod[i].valor * carrinho.quantidade[i]);
        }
    }
        printf("\t     ---------------------------------------------------------\n");
}
