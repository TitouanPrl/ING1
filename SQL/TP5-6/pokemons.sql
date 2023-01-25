/* Création des tables */

DROP DATABASE IF EXISTS Pokemon;
CREATE DATABASE Pokemon;
USE Pokemon;

CREATE TABLE Equipe(
	id INT PRIMARY KEY,
	nom VARCHAR(9),
	couleur VARCHAR(5)
	);

CREATE TABLE Joueur(
	idJoueur INT PRIMARY KEY,
	pseudonyme VARCHAR(30),
	sexe CHAR(1),
	niveau SMALLINT DEFAULT 0 NOT NULL,
	idEquipe INT,
	FOREIGN KEY fk_equipe(idEquipe) REFERENCES Equipe(id) ON DELETE CASCADE
	);

CREATE TABLE Pokemon(
	id INT PRIMARY KEY,
	nom VARCHAR(30),
	espece VARCHAR(20),
	pointCombat INT,
	idJoueur INT,
	FOREIGN KEY fk_joueur(idJoueur) REFERENCES Joueur(idJoueur)ON DELETE CASCADE
	);	

CREATE TABLE Emplacement(
	idEmplacement INT PRIMARY KEY,
	latitude DECIMAL(12,10) NOT NULL,
	longitude DECIMAL(13,10) NOT NULL,
	CONSTRAINT check_latitude CHECK (latitude BETWEEN -90 AND 90),
	CONSTRAINT check_longitude CHECK (longitude BETWEEN -180 AND 180)
	);

CREATE TABLE Apparition(
	idPokemon INT, 
	idEmplacement INT,
	horaire DATE,
	duree INT,
	CONSTRAINT pk_Apparition PRIMARY KEY (idPokemon, idEmplacement),
	FOREIGN KEY fk_pokemon(idPokemon) REFERENCES Pokemon(id) ON DELETE CASCADE,
	FOREIGN KEY fk_emplacement(idEmplacement) REFERENCES Emplacement(idEmplacement)
	);

CREATE TABLE Arene(
	id INT PRIMARY KEY, 
	nom VARCHAR(30), 
	idEmplacement INT,
	FOREIGN KEY fk_emplacement2(idEmplacement) REFERENCES Emplacement(idEmplacement)
	);

CREATE TABLE Defense(
	idEquipe INT, 
	idArene INT, 
	dateControle DATE,
	CONSTRAINT pk_Defense PRIMARY KEY (idEquipe, idArene, dateControle),
	FOREIGN KEY fk_equipe2(idEquipe) REFERENCES Equipe(id),
	FOREIGN KEY fk_arene(idArene) REFERENCES Arene(id));
	
/* Enregistrements */
INSERT INTO Equipe VALUES (1, 'Intuition', 'Jaune');
INSERT INTO Equipe VALUES (2, 'Sagesse', 'Bleu');
INSERT INTO Equipe VALUES (3, 'Bravoure', 'Rouge');
INSERT INTO Joueur VALUES (1,'Shadow', 'F', 10, 1);
INSERT INTO Joueur VALUES (2,'Elise', 'F', 20, 2);
INSERT INTO Joueur VALUES (3,'Bob54', 'M', 1, 1);
INSERT INTO Pokemon VALUES (1, 'Bulbizarre', 'Graine', 1071, 1);
INSERT INTO Pokemon VALUES (25, 'Pikachu', 'Souris', 887, 2);
INSERT INTO Pokemon VALUES (107, 'Tygnon', 'Puncheur', 204, 1);
INSERT INTO Pokemon VALUES (103, 'Noadkoko', 'Fruitpalme', 190, 3);
INSERT INTO Pokemon VALUES (150, 'Mewtwo', 'Génétique', 4144, 2);
INSERT INTO Pokemon VALUES (151, 'Raichu', 'Souris', 887, 2);
INSERT INTO Pokemon VALUES (155, 'Goupix', 'Renard', 650, 3);
INSERT INTO Pokemon VALUES (160, 'Sabelette', 'Souris', 350, 3);
INSERT INTO Emplacement VALUES (1, 49.0350369, 2.0696998);
INSERT INTO Emplacement VALUES (2, 48.857848, 2.295253);
INSERT INTO Emplacement VALUES (3, -74.0445, 40.6892);
INSERT INTO Apparition VALUES (1, 2, '2022-10-05', 10);
INSERT INTO Apparition VALUES (25, 1, '2022-09-01', 20);
INSERT INTO Apparition VALUES (107, 3, '2022-10-02', 5);
INSERT INTO Apparition VALUES (103, 1, '2022-10-04', 15);
INSERT INTO Apparition VALUES (25, 3, '2022-10-04', 3);
INSERT INTO Apparition VALUES (160, 1, '2022-10-15', 18);
INSERT INTO Apparition VALUES (107, 1, '2022-10-16', 5);
INSERT INTO Arene VALUES (1, 'Liberte', 3);
INSERT INTO Arene VALUES (2, 'CyTech', 1);
INSERT INTO Arene VALUES (3, 'Star', 2);
INSERT INTO Defense VALUES (1, 1, '2022-10-04');
INSERT INTO Defense VALUES (1, 2, '2022-09-01');


/* TD 5 */

/* 1) Durée d'apparition la plus récente */
SELECT duree
FROM Apparition
ORDER BY horaire DESC
LIMIT 1;

SELECT *
FROM Apparition;

/* 2) Nom des pokemons ayant les mêmes pts de combat et le même maitre que Pikachu */

SELECT nom
FROM Pokemon
WHERE pointCombat =
	(SELECT pointCombat 
	FROM Pokemon
	WHERE nom LIKE "Pikachu"
)
AND idJoueur =
	(SELECT idJoueur
	FROM Pokemon
	WHERE nom LIKE "Pikachu"
);

SELECT *
FROM Pokemon;

/* 3) Joueur avec pseudo plus court que tous les autres */
SELECT pseudonyme 
FROM Joueur
WHERE LENGTH(pseudonyme) = (
	SELECT MIN(LENGTH(pseudonyme))
	FROM Joueur
);

/* 4) Afficher date de prise des arènes et horaire spawn pokemon */
SELECT dateControle
FROM Defense;

SELECT horaire
FROM Apparition;

/* 5) Dates où il y a à la fois une apparition et une capture d'arène */
SELECT dateControle
FROM Defense
WHERE dateControle IN (
	SELECT horaire
	FROM Apparition
);

/* 6) Joueurs dont le pseudo commence par B ou S et n'est pas Bob */
SELECT pseudonyme
FROM Joueur
WHERE (pseudonyme LIKE "B%" OR pseudonyme LIKE "S%") AND (pseudonyme NOT LIKE "Bob%");

SELECT pseudonyme
FROM Joueur;

/* 7) Pokemons de Bob54 */
/*SELECT nom
FROM Pokemon
WHERE idJoueur = 3; */

SELECT nom
FROM Pokemon NATURAL JOIN Joueur
WHERE Joueur.pseudonyme = "Bob54";

SELECT *
FROM Pokemon;

/* 8) Joueurs sans pokemon souris */
SELECT pseudonyme
FROM Joueur
WHERE idJoueur NOT IN (
	SELECT idJoueur
	FROM Pokemon
	WHERE espece = "Souris"
);	/* ALED */

/* 9) Equipe de Shadow */
SELECT couleur
FROM Equipe
WHERE id = (
	SELECT idEquipe
	FROM Joueur
	WHERE pseudonyme = "Shadow"
);

SELECT *
FROM Equipe;

/* 10) Pokemons qui n'ont pas encore spawn (id + nom) */
SELECT id, nom
FROM Pokemon
WHERE id NOT IN ( 
	SELECT idPokemon
	FROM Apparition
);

SELECT COUNT(DISTINCT nom)
FROM Pokemon;

SELECT COUNT(DISTINCT idPokemon)
FROM Apparition;

/* 11) Latitude et Longitude de l'endroit où un pokemon de l'espèce Fruitpalme a spawn le 04 OCtobre 2022 */
SELECT latitude, longitude
FROM Emplacement
WHERE idEmplacement = (
	SELECT idEmplacement
	FROM Apparition
	WHERE horaire = "2022-10-04" AND idPokemon = (
		SELECT id
		FROM Pokemon
		WHERE espece = "Fruitpalme"
	)
);

/* 12) Pokemons meilleurs que ceux de l'équipe Jaune */
SELECT nom
FROM Pokemon
WHERE pointCombat > ALL(
	SELECT pointCombat
	FROM Pokemon
	WHERE idJoueur IN (
		SELECT idJoueur
		FROM Joueur
		WHERE idEquipe = (
			SELECT id
			FROM Equipe
			WHERE couleur = "Jaune"
		)
	)
);

/* 13) Combien de pokemons à l'arène CY */
SELECT COUNT(idPokemon) as NbPokemon
FROM Apparition NATURAL JOIN Arene
WHERE Arene.nom = "CyTech";

/* 14) Combien d'arènes a pris l'équipe intuition */
SELECT COUNT(DISTINCT idArene) as NbArenesPrises
FROM Equipe
INNER JOIN Defense ON Equipe.id = Defense.idEquipe
WHERE Equipe.nom = "Intuition";

/* 15) date première apparition Tygnon */
SELECT horaire as 1erPopTygnon
FROM Apparition
INNER JOIN Pokemon ON Apparition.idPokemon = Pokemon.id
WHERE Pokemon.nom = "Tygnon"
ORDER BY horaire ASC
LIMIT 1;

/* 16) moy pts combat de chaque espèce */
SELECT espece, AVG(pointCombat)
FROM Pokemon
GROUP BY espece;


/* 17) Nb pokemons de chaque joueur */
SELECT pseudonyme, COUNT(nom) as NbPokemons
FROM Joueur NATURAL JOIN Pokemon
GROUP BY pseudonyme;


/* 18) Affiche le pseudo, l'équipe et le nb de pokemon de chaque joueur */
SELECT pseudonyme, couleur, COUNT(Pokemon.nom) as NbPokemons
FROM (Joueur NATURAL JOIN Pokemon)
INNER JOIN Equipe ON Joueur.idEquipe = Equipe.id
GROUP BY idJoueur;

/* 19) Pour chaque pokémon, donner le nom et la durée totale d'apparition */
SELECT nom, SUM(duree)
FROM Pokemon 
INNER JOIN Apparition ON Pokemon.id = Apparition.idPokemon
GROUP BY id;

/* 20) Pour chaque pokémon, donner son nom, son espèce et le nombre d'apparitions. Nous
sommes intéressés seulement aux pokémons qui ont apparu au moins 2 fois. */
SELECT nom, espece, COUNT(idPokemon) as nbApparitions
FROM Pokemon
INNER JOIN Apparition ON Pokemon.id = Apparition.idPokemon
GROUP BY idPokemon
HAVING COUNT(idPokemon) >= 2;

/* 21) Pour chaque pokémon, donner son nom, son espèce et le nombre d'apparitions dont la
durée est supérieure à 5 minutes. */
SELECT nom, espece, COUNT(idPokemon) as nbApparitions
FROM Pokemon
INNER JOIN Apparition ON Pokemon.id = Apparition.idPokemon
GROUP BY idPokemon
HAVING SUM(duree) > 5;

/* 22) Pour chaque pokémon de plus de 1000 points de combat, donner son nom, son espèce
et la durée totale d’apparition. Nous sommes intéressés seulement aux pokémons qui
ont apparu au moins 10 minutes. */
SELECT nom, espece, SUM(duree) as DureeApparition
FROM Pokemon
INNER JOIN Apparition ON Pokemon.id = Apparition.idPokemon
WHERE pointCombat > 1000
GROUP BY idPokemon
HAVING SUM(duree) >= 10;

/* DEBUT DE L'ENFER */

/* 23) Donner le temps moyen d’apparition des pokémons appartenant aux joueurs de l’équipe
ayant contrôlé le plus d’arènes. */

/* SELECT nom, AVG(duree)
FROM ((Apparition
INNER JOIN Pokemon ON Apparition.idPokemon = Pokemon.id)
NATURAL JOIN Joueur)
NATURAL JOIN Defense
GROUP BY (idEquipe)
HAVING MAX(COUNT(idEquipe));


SELECT AVG(duree)
FROM Apparition
WHERE idPokemon IN (
	SELECT idPokemon
	FROM Pokemon
	WHERE idJoueur IN (
		SELECT idJoueur
		FROM Joueur
		WHERE idEquipe IN (
			SELECT idEquipe
			FROM Arene
			GROUP BY idEquipe
			HAVING MAX(idEquipe)
		)
	)
); 

SELECT nom, AVG(duree)
FROM Apparition
INNER JOIN Pokemon ON Apparition.idPokemon = Pokemon.id
WHERE idJoueur IN (
	SELECT idJoueur
) */

SELECT nom,avg(duree)
FROM Apparition 
INNER JOIN Pokemon ON Apparition.idPokemon = Pokemon.id 
AND Pokemon.id = ANY (
	SELECT id 
	FROM Pokemon 
	WHERE idJoueur = ANY (
		SELECT idJoueur 
		FROM Joueur 
		WHERE idEquipe = (
			SELECT idEquipe 
			FROM Defense 
			INNER JOIN Equipe 
			ON Defense.idEquipe = Equipe.id 
			GROUP BY idEquipe 
			ORDER BY count(idArene) desc limit 1
		)
	)
) 
GROUP BY id;

/* ========================= */

/* TD 6 */

/* 1) Durée d'apparition la plus récente */
SELECT duree
FROM Apparition
ORDER BY horaire DESC
LIMIT 1;

/* 2) Classez les pokémons en fonction du nombre d'apparitions. Nous sommes intéressés par
les Pokémons qui n'ont pas encore apparu également (dont le nombre d'apparition vaut
0) */

SELECT nom, COUNT(idPokemon) AS nbApparitions
FROM Pokemon p LEFT JOIN Apparition
ON idPokemon = p.id
GROUP BY p.id
ORDER BY COUNT(idPokemon) DESC;

/* 3) Quels sont les pokémons dont le nombre d'apparitions est supérieur au nombre moyen
d'apparitions ? */

SELECT nom
FROM Pokemon p LEFT JOIN Apparition
ON idPokemon = p.id
GROUP BY p.id
HAVING COUNT(idPokemon) > (
	SELECT AVG(poke.nb)
	FROM (
		SELECT COUNT(idPokemon) nb
		FROM Pokemon p LEFT JOIN Apparition
		ON idPokemon = p.id 
		GROUP BY p.id
	) poke
);

/* 4) On veut obtenir le pseudonyme, le sexe, le niveau et le nombre de pokémons de tous
les joueurs, y compris ceux qui n'ont capturé aucun Pokémon. Triez votre résultat */

INSERT INTO Joueur VALUES (4,'Dujol', 'M', 24, 1); /* On rajoute un joueur sans pokemon pour tester */

SELECT pseudonyme, sexe, niveau, COUNT(id) AS NbPoke
FROM Joueur j LEFT JOIN Pokemon p
ON p.idJoueur = j.idJoueur
GROUP BY j.idJoueur
ORDER BY pseudonyme;

/* 5) Quels sont les pokémons qui ont apparu dans tous les emplacements différents ? */

SELECT p.nom	
FROM Pokemon p INNER JOIN Apparition a
ON p.id = a.idPokemon
GROUP BY p.id
HAVING COUNT(DISTINCT a.idEmplacement) = (
	SELECT COUNT(idEmplacement)
	FROM Emplacement
);

/* 6) Quels sont les joueurs qui ont capturé toutes les espèces de pokémon ? */

SELECT pseudonyme	
FROM Joueur j NATURAL JOIN Pokemon p
GROUP BY j.idJoueur
HAVING COUNT(DISTINCT p.espece) = (
	SELECT COUNT(espece)
	FROM Pokemon
);

/* 7) Combien de joueurs possèdent des pokémons qui sont placés dans l'emplacement avec
la latitude la plus septentrionale (la plus haute) ? */

SELECT COUNT(j.idJoueur)
FROM Joueur j NATURAL JOIN Pokemon p
WHERE p.id = (
	SELECT id
	FROM Pokemon poke INNER JOIN Apparition a
	ON poke.id = a.idPokemon
	WHERE a.idEmplacement = (
		SELECT idEmplacement
		FROM Emplacement
		WHERE latitude = (
			SELECT MAX(latitude)
			FROM Emplacement
		)
	)
);

	SELECT id
	FROM Pokemon poke INNER JOIN Apparition a
	ON poke.id = a.idPokemon
	WHERE a.idEmplacement = (
		SELECT idEmplacement
		FROM Emplacement
		WHERE latitude = (
			SELECT MAX(latitude)
			FROM Emplacement
		)
	);