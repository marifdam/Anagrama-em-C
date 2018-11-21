#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int opc;
char v;
int k=0,m=0;
int fimdejogo();
void jogo();
int menu();
int delay(unsigned int milliseconds);
void design();

void design(){
   printf("   ###    ##    ##    ###     ######   ########     ###    ##     ##    ###\n");
   printf("  ## ##   ###   ##   ## ##   ##    ##  ##     ##   ## ##   ###   ###   ## ##\n");
   printf(" ##   ##  ####  ##  ##   ##  ##        ##     ##  ##   ##  #### ####  ##   ##\n");
   printf("##     ## ## ## ## ##     ## ##   #### ########  ##     ## ## ### ## ##     ##\n");
   printf("######### ##  #### ######### ##    ##  ##   ##   ######### ##     ## #########\n");
   printf("##     ## ##   ### ##     ## ##    ##  ##    ##  ##     ## ##     ## ##     ##\n");
   printf("##     ## ##    ## ##     ##  ######   ##     ## ##     ## ##     ## ##     ##\n");
}

void jogo(){ //função propria do jogo
  char pal[20];
  int result;
  int i,j,n;
  char* c[15];
  char* new[15];
  char* a[]={"mara","puti","papo","liox","osex",
             "vinao","tores","varol","becola","josu",
             "carag","urosm","zican","freros","remesv"}; //palavras embaralhadas
  char* b[]={"rama","tupi","popa","lixo","sexo",
             "noiva","resto","valor","cebola","sujo",
             "carga","muros","cinza","ferros","vermes"}; //palavras certas

while((k<15 || m<20) || (k==15 && m==20)){ //roda o vetor
  if((k==15 || m==20) || (k==15 && m==20)){
    fimdejogo();
  }

  system("clear");
  design();
  for(i=0;i<=4;i++){
    printf(" %d)%s\t\t",i+1,a[i]);
  }
  putchar('\n');
  for(i=5;i<=9;i++){
    printf(" %d)%s\t",i+1,a[i]);
  }
  putchar('\n');
  for(i=10;i<=14;i++){
  printf(" %d)%s\t",i+1,a[i]);
  }
  printf("\n\n %dºchance\n",m);


  putchar('\n');printf("->");scanf("%s",pal);


  for(i=0;i<15;i++){
    result=strcasecmp(b[i],pal); //compara as palavras
    if(result==0 && strlen(pal)==strlen(a[i])){
    k++;

   c[i]=a[i];
   a[i]=b[i];
   b[i]=c[i];

 }

   }

      m++;

}

}

int menu(){  //função do menu
  volta_ao_menu:
  system("clear");
  design();
  //puts("\t\t  ANAGRAMA\n");
  puts("\t\t> > Menu < <\n");
  puts("\t\t1 -> Jogar");
  puts("\t\t2 -> Regras do jogo");
  puts("\t\t3 -> Sair\n");

  printf("-> ");scanf("%d",&opc);

if(opc==1)
  {
    system("clear");
    jogo();
  }

if(opc==2)
  {
    system("clear");
  puts("\t\tREGRAS\n");
  puts("1 - Decifre as palavras embaralhadas");
  puts("2 - Voce só tem apenas 20 tentativas de respostas");
  puts("3 - Elas estao organizadas de tal forma que pareçam ser outras palavras");
  puts("\n\tvoltando ao menu..\n");
  delay(10000);
  goto volta_ao_menu;
  }

    if(opc==3){
     return 0;
   }

     if(opc!=1 ||opc!=2 ||opc!=3){

     puts("Alternativa não existente.");
     delay(3000);
     goto volta_ao_menu;
     }
   }



int fimdejogo(){ //função do fim do jogo
     if(k==15 || (k==15 && m==20)){
       puts("\nParabéns voce ganhou!!!");
       goto fim;
     }
     if(m==20){
       puts("\nParabens voce perdeu...");
     }
    fim:
     puts("\tFim de jogo.\n Gostaria de jogar novamente?");
     puts("1-Sim\n2-Não\n");
	   printf("-> ");scanf("%d",&opc);
    if(opc==1){
       system("clear");
       k=0;m=0;
       jogo();
      }
    else if(opc==2){
       printf("tchau!\n");
	     exit(0);
      }
   }

 int delay(unsigned int milliseconds)
 {
     long delay; //tempo que o programa fica parado
     clock_t t0,tn; //t0 é o tempo de inicio do delay, tn é o tempo atual

     delay = milliseconds*(CLOCKS_PER_SEC/1000);

     t0 = tn = clock();
     while( (tn-t0) < delay )
         tn = clock();

     return 0;
 }

int main(){
  system("clear");
  menu();
}
