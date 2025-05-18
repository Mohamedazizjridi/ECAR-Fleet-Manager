# ECAR Fleet Manager

1. **ECAR Fleet Manager** – Application de location de voitures en C (E-Cars)
2. **Projet-C** – Version finale

Bienvenue dans **ECAR Fleet Manager**, une application en ligne de commande écrite en C pour la gestion de la location de voitures. Cette application vous permet de :

- Consulter l'état des voitures disponibles à l'agence.
- Louer et retourner des véhicules avec suivi de l'historique.
- Générer des statistiques jour par jour et mois par mois.

## Fonctionnalités Principales

- **Louer une Voiture**: Permet de louer une voiture et enregistre les détails de la location.
- **Supprimer une Voiture en Panne**: Retire du parc une voiture déclarée en panne.
- **Modifier une Voiture**: Met à jour marque, modèle, année et statut.
- **Afficher l'État des Voitures Disponibles**: Liste les voitures libres pour location.
- **Historique des Locations**: Affiche l’historique complet, jour par jour et mois par mois.
- **Import/Export CSV**: Sauvegarde et charge les fichiers `voitures.csv` et `historique.csv`.
- **Statistiques Mensuelles**: Nombre de locations par mois.

## Comment Utiliser l'Application

1. **Compilation** :
   ```bash
   gcc main.c -o ecar_fleet_manager
   ```
2. **Exécution** :
   ```bash
   ./ecar_fleet_manager
   ```
3. **Navigation** :
   Suivez les options du menu interactif pour accéder aux fonctionnalités.

```text
1) Ajouter une voiture
2) Lister les voitures
3) Filtrer par statut
4) Modifier une voiture
5) Supprimer une voiture
6) Louer une voiture
7) Afficher l’historique
8) Retourner une voiture
9) Sauvegarder voitures (CSV)
a) Charger voitures (CSV)
b) Sauvegarder historique (CSV)
c) Charger historique (CSV)
d) Statistiques mensuelles
0) Quitter
```

## Contribuer

Vos contributions sont les bienvenues ! Ouvrez une issue ou une pull request pour proposer des améliorations.

---

© 2025 ECAR Fleet Manager – Tous droits réservés.
