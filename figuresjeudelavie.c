#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int monrand(){//Fonction qui renvoit un random
  
   static int first = 0;
   
   if (first == 0)
     {
       srand( time(NULL) );
       first = 1;
     }
   return (rand ()%2);
}




void aleatoire(int ** mat,int n){


  if(n < 6)
    {
    
    printf("La matrice n'est pas assez grande pour une configuration aleatoire\n");
    exit(EXIT_FAILURE);
  }

  
   for(int i = 0 ; i < n ; i++)
     {
       for(int j = 0 ; j < 2 * n; j++)
	 {
	   mat[i][j] = 0;
	 }
   
     }

   for(int i = 0 ; i < n/4 ; i++)
     {
       for(int j = 0 ; j <2 *(n/4) ; j++)
	 {
	   if(monrand() == 1)
	     {
	       mat[n/2 - n/8 + i][n - n/4 + j] = 1;
	     } 
	 }
     } 
}



void petitefloraison(int ** mat,int n){
  if(n < 20)
    {
    
      printf("La matrice est pas assez grande pour cette floraison\n");
      exit(EXIT_FAILURE);
    }
  //Initialise la matrice � 0
  for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < 2 * n ; j++)
	{
	  mat[i][j] = 0;
	}

      }

  //Initialisation manuelle de l'�tat de base d'une petite floraison
  mat[n/2 -1][n - 1] = 1;
  mat[n/2 - 1][n] = 1;
  mat[n/2 - 1][n + 1] = 1;
  mat[n/2][n - 2] = 1;
  mat[n/2][n] = 1;
  mat[n/2][n + 2] = 1;
  mat[n/2 + 1][n - 1] = 1;
  mat[n/2 + 1][n] = 1;
  mat[n/2 + 1][n + 1] = 1;
    

}



void petitsoscillateurs(int ** mat,int n){
  if(n < 10)
    {
      
      printf("La matrice est pas assez grande pour ces oscillateurs\n");
      exit(EXIT_FAILURE);
    }

   for(int i = 0 ; i < n ; i++)
     {
       for(int j = 0 ; j < 2 * n ; j++)
	 {
	   mat[i][j] = 0;
	 }
   
     }

   //Initialisation manuelle de 3 petits oscillateur, 2 dans les coins sup�rieurs et 1 au milieu
   mat[1][1] = 1;
   mat[2][1] = 1;
   mat[3][1] = 1;

   mat[1][2 * n - 1] = 1;
   mat[1][2* n - 2] = 1;
   mat[1][2 * n - 3] = 1;
   mat[2][2 * n - 2] = 1;
   mat[2][2 * n - 3] = 1;
   mat[2][2 * n - 4] = 1;


   mat[n/2][n - 2] = 1;
   mat[n/2 ][n - 1] = 1;
   mat[n/2 + 1 ][n - 2] = 1;
   mat[n/2 + 1][n - 1] = 1;
   mat[n/2 + 2][n] = 1;
   mat[n/2 + 2][n + 1] = 1;
   mat[n/2 + 3][n] = 1;
   mat[n/2 + 3][n + 1] = 1;
   
      
  

  
}




void pulsar(int ** mat,int n){
    if(n < 16)
      {

	printf("La matrice est pas assez grande pour le Pulsar\n");
	exit(EXIT_FAILURE);
      }
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < 2 * n ; j++){
	mat[i][j] = 0;
      }
   
    }

    //Pareil 
    mat[n/2 - 2][n - 1] = 1;
    mat[n/2 - 3][n - 1] = 1;
    mat[n/2 - 4][n - 1] = 1;
    mat[n/2 - 1][n - 2] = 1;
    mat[n/2 - 1][n - 3] = 1;
    mat[n/2 - 1][n - 4] = 1;
    mat[n/2 - 2][n - 6] = 1;
    mat[n/2 - 3][n - 6] = 1;
    mat[n/2 - 4][n - 6] = 1;
    mat[n/2 - 6][n - 2] = 1;
    mat[n/2 - 6][n - 3] = 1;
    mat[n/2 - 6][n - 4] = 1;


    mat[n/2 - 2][n + 1] = 1;
    mat[n/2 - 3][n + 1] = 1;
    mat[n/2 - 4][n + 1] = 1;
    mat[n/2 - 1][n + 2] = 1;
    mat[n/2 - 1][n + 3] = 1;
    mat[n/2 - 1][n + 4] = 1;
    mat[n/2 - 2][n + 6] = 1;
    mat[n/2 - 3][n + 6] = 1;
    mat[n/2 - 4][n + 6] = 1;
    mat[n/2 - 6][n + 2] = 1;
    mat[n/2 - 6][n + 3] = 1;
    mat[n/2 - 6][n + 4] = 1;


    mat[n/2 + 2][n - 1] = 1;
    mat[n/2 + 3][n - 1] = 1;
    mat[n/2 + 4][n - 1] = 1;
    mat[n/2 + 1][n - 2] = 1;
    mat[n/2 + 1][n - 3] = 1;
    mat[n/2 + 1][n - 4] = 1;
    mat[n/2 + 2][n - 6] = 1;
    mat[n/2 + 3][n - 6] = 1;
    mat[n/2 + 4][n - 6] = 1;
    mat[n/2 + 6][n - 2] = 1;
    mat[n/2 + 6][n - 3] = 1;
    mat[n/2 + 6][n - 4] = 1;



    
    mat[n/2 + 2][n + 1] = 1;
    mat[n/2 + 3][n + 1] = 1;
    mat[n/2 + 4][n + 1] = 1;
    mat[n/2 + 1][n + 2] = 1;
    mat[n/2 + 1][n + 3] = 1;
    mat[n/2 + 1][n + 4] = 1;
    mat[n/2 + 2][n + 6] = 1;
    mat[n/2 + 3][n + 6] = 1;
    mat[n/2 + 4][n + 6] = 1;
    mat[n/2 + 6][n + 2] = 1;
    mat[n/2 + 6][n + 3] = 1;
    mat[n/2 + 6][n + 4] = 1;
    
    

}










