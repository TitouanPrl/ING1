/* TD 3*/

DROP DATABASE IF EXISTS Pokemon;
CREATE DATABASE Pokemon;
USE Pokemon;

CREATE TABLE Equipe (
    idEquipe int NOT NULL AUTO_INCREMENT,
    nom varchar(255),
    couleur varchar(255),
    PRIMARY KEY(idEquipe)
);

CREATE TABLE Joueur (
    idJoueur int AUTO_INCREMENT,
    pseudo varchar(255) UNIQUE,
    sexe varchar(255),
    niveau int DEFAULT 0 NOT NULL,
    PRIMARY KEY(idJoueur),
    idEquipe int,
    FOREIGN KEY(idEquipe) REFERENCES Equipe(idEquipe) ON DELETE CASCADE
);

CREATE TABLE Pokemon (
    idPokemon int NOT NULL,
    nom varchar(255),
    espece varchar(255),
    ptsCombat int,
    idJoueur int,
    PRIMARY KEY(idPokemon),
    FOREIGN KEY(idJoueur) REFERENCES Joueur(idJoueur) ON DELETE CASCADE
);

CREATE TABLE Emplacement (
    idEmplacement int NOT NULL AUTO_INCREMENT,
    latitude float NOT NULL,
    longitude float NOT NULL,
    PRIMARY KEY(idEmplacement)
);

CREATE TABLE Apparition (
    idPokemon int NOT NULL,
    idEmplacement int NOT NULL,
    date date DEFAULT(CURRENT_TIME),
    duree int,
    PRIMARY KEY(idEmplacement, idPokemon),
    FOREIGN KEY(idPokemon) REFERENCES Pokemon(idPokemon) ON DELETE CASCADE,
    FOREIGN KEY(idEmplacement) REFERENCES Emplacement(idEmplacement) ON DELETE CASCADE
);

/* Modification nom colonne date */
ALTER TABLE Apparition RENAME COLUMN date TO horaire;

/* Ajout contrainte */
ALTER TABLE Pokemon ADD CONSTRAINT min_ptsCombat CHECK(ptsCombat >= 0);

ALTER TABLE Emplacement ADD CONSTRAINT champ_lat CHECK(latitude BETWEEN -90 AND 90);
ALTER TABLE Emplacement ADD CONSTRAINT champ_long CHECK((longitude >= -180) AND (longitude <= 180));

ALTER TABLE Joueur DROP INDEX pseudo;

/* Affichage des tables */
DESCRIBE Pokemon;
DESCRIBE Joueur;
DESCRIBE Emplacement;
DESCRIBE Apparition;
DESCRIBE Equipe;

/* TD 4 */

/* On remplit les tables */
insert into Equipe values (null,"Intuition","Jaune");
insert into Equipe values (null,"Sagesse","Bleu");
insert into Equipe values (null,"Bravoure","Rouge");

insert into Joueur values (null,"Shadow","F",10,1);
insert into Joueur values (null,"Elise","F",20,2);
insert into Joueur values (null,"Bob54","M",1,1);

insert into Pokemon values (1,"Bulbizarre","Graine",1071,1);
insert into Pokemon values (25,"Pikachu","Souris",887,2);
insert into Pokemon values (107,"Tygnon","Puncheur",204,1);
insert into Pokemon values (103,"Noidkoko","Fruitpalme",190,3);
insert into Pokemon values (150,"Mewtwo","Génétique",4144,2);

insert into Emplacement values (null,49.0350369,2.0696998);
insert into Emplacement values (null,48.857848,2.295253);
insert into Emplacement values (null,74.0445,40.6892);
    
insert into Apparition values (1,2,"2022-10-05",10);
insert into Apparition values (25,2,"2022-09-01",20);
insert into Apparition values (107,3,"2022-10-02",5);
insert into Apparition values (103,1,"2022-10-04",15);
insert into Apparition values (25,3,"2022-10-04",3);

/* On met les joueurs féminins lvl 15 */
UPDATE Joueur SET niveau="15" WHERE sexe="F";
SELECT * FROM Joueur;

/* On supprime les pokemon dont l'espèce contient "que" */
DELETE FROM Pokemon WHERE espece LIKE "%que%";
SELECT * FROM Pokemon;

/* On supprime le joueur Bob54 */
DELETE FROM Joueur WHERE pseudo LIKE "Bob54";       /* Il a fallu rajouter ON DELETE CASCADE pour supprimer les occurences */
SELECT * FROM Joueur;

/* Combien d'équipe dans la bdd */
SELECT COUNT(DISTINCT couleur) FROM Equipe;
SELECT * FROM Equipe;

/* Pokemon dont le nom commence par p sans tenir compte de la casse */
SELECT nom
FROM Pokemon
WHERE UPPER(nom) LIKE UPPER("P%");

SELECT *
FROM Pokemon;

/* Pseudo de joueurs qui ne contiennent pas a */
SELECT pseudo
FROM Joueur
WHERE UPPER(pseudo) NOT LIKE UPPER("%a%");

SELECT *
FROM Joueur;

/* Trier pokemon par odre décroissant de pts de combat */
SELECT *
FROM Pokemon
ORDER BY ptsCombat DESC;

/* Date spawn Tygnon */
SELECT horaire
FROM Apparition
WHERE idPokemon LIKE 107;   /* ID de Tygnon */

/* Durée moy apparition pokemon */
SELECT AVG(duree)
FROM Apparition;

SELECT *
FROM Apparition;

/* Nb d'apparitions de pokemon en Octobre 2022 */
SELECT COUNT(idPokemon)
FROM Apparition
WHERE horaire LIKE "2022-10%";

SELECT *
FROM Apparition;

/* Pokemon le plus fort */
SELECT nom, MAX(ptsCombat)
FROM Pokemon
GROUP BY nom;

/* +2 lvl à Shadow */
UPDATE Joueur
SET niveau=niveau+2
WHERE pseudo="Shadow";

SELECT *
FROM Joueur;

/* Sélectionner les pokemons apparus en septembre mais sans UTILISER LIKE */
/*SELECT nom
FROM Pokemon
WHERE 
    SELECT idPokemon
    FROM Apparition
    WHERE
        SELECT horaire  
        FROM Apparition
        WHERE horaire = "__-09%";

 ALED */

/* TD 5 */

/* Durée d'apparition la plus récente */
SELECT MAX(duree) AS 'durée la plus récente'
FROM Apparition;

SELECT *
FROM Apparition;

/* Nom des pokemons ayant les mêmes pts de combat et le même maitre que Pikachu */
