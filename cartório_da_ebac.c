#include <stdio.h> //bibliteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca reponsável pelas strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); //imprime essa mensagem no console para que o usuário digite o cpf a ser cadastrado
	scanf("%s", cpf); //%s armazena a entrada de caracteres que o usuário digita na string CPF.
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo para escrita. ("w" de write)
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo já existente
	fprintf(file,", "); //adiciona uma vírgula ao arquivo
	fclose(file); //fecha o arquivo novamente
	
	printf("Digite o nome a ser cadastrado: "); //o usuário digita
	scanf("%s",nome); //salva o valor na string
	
	file = fopen(arquivo,"a"); //atualizando o arquivo
	fprintf(file,nome); //salvando conteúdo nome dentro da variável do arquivo
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
	
	char cpf[40]; //armazena o CPF digitado pelo usuário no arquivo
	char conteudo[200]; //armazena o conteúdo lido do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //lê o CPF digitado pelo usário e armazena na variável cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //abre o arquivo cujo nome é o CPF fornecido pelo usuário. ("r" de read para leitura do arquivo aberto)
	
	if(file == NULL) //verifica se o arquivo foi aberto.
	{
		printf("Arquivo não localizado! \n"); //caso o cpf não esteja cadastrado, é declarado como NULL e aparece essa mensagem
	}
	
	while(fgets(conteudo,200, file) != NULL) //lê cada linha do arquivo e armazena em 'conteudo'
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo); //imprime as informações que foram armazenadas na variável 'conteudo'
		printf("\n\n"); //fecha o arquivo após na conclusão da leitura
	}
	
	system("pause");
	
}

int deletar() //função de deletar
{
	char cpf[40]; //string cpf já cadastrada anteriormente no sistema
	
	printf("Digite o CPF do usuário a ser deletado: "); //imprime a mensagem na tela para que o usuário digite o cpf desejado
	scanf("%s", cpf); //procura o cpf digitado pelo usuário dentro da string cpf
	
	remove(cpf); //remove o cpf caso ele seja encontrado
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo cpf no modo de leitura
	
	if(file == NULL); //função if para caso não encontre o cadastro do cpf no sistema
	{
		printf("Usuário não encontrado no sistema!\n"); //caso o cpf não seja encontrado no sistema, exibe essa mensagem no console para o usuário
		system("pause");
	}
	

}

int main() //Função de número inteiro
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo o laço de repetição
	
	for(laco=1;laco=1;)//Início do laço de repetição
	{
		
		system ("cls"); //Limpa a tela do console
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção:"); //final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário dentro da variável opcao. $d: lê dados de número inteiro.
		
		system("cls"); //limpa a tela após o comando do usuário
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
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
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //Fim da seleção
		
	}//Fim do laço de repetição
}
