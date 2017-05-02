[TOC]

#Conception

## Automates

#### Automate Distributeur de Balle - Robot

![Automate](./docs/automate2.png)

##### Transitions

* a :  Récupérer les informations de la partie sur DWEET (Reqûete HTTP) 
* b :  Attendre le robot dans la zone de distribution
* c :  Vérifier la présence du ballon sur le terrain 
* d :  Refuser la distribution du ballon (tous les ballons sont déjà sur le terrain)
* e :  Accepter la distribution et scanner la puce RFID
* f  :  Affecter le ballon encrypté à un robot
* g :  Relancer l'attente en zone de distribution

##### Etats

- 0 : Partie démarrée
- 1 :  Attente robot zone
- 2 :  Présence ballon
- 3 :  Robot identifié
- 4 :  Balle passée


#### Automate Distributeur de Balle - Validateur de but

![Automate](./docs/automate.png)

##### Transitions

- a :  Attendre requête du validateur de but
- b :  Vérifier la validité du ballon (decrypter et vérifier si le robot était le propriétaire de la balle)
- c :  Envoyer "Ballon valide" au validateur de but
- d :  Envoyer "Ballon non valide" au validateur de but
- e :  Décrémenter le nombre de ballon distribué

##### Etats

- 0 :  Attente but
- 1 :  Analyse ballon
- 2 :  Ballon valide