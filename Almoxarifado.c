#include <stdio.h> 					//biblioteca de comunicação com o usuário
#include <stdlib.h> 				//biblioteca de alocação de espaço em memória
#include <locale.h> 				//biblioteca de alocações de texto por região
#include <string.h> 				//biblioteca responsável por cuidar das string

int registro()						//Função responsávável por cadastrar os usuários no sistema
{
									//Início criação de variáveis/string
	char arquivo[40];
	char ficha[40];
	char produto[40];				//CHAR - Contabiliza a quantidade de caracteres que serão utilizados
	char descricao[40];
	char quantidade[40];
									//Final da criação de variáveis/string
					
	printf("Digite a ficha a ser cadastrada:  "); //Coletando informação do usuário
	scanf("%s",ficha);				//%s refere-se a string
	
	strcpy(arquivo, ficha); 		//Responsável por copiar os valores das string
	
	FILE *file;  					//Criando o arquivo
	file = fopen(arquivo, "w");  	//Cria o arquivo e "w" = Write (Escrever)
	fprintf(file, ficha); 			//Salvo o valor da variável
	fclose(file); 					//Fecha o arquivo
	
	file = fopen(arquivo, "a");		//Abre o arquivo criado  "a" = Atualizar
	fprintf(file, ",");				//Separação de caracteres
	fclose(file); 					//Fecha o arquivo
	
	printf("Digite o produto a ser cadastrado:  ");
	scanf("%s",produto);
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file,produto);			//Registra no arquivo a informação solicitada
	fclose(file);  					//Fecha o arquivo
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file, ",");				//Separação de caracteres
	fclose(file);  					//Fecha o arquivo
	
	printf("Digite a descrição a ser cadastrada:  ");
	scanf("%s", descricao);
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file,descricao);		//Registra no arquivo a informação solicitada
	fclose(file);  					//Fecha o arquivo
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file, ",");				//Separação de caracteres
	fclose(file);  					//Fecha o arquivo
	
	printf("Digite a quantidade a ser cadastrada:  ");
	scanf("%s", quantidade);
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file,quantidade);		//Registra no arquivo a informação solicitada
	fclose(file);  					//Fecha o arquivo
		
	system("pause");
}
	
int consulta()			
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char ficha[40];
	char conteudo[200];
	
	printf("Digite a ficha a ser consultado:  ");
	scanf("%s",ficha);
	
	FILE *file; 					//Consulta arquivo existente
	file = fopen(ficha,"r"); 		// Vai ler o arquivo para consulta  "r" = Read (ler)
	
	if(file == NULL)
	{
			printf("\nNão foi possível abrir o arquivo, não localizado!.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do produto: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char ficha[40]; 				//String produto
	
	printf("Digite o número da ficha a ser deletado: ");
	scanf("%s",ficha);
	
	remove(ficha);
	
	FILE *file;
	file = fopen(ficha,"r");
	
	if(file == NULL)				//Verifica se a Ficha digitada existe no banco de daos. (Caso n exista, exibe mensagem de erro)
	{
		printf("O Ficha não se encontra no sistema.\n");
		system("pause");
	}
	
		fclose(file);
	
}

int main()
	{
	int opcao=0; 					//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)	
	{
	
		system("cls");					//Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("«««««« Estoque Almoxarifado »»»»»»\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar Produto\n");
		printf("\t2 - Consultar Produto\n");
		printf("\t3 - Deletar Produto\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) //Início da Seleção
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não existe :( \n\n");
			system("pause");
			break; 
		}			//Fim da Seleção	
	}
}

