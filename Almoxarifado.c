#include <stdio.h> 					//biblioteca de comunica��o com o usu�rio
#include <stdlib.h> 				//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> 				//biblioteca de aloca��es de texto por regi�o
#include <string.h> 				//biblioteca respons�vel por cuidar das string

int registro()						//Fun��o respons�v�vel por cadastrar os usu�rios no sistema
{
									//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char ficha[40];
	char produto[40];				//CHAR - Contabiliza a quantidade de caracteres que ser�o utilizados
	char descricao[40];
	char quantidade[40];
									//Final da cria��o de vari�veis/string
					
	printf("Digite a ficha a ser cadastrada:  "); //Coletando informa��o do usu�rio
	scanf("%s",ficha);				//%s refere-se a string
	
	strcpy(arquivo, ficha); 		//Respons�vel por copiar os valores das string
	
	FILE *file;  					//Criando o arquivo
	file = fopen(arquivo, "w");  	//Cria o arquivo e "w" = Write (Escrever)
	fprintf(file, ficha); 			//Salvo o valor da vari�vel
	fclose(file); 					//Fecha o arquivo
	
	file = fopen(arquivo, "a");		//Abre o arquivo criado  "a" = Atualizar
	fprintf(file, ",");				//Separa��o de caracteres
	fclose(file); 					//Fecha o arquivo
	
	printf("Digite o produto a ser cadastrado:  ");
	scanf("%s",produto);
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file,produto);			//Registra no arquivo a informa��o solicitada
	fclose(file);  					//Fecha o arquivo
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file, ",");				//Separa��o de caracteres
	fclose(file);  					//Fecha o arquivo
	
	printf("Digite a descri��o a ser cadastrada:  ");
	scanf("%s", descricao);
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file,descricao);		//Registra no arquivo a informa��o solicitada
	fclose(file);  					//Fecha o arquivo
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file, ",");				//Separa��o de caracteres
	fclose(file);  					//Fecha o arquivo
	
	printf("Digite a quantidade a ser cadastrada:  ");
	scanf("%s", quantidade);
	
	file = fopen(arquivo, "a");  	//Abre o arquivo criado
	fprintf(file,quantidade);		//Registra no arquivo a informa��o solicitada
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
			printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do produto: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char ficha[40]; 				//String produto
	
	printf("Digite o n�mero da ficha a ser deletado: ");
	scanf("%s",ficha);
	
	remove(ficha);
	
	FILE *file;
	file = fopen(ficha,"r");
	
	if(file == NULL)				//Verifica se a Ficha digitada existe no banco de daos. (Caso n exista, exibe mensagem de erro)
	{
		printf("O Ficha n�o se encontra no sistema.\n");
		system("pause");
	}
	
		fclose(file);
	
}

int main()
	{
	int opcao=0; 					//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)	
	{
	
		system("cls");					//Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("������ Estoque Almoxarifado ������\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar Produto\n");
		printf("\t2 - Consultar Produto\n");
		printf("\t3 - Deletar Produto\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao) //In�cio da Sele��o
		{
			case 1:
			registro(); //Chamada de fun��es
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
			printf("Essa op��o n�o existe :( \n\n");
			system("pause");
			break; 
		}			//Fim da Sele��o	
	}
}

