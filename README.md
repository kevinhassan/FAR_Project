# ProjetFAR

### Role: 
Distributeur de ballon

### Contributeurs:

* [Kévin Hassan]("https://github.com/kevinhassan")
* [Yves-Alain Agbodjogbe]("https://github.com/AgbodjogbeYves-alain")

## Fonctions RPC pour demander un ballon :

```shell
cd ./RPC
make -f Makefile.calcul
```

**LANCER DANS 2 TERMINAUX DIFFERENTS :** 
```shell
./calcul_client [HOST][NUMERO FONCTION]
./calcul_server
```
**NB : NUMERO FONCTION = {1,2}**

* 1 --> Demander un ballon
* 2 --> Vérifier authenticité du ballon

## Client - Server : robot et server intermédiaire:

### Lancer le server RPC :

```shell
./RPC/calcul_server
```

### Lancer le server intermédiaire : 

```shell
./clients/ClientServeurIntermediaire
```

**Entrer son port d'écoute (ex: 10000)** 

### Lancer le clientRobot : 

```shell
./clients/clientRobot 
```

**Entrer le port sur lequel communiquer (ex: 10000)**

**N.B :**

- Le numéro RFID du robot sera attendu au niveau du server intermédiaire

## Bilan 

### Ce qui marche:

* Server intermédiaire
* Server central
* Authentification ballon
* Distribution ballon

### Ce qui marche pas :

* Communication avec Beebot
* Durée de validité d'un ballon
