# 🧠 Philosophers (philo)

**philo** est un projet de l'école 42 visant à modéliser le **problème des philosophes** : un classique de la programmation concurrente. Il permet de se familiariser avec les threads, les mutex et la synchronisation en environnement multi-threadé.

## 🎯 Objectif

Simuler le comportement de philosophes autour d'une table, qui passent leur temps à **penser**, **manger**, et **dormir**, tout en évitant les conditions de **deadlock** ou de **race conditions**.

## 📚 Règles du problème

- Chaque philosophe a besoin de **deux fourchettes** (gauche et droite) pour manger.
- Une fourchette est partagée entre deux voisins.
- Si un philosophe ne mange pas pendant un temps trop long, il **meurt**.
- Le programme s’arrête si un philosophe meurt ou si tous ont mangé un certain nombre de fois (si spécifié).

## 🧱 Fonctions clés

- Utilisation de **threads (`pthread`)** pour gérer les philosophes
- **Mutex** pour éviter l'accès simultané aux fourchettes
- Prise en compte en `milliseconde` :
  - du temps avant la mort (`time_to_die`)
  - du temps de repas (`time_to_eat`)
  - du temps de sommeil (`time_to_sleep`)
- Messages synchronisés :
  - Philosophe mange 🥄
  - Philosophe pense 🤔
  - Philosophe dort 😴
  - Philosophe meurt 💀

## 🧪 Compilation et Utilisation

### Compilation

Le projet utilise un `Makefile` pour faciliter la compilation.

```bash
make
```

Pour nettoyer les fichiers objets :

```bash
make clean
```

Pour supprimer tous les fichiers compilés (objets + exécutable) :

```bash
make fclean
```

Pour recompiler le projet :

```bash
make re
```

### 📄 Utilisation

```bash
./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep> [nb_must_eat]
```

Exemple : 

```bash
./philo 5 800 200 200
./philo 4 410 200 200 7
```
