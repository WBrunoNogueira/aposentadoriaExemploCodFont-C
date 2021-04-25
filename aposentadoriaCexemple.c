#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*Rode o exemplo abaixo. Após entender o funcionamento do código faça
uma adequação para a criação de um código que faça o cálculo em funções separadas de acordo com
a regra de aposentadoria brasileira. 

Ex: aposentadoria por tempo de serviço, aposentadoria por tempo de serviço + idade e aposentadoria
por idade. Mesmo que exista outras possibilidades se atenha inicialmente a essas

o sistema tem que dizer se vc pode aposentar por idade 
por tempo de servico

*/
/*variaveis*/
char sexo;
int idade, tempo_contrib, op;

/*processamento*/
void aposentadoriaIdade(){
	if (idade >= 65 &&  tolower(sexo) == 'f'  ||  idade >= 60 && tolower(sexo) == 'm'){
		printf("APOSENTADORIA IDADE VALIDA");
			
	}
   	else{
   		printf("APOSENTADORIA IDADE INVALIDA");
   		
	}
}

void aposentadoriaTempo(){
	
	if ( tempo_contrib >= 30 &&  tolower(sexo) == 'f'  ||   tempo_contrib >= 35 && tolower(sexo) == 'm'){
		printf("APOSENTADORIA POR TEMPO DE SERVICO VALIDA");
			
	}
   	else{
   		printf("APOSENTADORIA TEMPO INVALIDA");
   		
	}
}

void aposentadoriaTempoIdade(void (*aposentadoriaTempo)(void), void (*aposentadoriaIdade)(void)){

	aposentadoriaIdade();
	printf("\t");
	aposentadoriaTempo();
	
}



int main(){

	/*entradas swich*/
	printf("SISTEMA DE ANALISE DE APOSENTADORIA");
	printf("\n Entre com as opção de escolha da apsentadoria:");
	printf("\n Menu:\n");
	printf("\n 1-APOSENTADORIA IDADE");
	printf("\n 2-TEMPO DE SERVICO");
	printf("\n 3-APOSENTADORIA IDADE E TEMPO DE SERVICO \n");
	scanf("%d", &op);
	
	
	/*entradas variaveis*/
	printf("Digite sua idade? \n");
	scanf("%d", &idade); 
	gets(stdin); 
	printf("Digite sexo (m/f)\n");
	scanf("%c", &sexo);
	gets(stdin);
	printf("Digite tempo de contribuicao em anos\n");
	scanf("%d", &tempo_contrib);    


 switch(op) {
	 case 1:
	 	aposentadoriaIdade(idade,sexo);
	 break;
	 
	 case 2:
		aposentadoriaTempo(tempo_contrib,sexo);
	 break;
	 
	 case 3:
	 	aposentadoriaTempoIdade(aposentadoriaIdade,aposentadoriaTempo);
	 break;	
	  
	 default:
	 printf("\nErro! Opcao inexistente.\n");
	 break;
}



return 0;
}

