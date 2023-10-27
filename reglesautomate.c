#include <stdio.h>
#include <stdlib.h>
 
 
int compteVoisin(int ** tab, int n, int i, int j)
{
  int compte = 0;
  int borneL, borneC;
  for (borneL = i - 1; borneL <= i + 1; borneL++)
  {
      for (borneC = j - 1; borneC <= j + 1; borneC++)
      {
          if (borneC >= 0 && borneL >= 0 && borneC < 2 * n && borneL < n && (borneC != j || borneL != i))
          {
              if (tab[borneL][borneC] == 1)
               {
                   compte++;
               }
          }
      }
  }
  return compte;
}




int compteVoisinDirect(int ** tab, int n, int i, int j)
{
   int compte = 0;
   
   if(i < n && j < 2 * n && i > 0 && j > 0)
     {
     
     if(tab[i-1][j]==1)
       {
	 compte ++;
       }
   
   
     if(tab[i+1][j]==1)
       {
	 compte ++;
       }
   
  
     if(tab[i][j-1]==1)
       {
	 compte ++;
       }
 
     if (tab[i][j+1]==1)
       {
	 compte ++;
       }
     
     }
   return compte;
}






//Prend en entrée la matrice et sa hauteur
void jeudelavie(int ** tab,int n)
{
   int i ,j;

   //création d'une matrice bis de même taille
   int ** tmp = malloc(2 * n * sizeof(int*));
   for (i = 0; i < n ; i++)
   {
       tmp[i] = malloc( 2 * n * sizeof(int));
   }


   //Copie de la matrice de base dans la matrice bis
   for( i = 0; i < n; i ++)
  {
      for( j = 0 ; j < 2 * n ; j++)
      {
          tmp[i][j] = tab[i][j];
      }
  }

   //Parcourt de toute la matrice
   for( i = 0; i < n; i ++)
     {
       for( j = 0 ; j < 2 * n ; j++)
	 {

	   //On ne traite que les cas ou la valeur d'une case de la matrice de base doit changer car on travaille avec des effets de bords

	   if (tmp[i][j]==1)//Si la cellule de l'état -1 est vivante
	    {
              if (compteVoisin(tmp,n,i,j) > 3 || compteVoisin(tmp,n,i,j)< 2)
		{
                  tab[i][j]=0;
		}
	    }
	   else//Si la cellule de l'état -1 est morte
	     {
	       if (compteVoisin(tmp,n,i,j)==3)
		{
		  tab[i][j] = 1;
		}
	     }
	 }
     }


   //Libération de la matrice bis
   for (i = 0; i < n; i++)
     {
       free(tmp[i]);
      
     }
   free(tmp);
 
}





void ulman(int ** tab,int n)
{
   int i ,j;

   //Initialisation
   int ** tmp = malloc( n * sizeof(int*));
   for (i = 0; i < n ; i++)
     {
       tmp[i] = malloc(2 *  n * sizeof(int));
     }

   //Copie
   for( i = 0; i < n; i ++)
     {
       for( j = 0 ; j < 2 * n ; j++)
	 {
	   tmp[i][j] = tab[i][j];
	 }
     }


   //Règles
   for( i = 1; i < n - 1; i ++)
     {
       for( j = 1 ; j < 2 * n - 1; j++)
	{
          if (tmp[i][j]==0)
	    {
	      if (compteVoisinDirect(tmp,n,i,j)==1)
		{
		  tab[i][j] = 1;
		}
	    }
	}
     }

   //Libération matrice bis
   for (i = 0; i < n; i++)
     {
       free(tmp[i]);
     }
   free(tmp);
}



void parite(int ** tab,int n, int nbIte)
{
  
   int i ,j;

   //Initialisation
   int ** tmp = malloc( n * sizeof(int*));
   for (i = 0; i <  n ; i++)
     {
       tmp[i] = malloc( 2 * n * sizeof(int));
     }


   //Copie
   for( i = 0; i < n; i ++)
     {
       for( j = 0 ; j < 2 * n ; j++)
	 {
	   tmp[i][j] = tab[i][j];
	 }
     }

   //Règles
   if (nbIte % 2 == 0)//Itération Paire
     {
       for (i = 1; i < n - 1;i++)
	 {
           for (j = 1; j < 2 * n - 1; j++)
	     {
	       if (compteVoisinDirect(tmp,n,i,j) == 1)
		 {
                   tab[i][j] = 1;
		 }
	     }
	 }
     }
   else//Itération impaire
     {
       for (i=0; i<n;i++)
	 {
           for (j=0; j < 2 * n; j++)
	     {
               if (compteVoisin(tmp,n,i,j) == 1)
		 {
                   tab[i][j] = 1;
		 }
	     }
	 }
     }

   //Libération
   for (i = 0; i < n; i++)
     {
       free(tmp[i]);
     }
   free(tmp);
}
