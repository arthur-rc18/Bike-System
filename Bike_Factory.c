#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[100], group[30];
  float price;
  long int cod;
  int qtde;
} set_products;

typedef struct{
	char name[100], adress[100], cpf[20], number[20], age[3];
} set_clients;

int open_file_product(set_products product[], FILE *file){

  int x, counter = 0, aux;
  char c;

  file = fopen("products.txt", "r");

  if (file == NULL){
    return counter;
    // exit(1);
  }

  do {

    x = fscanf (file, "%s %s %f %ld", product[counter].name, product[counter].group, &product[counter].price, &product[counter].cod);

    counter ++;

  } while (x != EOF);

  fclose(file);

  return (counter-1);

}

void fecha_file_product(set_products product[], int quantage_product, FILE *file){

  int counter;

  file = fopen("products.txt", "w");

  if (file == NULL){
    printf ("Erro na abertura do file\n");
    exit(1);
  }

  for (counter = 0; counter < quantage_product; counter ++){

    fprintf (file, "%s %s %.2f %ld\n", product[counter].name, product[counter].group, product[counter].price, product[counter].cod);

  }

  fclose (file);

}

int open_file_client(set_clients client[], FILE *file){

  int x, counter = 0;

  file = fopen("clients.txt", "r");

  if (file == NULL){
    return counter;
    // exit(1);
  }

  do {

    x = fscanf (file, "%s %s %s %s %s\n", client[counter].name, client[counter].adress, client[counter].cpf, client[counter].age, client[counter].number);

    counter ++;

  } while (x != EOF);

  fclose(file);

  return (counter-1);

}

void fecha_file_client(set_clients client[], int quantage_client, FILE *file){

  int counter;

  file = fopen("clients.txt", "w");

  if (file == NULL){
    printf ("Erro na abertura do file\n");
    exit(1);
  }

  for (counter = 0; counter < quantage_client; counter ++){

    fprintf (file, "%s %s %s %s %s\n", client[counter].name, client[counter].adress, client[counter].cpf, client[counter].age, client[counter].number);

  }

  fclose (file);

}
// void file_bike (set_products bike[], int quantage_product){

//   FILE *bike;

//   bike = fopen("bikes.txt", "a+");
//       if (bike == NULL){
//         printf ("Erro na abertura do file");
//         exit(1);
//       }

//       fprintf (bike, "product: %s\ngroup: %s\nprice: R$%.2f\ncod: %ld\n\n", bike[quantage_product].name, bike[quantage_product].group, bike[quantage_product].price, bike[quantage_product].cod);

//       fclose(bike);

// }
  
// void file_accessorie  (set_products accessorie[], int quantage_product){

//   FILE *file;

//   file = fopen("accessories.txt", "a+");
//       if (file == NULL){
//         printf ("Erro na abertura do file");
//         exit(1);
//       }

//       fprintf (file, "product: %s\ngroup: %s\nprice: R$%.2f\ncod: %ld\n\n", accessorie[quantage_product].name, accessorie[quantage_product].group, accessorie[quantage_product].price, accessorie[quantage_product].cod);

//       fclose(file);

// }

// void file_clothing (set_products clothing[], int quantage_product){

//   FILE *roupa;

//   roupa = fopen("clothings.txt", "a+");
//       if (roupa == NULL){
//         printf ("Erro na abertura do file");
//         exit(1);
//       }
      
//       fprintf (roupa, "product: %s\ngroup: %s\nprice: R$%.2f\ncod: %ld\n\n", clothing[quantage_product].name, clothing[quantage_product].group, clothing[quantage_product].price, clothing[quantage_product].cod);

//       fclose(roupa);

// }

void cadastro_product(set_products product[], FILE *file){

  int res, gp, quantage;

  quantage = open_file_product(product, file);

  do {
    system ("cls");
    do {
      printf ("group do product (%d):\n[1]bike\n[2]accessories\n[3]clothing\n---------------\n", quantage);
        scanf ("%d", &gp);
        setbuf(stdin, NULL);
      switch (gp){
        case 1:
          strcpy(product[quantage].group, "bike");
          system("cls");
          break;
        case 2: 
          strcpy(product[quantage].group, "accessorie");
          system("cls");
          break;
        case 3: 
          strcpy(product[quantage].group, "clothing");
          system("cls");
          break;
        default: 
          system("cls");
          printf ("option invalida\n\n");
          break;
      }
    } while (gp != 1 && gp  != 2 && gp != 3);

  	printf ("type o name do product (%d): ", quantage);
      scanf ("%[^\n]s", product[quantage].name);
      setbuf(stdin, NULL);
    printf ("type o price do product (%d): R$", quantage);
      scanf ("%f", &product[quantage].price);
      setbuf(stdin, NULL);
    printf ("type o cod do product (%d): ", quantage);
      scanf ("%ld", &product[quantage].cod);
      setbuf(stdin, NULL);

    printf ("\nWanna add another product?\n[1]YES\n[2]NO\n----------\n");
      scanf ("%d", &res);

    quantage += 1;
    
  } while (res == 1);

  fecha_file_product(product, quantage, file);
  
  // fclose(cadastro_product);

  system("cls");
  
}

void show_product(set_products product [], FILE *file){

  int counter, quantage;

  system("cls");

  quantage = open_file_product(product, file);
  
  for (counter = 0; counter < quantage; counter ++){

    printf ("name: %s\ngroup: %s\nprice: R$%.2f\ncod: %ld\n\n", product[counter].name, product[counter].group, product[counter].price, product[counter].cod);

  }

  // fecha_file(product, quantage, file);

}

void show_product_group(set_products product[], FILE *file){

  int counter, option, quantage;
  char texto;
  system("cls");

  quantage = open_file_product(product, file);

  do {
    printf ("Wich group of products should be shown:\n[1]bikes\n[2]accessories\n[3]clothing\n\nOption: ");
      scanf ("%d", &option);
    printf ("\n");

    switch(option){

      case 1:
        system("cls");
        for (counter = 0; counter < quantage; counter ++){
          if (strcmp(product[counter].group, "bike") == 0){
            printf ("product: %s\nprice: R$%.2f\ncod: %ld\n\n", product[counter].name, product[counter].price, product[counter].cod);
          }
        }
        break;

      case 2:
        system("cls");
        for (counter = 0; counter < quantage; counter ++){
          if (strcmp(product[counter].group, "accessorie") == 0){
            printf ("product: %s\nprice: R$%.2f\ncod: %ld\n\n", product[counter].name, product[counter].price, product[counter].cod);
          }
        }
        break;

      case 3:
        system("cls");
        for (counter = 0; counter < quantage; counter ++){
          if (strcmp(product[counter].group, "clothing") == 0){
            printf ("product: %s\nprice: R$%.2f\ncod: %ld\n\n", product[counter].name, product[counter].price, product[counter].cod);
          }
        }
        break;

        default:
          system("cls");
          printf ("invalid option\n\n");
    
    }

  } while (option != 1 && option != 2 && option != 3);

}

void cadastro_client(set_clients client[], FILE *file){

  int res, aux = 0, quantage;

  quantage = open_file_client(client, file);

  do {
    system ("cls");

    printf ("type the name of the client: ");
      scanf ("%[^\n]s", client[quantage].name);
      setbuf(stdin, NULL);

    printf ("type the age: ");
      scanf ("%[^\n]s", client[quantage].age);
      setbuf(stdin, NULL);
    // do {
    printf ("type the CPF of the client: ");
      scanf ("%[^\n]s", client[quantage].cpf);
      setbuf(stdin, NULL);
    
    printf ("type the adress: ");
      scanf ("%[^\n]s", client[quantage].adress);
      setbuf(stdin, NULL);

    printf ("type the number: ");
      scanf ("%[^\n]s", client[quantage].number);
      setbuf(stdin, NULL);

    printf ("\nWanna add another client?\n[1]YES\n[2]NO\n---------------\n");
      scanf ("%d", &res);
      setbuf(stdin, NULL);

    quantage ++;

  } while (res == 1);

  fecha_file_client(client, quantage, file);

}

void show_client(set_clients client[], FILE *file){

  int quantage, counter;

  quantage = open_file_client(client, file);

  system ("cls");

  for (counter = 0; counter < quantage; counter++){
    printf ("name: %s\nCPF: %s\nage: %s anos\nadress: %s\nnumber: %s\n\n", client[counter].name, client[counter].cpf, client[counter].age, client[counter].adress, client[counter].number);
  }

}

void show_client_cpf(set_clients client[], FILE *file){

  int counter, quantage;
  char cpf[20];

  system ("cls");

  quantage = open_file_client(client, file);

  printf ("type o cpf do client: ");
    scanf ("%s", cpf);

  system ("cls");

  for (counter = 0; counter < quantage; counter ++){
    if (strcmp(cpf, client[counter].cpf) == 0){
      printf ("name: %s\nCPF: %s\nage: %s anos\nadress: %s\nnumber: %s\n\n", client[counter].name, client[counter].cpf, client[counter].age, client[counter].adress, client[counter].number);
    }
  }

}

int cadastro_client_orcamento(set_clients client[], int *quantage_client){

  int aux = 0;

  FILE *file;

  file = fopen ("clients.txt", "a+");

  if (file == NULL){
    printf ("Erro na abertura do file\n");
    exit(1);
  }

    system ("cls");

    printf ("type o name do client: ");
      scanf ("%[^\n]s", client[*quantage_client].name);
      setbuf(stdin, NULL);

    printf ("type a age: ");
      scanf ("%s", client[*quantage_client].age);
      setbuf(stdin, NULL);
    // do {
    printf ("type o CPF do client: ");
      scanf ("%[^\n]s", client[*quantage_client].cpf);
      setbuf(stdin, NULL);
    
    printf ("type o adress: ");
      scanf ("%[^\n]s", client[*quantage_client].adress);
      setbuf(stdin, NULL);

    printf ("type o number de number: ");
      scanf ("%[^\n]s", client[*quantage_client].number);
      setbuf(stdin, NULL);

    fprintf (file, "name: %s\nage: %s\nCPF: %s\nadress: %s\nnumber: %s\n\n", client[*quantage_client].name, client[*quantage_client].age, client[*quantage_client].cpf, client[*quantage_client].adress, client[*quantage_client].number);
    
    *quantage_client += 1;

  fclose(file);

  return *quantage_client;
}

int cadastro_product_orcamento(set_products T[], int *quantage_product){


  int gp;
  // system("cls");

  // printf ("Quantos products voce quer cadastrar? ");
  //   scanf("%d", &qtde);
  //   setbuf(stdin, NULL);

  // for (counter = 0; counter < qtde; counter++){

  FILE *cadastro_product;
  
  cadastro_product = fopen("products.txt", "a+");
  if (cadastro_product == NULL){
    printf ("Erro na abertura do file");
    exit(1);
  }

    system ("cls");
    do {
      printf ("group do product (%d):\n[1]bike\n[2]accessories\n[3]clothing\n---------------\n", *quantage_product+1);
        scanf ("%d", &gp);
        setbuf(stdin, NULL);
      switch (gp){
        case 1:
          strcpy(T[*quantage_product].group, "bike");
          system("cls");
          break;
        case 2: 
          strcpy(T[*quantage_product].group, "accessories");
          system("cls");
          break;
        case 3: 
          strcpy(T[*quantage_product].group, "clothing");
          system("cls");
          break;
        default: 
          system("cls");
          printf ("option invalida\n");
          break;
      }
    } while (gp != 1 && gp  != 2 && gp != 3);

  	printf ("type o name do product (%d): ", *quantage_product+1);
      scanf ("%[^\n]s", T[*quantage_product].name);
      setbuf(stdin, NULL);
    printf ("type o price do product (%d): R$", *quantage_product+1);
      scanf ("%f", &T[*quantage_product].price);
      setbuf(stdin, NULL);
    printf ("type o cod do product (%d): ", *quantage_product+1);
      scanf ("%ld", &T[*quantage_product].cod);
      setbuf(stdin, NULL);
    // system("cls");

    fprintf (cadastro_product, "product: %s\ngroup: %s\nprice: R$%.2f\ncod: %ld\n\n", T[*quantage_product].name, T[*quantage_product].group, T[*quantage_product].price, T[*quantage_product].cod);
    // fprintf (cadastro_product, "product: %s\n", T[*qtde_product].name);

    // if (gp == 1){ file_bike(T, quantage_product);} 
    //   else if (gp == 2){ file_accessorie(T, quantage_product);} 
    //     else if (gp == 3){ file_clothing(T, quantage_product);}

    *quantage_product += 1;
  
  fclose(cadastro_product);

  return *quantage_product;
  
}

void orcamento (set_clients client[], int *quantage_client, set_products product[], int *quantage_product, float *vendas_dia){

    long int cod;
    int res, counter, res_cad, aux = 0, posicao;
    char cpf[20], c;
    float soma = 0;
    
    system("cls");

    FILE *orcamento;

    orcamento = fopen("orcamento.txt", "a+");

    if (orcamento == NULL){
      printf ("erro na abertura do file\n");
      exit(1);
    }

    FILE *orcamento_unico;

    orcamento_unico = fopen("orcamento_unico.txt", "w");

    if (orcamento_unico == NULL){
      printf ("erro na abertura do file\n");
      exit(1);
    }

    printf ("type o CPF do client: ");
      scanf ("%s", cpf);
      setbuf(stdin, NULL);

    for (counter = 0; counter < *quantage_client; counter++){
      if (strcmp(client[counter].cpf, cpf) == 0){

        fprintf(orcamento, "==================== Orcamento ====================\nname: %s\nCPF: %s\nnumber: %s\n===================================================\n\n", client[counter].name, client[counter].cpf, client[counter].number);
        fprintf(orcamento_unico, "==================== Orcamento ====================\nname: %s\nCPF: %s\nnumber: %s\n===================================================\n\n", client[counter].name, client[counter].cpf, client[counter].number);

        aux++;
        res_cad = 2;
        break;
      }
    }

    do {
      if (aux == 0){
        printf ("\nCPF nao encontrado\n\nQuer cadastrar o client?\n[1]SIM\n[2]NAO\n\noption: ");
          scanf("%d", &res_cad);
          setbuf(stdin, NULL);
        
        switch (res_cad)
        {
        case 1:
          posicao = cadastro_client_orcamento(client, quantage_client);

          fprintf(orcamento, "==================== Orcamento ====================\nname: %s\nCPF: %s\nnumber: %s\n===================================================\n\n", client[posicao-1].name, client[posicao-1].cpf, client[posicao-1].number);
          fprintf(orcamento_unico, "==================== Orcamento ====================\n\nname: %s\nCPF: %s\nnumber: %s\n===================================================\n", client[posicao-1].name, client[posicao-1].cpf, client[posicao-1].number);
          break;
        
        case 2:
          return;

        default:
          system ("cls");
          printf ("option Invalida\n");
          break;
        }

      }
    } while (res_cad != 1 && res_cad != 2);

    aux = 0;
   
    do {

      system("cls");

        printf ("type o cod do product: ");
          scanf ("%ld", &cod);
          setbuf(stdin, NULL);

        for (counter = 0; counter < *quantage_product; counter++){
          if (product[counter].cod == cod){

            printf ("type a quantage: ");
              scanf("%d", &product[counter].qtde);
              setbuf(stdin, NULL);

            soma += (product[counter].price*product[counter].qtde);
            *vendas_dia += (product[counter].price*product[counter].qtde);

            fprintf(orcamento, "product: %s\nprice: R$%.2f\nQuantage: %d\n\n", product[counter].name, product[counter].price, product[counter].qtde);
            fprintf(orcamento_unico, "product: %s\nprice: R$%.2f\nQuantage: %d\n\n", product[counter].name, product[counter].price, product[counter].qtde);
            
            res_cad = 2;
            aux ++;
            break;
          }
        }

      do {
        if (aux == 0){
          printf ("\nproduct nao encontrado\n\nQuer cadastrar o product?\n[1]SIM\n[2]NAO\n\noption: ");
            scanf("%d", &res_cad);
            setbuf(stdin, NULL);
          
          switch (res_cad)
          {
          case 1:
            posicao = cadastro_product_orcamento(product, quantage_product);

            system("cls");

            printf ("type a quantage: ");
              scanf("%d", &product[posicao-1].qtde);
              setbuf(stdin, NULL);
            
            fprintf(orcamento, "product: %s\nprice: R$%.2f\nQuantage: %d\n\n", product[posicao-1].name, product[posicao-1].price, product[posicao-1].qtde);
            fprintf(orcamento_unico, "product: %s\nprice: R$%.2f\nQuantage: %d\n\n", product[posicao-1].name, product[posicao-1].price, product[posicao-1].qtde);

            soma += (product[counter].price*product[counter].qtde);
            *vendas_dia += (product[counter].price*product[counter].qtde);

            break;
          
          case 2:
            return;

          default:
            system ("cls");
            printf ("option Invalida\n");
            break;
          }

        }
      } while (res_cad != 1 && res_cad != 2);

      printf ("Quer acrescentar mais products?\n[1]SIM\n[2]NAO\n\noption: ");
        scanf("%d", &res);
        setbuf(stdin, NULL);

    } while (res == 1);

  fprintf (orcamento, "===================================================\nTotal:\tR$%.2f\n\n", soma);
  fprintf (orcamento_unico, "===================================================\nTotal:\tR$%.2f\n\n", soma);

  fclose(orcamento);
  fclose(orcamento_unico);

  orcamento_unico = fopen("orcamento_unico.txt", "r");

  system("cls");

    if (orcamento_unico == NULL){
      printf ("erro na abertura do file\n");
      exit(1);
    }

  do {

    c = fgetc(orcamento_unico);
    printf("%c", c);

  } while (c != EOF);

  fclose(orcamento_unico);
  
}

void vendas (float *total_vendas){

  char texto;
  FILE *total_orcamento;

  system ("cls");

  total_orcamento = fopen("orcamento.txt", "r");
  if (total_orcamento == NULL){
    printf ("error while opening the file\n");
    exit(1);
  }

  do {
    texto = fgetc(total_orcamento);
    printf ("%c", texto);
  } while (texto != EOF);

  printf ("\nTotal of sells:\nR$ %.2f\n", *total_vendas);

}

void editar_product (set_products product[], FILE *file){

  system("cls");

  char novo_name[50];
  int counter, res, novo_group, quantage;
  long int cod_product, novo_cod;
  float novo_price;

  quantage = open_file_product(product, file);

  printf ("type the cod of the product you want to edit: ");
    scanf ("%ld", &cod_product);
    setbuf(stdin, NULL);

  for (counter = 0; counter < quantage; counter++){

    if (cod_product == product[counter].cod){
      system ("cls");
      do {

        printf ("Which data you want to edit?\n");
        printf ("[1]name\n[2]group\n[3]cod\n[4]price\n----------\n");
          scanf ("%d", &res);
          setbuf(stdin, NULL);
        // aux ++;
  
        switch (res)
        {
  
        case 1:
          printf ("type o novo name: ");
            scanf ("%[^\n]s", novo_name);
            setbuf(stdin, NULL);
          strcpy(product[counter].name, novo_name);
          break;
  
        case 2:
          printf ("type a option do group:\n");
          printf ("[1]bike\n[2]accessorie\n[3]clothing\n----------\n");
            scanf ("%d", &novo_group);
            setbuf(stdin, NULL);
          switch(novo_group){
            case 1:
              strcpy(product[counter].group, "bike");
              break;
            case 2:
              strcpy(product[counter].group, "accessorie");
              break;
            case 3:
              strcpy(product[counter].group, "clothing");
              break;
            default:
              printf ("option invalida\n");
              break;
          }
          break;
        
        case 3: 
          printf ("type o novo cod: ");
            scanf("%ld", &novo_cod);
            setbuf(stdin, NULL);
          product[counter].cod = novo_cod;
          break;
  
        case 4:
          printf ("type o novo price: R$");
            scanf ("%f", &novo_price);
            setbuf(stdin, NULL);
          product[counter].price = novo_price;
          break;
        
        default:
          system("cls");
          printf ("option invalida\n");
          break;
        }

      } while (res != 1 && res != 2 && res != 3 && res != 4);
    }
  }
  fecha_file_product(product, quantage, file);
}

void alugar_bike (set_products T[], int *quantage_product, int *quantage_client){

  system("cls");

  char cpf_client[20];
  int counter;
  long int cod_product;

  printf("quantage %p", *quantage_product);

    printf ("type o cpf do client que deseja alugar a bike: ");
    scanf ("%[^\n]s", cpf_client);


    printf ("type o cod da bike que deseja alugar: ");
    scanf ("%ld", &cod_product);



  for(counter = 0; counter < *quantage_product; counter++) {
      

    
      //     if (cpf_client == T[*quantage_client].cpf_client) {

      //     if (cod_product == T[*quantage_product].cod) {
      //         strcpy(T[*quantage_product].cpf_client, cpf_client);
             
      //         printf ("bike alugada com sucesso!");
      //     }
      //     else {
      //         printf ("Erro, bike não encontrada!");
      //     }
      // } else {
      //     printf ("Erro, client não encontrado!");
      // }
  }
}

void menu(){

	int option, quantage_product = 0, quantage_client = 0;
  float vendas_do_dia = 0, *total_vendas;
	set_products P[50];
  set_clients R[50];
  int *qtde_product, *qtde_client;

  qtde_product = &quantage_product;
  qtde_client = &quantage_client;
  total_vendas = &vendas_do_dia;

  FILE *product;
  FILE *client;

	while(1){
		printf("\nBem vindo ao Sistema de Bikes Lobo ");
		printf("\n1- Cadastrar products ");
		printf("\n2- showr todos os products");
		printf("\n3- showr products por group");
    printf("\n4- Editar products");
    printf("\n5- Cadastrar clients");
    printf("\n6- showr todos os clients");
    printf("\n7- showr client especifico");
		printf("\n8- Venda");
    printf("\n9- Alugar bikes");
    printf("\n10- Relatorio de Vendas");
		printf("\n11- Sair");
		printf("\ntype option: ");
		scanf("%d", &option);
    setbuf(stdin, NULL);

		if(option == 1) cadastro_product(P, product);
		if(option == 2) show_product(P, product);
		if(option == 3) show_product_group(P, product);
    if(option == 4) editar_product(P, product);
		if(option == 5) cadastro_client(R, client);
    if(option == 6) show_client(R, client);
    if(option == 7) show_client_cpf(R, client);
    if(option == 8) orcamento(R, qtde_client, P, qtde_product, total_vendas);
    if(option == 9) alugar_bike(P, qtde_product, qtde_client);
    if(option == 10) vendas(total_vendas);
		if(option == 11) return;
	}
}

int main(){
	menu();
  return 0;
}
// falta (editar clients)


// função tanto para ler quanto para escrever
// int open_file_product(cadastro_product T[], *quantage_product)
// int counter = 0;

// do {

// fscanf(file,"%s %s %f %ld", T[posicao do vetor]...)

// } while (fscanf != EOF);

// variavel de controle para alugar (0 - disponivel) (1 - ocupado)

// fluxo de caixa
// orçamento
// products
// vendas
// funções pequenas fica mais fácil de modificar

// e-mail
// age

// FILE *f = fopen("file.txt", "r");
// char c;
// int i;
// char* string_pesquisar = "Revista Epoca";
// while((c = fgetc(f)) != EOF){
//     if(c == *string_pesquisar){ //Primeiro caracter da STRING que estamos buscando foi encontrado, vamos checas os subsequentes:

//         for(i = 0; i < strlen(string_pesquisar); i ++){ //loop para comparar cada caracter da String pesquisada com o proximo caracter lido
//             c = fgetc(f); //lê mais um caracter no file
//             if(c == EOF)  //se encontrar o final do file sai do loop
//                 break;
//             if(*(string_pesquisar + i) != c) //se algum caracter subsequente lido for diferente da string pesquisada sai do loop
//                 break;
//         }

//         if(i == strlen(string_pesquisar){ //se i == qtd caracteres da String a pesquisar então achamos a string (a verificação não foi interrompida durante as comparações de caracteres)
//              //Aqui entra o seu código ao achar a STRING que você procurava

//              break; //break para parar de ler o file
//         }
//      }
// }

// fclose(f);