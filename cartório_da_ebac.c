#include <stdio.h> //bibliteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca repons�vel pelas strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); //imprime essa mensagem no console para que o usu�rio digite o cpf a ser cadastrado
	scanf("%s", cpf); //%s armazena a entrada de caracteres que o usu�rio digita na string CPF.
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo para escrita. ("w" de write)
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo j� existente
	fprintf(file,", "); //adiciona uma v�rgula ao arquivo
	fclose(file); //fecha o arquivo novamente
	
	printf("Digite o nome a ser cadastrado: "); //o usu�rio digita
	scanf("%s",nome); //salva o valor na string
	
	file = fopen(arquivo,"a"); //atualizando o arquivo
	fprintf(file,nome); //salvando conte�do nome dentro da vari�vel do arquivo
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
				
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //armazena o CPF digitado pelo usu�rio no arquivo
	char conteudo[200]; //armazena o conte�do lido do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //l� o CPF digitado pelo us�rio e armazena na vari�vel cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo cujo nome � o CPF fornecido pelo usu�rio. ("r" de read para leitura do arquivo aberto)
	
	if(file == NULL) //verifica se o arquivo foi aberto.
	{
		printf("Arquivo n�o localizado! \n"); //caso o cpf n�o esteja cadastrado, � declarado como NULL e aparece essa mensagem
	}
	
	while(fgets(conteudo,200, file) != NULL) //l� cada linha do arquivo e armazena em 'conteudo'
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //imprime as informa��es que foram armazenadas na vari�vel 'conteudo'
		printf("\n\n"); //fecha o arquivo ap�s na conclus�o da leitura
	}
	
	system("pause");
	
}

int deletar() //fun��o de deletar
{
	char cpf[40]; //string cpf j� cadastrada anteriormente no sistema
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //imprime a mensagem na tela para que o usu�rio digite o cpf desejado
	scanf("%s", cpf); //procura o cpf digitado pelo usu�rio dentro da string cpf
	
	remove(cpf); //remove o cpf caso ele seja encontrado
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo cpf no modo de leitura
	
	if(file == NULL); //fun��o if para caso n�o encontre o cadastro do cpf no sistema
	{
		printf("Usu�rio n�o encontrado no sistema!\n"); //caso o cpf n�o seja encontrado no sistema, exibe essa mensagem no console para o usu�rio
		system("pause");
	}
	

}

int main() //Fun��o de n�mero inteiro
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo o la�o de repeti��o
	
	for(laco=1;laco=1;)//In�cio do la�o de repeti��o
	{
		
		system ("cls"); //Limpa a tela do console
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Op��o:"); //final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio dentro da vari�vel opcao. $d: l� dados de n�mero inteiro.
		
		system("cls"); //limpa a tela ap�s o comando do usu�rio
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //Fim da sele��o
		
	}//Fim do la�o de repeti��o
}
