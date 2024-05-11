
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<windows.h>
#include<unistd.h>
#define taille 100
////////////////////////adh�rant 

typedef struct 
{
int j;
int m;
int a;	
}
date;
typedef struct 
{
int nbr_doc;
int duree;
}
cnd_emprn;//le condition d'emprunt


typedef struct 
{
unsigned int  cin ;
char nom[10];
char prenom[10];
int type;
cnd_emprn conditions;
int nbr_max;
int sut;
unsigned int code_dc;
date dl;
}
adh;

typedef struct 
{
int salle;
int rayon;	
}
locale;

typedef struct 
{
char noma[10];
date dt_pb;
}
article;

typedef struct 
{
char Nom[10];
char nomedt[10];
date dt_ed;
}
livre;
typedef struct 
{
unsigned int fre_par;	
}
magazine;


typedef struct 
{
int typ;
char titre[10];
unsigned int code ;
int nbr_exm;

locale loc;	
magazine mag;
livre liv;
article art;

}
doc;

adh t[taille];
doc T[taille];
typedef struct 
{
 int jj;
 int mm;
 int aa;	
}
dd;	

typedef struct
{
unsigned int cn;
unsigned int cde;
dd dt_d ;
dd dt_l;
}
emp;
emp f[taille];
int k;
const char * NomJourSemaine[] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"}; 
  
const char * NomMois[] = {"janvier", "fevrier", "mars"     , "avril"  , "mai"     , "juin"    , 
"juillet", "aout"   , "septembre", "octobre", "novembre", "decembre"}; 


int n,n1,z;
 void Menu_P();
 void Gest_emp();
 void Gest_adh();
 void Gest_doc();
 void Gest_emp();

int verfexcin_adh(unsigned int c)
{
int x,j;
x=0;
for(j=0;j<n;j++)
{
	
if(t[j].cin==c)
  {
			          
	       
			   x=1;
			  break; 
		}
			  
}
return x;
}
void aj_adh()
{
	int rep;
	printf("             ***** Bienvenu vous vennez d'ajouter un adhearnt ***** \n\n");
   printf("Donner le cin de nouveau adherant: ");
   scanf(" %d",&t[n].cin);  
   if(verfexcin_adh(t[n].cin)==1)
            {
			printf ("               !!cin est deja dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un cin valid svp!! \n");
            scanf("%d",&t[n].cin);
			}
            while(verfexcin_adh(t[n].cin==1));
        }

   
   printf("Donner le nom de nouveau adherant: ");
   scanf(" %s",&t[n].nom);
   printf("Donner le prenom de nouveau adherant: ");
   scanf(" %s",&t[n].prenom);
   
   printf("Quelle est le type de cette adh�rant !!\n");
   printf("      <1.  Un etudiant ------------------------------ \n");
   printf("      <2.  Un enseignant----------------------------- \n");
   printf("      <3.  UN Visiteur-------------------------------\n");
       do{
          printf("Donner le  type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;
	t[n].type=rep;
	 printf("          ============================================== \n\n");
  
   if (t[n].type==1){t[n].conditions.duree=14; t[n].nbr_max=4;}//14jours pour etudiant et 4 emprute possible 
	if (t[n].type==2){t[n].conditions.duree=21;t[n].nbr_max=2;}//21jours pour ensiegnant et 6 emprute possible
	if (t[n].type==3){t[n].conditions.duree=7;t[n].nbr_max=6;}//7jours  pour visiteur et 2 emprute possible
	n++;
}
void aj_pluseiurs_adh()
{
	int rep;
	char ch;
		printf("             ***** Bienvenu vous vennez d'ajouter un adhearnt ***** \n\n");
	do
{
	
   printf("donner le cin d'adherant ");
   scanf(" %d",&t[n].cin);
   if(verfexcin_adh(t[n].cin)==1)
            {
			printf ("               !!cin est deja dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un cin valid svp!! \n");
            scanf("%d",&t[n].cin);
			}
            while(verfexcin_adh(t[n].cin==1));
        }

   printf("donner le nom d'adherant ");
   scanf(" %s",&t[n].nom);
   fflush(stdin);
   printf("donner le prenom d'adherant ");
   fflush(stdin);
   scanf(" %s",&t[n].prenom);
   fflush(stdin);   
   printf("quelle est le type de cette adh�rant !!\n");
   printf("      <1.  Un etudiant ------------------------------ \n");
   printf("      <2.  Un enseignant----------------------- \n");
   printf("      <3.  UN Visiteur------------------ \n");
       do{
          printf("Dooner le  type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;
		t[n].type=rep;
    t[n].conditions.nbr_doc=0;
    if (t[n].type==1){t[n].conditions.duree=7;}//jours
	if (t[n].type==2){t[n].conditions.duree=21;}//jours 
	if (t[n].type==3){t[n].conditions.duree=7;}//jours 
	
	printf("======================================================\n\n");
	n++;
	  
	do  
      {
       printf ("Voulez contuniez L'ajout des adh�rant O/N \n");
       scanf("%s",&ch);
       }
    while (ch!='o' && ch!='n');
  }
   while (ch!='n');	
}

void aff()
{
	printf("             ***** L''AFFICHAGE Des Tout les adherants: *****\n\n");
	int j;
	for(j=0;j<n;j++)
	{
	printf("--------->adherant Numuro %d \n",j+1);	
	printf(" Le cin : %d\n",t[j].cin);
	printf("Le nom : %s\n", t[j].nom);
	printf("Le prenom : %s \n",t[j].prenom);
 	if(t[j].type==1){printf(" LE type : Etudiant\n");}
    else if(t[j].type==2){printf("LE type :Ensiengnant\n");}
    else if(t[j].type==3){printf("LE type :Visiteur\n");}
    printf("======================================================\n\n");
}
}

int pos_cinadh(unsigned int c)
{
int x,j;
x=0;
for(j=0;j<n;j++)
{
	
if(t[j].cin==c)
  {
			          
	       
			   x=j;
			  break; 
		}
			  
}

return x;
}

void mdf_adh()
{
unsigned int x;
int pos,rep ;
printf("donner le cin d 'adherant qui voulez vous modifier ses donnees \n "); scanf("%d",&x);
pos=pos_cinadh(x);

if(verfexcin_adh(x)==0)
            {
			printf ("               !!cin introuvable dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un cin valid svp!! \n");
            scanf("%d",&x);
			}
            while(verfexcin_adh(x)==0);
        }

{
   printf("Entrez Le Nom : "); fflush(stdin); gets(t[pos].nom);
   printf("Entrez Le Prenom : "); fflush(stdin); gets(t[pos].prenom);
   printf("quelle est le type de cette adh�rant !!\n");
   printf("      <1.  Un etudiant ------------------------------ \n");
   printf("      <2.  Un enseignant----------------------- \n");
   printf("      <3.  UN Visiteur------------------ \n");
       do{
          printf("Dooner le  type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;

}

}

 void supprimer_adh(){
    unsigned int ci;
     int i,j,k;
     printf("Saisir le cin de l 'adh�rant que vous voulez  supprimier : ");
     scanf("%d",&ci);
     if(verfexcin_adh(ci)==0)
            {
			printf ("               !!cin introuvable dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un cin valid svp!! \n");
            scanf("%d",&ci);
			}
            while(verfexcin_adh(ci)==0);
        }

     for(i=0;i<n;i++){
         if(t[i].cin==ci){
                k=i;
                n=n-1;
                for(j=k;j<n;j++){
                                   t[j]=t[j+1];
                 }
     }}}

 void quitter(){
     system("cls");
 printf("\n\n        \t------------FIN-----------\n\n\n");
 printf("\n\n        \t------------MERCI-----------\n\n\n");
 }
 void rechercher_adh_par_cin(){
      unsigned int ci;
      int i;
      printf(" Saisir un le cin : ");
      scanf("%d",&ci);
      if(verfexcin_adh(ci)==0)
            {
			printf ("               !!cin introuvable dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un cin valid svp!! \n");
            scanf("%d",&ci);
			}
            while(verfexcin_adh(ci)==0);
        }

       for(i=0;i<n;i++){

           if(t[i].cin==ci){
                  printf("\n      ||Rechercher un adh�rant  par son n� cin :  ||\n");
                  printf("Les donnees d 'adherant que vous avez recherche : \n");
                  printf("----------------------------------\n");
                  printf("Numero d'cin : %d\n",ci);
                  printf("Nom : %s\n",t[i].nom);
                  printf("Prenom : %s\n",t[i].prenom);
                 if(t[i].type==1){printf("Etudiant\n");}
                 else if(t[i].type==2){printf("Ensiengnant\n");}
                 else if(t[i].type==3){printf("Visiteur\n");}

             }
         printf("<----------------------------------------------------------------------->\n\n");
		 }
}


void rechercher_adh_par_nom(){
      
      char nom[10];
      int  r, i;
      printf("\nRechercher un adherant par son nom :\n");
      printf("--------------------------\n");   
      printf("Entrer le nom d'adherant  : ");
      scanf("%s",&nom);
      r=0;
       for(i=0;i<n;i++){
          if(strcmp(t[i].nom,nom)==0){
            r++;
             printf("\nAdherant numuro %d  qui avait le nom : %s\n",r,nom);
             printf("                  --------------------\n");
             printf("        ********* Ses donnnes: *********:\n");
             printf("                ----------------------------------\n");
             printf("Numero de cin  : %d\n",t[i].cin);
             printf("Nom : %s\n",t[i].nom);
             printf("Prenom : %s\n",t[i].prenom);
             if(t[i].type==1){printf("Type : Etudiant\n");}
             else if(t[i].type==2){printf("Type : Ensiengnant\n");}
             else if(t[i].type==3){printf("Type : Visiteur\n");}
             
          }
           printf("<----------------------------------------------------------------------->\n\n");
  }
}

void rechercher_adh_par_pn(){
      char prenom[10];
      int i ,r ;
      
     printf("\n          **||**Rechercher un adherant par son prenom :**||**    \n"); 
     printf("---------------------------");
     printf("Saisir un prenom : ");
     scanf("%s",&prenom);
     r=0;
     for(i=1;i<=n;i++){

         if(strcmp(t[i].prenom,prenom)==0){
             r++;
             printf("\nAdherant numuro %d  qui avait le prenom : %s\n",r,prenom);
             printf("                  --------------------\n");
             printf("        ********* Ses donnnes: *********:\n");
             printf("                ----------------------------------\n");
             printf("Numero de cin  : %d\n",t[i].cin);
             printf("Nom : %s\n",t[i].nom);
             printf("Prenom : %s\n",t[i].prenom);
             if(t[i].type==1){printf(" Type : Etudiant\n");}
                 else if(t[i].type==2){printf("Type : Ensiengnant\n");}
                 else if(t[i].type==3){printf("Type : Visiteur\n");}
           }
            printf("<----------------------------------------------------------------------->\n\n");
       }
}

void rechercher_adh_par_typ(){
      
      char typ[10];
      int  r, i,rep;
      printf("\n          **||**Rechercher un adherant par son type **||** :\n");
      printf("--------------------------\n");   
      printf("quelle est le type de cette adh�rant !!\n");
   printf("      <1.  Un etudiant ------------------------------ \n");
   printf("      <2.  Un enseignant----------------------- \n");
   printf("      <3.  UN Visiteur------------------ \n");
       do{
          printf("Dooner le  type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;
      r=0;
       for(i=1;i<=n;i++){
          if(t[i].type==rep){
            r++;
             printf("\nAdherant numuro %d  qui avait le type: ",r);
             if(t[i].type==1){printf(" Type : Etudiant\n");}
             else if(t[i].type==2){printf("Type : Ensiengnant\n");}
             else if(t[i].type==3){printf("Type : Visiteur\n");}
             printf("                  --------------------\n");
             printf("        ********* Ses donnnes: *********:\n");
             printf("                ----------------------------------\n");
             printf("Numero de cin  : %d\n",t[i].cin);
             printf("Nom : %s\n",t[i].nom);
             printf("Prenom : %s\n",t[i].prenom);
             if(t[i].type==1){printf(" Type : Etudiant\n");}
             else if(t[i].type==2){printf("Type : Ensiengnant\n");}
             else if(t[i].type==3){printf("Type : Visiteur\n");}
          }
           printf("<----------------------------------------------------------------------->\n\n");
  }
}

int pos_doc(unsigned int c)
{
int x,j;
x=0;
for(j=0;j<n1;j++)
{
	
if(T[j].code==c)
  {
			          
	       
			   x=j;
			  break; 
		}
			  
}

return x;
}
int verfex_doc(unsigned int c)
{
int x,j;
x=0;
for(j=0;j<n1;j++)
{
	
if(T[j].code==c)
  {
			          
	       
			   x=1;
			  break; 
		}
			  
}

return x;
}

void aj_doc()
{
   int x,rep;
   printf("donner le code  de nouveau document  ");
   scanf(" %d",&T[n1].code);
   
   x=verfex_doc(T[n1].code);
   if(x==1)
   {
	  do{
	    printf("Code de document existe deja !!");
		printf(" SVP,Merci de saisir un autre code ");  
		scanf(" %d",&T[n1].code);
	  
	     }
	  while(verfex_doc(T[n1].code)==1);   
	} 
	printf("Donner le titre de doucument ");
   scanf(" %s",&T[n1].titre); 
   printf("Donner le nombre de la salle ou se trouve le document ");
   scanf(" %d",&T[n1].loc.salle);  
   printf("Donner le nombre de rayon ou se trouve  de doucument ");
   scanf(" %d",&T[n1].loc.rayon); 
   printf("Donner le nomrbre d 'exomplaire existe pour cette document ");
   scanf(" %d",&T[n1].nbr_exm); 
   printf("quelle est le type de votre document!!\n");
   printf("      <1.  Un livre------------------------------ \n");
   printf("      <2.  Une magazine----------------------- \n");
   printf("      <3.  UN article------------------ \n");
       do{
          printf("choisir un type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;
		
		switch(rep)
		          {
				  case 1: T[n1].typ=1;
				          printf("Donner le nom de l'auteur de livre ");
				          scanf("%s",&T[n1].liv.Nom);
				         printf("Donner le nom de l editeur de livre ");
				          scanf("%s",T[n1].liv.nomedt);
				        do{
				          printf("Donner le jour  de la date d'edution de livre ");
				          scanf("%d",&T[n1].liv.dt_ed.j);
				          }
				          while(T[n1].liv.dt_ed.j<0 || T[n1].liv.dt_ed.j>31);
				        do{
						  printf("Donner le mois  de la date d'edution de livre ");
				          scanf("%d",&T[n1].liv.dt_ed.m);
				         // printf("T[n1].liv.dt_ed.m=%d",T[n1].liv.dt_ed.m);
				          }
				          while(T[n1].liv.dt_ed.m<0 || T[n1].liv.dt_ed.m>12);
				        do{
				          printf("Donner l'annee  de la date d'edution de livre ");
				          scanf("%d",&T[n1].liv.dt_ed.a);
				          }
				          while(T[n1].liv.dt_ed.a<0 || T[n1].liv.dt_ed.a>2020);
						  break;
				  case 2:T[n1].typ=2;
				         printf("Donner la frecunce de parution de magazine ");
				         scanf("%d",&T[n1].mag.fre_par);
				         break;
				  case 3:T[n1].typ=3;
				        printf("Donner le nom de l'auteur de l''article ");
				        scanf("%s",&T[n1].art.noma);
					do{  
					   	printf("Donner le jour  de la date de publication d'article ");
			            scanf("%d",&T[n1].art.dt_pb.j);
				      }
				    while(T[n1].art.dt_pb.j<0 || T[n1].art.dt_pb.j>31);
					do{
						printf("Donner le mois  de la date de publication d'article ");
				        scanf("%d",&T[n1].art.dt_pb.m);
				      }
				      while(T[n1].art.dt_pb.m<0 || T[n1].art.dt_pb.m>12);
					do{  
						printf("Donner l'annee  de la date de publication d'article ");
				        scanf("%d",&T[n1].art.dt_pb.a);
				      }
				    while(T[n1].art.dt_pb.a<0 || T[n1].art.dt_pb.a>2020);
					   
					    break;
				  default : printf("document indisponible !!!\n");      	   
			     } 
   n1++;
}
void supprimer_doc(){
    unsigned int cd;
     int i,j,k;
     printf("Saisir le code de document  que vous voulez  supprimier : ");
     scanf("%d",&cd);
     if(verfex_doc(cd)==0)
            {
			printf ("               !!code documment introuvable dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un code  valide svp!! \n");
            scanf("%d",&cd);
			}
            while(verfex_doc(cd)==0);
        }

     for(i=0;i<n1;i++){
         if(T[i].code==cd){
                k=i;
                n1=n1-1;
                for(j=k;j<n1;j++){
                                   T[j]=T[j+1];
                 }
     }
	 }
	 }


void mdf_doc()
{
int rep;
unsigned int x;
int pos ;
printf("donner le code de documment qui voulez vous modifier ses donnees \n "); scanf("%d",&x);
pos=pos_doc(x);

if(verfex_doc(x)==0)
            {
			printf ("               !!code documment  introuvable dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un code valid svp!! \n");
            scanf("%d",&x);
			}
            while(verfex_doc(x)==0);
        }

{
printf("Entrez Le Titre : "); fflush(stdin); gets(T[pos].titre);
printf("Entrez Le Num de salle : ");  scanf(" %d",&T[pos].loc.salle);  
printf("Entrez Le Num de rayon: ");  scanf(" %d",&T[pos].loc.rayon);
printf("Entrez Le Nombre de exemplaire: ");  scanf(" %d",&T[pos].nbr_exm); 
printf("quelle est le nouveau type de votre document!!\n");
   printf("      <1.  Un livre------------------------------ \n");
   printf("      <2.  Une magazine----------------------- \n");
   printf("      <3.  UN article------------------ \n");
       do{
          printf("choisir un type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;
		
		switch(rep)
		          {
				  case 1: T[pos].typ=1;
				          printf("Donner le nom de l'auteur de livre ");
				          scanf("%s",&T[pos].liv.Nom);
				         printf("Donner le nom de l editeur de livre ");
				          scanf("%s",T[pos].liv.nomedt);
				        do{
				          printf("Donner le jour  de la date d'edution de livre ");
				          scanf("%d",&T[pos].liv.dt_ed.j);
				          }
				          while(T[pos].liv.dt_ed.j<0 || T[pos].liv.dt_ed.j>31);
				        do{
						  printf("Donner le mois  de la date d'edution de livre ");
				          scanf("%d",&T[pos].liv.dt_ed.m);
				          printf("T[n1].liv.dt_ed.m=%d",T[pos].liv.dt_ed.m);
				          }
				          while(T[pos].liv.dt_ed.m<0 || T[pos].liv.dt_ed.m>12);
				        do{
				          printf("Donner l'annee  de la date d'edution de livre ");
				          scanf("%d",&T[pos].liv.dt_ed.a);
				          }
				          while(T[pos].liv.dt_ed.a<0 || T[pos].liv.dt_ed.a>2020);
						  break;
				  case 2:T[pos].typ=2;
				         printf("Donner la frecunce de parution de magazine ");
				         scanf("%d",&T[pos].mag.fre_par);
				         break;
				  case 3:T[pos].typ=3;
				        printf("Donner le nom de l'auteur de l''article ");
				        scanf("%s",&T[pos].art.noma);
					do{  
					   	printf("Donner le jour  de la date de publication d'article ");
			            scanf("%d",&T[pos].art.dt_pb.j);
				      }
				    while(T[pos].art.dt_pb.j<0 || T[pos].art.dt_pb.j>31);
					do{
						printf("Donner le mois  de la date de publication d'article ");
				        scanf("%d",&T[pos].art.dt_pb.m);
				      }
				      while(T[pos].art.dt_pb.m<0 || T[pos].art.dt_pb.m>12);
					do{  
						printf("Donner l'annee  de la date de publication d'article ");
				        scanf("%d",&T[pos].art.dt_pb.a);
				      }
				    while(T[pos].art.dt_pb.a<0 || T[pos].art.dt_pb.a>2020);
					   
					    break;
				  default : printf("document indisponible !!!\n");      	   
			     }

}

}

void rechercher_doc_par_cd(){
      unsigned int cd;
      int i;
      printf(" Saisir un le code de documment: ");
      scanf("%d",&cd);
      if(verfex_doc(cd)==0)
            {
			printf ("               !!code documment  introuvable dans notre biblioth�que verfier les donn�s!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 donner un code valid svp!! \n");
            scanf("%d",&cd);
			}
            while(verfex_doc(cd)==0);
        }

       for(i=0;i<n1;i++){

           if(T[i].code==cd){
                  printf("\nRechercher un adh�rant  par son code  : \n");
                  printf("Les inforamations de documment que vous avez recherche : \n");
                  printf("----------------------------------\n");
                  printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				        				         
				  
				  
				  
				  
				  
				  
				 
 
             }
         }
}

void rechercher_doc_par_Nsal(){
      
      int sl;
      int  r, i;
      printf("\nRechercher un documment  par le Numero de salle :\n");
      printf("--------------------------\n");   
      printf("Entrer le numero de la salle de document  : ");
      scanf("%d",&sl);
      r=0;
         for(i=0;i<n1;i++){
          if(T[i].loc.salle==sl){
            r++;
             printf("\nDocumment  numuro %d  qui se trouve dans la salle Num : %d\n",r,sl);
             printf("                  --------------------\n");
             printf("        ********* Ses Informations: *********:\n");
                               printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				        				                  
          }
  }
}

void rechercher_doc_par_titre(){
      
      char tit[10];
      int  r, i;
      printf("\nRechercher un documment  par son titre :\n");
      printf("--------------------------\n");   
      printf("Entrer le titre de document  : ");
      scanf("%s",&tit);
      r=0;
       for(i=0;i<n1;i++){
          if(strcmp(T[i].titre,tit)==0){
            r++;
             printf("\nDocumment  numuro %d  qui avait le titre : %s\n",r,tit);
             printf("                  --------------------\n");
             printf("        ********* Ses Informations: *********:\n");
                               printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				        				         
				  
             
          }
  }
}

void rechercher_doc_par_Nray(){
      
      int sl;
      int  r, i;
      printf("\nRechercher un documment  par le Numero de rayon :\n");
      printf("--------------------------\n");   
      printf("Entrer le numero du rayon de document  : ");
      scanf("%d",&sl);
      r=0;
       for(i=0;i<n1;i++){
          if(T[i].loc.rayon==sl){
            r++;
             printf("\nDocumment  numuro %d  qui se trouve dans le rayon Num : %d\n",r,sl);
             printf("                  --------------------\n");
             printf("        ********* Ses Informations: *********:\n");
                               printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				        				                  
          }
  }
}

void rechercher_doc_par_NBexm(){
      
      int sl;
      int  r, i;
      printf("\nRechercher un documment  par le nombre des exemlaires :\n");
      printf("--------------------------\n");   
      printf("Entrer le nombre des exemplaires  de document  : ");
      scanf("%d",&sl);
      r=0;
       for(i=0;i<n1;i++){
          if(T[i].nbr_exm==sl){
            r++;
             printf("\nDocumment  numuro %d  qui disponible avec %d  exemplaire:\n",r,sl);
             printf("                  --------------------\n");
             printf("        ********* Ses Informations: *********:\n");
                               printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				        				                  
          }
  }
}

void rechercher_doc_par_typ(){
      
      int sl;
      int  r, i;
   printf("\nRechercher un documment  par son type :\n");
   printf("--------------------------\n");  
   printf("Entrez le type de votre document!!\n");
   printf("      <1.  Un livre------------------------------ \n");
   printf("      <2.  Une magazine----------------------- \n");
   printf("      <3.  UN article------------------ \n");
       do{
         printf("Entrez le type de votre document!!\n");	;
		  scanf("%d",&sl)  ;
		 }
		while(sl!=1 && sl!=2 &sl!=3) ;
      r=0;
       for(i=0;i<n1;i++){
          if(T[i].typ==sl){
            r++;
             switch(sl){
             	       case 1:printf("\n Le livre  num %d dans notre biblioth�que sont :\n",r);break;
             	       case 2:printf("\n Le magazine num %d dans notre biblioth�que sont :\n",r);break;
             	       case 3: printf("\n L'article num %d dans notre biblioth�que sont :\n",r);break;
			           }
             printf("                  --------------------\n");
             printf("        ********* Ses Informations: *********:\n");
                               printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				        				                  
          }
  }
}
void aff1()
{
int i	;

        
 printf("les documment exsites  dans notre biblioth�que sont \n: ");
 for (i=0;i<n1;i++)
 {
  printf("                     Le code: %d \n",T[i].code);
  printf("Le titre: %s \n",T[i].titre);
  printf("Le Num de salle est %d \n",T[i].loc.salle);
  printf("Le Num de rayon est %d \n",T[i].loc.rayon);
  printf("le nomrbre d 'exomplaire existe pour cette document %d \n",T[i].nbr_exm); 
     if (T[i].typ==1){          printf("LE type de de document est :Livre \n");
                                printf("Le nom de l auteur de livre %s \n",T[i].liv.Nom);
                                printf("Le nom de l auteur de livre %s\n",T[i].liv.nomedt);
								printf("Le date d'edution de cette livre: %d/%d/%d\n",T[i].liv.dt_ed.j,T[i].liv.dt_ed.m,T[i].liv.dt_ed.a);
                           }    
                                
     else if(T[i].typ==2) 
	                       {
	                            printf("LE type de de document est :Magazine \n"); 
					            printf("la frucence de parution de magazine: %d\n",T[i].mag.fre_par);
							} 
					
	else                    {
		                        printf("LE type de de document est :Article \n"); 
	                            printf("le nom de l'auteur de l''article : %s \n",T[i].art.noma);
					            printf("Le date de publication de cette article: %d/%d/%d\n",T[i].art.dt_pb.j,T[i].art.dt_pb.m,T[i].art.dt_pb.a);
					        }
				 
 printf("=====================================================================================\n\n");
 
 }
}
void aj_pluseiurs_doc()
{
	int x,rep;
	char ch;
do
{
	
   printf("Donner le  code de doucument ");
   scanf(" %d",&T[n1].code);
   x=verfex_doc(T[n1].code);
   if(x==1)
   {
	  do{
	    printf("               Code de document existe deja !!\n");
		printf("               SVP,Merci de saisir un autre code\n ");  
		scanf(" %d",&T[n1].code);
	  
	     }
	  while(verfex_doc(T[n1].code)==1);   
}
   printf("Donner le titre de doucument ");
   scanf(" %s",&T[n1].titre); 
   printf("Donner le nombre de la salle ou se trouve le document ");
   scanf(" %d",&T[n1].loc.salle);  
   printf("Donner le nombre de rayon ou se trouve  de doucument ");
   scanf(" %d",&T[n1].loc.rayon); 
   printf("Donner le nomrbre d 'exomplaire existe pour cette document ");
   scanf(" %d",&T[n1].nbr_exm); 
   printf("quelle est le type de votre document!!\n");
   printf("      <1.  Un livre------------------------------ \n");
   printf("      <2.  Une magazine----------------------- \n");
   printf("      <3.  UN article------------------ \n");
       do{
          printf("choisir un type !")	;
		  scanf("%d",&rep)  ;
		 }
		while(rep!=1 && rep!=2 &rep!=3) ;
		
		switch(rep)
		          {
				  case 1: T[n1].typ=1;
				          printf("Donner le nom de l'auteur de livre ");
				          scanf("%s",&T[n1].liv.Nom);
				         printf("Donner le nom de l editeur de livre ");
				          scanf("%s",T[n1].liv.nomedt);
				        do{
				          printf("Donner le jour  de la date d'edution de livre ");
				          scanf("%d",&T[n1].liv.dt_ed.j);
				          }
				          while(T[n1].liv.dt_ed.j<0 || T[n1].liv.dt_ed.j>31);
				        do{
						  printf("Donner le mois  de la date d'edution de livre ");
				          scanf("%d",&T[n1].liv.dt_ed.m);
				        //  printf("T[n1].liv.dt_ed.m=%d",T[n1].liv.dt_ed.m);
				          }
				          while(T[n1].liv.dt_ed.m<0 || T[n1].liv.dt_ed.m>12);
				        do{
				          printf("Donner l'annee  de la date d'edution de livre ");
				          scanf("%d",&T[n1].liv.dt_ed.a);
				          }
				          while(T[n1].liv.dt_ed.a<0 || T[n1].liv.dt_ed.a>2020);
						  break;
				  case 2:T[n1].typ=2;
				         printf("Donner la frecunce de parution de magazine ");
				         scanf("%d",&T[n1].mag.fre_par);
				         break;
				  case 3:T[n1].typ=3;
				        printf("Donner le nom de l'auteur de l''article ");
				        scanf("%s",&T[n1].art.noma);
					do{  
					   	printf("Donner le jour  de la date de publication d'article ");
			            scanf("%d",&T[n1].art.dt_pb.j);
				      }
				    while(T[n1].art.dt_pb.j<0 || T[n1].art.dt_pb.j>31);
					do{
						printf("Donner le mois  de la date de publication d'article ");
				        scanf("%d",&T[n1].art.dt_pb.m);
				      }
				      while(T[n1].art.dt_pb.m<0 || T[n1].art.dt_pb.m>12);
					do{  
						printf("Donner l'annee  de la date de publication d'article ");
				        scanf("%d",&T[n1].art.dt_pb.a);
				      }
				    while(T[n1].art.dt_pb.a<0 || T[n1].art.dt_pb.a>2020);
					   
					    break;
				  default : printf("document indisponible !!!\n");      	   
			     }
			     
				 n1++;
do  
 {
  printf ("Voulez contuniez d'entrir des adh�rant O/N ");
  scanf("%s",&ch);
 }
 while (ch!='o' && ch!='n');
}
while (ch!='n');			
}

int verfex_emp(unsigned int c, unsigned int b)
{
int x,j;
x=0;
for(j=0;j<z;j++)
{
	
if(f[j].cn==c && f[j].cde==b)
  {   
			   x=1;
			  break; 
		}
			  
}
return x;
}

		
void aj_emprunt()
{
	int  p1,d,p;
	time_t Temps;
    struct tm *Date;
	time(&Temps); 
    Date = localtime(&Temps);
   
   printf(" Donner L'identifiant de l'adherant(cin) que va effecteuer cette emprunte Num %d\n:",k+1);
   scanf("%d",&f[z].cn);
   if(verfexcin_adh(f[z].cn)==0)
   {
   printf("!!! CIN INVALIDE !!! (n'existe pas dans la base)\n");
   do
   {
   printf("           ----SVP SAISIER UN CIN VALIDE----\n");
   scanf("%d",&f[z].cn);
   }
   while(verfexcin_adh(f[z].cn)==0);
   }
   printf(" Donner Le code de documment a emprunter par cette adhearnt :  \n");
   scanf("%d",&f[z].cde);
   if(verfex_doc(f[z].cde)==0)
   {
   printf("!!! CODE INVALIDE !!! (n'existe pas dans la base)\n");
   do
   {
   printf("           ----SVP SAISIER UN CODE VALIDE----\n");
   scanf("%d",&f[z].cde);
   }
   while(verfex_doc(f[z].cde)==0);
   }
   
   
     if (verfex_emp(f[z].cn,f[z].cde)==1)
    {
   
           do{
	           printf("     Emprunte   existe deja !! \n");
		       printf("     SVP,Merci d une autre emprunte\n\n ");  
	           printf("Le nouveau Num de cin  \n:");
               scanf("%d",&f[z].cn);
               if(verfexcin_adh(f[z].cn)==0)
               {
                 printf("!!! CIN INVALIDE !!! (n'existe pas dans la base)\n");
                 do
                 {
                    printf("           ----SVP SAISIER UN CIN VALIDE----\n");
                    scanf("%d",&f[z].cn);
                  }
                 while(verfexcin_adh(f[z].cn)==0);
                }
                  printf("Le nouveau code de documment :  \n");
                  scanf("%d",&f[z].cde);
                   if(verfex_doc(f[z].cde)==0)
                    {
                      printf("!!! CODE INVALIDE !!! (n'existe pas dans la base)\n");
                      do
                       {
                        printf("           ----SVP SAISIER UN CODE VALIDE----\n");
                        scanf("%d",&f[z].cde);
                        }
                      while(verfex_doc(f[z].cde)==0);
                    }
   
	        }
	         while(verfex_emp(f[z].cn,f[z].cde)==1); 
   
   }
p=pos_cinadh(f[z].cn);
d=t[p].conditions.duree;
t[p].conditions.nbr_doc++;
p1=pos_doc(f[z].cde);
T[p1].nbr_exm--;
if(t[p].conditions.nbr_doc>t[p].nbr_max)
   {
   printf("     ////\\\\   Nombre maximale des empruntes pour cette adherant   ////\\\\  \n\n ");
     Gest_emp();
   }

if(T[p1].nbr_exm<0)
 {
     printf("    ////\\\\  OPS! Le nombre des exemplaires pour cette est finit !!  ////\\\\  \n\n ");
     Gest_emp(); 
 }
   
   
  f[z].dt_d.jj=Date->tm_mday;
  f[z].dt_d.mm=Date->tm_mon + 1;
  f[z].dt_d.aa=1900 + Date->tm_year;
      printf("###############################################################################\n\n");

    printf("              ******* FICHE DES EMPRUNTES ******* \n\n");
    printf("          CIN ADHERANT : %d                CODE DOCUMMENT: %d \n\n",f[z].cn,f[z].cde);
    printf("La Date d'affection de cette emprunte est:\n");
    printf("================================================================================");
    printf("         Le %s, ", NomJourSemaine[Date->tm_wday]); 
    printf("le %02u %s %04u, ", f[z].dt_d.jj, NomMois[f[z].dt_d.mm-1], f[z].dt_d.aa); 
    printf("et il est %02uh %02umin %02usec.\n", Date->tm_hour, Date->tm_min, Date->tm_sec); 
    printf("================================================================================\n");
    printf("La Date de retour de cette emprunte est:\n");   

Temps += (time_t)(d* 86400);
Date = localtime(&Temps);

f[z].dt_l.jj=Date->tm_mday;
f[z].dt_l.mm=   Date->tm_mon + 1;
f[z].dt_l.aa=Date->tm_year + 1900;
    printf("================================================================================\n");

	printf("         Le %s, ", NomJourSemaine[Date->tm_wday]); 
    printf("le %02u %s %04u, ", f[z].dt_l.jj, NomMois[f[z].dt_l.mm-1], f[z].dt_l.aa); 
    printf("et il est %02uh %02umin %02usec.\n", Date->tm_hour, Date->tm_min, Date->tm_sec); 
    printf("================================================================================\n");

    printf("###############################################################################\n\n");

z++;
}

void Supp_emp()
{
unsigned int c,s;
int p,i,b,j;	
printf("                ********* VOUS VENNZER DE SUPPRIMER UNE EMPRUNTE*********\n\n");

printf(" Donner Le cin adherant qui effecteur cette emprunte : ");
scanf("%d",&c);
printf(" Donner Le code de documment  empruntee:  ");
scanf("%d",&s);
if(verfex_emp(c,s)==0)
{
			printf ("                !! Donnee introuvable dans notre biblioth�que verfier!! \n");	
	        printf("---------------------------------------------------------------------------------\n");
            do
            {
			printf("                 Entrer des codes valide svp!! \n");
			printf("LE CIN :  ");
            
			scanf("%d",&c);
            printf("LE CODE :  ");
            scanf("%d",&s);
            printf("---------------------------------------------------\n");
			}
            while(verfex_emp(c,s)==0);
}


for(i=0;i<z;i++)
   {
         if(f[i].cn==c && f[i].cde==s)
		 {
			    b=i;
                z=z-1;
                for(j=b;j<z;j++)
				{
                                   f[j]=f[j+1];
                }
          }
	 

}
}



void rech_retardaire()
{
int i ,j,m,d,a,p,w;
time_t Temps;
    struct tm *Date;
	time(&Temps); 
    Date = localtime(&Temps);
   j=Date->tm_mday;
   m=Date->tm_mon + 1;
   a=1900 + Date->tm_year;
      printf("         ////\\\\   RECHERCHE DES RETARDIRES   ////\\\\    \n\n ") ;

   a=0;
for (i=0;i<z;i++)
 {
     if( f[i].dt_l.aa==a && f[i].dt_l.mm==m && f[i].dt_l.jj<j)
  	{
	printf("<====><======================><=======================><===>\n\n");
	a++;
	printf("              RETARDAIRE NUM : %d\n",a);
	p=pos_cinadh(f[i].cn);
	printf("   Le retardaire :: %s  %s\n",t[p].prenom,t[p].nom);
	printf("   Le cin de retardaire : %d  \n",f[i].cn);
	printf("   Le code de documment emprunt� : %d\n",f[i].cde);
	printf("   Duree de retard :  %d  jours \n",j-f[i].dt_l.jj);
	printf("<====><======================><=======================><===>\n\n");
     
	}
   if( f[i].dt_l.aa==a && f[i].dt_l.mm<m)
  	{
	printf("<====><======================><=======================><===>\n\n");
	a++;
	printf("              RETARDAIRE NUM : %d \n",a);
	p=pos_cinadh(f[i].cn);
	printf("   Le retardaire :: %s  %s \n",t[p].prenom,t[p].nom);
	printf("   Le cin de retardaire : %d  \n",f[i].cn);
	printf("   Le code de documment emprunt� : \n%d",f[i].cde);
	w=((30*m)+j)-f[i].dt_l.jj;
	printf("   Duree de retard :  %d  jours \n",w);
	printf("<====><======================><=======================><===>\n\n");

	}
	if( f[i].dt_l.aa<a)
  	{
	printf("<====><======================><=======================><===>\n\n");
	a++;
	printf("              RETARDAIRE NUM : %d \n",a);
	p=pos_cinadh(f[i].cn);
	printf("   Le retardaire :: %s  %s \n",t[p].prenom,t[p].nom);
	printf("   Le cin de retardaire : %d  \n",f[i].cn);
	printf("   Le code de documment emprunt� : \n%d",f[i].cde);
	printf("   Duree de retard :  %d  jours \n",((12*(a-f[i].dt_l.aa))+(30*(m-f[i].dt_l.mm))-f[i].dt_l.jj));
	printf("<====><======================><=======================><===>\n\n");

	}
 
 }
if (a==0)
{
printf("     ****** <======>  N'EXISTE PAS DES RETARDIRES  <======> ****** ");
}
}








void affe()
{
int  i ;
    printf("                 ########**LES LISTES DEMPRUNTE**########\n\n");
   for (i=0;i<z;i++)
   {
           	
        printf("                  ***|| EMPRUNT NUM %d  ||***\n\n",i+1);
        printf("-----------------------------------------------------------------------\n");
        printf("--->Le  cin de l'adherant : %d \n",f[i].cn);
       	printf("--->LE code de documment  :  %d \n",f[i].cde);
       	printf("----->LE date de debut de cette emprunte est :  %d/%d/%d \n",f[i].dt_d.jj,f[i].dt_d.mm,f[i].dt_d.aa);
       	printf("--------------->Le date de retour de cette emprunt est :  %d/%d/%d \n",f[i].dt_l.jj,f[i].dt_l.mm,f[i].dt_l.aa);
	    printf("-----------------------------------------------------------------------\n\n");

	}
}			  
	

void Menu_P()
{
int  choix;
system("color 1A");
do{
           printf("\n        *******      GESTION DES BIBLIOTHEQUE    ****** \n\n");///sleep(1);
           printf("          ============================================= \n\n");//sleep(1);
           printf("  TOTALE DES ADHERANTSt : %d\n",n);//sleep(1);
           printf("  TOTALE DES DOUCUMRNTS : %d\n",n1);//sleep(1);
           printf("  TOTALE DES EMPRUNTS   : %d\n\n",z);//sleep(1);
           printf("      <1. GESTIONS DES ADHERANTS------------------------------ \n\n");//sleep(1);
           printf("      <2. GESTIONS DES DOUCUMMENTS---------------------------- \n\n");//sleep(1);
           printf("      <3. GESTION DES EMPRUNTS-------------------------------- \n\n");//sleep(1);
           printf("      <4. QUITTER---------------------------------------------\n\n");//sleep(1);
           printf("          ============================================== \n\n");//sleep(1);
           printf("Entre votre choix : ");   
		   scanf("%d",&choix);
           printf("\n\n");
            switch(choix)
			{
            case 1: system("cls");Gest_adh();break;
           case 2: system("cls");Gest_doc();break;
           case 3: system("cls");Gest_emp();break;
           case 4: system("cls");quitter();break;
      default: system("cls");printf("############### votre choix n'est pas valide !!! ###############\n\n");
           }
}
        while((choix)!=3 && (choix)!=1 && (choix)!=2&& (choix)!=4);
     

}


 void Gest_adh()
   {
   int choix;
	system("color 1A");
do{
           printf("\n        *******      Gestion des Adherants    ****** \n\n");
           printf("          ============================================= \n\n");
                     printf("  Totale des eleves : %d\n\n",n);
           printf("      <1.  Ajouter un Adh�rant------------------------------ \n");
           printf("      <2.  Ajouter plusieurs Adh�rants----------------------\n");
           printf("      <3.  Afficher la list des Adherants------------------- \n");
           printf("      <4.  Rechercher un Adhearnt par numero de cin--------- \n");
           printf("      <5.  Rechercher un Adhearnt par nom------------------- \n");
           printf("      <6.  Rechercher un Adhearnt par prenom---------------- \n");
           printf("      <7.  Rechercher un Adhearnt par type------------------ \n");
		   printf("      <8.  Modifier un Adhearnt----------------------------- \n");
           printf("      <9. Supprimier un Adhearnt---------------------------- \n");
           printf("      <10.  Retour au Menu Principale------------------------ \n");
           printf("      <11.  Quitter----------------------------------------- \n");
           printf("          ============================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&choix);
           printf("\n\n");
           switch(choix){
	  case 1: system("cls");aj_adh();break;
	  case 2: system("cls");aj_pluseiurs_adh();break;
      case 3: system("cls");aff();break;
      case 4: system("cls");rechercher_adh_par_cin();break;
      case 5: system("cls");rechercher_adh_par_nom();break;
      case 6: system("cls");rechercher_adh_par_pn();break;
      case 7: system("cls");rechercher_adh_par_typ();break;
      case 8: system("cls");mdf_adh();break;
      case 9: system("cls");supprimer_adh();break;
      case 10:system("cls"); Menu_P();break;
      case 11:system("cls");quitter();break;
      default: system("cls");printf("############### votre choix n'est pas valide !!! ###############\n\n");
               
        }
        }while(choix!=11 && choix!=10);	  
	}  
void Gest_doc()
{
	int choix;
	do{
           printf("\n        *******      GESTION DES DOUCUMMENTS   ****** \n\n");
           printf("       ====================================================== \n\n");
                     printf("  Totale Des Doucumments : %d\n\n",n1);
           printf("      <1.  Ajouter un Documment-----------------------------------------\n");
           printf("      <2.  Ajouter plusieurs Doucumments--------------------------------\n");
           printf("      <3.  Afficher la list des Documments------------------------------\n");
           printf("      <4.  Rechercher de Documment par son  code------------------------ \n");
           printf("      <5.  Rechercher des Documments par leur Numero du salle----------- \n");
           printf("      <6.  Rechercher des Documments par leur Numero du rayon-----------\n");
           printf("      <7.  Rechercher des Documments par leur Titre--------------------- \n");
           printf("      <8.  Rechercher des Documments par leur nombres des exemplaires---\n");
           printf("      <9.  Rechercher des Documments par leur Type---------------------- \n");
		   printf("      <10.  Modifier un Documment--------------------------------------- \n");
           printf("      <11. Supprimier un Documment-------------------------------------- \n");
           printf("      <12. Retour au Menu Principale------------------------------------ \n");
           printf("      <13. Quitter------------------------------------------------------ \n");
           printf("       ====================================================== \n\n");
           printf("Entre votre choix : ");
           scanf("%d",&choix);
           printf("\n\n");
           switch(choix){
	  case 1: system("cls");aj_doc();break;
	  case 2: system("cls");aj_pluseiurs_doc();break;
      case 3: system("cls");aff1();break;
      case 4: system("cls");rechercher_doc_par_cd();break;
      case 5: system("cls");rechercher_doc_par_Nsal();break;
      case 6: system("cls");rechercher_doc_par_Nray();break;
      case 7: system("cls");rechercher_doc_par_titre();break;
      case 8: system("cls");rechercher_doc_par_NBexm();break;
	  case 9: system("cls");rechercher_doc_par_typ();break;
      case 10: system("cls");mdf_doc();break;
      case 11: system("cls");supprimer_doc();break;
     case 12:system("cls"); Menu_P();break;
      case 13:system("cls");quitter();break;
      default: system("cls");printf("############### votre choix n'est pas valide !!! ###############\n\n");  
        }
        }while(choix!=12 && choix!=13);

}
void Gest_emp()
{
int  choix;
system("color 1A");
do{
           printf("\n        *******      GESTION DES EMPRUNTS    ****** \n\n");///sleep(1);
           printf("          ============================================= \n\n");//sleep(1);
           printf("  Totale des empruntes : %d\n\n",z);//sleep(1);
           printf("      <1. Ajouter une emprunte------------------------------\n\n");//sleep(1);
           printf("      <2. Afficher La liste Des empruntes  ----------------- \n\n");//sleep(1);
           printf("      <3. Supprimer une emprunte --------------------------- \n\n");//sleep(1);
           printf("      <4. Recherche Des Retardaires-------------------------\n\n");//sleep(1);
           printf("      <5. Retour au Menu principale ------------------------ \n\n");//sleep(1);
           printf("      <6. Quitter-------------------------------------------\n\n");//sleep(1);
           printf("          ============================================== \n\n");//sleep(1);
           printf("Entre votre choix : ");   
		   scanf("%d",&choix);
           printf("\n\n");
            switch(choix)
			{
           case 1: system("cls");aj_emprunt();break;
           case 2: system("cls");affe();break;
           case 3: system("cls");Supp_emp();break;
		   case 4: system("cls");rech_retardaire();break;            
		   case 5: system("cls");Menu_P();break;   
           case 6:system("cls");quitter();break;
      default: system("cls");printf("############### votre choix n'est pas valide !!! ###############\n\n");
           }
}
while((choix)!=5 && (choix)!=6);
     	
}

int main()
    {
    n=0;
	z=0;	
Menu_P();	

	
 
           	


getch();

	}	
