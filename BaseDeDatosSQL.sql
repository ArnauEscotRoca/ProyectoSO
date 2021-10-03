DROP DATABASE IF EXISTS Tablas;
CREATE DATABASE Tablas;
USE Tablas;

CREATE TABLE Jugador (
idJ INT NOT NULL,
PRIMARY KEY(idJ),
Nombre VARCHAR(20),
Password VARCHAR(9)
)ENGINE=InnoDB;

INSERT INTO Jugador VALUES (1, 'Marina', '123456789');
INSERT INTO Jugador VALUES (2, 'Manel', '987654321');
INSERT INTO Jugador VALUES (3, 'Marcos', 'mysql');
INSERT INTO Jugador VALUES (4, 'Maria', 'mimara');


CREATE TABLE Partida (
idP INT NOT NULL,
PRIMARY KEY (idP),
Ganador VARCHAR(20),
Fecha VARCHAR(20),
Duracion VARCHAR(20)
)ENGINE=InnoDB;

INSERT INTO Partida VALUES (1, 'Maria','1/2/21','15');
INSERT INTO Partida VALUES (2, 'Marina','1/2/21','20');
INSERT INTO Partida VALUES (3, 'Marcos','1/2/21','17');

CREATE TABLE Pruebas (
idPb INT NOT NULL,
PRIMARY KEY (idPb),
Nombre VARCHAR (20),
Puntos INT NOT NULL
)ENGINE=InnoDB;

INSERT INTO Pruebas VALUES (1, 'Trivia', 10);
INSERT INTO Pruebas VALUES (2, 'SaltoCuerda', 20);

CREATE TABLE Juegos (
idP INT NOT NULL,
FOREIGN KEY (idP) REFERENCES Partida (idP),
idPb INT NOT NULL,
FOREIGN KEY (idPb) REFERENCES Pruebas (idPb),
Cantidad INT
)ENGINE=InnoDB;

INSERT INTO Juegos VALUES (1, 1, 3);
INSERT INTO Juegos VALUES (1, 2, 2);

CREATE TABLE Historial (
idJ INT NOT NULL,
FOREIGN KEY (idJ) REFERENCES Jugador (idJ),
idP INT NOT NULL,
FOREIGN KEY (idP) REFERENCES Partida (idP),
Puntuacion INT
)ENGINE=InnoDB;

INSERT INTO Historial VALUES (1, 1, 64);
INSERT INTO Historial VALUES (1, 2, 37);
INSERT INTO Historial VALUES (2, 1, 60);