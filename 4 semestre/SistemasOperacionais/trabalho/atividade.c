/*Cassio V. Ferrazzo*/
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
 DIR *dr;
 char *arq;
 arq = (char *)malloc(20*sizeof(char));
 char *frase;
 frase = (char *)malloc(100*sizeof(char));
 char *caminho;
 caminho = (char *)malloc(200*sizeof(char));
 struct dirent *ep;
 mkdir("/home/unochapeco/Downloads/Cassio/arquivos", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
 dr = opendir("/home/unochapeco/Downloads/Cassio/arquivos");
 system("touch /home/unochapeco/Downloads/Cassio/arquivos/arq1.txt"); 
 system("touch /home/unochapeco/Downloads/Cassio/arquivos/arq2.txt");
 system("touch /home/unochapeco/Downloads/Cassio/arquivos/arq3.txt");
 system("touch /home/unochapeco/Downloads/Cassio/arquivos/arq4.txt");
 if(dr!=NULL)
  {
   while(ep=readdir(dr))//o ponteiro ep é apontado para a estrutura dirent
    {
     puts(ep->d_name);
    }
   strcpy(caminho,"/home/unochapeco/Downloads/Cassio/arquivos/");
   printf("\n\nDigite o arquivo com a extensao que deseja utilizar: ");
   gets(arq);
   strcat(caminho,arq);
   int pa = open(caminho,O_CREAT|O_WRONLY, S_IREAD|S_IWUSR);
   if(pa)
     {
      printf("Digite algo a ser gravado no arquivo selecioando: ");
      gets(frase);
      write(pa,frase,strlen(frase));
     }
   close(pa);
   (void) closedir (dr); 
  }
 else
  printf("\nImpossivel abrir o diretorio.\n");
 free(arq);
 free(frase);
 free(caminho);
 
 return(0);
}
        
