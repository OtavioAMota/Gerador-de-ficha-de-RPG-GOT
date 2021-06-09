#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

	int comando, num, quant, resul, soma=0,contas, loop=1, somaRM, mediaTT, media;
	int defesa, influencia, lei, poder, populacao, riqueza, terras;
	int multdefesa=0 , multinfluencia=0, multlei=0 , multpoder=0, multpopulacao=0 , multriqueza=0,  multterras=0;
	char nivel, reino[200];

//MUDA A POSIÇÃO DO CURSOR DO CONSOLE
void gotoxy(int x,int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
//ESCONDER CURSOR DO CONSOLE
void HideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void clear(){
	system("color 70");
	system("CLS");
}

int dados(int num, int quant){
	srand(time(NULL));
	soma = 0;
	somaRM = 0;
	mediaTT = 0;
	for(int i=1;i<=quant;i++){
		resul = rand() % num+1;
		media = 0;
		//resul = 6; // para teste 100% rank S
		if(resul==0){
			resul=1;
		}
		if(soma>=num*0){
			nivel='F';
		}
		if(soma>=num*0.125){
			nivel='E';
		}
		if(soma>=num*0.25){
			nivel='D';
		}
		if(resul>=num*0.5){
			nivel='C';
		}
		if(resul>=num*0.75){
			nivel='B';
		}
		if(resul>=num*0.875){
			nivel='A';
		}
		if(resul==num*1.0){
			nivel='S';
		}
		switch(nivel){
			case 'F':
				somaRM = somaRM - 3;
				media = -3;
				break;
			case 'E':
				somaRM = somaRM - 2;
				media = -2;
				break;
			case 'D':
				somaRM = somaRM - 1;
				media = -1;
				break;
			case 'C':
				somaRM = somaRM + 0;
				media = 0;
				break;
			case 'B':
				somaRM = somaRM + 1;
				media = 1;
				break;
			case 'A':
				somaRM = somaRM + 2;
				media = 2;
				break;
			case 'S':
				somaRM = somaRM + 3;
				media = 3;
				break;
		}
		mediaTT = mediaTT + media;
		printf("dado - %d : %d - Rank:%c (%d)  \n",i,resul,nivel,media);
		soma = soma + resul;
		_sleep(100);
	}
	somaRM = somaRM / quant;
	switch(somaRM){
		case -3:
			nivel='F';
			break;
		case -2:
			nivel='E';
			break;
		case -1:
			nivel='D';
			break;
		case 0:
			nivel='C';
			break;
		case 1:
			nivel='B';
			break;
		case 2:
			nivel='A';
			break;
		case 3:
			nivel='S';
			break;
	}
	printf("\nsoma dos dados : %d - Rank:%c (%d)  \n\n",soma,nivel,somaRM);
	_sleep(quant*100);
	return soma;
}

void descReino(){

	//defesa descrição 
	//defesa = 100;
	printf("\n-----------------------------------------------------\n");
	printf("Defesa(%d):",defesa);
	if(defesa<=0){
		_sleep(250);
		printf(" Terra desolada e arruinada, assolada\n");
		_sleep(250);
		printf("por desastres ou guerra, ou apenas abandonada.\n");
		_sleep(250);
		printf("Nenhuma estrutura defensiva de\n");
		_sleep(250);
		printf("qualquer tipo e nenhuma infraestrutura\n");
		_sleep(200);
		printf("para movimentacao de tropas.\n");
		_sleep(250);
		printf("Voce nao tem nenhuma fortificacao.\n");
	}
	if(defesa>=1 && defesa<=10){
		_sleep(250);
		printf(" Cultivo escasso, a maior parte\n");
		_sleep(250);
		printf("da terra e selvagem, com alguns bolsoes de civilizacao\n");
		_sleep(250);
		printf("sem qualquer protecao. Uma\n");
		_sleep(250);
		printf("ou duas estradas ou um forte pequeno.\n");
	}
	if(defesa>=11 && defesa<=20){
		_sleep(250);
		printf(" Algum cultivo, presenca de um forte ou\n");
		_sleep(250);
		printf("uma estrutura menor com\n");
		_sleep(250);
		printf("algumas estradas, rios ou portos.\n");
	}
	if(defesa>=21 && defesa<=30){
		_sleep(250);
		printf(" Defensavel, com pelo menos uma\n");
		_sleep(250);
		printf("cidade fortificada ou castelo. Existem\n");
		_sleep(250);
		printf("estradas e trilhas; provavelmente\n");
		_sleep(250);
		printf("existem rios ou portos.\n");
	}
	if(defesa>=31 && defesa<=40){
		_sleep(250);
		printf(" Boas defesas, com presença quase certa\n");
		_sleep(250);
		printf("de um castelo, alem de alguns outros pontos\n");
		_sleep(250);
		printf("fortificados. Estradas e rios fornecem\n");
		_sleep(250);
		printf("transporte facil. Como alternativa, caracteristicas\n");
		_sleep(250);
		printf("naturais do terreno, como\n");
		_sleep(250);
		printf("montanhas ou pantanos, fornecem fortificacoes adicionais.");
	}
	if(defesa>=41 && defesa<=50){
		_sleep(250);
		printf(" Defesas excelentes, com fortificacoes\n");
		_sleep(250);
		printf("construidas provavelmente\n");
		_sleep(250);
		printf("combinadas com caracteristicas naturais do terreno.\n");
	}
	if(defesa>=51 && defesa<=60){
		_sleep(250);
		printf(" Defesas extraordinarias, com estruturas,\n");
		_sleep(250);
		printf("muralhas e caracteristicas naturais que, em\n");
		_sleep(250);
		printf("conjunto, tornam um ataque a esta\n");
		_sleep(250);
		printf("terra um empreendimento muito custoso.\n");
	}
	if(defesa>=61 && defesa<=70 || defesa > 70){
		_sleep(250);
		printf(" Uma das maiores defesas do mundo. Um bom\n");
		_sleep(250);
		printf("exemplo seria Ninho da Aguia e o Vale de Arryn\n");
	}
	//influencia descrição
	//influencia = 100;
	printf("-----------------------------------------------------\n");
	printf("Influencia(%d):",influencia);
	if(influencia<=0){
		_sleep(250);
		printf(" O nome e a historia da casa foram apagados\n");
		_sleep(250);
		printf("de todos os registros, ninguem menciona-os.\n");
	}
	if(influencia>=1 && influencia<=10){
		_sleep(250);
		printf("  Status máximo do Lorde: 2. Um exemplo seria Craster.\n");
		_sleep(250);
		printf("Um cavaleiro com terras menor.\n");
	}
	if(influencia>=11 && influencia<=20){
		_sleep(250);
		printf(" Status maximo do Lorde: 3. Um cavaleiro\n");
		_sleep(250);
		printf("com terras maior. Exemplos de casas seriam os\n");
		_sleep(250);
		printf("Knott e os Liddle, no Norte.\n");
	}
	if(influencia>=21 && influencia<=30){
		_sleep(250);
		printf("  Status maximo do Lorde: 4. Uma casa menor\n");
		_sleep(250);
		printf("de pouca importancia. Exemplos incluem a Casa\n");
		_sleep(250);
		printf("Mormont e a Casa Povo do Oeste.\n");
	}
	if(influencia>=31 && influencia<=40){
		_sleep(250);
		printf(" Status Maximo do Lorde: 4. Uma casa menor.\n");
		_sleep(250);
		printf("Exemplos incluem a Casa Clegane,\n");
		_sleep(250);
		printf("a Casa Payne e a Casa Karstark.\n");
	}
	if(influencia>=41 && influencia<=50){
		_sleep(250);
		printf("  Status maximo do Lorde: 5.\n");
		_sleep(250);
		printf("Uma casa menor poderosa, com uma historia rica.\n");
		_sleep(250);
		printf("Exemplos incluem a Casa Florent e a Casa Frey.\n");
	}
	if(influencia>=51 && influencia<=60){
		_sleep(250);
		printf("  Status máximo do Lorde: 6. Uma casa maior.\n");
		_sleep(250);
		printf("Exemplos incluem a Casa Tully e a Casa Martell\n");
	}
	if(influencia>=61 && influencia<=70 || influencia>70){
		_sleep(250);
		printf("  Status maximo do Lorde: 7. Uma grande casa.\n");
		_sleep(250);
		printf("Exemplos incluem a Casa Arryn, a Casa Stark,\n");
		_sleep(250);
		printf("a Casa Baratheon e a Casa Lannister.\n");
	}
	
	//lei descrição
	//lei = 100;
	printf("-----------------------------------------------------\n");
	printf("Lei(%d):",lei);
	if(lei<=0){
		_sleep(250);
		printf("  Terra selvagem e sem lei. Voce nao tem\n");
		_sleep(250);
		printf("autoridade aqui — as terras alem da Muralha.\n");
	}
	if(lei>=1 && lei<=10){
		_sleep(250);
		printf(" Bandidos, saqueadores e outros bandos\n");
		_sleep(250);
		printf("criminosos operam nas suas terras,\n");
		_sleep(250);
		printf("causando problemas e preocupacoes.\n");
	}
	if(lei>=11 && lei<=20){
		_sleep(250);
		printf(" O crime e um problema nos\n");
		_sleep(250);
		printf("arrabaldes de suas terras.\n");
	}
	if(lei>=21 && lei<=30){
		_sleep(250);
		printf("  O nivel de Lei em boa parte de Westeros.\n");
		_sleep(250);
		printf("O crime e comum, mas esta sob controle.\n");
	}
	if(lei>=31 && lei<=40){
		_sleep(250);
		printf(" Voce tem bastante controle sobre\n");
		_sleep(250);
		printf("suas terras, o crime e incomum.\n");
	}
	if(lei>=41 && lei<=50){
		_sleep(250);
		printf(" Sua influencia e devocao a manter a paz\n");
		_sleep(250);
		printf("sao tamanhas que o crime e raro.\n");
	}if(lei>=51 && lei<=60){
		_sleep(250);
		printf("Quase nao existe crime em suas terras\n");
	}
	if(lei>=61 && lei<=70 || lei>70){
		_sleep(250);
		printf(" Nao ha crime em suas terras.\n");
	}
	//poder descrição
	//poder = 100;
	printf("-----------------------------------------------------\n");
	printf("Poder(%d):",poder);
	if(poder<=0){
		_sleep(250);
		printf(" Nenhum poder. Voce nao tem\n");
		_sleep(250);
		printf("tropas ou soldados, nem qualquer\n");
		_sleep(250);
		printf("pessoa leal a sua familia.\n");
	}
	if(poder>=1 && poder<=10){
		_sleep(250);
		printf("  Apenas uma guarda pessoal, com uma\n");
		_sleep(250);
		printf("ou duas espadas juradas e no máximo\n");
		_sleep(250);
		printf("um esquadrao de guerreiros plebeus.\n");
	}
	if(poder>=11 && poder<=20){
		_sleep(250);
		printf("  Uma pequena forca de soldados,\n");
		_sleep(250);
		printf("quase todos plebeus.\n");
	}
	if(poder>=21 && poder<=30){
		_sleep(250);
		printf(" Uma forca modesta de soldados,\n");
		_sleep(250);
		printf("incluindo alguns treinados.\n");
	}
	if(poder>=31 && poder<=40){
		_sleep(250);
		printf("  Uma forca treinada de soldados, incluindo\n");
		_sleep(250);
		printf("cavalaria e possivelmente navios. Voce\n");
		_sleep(250);
		printf("pode contar com o servico de uma \n");
		_sleep(250);
		printf("família nobre (um brasão vassalo).\n");
	}
	if(poder>=41 && poder<=50){
		_sleep(250);
		printf(" Uma grande forca de soldados treinados,\n");
		_sleep(250);
		printf("variados e competentes. Voce provavelmente \n");
		_sleep(250);
		printf("tambem conta com os servicos de uma pequena\n");
		_sleep(250);
		printf("forca naval. Varias casas são juradas a voce.\n");
	}
	if(poder>=51 && poder<=60){
		_sleep(250);
		printf(" Voce pode arregimentar uma forca imensa\n");
		_sleep(250);
		printf("de soldados, tirados de suas terras e das \n");
		_sleep(250);
		printf("terras das varias casas juradas a voce.\n");
	}
	if(poder>=61 && poder<=70 || poder>70){
		_sleep(250);
		printf(" Voce conta com a forca da maior\n");
		_sleep(250);
		printf("parte dos Sete Reinos.\n");
	}
	//populacao descrição
	//populacao = 100;
	printf("-----------------------------------------------------\n");
	printf("Populacao(%d):",populacao);
	if(populacao<=0){
		_sleep(250);
		printf(" Vazio. Ninguem vive sob seu governo.\n");
	}
	if(populacao>=1 && populacao<=10){
		_sleep(250);
		printf(" População escassa. Minusculas comunidades\n");
		_sleep(250);
		printf("espalham-se por suas terras.\n");
	}
	if(populacao>=11 && populacao<=20){
		_sleep(250);
		printf(" Populacao pequena, mas nenhuma\n");
		_sleep(250);
		printf("comunidade maior que uma cidade pequena.\n");
	}
	if(populacao>=21 && populacao<=30){
		_sleep(250);
		printf("  População tipica. A maioria dos\n");
		_sleep(250);
		printf("plebeus vive em fazendas ou aldeias,\n");
		_sleep(250);
		printf("mas voce pode ter algumas cidades \n");
		_sleep(250);
		printf("pequenas e uma comunidade ao\n");
		_sleep(250);
		printf("redor de sua principal fortificacao.\n");
	}
	if(populacao>=31 && populacao<=40){
		_sleep(250);
		printf("  Populacao modesta. Pelo menos\n");
		_sleep(250);
		printf("uma cidade e varias aldeias.\n");
	}
	if(populacao>=41 && populacao<=50){
		_sleep(250);
		printf(" Populacao grande. Você tem muitas \n");
		_sleep(250);
		printf("pessoas em suas terras; varias vivem\n");
		_sleep(250);
		printf("em uma cidade grande ou espalham-se\n");
		_sleep(250);
		printf("por inumeras cidades pequenas.\n");
	}
	if(populacao>=51 && populacao<=60){
		_sleep(250);
		printf("  Populacao imensa. Um enorme numero\n");
		_sleep(250);
		printf("de pessoas vive sob sua protecao.\n");
	}
	if(populacao>=61 && populacao<=70 || populacao>70){
		_sleep(250);
		printf(" Quase todos em Westeros.\n");
	}
	//riqueza descrição
	//riqueza = 100;
	printf("-----------------------------------------------------\n");
	printf("Riqueza(%d):",riqueza);
	if(riqueza<=0){
		_sleep(250);
		printf(" Miseravel. Sua familia nao\n");
		_sleep(250);
		printf("tem uma unica moeda.\n");
	}
	if(riqueza>=1 && riqueza<=10){
		_sleep(250);
		printf("  Arrasada. Sua familia nao dispoe de recursos\n");
		_sleep(250);
		printf("essenciais e tem dificuldade em sobreviver\n");
	}
	if(riqueza>=11 && riqueza<=20){
		_sleep(250);
		printf(" Pobre. Sua familia dispoe de poucos excessos.\n");
		_sleep(250);
		printf("Embora consiga se sustentar e sustentar\n");
		_sleep(250);
		printf("seus dominios, nao ha qualquer luxo.\n");
	}
	if(riqueza>=21 && riqueza<=30){
		_sleep(250);
		printf(" Comum. Sua familia consegue se virar\n");
	}
	if(riqueza>=31 && riqueza<=40){
		_sleep(250);
		printf(" Prospera. Sua familia tem recursos para\n");
		_sleep(250);
		printf("viver de acordo com sua posicao.\n");
	}
	if(riqueza>=41 && riqueza<=50){
		_sleep(250);
		printf(" Opulenta. Sua familia tem mais recursos\n");
		_sleep(250);
		printf("do que precisa, e vive confortavelmente.\n");
	}
	if(riqueza>=51 && riqueza<=60){
		_sleep(250);
		printf("  Rica. Nada falta para sua familia.\n");
	}
	if(riqueza>=61 && riqueza<=70 || riqueza>70){
		_sleep(250);
		printf(" Decadente. Sua familia e tao abastada que pode\n");
		_sleep(250);
		printf("oferecer banquetes de setenta e sete pratos.\n");
	}
	//terras descrição
	//terras = 100;
	printf("-----------------------------------------------------\n");
	printf("Terras(%d):",terras);
	if(terras<=0){
		_sleep(250);
		printf(" Sem terras, a casa perdeu todas as suas posses.\n");
	}
	if(terras>=1 && terras<=10){
		_sleep(250);
		printf(" Terras minusculas, com o tamanho\n");
		_sleep(250);
		printf("maximo de uma unica cidade pequena.\n");
	}
	if(terras>=11 && terras<=20){
		_sleep(250);
		printf("  Uma pequena extensão de terras, com o\n");
		_sleep(250);
		printf("tamanho aproximado de uma unica ilha\n");
		_sleep(250);
		printf("pequena ou uma pequena parte de uma\n");
		_sleep(250);
		printf("ilha maior; ou uma grande cidade e seus\n");
		_sleep(250);
		printf("arredores, como a Casa Mormont.\n");
	}
	if(terras>=21 && terras<=30){
		_sleep(250);
		printf("  Uma extensao de terras modesta ou uma\n");
		_sleep(250);
		printf("ilha de tamanho medio, como a Casa Frey.\n");
	}
	if(terras>=31 && terras<=40){
		_sleep(250);
		printf(" Uma area que inclui varios acidentes\n");
		_sleep(250);
		printf("geograficos, ilhas ou grandes grupos de\n");
		_sleep(250);
		printf("ilhas. Por exemplo, a Casa Greyjoy.\n");
	}
	if(terras>=41 && terras<=50){
		_sleep(250);
		printf(" Uma grande area que se estende por uma\n");
		_sleep(250);
		printf("vasta distancia. O controle que a Casa Martell\n");
		_sleep(250);
		printf("tem sobre Dorne representa este nivel.\n");
	}
	if(terras>=51 && terras<=60){
		_sleep(250);
		printf(" Uma imensa area, representando uma\n");
		_sleep(250);
		printf("porcao consideravel da geografia de\n");
		_sleep(250);
		printf("Westeros. O controle que a Casa Stark\n");
		_sleep(250);
		printf("tem sobre o Norte é um bom exemplo.\n");
	}
	if(terras>=61 && terras<=70 || terras >70){
		_sleep(250);
		printf("  A maior parte dos Sete Reinos, ou todo o\n");
		_sleep(250);
		printf("territorio. Exemplos: os dominios do Rei\n");
		_sleep(250);
		printf("Robert e do ramo real da Casa Baratheon.\n");
	}
	printf("\n\n");
	system("pause");
}

void fundacao(){
	
	dados(6,1);
}

void criarReino(){
	comando=0;
	defesa=0; influencia=0; lei=0; poder=0; populacao=0; riqueza=0; terras=0;
	multdefesa=-9999999999 ; multinfluencia=-9999999999; multlei=-9999999999 ; multpoder=-9999999999; multpopulacao=-9999999999 ; multriqueza=-9999999999;  multterras=-9999999999;
	system("title Criando o reino - RPG v0.01");
	printf("-------------------------------------------\n");
	printf("|Escolha um reino para comecar            |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- nome do reino         (Rolagem)|\n");
	printf("|[1]     - Porto do Rei          (   3   )|\n");
	printf("|[2]     - Rocha do Dragao       (   4   )|\n");
	printf("|[3]     - O Norte               (  5-6  )|\n");
	printf("|[4]     - As Ilhas de Ferro     (   7   )|\n");
	printf("|[5]     - As Terras Fluviais    (  8-9  )|\n");
	printf("|[6]     - As Montanhas da Lua   ( 10-11 )|\n");
	printf("|[7]     - As Terras Ocidentais  ( 12-13 )|\n");
	printf("|[8]     - O Extremo             ( 14-15 )|\n");
	printf("|[9]     - As Terras Tempestuosas( 16-17 )|\n");
	printf("|[10]    - Dorne                 (  1 8  )|\n");
	printf("-------------------------------------------\n");
	printf("|11-Aleatorio(escolhe o reino para voce)  |\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			strcpy(reino, "Porto do Rei");
			multdefesa=5 ; multinfluencia=-5; multlei=20 ; multpoder=-5; multpopulacao=5 ; multriqueza=-5; multterras=-5;
			break;
		case 2:
			strcpy(reino,"Rocha do Dragao");
			multdefesa=20; multinfluencia=-5; multlei=5  ; multpoder=0 ; multpopulacao=0 ; multriqueza=-5; multterras=-5;
			break;
		case 3:
			strcpy(reino,"O Norte");
			multdefesa=5 ; multinfluencia=10; multlei=-10; multpoder=-5; multpopulacao=-5; multriqueza=-5; multterras=20;
			break;
		case 4:
			strcpy(reino,"As Ilhas de Ferro");
			multdefesa=10; multinfluencia=-5; multlei=0  ; multpoder=10; multpopulacao=0 ; multriqueza=0;  multterras=-5;
			break;
		case 5:
			strcpy(reino,"As Terras Fluviais");
			multdefesa=-5; multinfluencia=-5; multlei=0  ; multpoder=0 ; multpopulacao=10; multriqueza=5;  multterras=5 ;
			break;
		case 6:
			strcpy(reino,"As Montanhas da Lua");
			multdefesa=20; multinfluencia=10; multlei=-10; multpoder=0 ; multpopulacao=-5; multriqueza=0;  multterras=-5;
			break;
		case 7:
			strcpy(reino,"As Terras Ocidentais");
			multdefesa=-5; multinfluencia=10; multlei=-5 ; multpoder=0 ; multpopulacao=-5; multriqueza=20; multterras=-5;
			break;
		case 8:
			strcpy(reino,"O Extremo");
			multdefesa=-5; multinfluencia=10; multlei=-5 ; multpoder=0 ; multpopulacao=5 ; multriqueza=5;  multterras=0 ;
			break;
		case 9:
			strcpy(reino,"As Terras Tempestuosas");
			multdefesa=5 ; multinfluencia=0 ; multlei=10 ; multpoder=5;  multpopulacao=-5; multriqueza=0;  multterras=-5;
			break;
		case 10:
			strcpy(reino,"Dorne");
			multdefesa=0 ; multinfluencia=-5; multlei=-5 ; multpoder=10; multpopulacao=0 ; multriqueza=0;  multterras=10;
			break;
		case 11:
			dados(6,3);
			switch(soma){
				case 3:
					strcpy(reino,"Porto do Rei");
					multdefesa=5 ; multinfluencia=-5; multlei=20 ; multpoder=-5; multpopulacao=5 ; multriqueza=-5; multterras=-5;
					break;
				case 4:
					strcpy(reino,"Rocha do Dragao");
					multdefesa=20; multinfluencia=-5; multlei=5  ; multpoder=0 ; multpopulacao=0 ; multriqueza=-5; multterras=-5;
					break;
				case 5:
					strcpy(reino,"O Norte");
					multdefesa=5 ; multinfluencia=10; multlei=-10; multpoder=-5; multpopulacao=-5; multriqueza=-5; multterras=20;
					break;
				case 6:
					strcpy(reino,"O Norte");
					multdefesa=5 ; multinfluencia=10; multlei=-10; multpoder=-5; multpopulacao=-5; multriqueza=-5; multterras=20;
					break;
				case 7:
					strcpy(reino,"As Ilhas de Ferro");
					multdefesa=10; multinfluencia=-5; multlei=0  ; multpoder=10; multpopulacao=0 ; multriqueza=0;  multterras=-5;
					break;
				case 8:
					strcpy(reino,"As Terras Fluviais");
					multdefesa=-5; multinfluencia=-5; multlei=0  ; multpoder=0 ; multpopulacao=10; multriqueza=5;  multterras=5 ;
					break;
				case 9:
					strcpy(reino,"As Terras Fluviais");
					multdefesa=-5; multinfluencia=-5; multlei=0  ; multpoder=0 ; multpopulacao=10; multriqueza=5;  multterras=5 ;
					break;
				case 10:
					strcpy(reino,"As Montanhas da Lua");
					multdefesa=20; multinfluencia=10; multlei=-10; multpoder=0 ; multpopulacao=-5; multriqueza=0;  multterras=-5;
					break;
				case 11:
					strcpy(reino,"As Montanhas da Lua");
					multdefesa=20; multinfluencia=10; multlei=-10; multpoder=0 ; multpopulacao=-5; multriqueza=0;  multterras=-5;
					break;
				case 12:
					strcpy(reino,"As Terras Ocidentais");
					multdefesa=-5; multinfluencia=10; multlei=-5 ; multpoder=0 ; multpopulacao=-5; multriqueza=20; multterras=-5;
					break;
				case 13:
					strcpy(reino,"As Terras Ocidentais");
					multdefesa=-5; multinfluencia=10; multlei=-5 ; multpoder=0 ; multpopulacao=-5; multriqueza=20; multterras=-5;
					break;
				case 14:
					strcpy(reino,"O Extremo");
					multdefesa=-5; multinfluencia=10; multlei=-5 ; multpoder=0 ; multpopulacao=5 ; multriqueza=5;  multterras=0 ;
					break;
				case 15:
					strcpy(reino,"O Extremo");
					multdefesa=-5; multinfluencia=10; multlei=-5 ; multpoder=0 ; multpopulacao=5 ; multriqueza=5;  multterras=0 ;
					break;
				case 16:
					strcpy(reino,"As Terras Tempestuosas");
					multdefesa=5 ; multinfluencia=0 ; multlei=10 ; multpoder=5;  multpopulacao=-5; multriqueza=0;  multterras=-5;
					break;
				case 17:
					strcpy(reino,"As Terras Tempestuosas");
					multdefesa=5 ; multinfluencia=0 ; multlei=10 ; multpoder=5;  multpopulacao=-5; multriqueza=0;  multterras=-5;
					break;
				case 18:
					strcpy(reino,"Dorne");
					multdefesa=0 ; multinfluencia=-5; multlei=-5 ; multpoder=10; multpopulacao=0 ; multriqueza=0;  multterras=10;
					break;
				default:
					if(soma>=19){
						strcpy(reino,"ERROR");
					}
					break;
			}
			break;
		default:
			if(comando>=12){
				strcpy(reino,"Escolha incorreta");
			main();
			break;
			}
	}
	printf("\nReino Escolhido: %s.\n\n",reino);
	printf("Proximo passo: Rolar dados de DEFESA\n");
	system("pause");
	clear();
	printf("-------------------------------------------\n");
	printf("|Rolar dados de DEFESA                    |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			defesa = defesa + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			defesa = defesa + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("Proximo passo: Rolar dados de INFLUENCIA\n");
	system("pause");
	clear();
	printf("-------------------------------------------\n");
	printf("|Rolar dados de INFLIENCIA                |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			influencia = influencia + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			influencia = influencia + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("Proximo passo: Rolar dados de LEI\n");
	system("pause");
	clear();
	printf("-------------------------------------------\n");
	printf("|Rolar dados de LEI                       |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			lei = lei + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			lei = lei + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("Proximo passo: Rolar dados de PODER\n");
	system("pause");
	clear();
	printf("-------------------------------------------\n");
	printf("|Rolar dados de PODER                     |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			poder = poder + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			poder = poder + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("Proximo passo: Rolar dados de POPULACAO\n");
	system("pause");
	clear();
	printf("-------------------------------------------\n");
	printf("|Rolar dados de POPULACAO                 |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			populacao = populacao + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			populacao = populacao + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("Proximo passo: Rolar dados de RIQUEZA\n");
	system("pause");
	clear();;
	printf("-------------------------------------------\n");
	printf("|Rolar dados de RIQUEZA                   |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			riqueza = riqueza + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			riqueza = riqueza + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("Proximo passo: Rolar dados de TERRAS\n");
	system("pause");
	clear();
	printf("-------------------------------------------\n");
	printf("|Rolar dados de TERRAS                    |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Tipo de rolagem    (Informacao)|\n");
	printf("|[1]     - Padrao        (7 dados 6 lados)|\n");
	printf("|[2]     - Mestre Edita  (X dados X lados)|\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			dados(6,7);
			terras = terras + soma;
			break;
		case 2:
			printf("Lados do dado:");
			scanf("%d",&num);
			printf("Quantidade de dados:");
			scanf("%d",&quant);
			dados(num,quant);
			terras = terras + soma;
			break;
		default:
			printf("ERRO");
			break;
	}
	printf("\nProximo passo: Descricao dos recursos do reino\n");
	system("pause");
	clear();
	defesa     = defesa     + multdefesa;
	influencia = influencia + multinfluencia;
	lei        = lei        + multlei;
	poder      = poder      + multpoder;
	populacao  = populacao  + multpopulacao;
	riqueza    = riqueza    + multriqueza;
	terras     = terras     + multterras;
	descReino();
	system("pause");
	menu();
}

void menu(){
	system("title Menu - RPG v0.01");
	clear();
	while(loop==1){
		gotoxy(0,0);
		printf("-------------------------------------------\n"         );
		printf("|Nome do Reino  :%s\n"                           ,reino);
		printf("-------------------------------------------\n"         );
		printf("|Recursos       :[Total] (Valores Iniciais)\n"         );
		printf("|Defesa         :[%d] (%d)\n"        ,defesa,multdefesa);
		printf("|Influencia     :[%d] (%d)\n",influencia,multinfluencia);
		printf("|Lei            :[%d] (%d)\n"              ,lei,multlei);
		printf("|Poder          :[%d] (%d)\n"         ,poder ,multpoder);
		printf("|Populacao      :[%d] (%d)\n"  ,populacao,multpopulacao);
		printf("|Riqueza        :[%d] (%d)\n"      ,riqueza,multriqueza);
		printf("|Terras         :[%d] (%d)\n"        ,terras,multterras);
		printf("-------------------------------------------\n"         );
		printf("Comando:");
		gotoxy(60,0);
		printf("-------------------------------------------\n");
		gotoxy(60,1);
		printf("|Opcoes de comando                        |\n");
		gotoxy(60,2);
		printf("-------------------------------------------\n");
		gotoxy(60,3);
		printf("|[numero]- Opcoes                         |\n");
		gotoxy(60,4);
		printf("|[1]     - Descricao dos recursos da casa |\n");
		gotoxy(60,5);
		printf("|[2]     - Historia da casa               |\n");
		gotoxy(60,6);
		printf("|[3]     - Posses                         |\n");
		gotoxy(60,7);
		printf("|[4]     - Treinamento de unidades        |\n");
		gotoxy(60,8);
		printf("|[5]     - Brasoes vassalos               |\n");
		gotoxy(60,9);
		printf("|[6]     - Lema e brasao                  |\n");
		gotoxy(60,10);
		printf("|[7]     - Personagem                     |\n");
		gotoxy(60,11);
		printf("|[8]     - Gerenciamento de recurso       |\n");
		gotoxy(60,12);
		printf("|[9]     - Compra de itens                |\n");
		gotoxy(60,13);
		printf("|[10]    - Mais opcoes                    |\n");
		gotoxy(60,14);
		printf("-------------------------------------------\n");
		gotoxy(60,15);
		printf("|                                         |\n");
		gotoxy(60,16);
		printf("-------------------------------------------\n");
		gotoxy(8,12);
		scanf("%d",&comando);
		switch(comando){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}
	main();
}
int main (){
	clear();
	system("title Inicio - RPG v0.01");
	printf("-------------------------------------------\n");
	printf("|Tela inicial                             |\n");
	printf("-------------------------------------------\n");
	printf("|[numero]- Opcao                          |\n");
	printf("|[1]     - Criar reino                    |\n");
	printf("|[2]     - Carregar reino existente       |\n");
	printf("|[3]     - Excluir reino existente        |\n");
	printf("|[4]     - Configuracoes                  |\n");
	printf("|[5]     - Sair                           |\n");
	printf("|[6]     - [BLOQUEADO]                    |\n");
	printf("|[7]     - [BLOQUEADO]                    |\n");
	printf("|[8]     - [BLOQUEADO]                    |\n");
	printf("|[9]     - [BLOQUEADO]                    |\n");
	printf("|[10]    - [BLOQUEADO]                    |\n");
	printf("-------------------------------------------\n");
	printf("|                                         |\n");
	printf("-------------------------------------------\n");
	printf("Escolha a opcao desejada(APENAS NUMEROS):");
	scanf("%d",&comando);
	switch(comando){
		case 1:
			clear();
			criarReino();
			break;
		case 2:
			menu();
			break;
		case 3:
			main();//
			break;
		case 4:
			main();//
			break;
		case 5:
			main();//
			break;
		case 6:
			main();//
			break;
		default:
			comando=0;
			main();
			break;
	}
	return 0;
}
