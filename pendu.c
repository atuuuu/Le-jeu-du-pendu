#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "pendu.h"
#include "chaine.h"


int demandeRejouer()
{
	int rejouer=0;
	printf("Voulez vous rejouez ?(0=non/1=oui)\n");							//On propose de rejouer
	scanf("%d",&rejouer);
	return rejouer;
}


int verifVictoire(int* caracTrouve,int longueur)
{
	int victoire=1;															//On considère que le joueur a gagné
			
	for(int i=0;i<longueur-1;i++)
	{
		if(caracTrouve[i]==1 && victoire!=0);							//Si les lettres correspondent, on ne change rien
		else															//Si une lettre minimum ne correspond pas, alors on considère qu'il n'a pas gagné
		{
			victoire=0;
		}
	}
	return victoire;
}

int verifLettre(char lettre,int* caracTrouve,int longueur,char* mot,int* compteurEssais)
{
	int trouve=0;
			
	for(int i=0;i<longueur-1;i++)											//On teste si la lettre est dans le mot recherché
	{
		if(lettre==mot[i])												//si la lettre correspond à au moins une lettre du mot : trouve passe à vrai
		{
			caracTrouve[i]=1;
			trouve=1;
		}
	}
	clear();
	
	if(trouve==0)														//si la lettre n'est pas dans le mot on enlève une vie
	{
		printf("dommage, essayez encore !\n");
		(*compteurEssais)++;
		printf("Il vous reste %d essais\n",vie-*compteurEssais);
	}
	
	else
	{
		printf("vous avez trouvé une lettre !\n");
		printf("Il vous reste %d essais\n",vie-*compteurEssais);
	}
	
	return trouve;
}


char lireLettre()
{
	printf("\nentrez une lettre !\n");									//Demande d'une lettre
	return lire();
}


void affichageMot(char* mot,int* caracTrouve,int longueur)
{
	printf("le mot cherche est : ");
	for(int i=0;i<longueur-1;i++)										//Affichage des lettres trouvées et non trouvées
	{
		if(caracTrouve[i])												//Lettres trouvées
		{
			printf("%c",mot[i]);
		}
		else															//Lettres non trouvées
		{
			printf("*");
		}
	}
}

SDL_Window* testVictoire(int victoire, char* mot)
{
	SDL_Window* fenetre = NULL;
	if(victoire==0)															//Si on sort de la boucle :
	{
		printf("\nperdu !\n");												//Soit le joueur n'a plus de vie
		printf("Le mot était : %s",mot);
		
		fenetre = afficherFenetre(0);
	}
	
	else
	{
		fenetre = afficherFenetre(1);
		
		printf("\ngagne !\n");												//Soit il a trouvé le mot
		printf("Le mot etait bien : %s\n",mot);
	}
	
	return fenetre;
}


SDL_Window* afficherFenetre(int victoire)
{
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* fenetre = NULL;
	
	SDL_Surface* image = NULL;
	
	SDL_Surface* surfaceFenetre = NULL;
	
	switch(victoire)
	{
		case 0:
			image = SDL_LoadBMP("defaite.bmp");
			
			fenetre = SDL_CreateWindow("VICTOIRE !",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,778,813,SDL_WINDOW_SHOWN);
			
			surfaceFenetre = SDL_GetWindowSurface(fenetre);
			
			SDL_BlitSurface(image,NULL,surfaceFenetre,NULL);
			
			SDL_UpdateWindowSurface(fenetre);
			
			break;
			
		case 1:
			image = SDL_LoadBMP("Victoire_660x330.bmp");
			
			fenetre = SDL_CreateWindow("DEFAITE !",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,660,330,SDL_WINDOW_SHOWN);
			
			surfaceFenetre = SDL_GetWindowSurface(fenetre);
			
			SDL_BlitSurface(image,NULL,surfaceFenetre,NULL);
			
			SDL_UpdateWindowSurface(fenetre);
			
			break;
	}
	return fenetre;
}


void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}


void affichagePendu(int compteurEssais)
{
	switch(compteurEssais)
	{
		case 10:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |	O\n");
		printf("  |    /|\\\n");
		printf("  |	/\\\n");
		printf("__|__\n\n");
		break;
		
		case 9:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |	O\n");
		printf("  |    /|\\\n");
		printf("  |	/\n");
		printf("__|__\n\n");
		break;
		
		case 8:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |	O\n");
		printf("  |    /|\\\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 7:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |	O\n");
		printf("  |    /|\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 6:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |	O\n");
		printf("  |	|\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 5:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |	O\n");
		printf("  |\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 4:
		printf("  ______\n");
		printf("  |	|\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 3:
		printf("  ______\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 2:
		printf("  \n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("__|__\n\n");
		break;
		
		case 1:
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("_____\n\n");
		break;
		
		case 0:
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n\n");
		break;
		
		
	}
}


void lireMot(const char* fichier,char* pointeurVersMot)
{
	FILE* liste=fopen(fichier,"r");
	char caractereLu;
	int nbMots=0;
	int mot=0, i=0;
	
	if(liste==NULL)															//si on ne peut pas ouvrir le fichier
	{
		printf("Echec de la lecture de la liste de mot\n");
		exit(0);
	}
	else																	//si on peut ouvrir le fichier
	{
		do																	//On compte le nombre de ligne :
		{
			caractereLu=fgetc(liste);
			if(caractereLu=='\n')
			{
				nbMots++;
			}
		}while(caractereLu!=EOF);
		
		rewind(liste);
		mot=nbRandom(nbMots);
		while(i<mot)
		{
			if(fgetc(liste)=='\n')
			i++;
		}
		fgets(pointeurVersMot,TAILLE_MAX,liste);
	}
	
	fclose(liste);
}


char* choixTheme()
{
	int choix=0;
	char* theme;
	
	printf("Choisissez un thème :\n1 : animaux\n2 : transport\n3 : couleur\n4 : nourriture\n");
	choix=lireEntier();
	
	switch(choix)
	{
		case 1:
			theme="animaux.txt";
			break;
		
		case 2:
			theme="transport.txt";
			break;
			
		case 3:
			theme="couleur.txt";
			break;
			
		case 4:
			theme="nourriture.txt";
			break;
			
		default:
			theme="mots.txt";
			break;
	}
	
	clear();
	
	return theme;
}


int nbRandom(int MAX)
{
	MAX--;
	srand(time(NULL));
	return(rand() % (MAX)) + 1;
}


void pause()
{
   puts("Appuyez sur ENTREE pour continuer...");
   getchar();
}
