#ifndef PENDU_H
#define PENDU_H

#define TAILLE_MAX 25
#define vie 10

void pause();
void clear();
void affichagePendu(int compteurEssais);
SDL_Window* afficherFenetre(int victoire);
SDL_Window* testVictoire(int victoire, char* mot);
void affichageMot(char* mot,int* caracTrouve,int longueur);
void lireMot(const char* fichier, char* pointeurVersMot);


char lireLettre();
char* choixTheme();


int demandeRejouer();
int nbRandom(int MAX);
int verifVictoire(int* caracTrouve,int longueur);
int verifLettre(char lettre,int* caracTrouve,int longueur,char* mot,int* compteurEssais);

#endif
