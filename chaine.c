#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "chaine.h"


void iniChaineEntier(int* chaine,int longueur)
{
	for(int i=0;i<longueur;i++)
	{
		chaine[i]=0;
	}
}


int lenght(const char* chaine)	//fonctionnel : récupère la longueure d'une chaine (1 caractère = longueur : 1)
{
	int i=0;
	while(chaine[i]!='\0')
	{
		i++;
	}
	
	return i;
}


char lire()	//lis un caractere utilisateur et le met en majuscule
{
	char carac;
	carac = getchar();
	carac=toupper(carac);
	while(getchar()!='\n');
	
	return carac;
}


int lireEntier()
{
	int entier;
	scanf("%d",&entier);
	while(getchar()!='\n');
	
	return entier;
}


void iniChaineChar(char* chaine)
{
	for(int i=0;i<(lenght(chaine));i++)
	{
		chaine[i]=' ';
	}
}


void affichageTableauChar(char* chaine,int longueurChaine)
{
	for(int i=0;i<longueurChaine;i++)
	{
		printf("%c",chaine[i]);
	}
}
