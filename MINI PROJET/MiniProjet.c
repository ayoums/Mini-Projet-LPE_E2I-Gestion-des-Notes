#include <stdio.h>

#define MAX_ETUDIANTS 100

int main() {
	int notes[MAX_ETUDIANTS],cnes[MAX_ETUDIANTS];
	int nb_etudiants = 0, choix, note;

	do {
		printf("\n**** Menu ****\n");
		printf("1. Ajouter un etudiant\n");
		printf("2. Afficher les etudiants et mentions\n");
		printf("3. Modifier une note\n");
		printf("4. Supprimer un etudiant\n");
		printf("5. Trier les etudiants par note\n");
		printf("0. Quitter\n");
		printf("Votre choix : ");
		scanf("%d", &choix);

		if (choix == 1) {
			if (nb_etudiants >= MAX_ETUDIANTS) {
				printf("Nombre maximum d'etudiants atteint.\n");
			} else {
				int note, cne;

				printf("CNE de l'etudiant [nombre inteire sans caractire] : ");
				scanf("%d", &cne);

				do {
					printf("Note (0-20) : ");
					scanf("%d", &note);
					if (note < 0 || note > 20) {
						printf("Erreur ! Note invalide. Veuillez entrer une note entre 0 et 20.\n");
					}
				} while (note < 0 || note > 20);

				cnes[nb_etudiants] = cne;
				notes[nb_etudiants] = note;
				nb_etudiants++;
			}
		} else if (choix == 2) {
			printf("\nListe des etudiants et mentions :\n");
			for (int i = 0; i < nb_etudiants; i++) {
				printf("CNE : %d | Note : %d | Mention : ", cnes[i], notes[i]);

				if (notes[i] < 10) {
					printf("Non valide\n");
				} else if (notes[i] < 12) {
					printf("Passable\n");
				} else if (notes[i] < 14) {
					printf("Assez bien\n");
				} else if (notes[i] < 16) {
					printf("Bien\n");
				} else {
					printf("Tres bien\n");
				}
			}
		} else if (choix == 3) {
			int cne, index = -1;
			printf("CNE de l'Etudiant a modifier : ");
			scanf("%d", &cne);

			for (int i = 0; i < nb_etudiants; i++) {
				if (cnes[i] == cne) {
					index = i;
					break;
				}
			}

			if (index == -1) {
				printf("Etudiant non trouve.\n");
			} else {
				int note;
				do {
					printf("Nouvelle note (0-20) : ");
					scanf("%d", &note);
					if (note < 0 || note > 20) {
						printf("Erreur ! Note invalide. Veuillez entrer une note entre 0 et 20.\n");
					}
				} while (note < 0 || note > 20);
				notes[index] = note;
			}
		} else if (choix == 4) {
			int cne, index = -1;
			printf("CNE de l'etudiant a supprimer : ");
			scanf("%d", &cne);


			for (int i = 0; i < nb_etudiants; i++) {
				if (cnes[i] == cne) {
					index = i;
					break;
				}
			}

			if (index == -1) {
				printf("Etudiant non trouve.\n");
			} else {
				for (int i = index; i < nb_etudiants - 1; i++) {
					cnes[i] = cnes[i + 1];
					notes[i] = notes[i + 1];
				}
				nb_etudiants--;
			}
		} else if (choix == 5) {
			for (int i = 0; i < nb_etudiants - 1; i++) {
				for (int j = i + 1; j < nb_etudiants; j++) {
					if (notes[i] > notes[j]) {
						int temp_note = notes[i];
						notes[i] = notes[j];
						notes[j] = temp_note;

						int temp_cne = cnes[i];
						cnes[i] = cnes[j];
						cnes[j] = temp_cne;
					}
				}
			}
			printf("Notes triees.\n");
		} else if (choix == 0) {
			printf("Au revoir !\n");
		} else {
			printf("Choix invalide.\n");
		}
	} while (choix != 0);

	return 0;
}
