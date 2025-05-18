// Ecar application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Voiture {
    int id;
    char marque[100];
    char modele[100];
    int annee;
    char statut[20];
};

struct Location {
    int idVoiture;
    char date[20];
    char nomClient[50];
    char statutRetour[20];
};

struct Historique {
    struct Location *locations;
    int nombreLocations;
};
void afficherVoiture(const struct Voiture *voiture);
void louerVoiture(struct Voiture *voiture, const struct Location *location);
void supprimerVoitureEnPanne(struct Voiture *voiture);
void modifierVoiture(struct Voiture *voiture, const char nouvelleMarque[50], const char nouveauModele[50], int nouvelleAnnee, const char nouveauStatut[20]);
void afficherHistoriqueLocations(const struct Location *locations, int nombreLocations);
void retourVoitureEnCasReclamation(struct Voiture *voiture, struct Location *location);
void afficherVoituresDisponibles(const struct Voiture *voitures, int nombreVoitures);
void afficherDetailsLocation(const struct Location *locations, int nombreLocations, int idLocation);
void sauvegarderHistoriqueDansFichier(const struct Historique *historique, const char *nomFichier);
void consulterEtatAgence(const struct Voiture *voitures, int nombreVoitures);
void afficherHistoriqueJourParJour(const struct Historique *historique);
void afficherHistoriqueMoisParMois(const struct Historique *historique);


void afficherVoiture(const struct Voiture *voiture) {
    printf("\n===== Détails de la voiture =====\n");
    printf("ID : %d\n", voiture->id);
    printf("Marque : %s\n", voiture->marque);
    printf("Modèle : %s\n", voiture->modele);
    printf("Année : %d\n", voiture->annee);
    printf("Statut : %s\n", voiture->statut);
    printf("==============================\n");
}

void louerVoiture(struct Voiture *voiture, const struct Location *location) {
    strcpy(voiture->statut, "Louée");
    printf("La voiture a été louée avec succès!\n");
    printf("Enregistrement de la location dans l'historique...\n");
}

void supprimerVoitureEnPanne(struct Voiture *voiture) {
    if (strcmp(voiture->statut, "En panne") == 0) {
        printf("La voiture en panne a été supprimée ou mise à jour avec succès!\n");
    } else {
        printf("Cette voiture n'est pas en panne. Aucune action nécessaire.\n");
    }
}
void modifierVoiture(struct Voiture *voiture, const char nouvelleMarque[50], const char nouveauModele[50], int nouvelleAnnee, const char nouveauStatut[20]) {
    strcpy(voiture->marque, nouvelleMarque);
    strcpy(voiture->modele, nouveauModele);
    voiture->annee = nouvelleAnnee;
    strcpy(voiture->statut, nouveauStatut);
}
void afficherHistoriqueLocations(const struct Location *locations, int nombreLocations) {
    printf("\n===== Historique des locations =====\n");
    for (int i = 0; i < nombreLocations; i++) {
        printf("Location %d\n", i + 1);
        printf("ID Voiture : %d\n", locations[i].idVoiture);
        printf("Date : %s\n", locations[i].date);
        printf("Nom Client : %s\n", locations[i].nomClient);
        printf("Statut Retour : %s\n", locations[i].statutRetour);
        printf("-----------------------------\n");
    }
    printf("==============================\n");
}
void retourVoitureEnCasReclamation(struct Voiture *voiture, struct Location *location) {
    strcpy(location->statutRetour, "Réclamation traitée");
}
void afficherVoituresDisponibles(const struct Voiture *voitures, int nombreVoitures) {
    printf("\n===== Voitures Disponibles =====\n");
    for (int i = 0; i < nombreVoitures; i++) {
        if (strcmp(voitures[i].statut, "Disponible") == 0) {
            afficherVoiture(&voitures[i]);
        }
    }
    printf("==============================\n");
}
void afficherDetailsLocation(const struct Location *locations, int nombreLocations, int idLocation) {
    for (int i = 0; i < nombreLocations; i++) {
        if (locations[i].idVoiture == idLocation) {
            printf("\n===== Détails de la location =====\n");
            printf("ID Voiture : %d\n", locations[i].idVoiture);
            printf("Date : %s\n", locations[i].date);
            printf("Nom Client : %s\n", locations[i].nomClient);
            printf("Statut Retour : %s\n", locations[i].statutRetour);
            printf("==============================\n");
            return; 
        }
    }
    printf("Location non trouvée avec l'ID %d\n", idLocation);
}
void sauvegarderHistorique(const struct Historique *historique, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarde.\n");
        return;
    }

    fprintf(fichier, "\n===== Historique des locations =====\n");
    for (int i = 0; i < historique->nombreLocations; i++) {
        fprintf(fichier, "Location %d\n", i + 1);
        fprintf(fichier, "ID Voiture : %d\n", historique->locations[i].idVoiture);
        fprintf(fichier, "Date : %s\n", historique->locations[i].date);
        fprintf(fichier, "Nom Client : %s\n", historique->locations[i].nomClient);
        fprintf(fichier, "Statut Retour : %s\n", historique->locations[i].statutRetour);
        fprintf(fichier, "-----------------------------\n");
    }
    fprintf(fichier, "==============================\n");

    fclose(fichier);
    printf("L'historique a été sauvegardé dans le fichier %s.\n", nomFichier);
}

void consulterEtatAgence(const struct Voiture *voitures, int nombreVoitures) {
    printf("\n===== État de l'agence =====\n");
    afficherVoituresDisponibles(voitures, nombreVoitures);
    printf("==============================\n");
}

void afficherHistoriqueJourParJour(const struct Historique *historique) {
    printf("\n===== Historique jour par jour =====\n");
    for (int i = 0; i < historique->nombreLocations; i++) {
        printf("Date : %s\n", historique->locations[i].date);
        printf("ID Voiture : %d\n", historique->locations[i].idVoiture);
        printf("Nom Client : %s\n", historique->locations[i].nomClient);
        printf("Statut Retour : %s\n", historique->locations[i].statutRetour);
        printf("-----------------------------\n");
    }
    printf("==============================\n");
}
void afficherHistoriqueMoisParMois(const struct Historique *historique) {
    printf("\n===== Historique mois par mois =====\n");
    printf("==============================\n");
}


int main() {

    printf("  _______   ______\n");
    printf(" /  ____| |  _____|\n");
    printf("| |       | |__\n");
    printf("| |       |  ____|\n");
    printf("| |____   | \n");
    printf(" \\_____| |_ __ _|\n");

    struct Voiture voiture1 = {1, "Ferrari", "aziz", 2022, "Disponible"};
    struct Location location1 = {1, "2023-01-01", "ines", "Non retournée"};
    struct Historique historique;
    historique.locations = &location1;
    historique.nombreLocations = 1;

    int choix = -1;

    while (choix != 0) {
        printf("\n===== Menu =====\n");
        printf("1. Afficher une voiture\n");
        printf("2. Louer une voiture\n");
        printf("3. Supprimer une voiture en panne\n");
        printf("4. Modifier une voiture\n");
        printf("5. Afficher l'historique des locations\n");
        printf("6. Retour d'une voiture en cas de réclamation\n");
        printf("7. Afficher les voitures disponibles\n");
        printf("8. Afficher les détails d'une location\n");
        printf("9. Sauvegarder l'historique dans un fichier\n");
        printf("10. Consulter l'état de l'agence\n");
        printf("11. Afficher l'historique jour par jour\n");
        printf("12. Afficher l'historique mois par mois\n");
        printf("0. Quitter\n");
        printf("================\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherVoiture(&voiture1);
                break;
            case 2:
                louerVoiture(&voiture1, &location1);
                break;
            case 3:
                supprimerVoitureEnPanne(&voiture1);
                break;
            case 4:
                modifierVoiture(&voiture1, "NouvelleMarque", "NouveauModèle", 2023, "Disponible");
                break;
            case 5:
                afficherHistoriqueLocations(&location1, 1);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Option non valide. Veuillez choisir une option valide.\n");
        }
    }

    return 0;
}
