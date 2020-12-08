#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "pendu.h"
#include "chaine.h"

int main(int agrv, char* argv[])
{
	SDL_Window* fenetre;
	
	char mot[TAILLE_MAX],theme[TAILLE_MAX],lettre=' ';							//Initialisation des variables
	
	char lettreDejaSaisie[TAILLE_MAX+11];

	int caracTrouve[TAILLE_MAX]={0},victoire=0,longueur=lenght(mot),compteurEssais=0,compteurLettre=0;
	
	int *pointeurCompteur=&compteurEssais;
	
	do
	{																			//Fonctionne, tire un mot aléatoire du fichier spécifié en paramètre
		SDL_DestroyWindow(fenetre);
		
		compteurLettre=0;
		
		iniChaineChar(lettreDejaSaisie);
		
		compteurEssais=0;
		
		victoire=0;
		
		lireMot(choixTheme(theme),mot);
		
		longueur=lenght(mot);
		
		iniChaineEntier(caracTrouve,longueur);
		
		while(compteurEssais<vie && victoire==0)								//Tant qu'il reste des vies et que le mot n'est pas bon
		{
			affichageMot(mot,caracTrouve,longueur);
			
			compteurLettre++;
			
			printf("\nVous avez déjà entré : \n");
			affichageTableauChar(lettreDejaSaisie,compteurLettre);
			
			lettre=lireLettre();												//Lecture de la lettre
			
			lettreDejaSaisie[compteurLettre]=lettre;
			
			verifLettre(lettre,caracTrouve,longueur,mot,pointeurCompteur);
			
			affichagePendu(compteurEssais);
			
			victoire=verifVictoire(caracTrouve,longueur);
		}
		
		clear();
		
		affichagePendu(compteurEssais);
		
		affichageTableauChar(lettreDejaSaisie,compteurLettre);
		
		fenetre = testVictoire(victoire, mot);
		
	}while(demandeRejouer()==1);
	
	SDL_Quit();
	
	return 0;
}
