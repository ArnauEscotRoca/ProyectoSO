DROP DATABASE IF EXISTS tablas;
CREATE DATABASE tablas;

USE tablas;

CREATE TABLE jugador (
    idJ INT NOT NULL, 
    PRIMARY KEY (idJ),    
    nombre VARCHAR(60),
    contraseña VARCHAR(60)
)ENGINE=InnoDB;

INSERT INTO jugador VALUES ('1', 'Juan', 'vfd');
INSERT INTO jugador VALUES ('2', 'Pedro', 'vfd');

CREATE TABLE partida (
    idP INT NOT NULL, 
    PRIMARY KEY (idP),
    ganador VARCHAR(60),
    fecha VARCHAR(60),
    duracion VARCHAR(60)
)ENGINE=InnoDB;

INSERT INTO partida VALUES ('1', 'Juan', '1/2/21', '54');
INSERT INTO partida VALUES ('2', 'Juan', '1/2/21', '54');
INSERT INTO partida VALUES ('3', 'Juan', '1/2/21', '54');
INSERT INTO partida VALUES ('4', 'Pedro', '1/2/21', '54');

CREATE TABLE historial (
    idJ INT NOT NULL, 
    FOREIGN KEY (idJ) REFERENCES jugador(idJ), 
    idP INT NOT NULL, 
    FOREIGN KEY (idP) REFERENCES partida(idP),   
    puntuacion INT
)ENGINE=InnoDB;

INSERT INTO historial VALUES ('1', '1', '547');
INSERT INTO historial VALUES ('2', '1', '587');
INSERT INTO historial VALUES ('2', '2', '587');
INSERT INTO historial VALUES ('2', '3', '587');
INSERT INTO historial VALUES ('2', '4', '756');

CREATE TABLE pruebas (
    idPb INT NOT NULL, 
    PRIMARY KEY (idPb),
    nombre VARCHAR(60),
    puntos INT 
)ENGINE=InnoDB;

INSERT INTO pruebas VALUES ('5', 'preguntas', '20');

CREATE TABLE juego (
    idP INT NOT NULL,
    FOREIGN KEY (idP) REFERENCES partida (idP),
    idPb INT NOT NULL, 
    FOREIGN KEY (idPb) REFERENCES pruebas (idPb),
    cantidad INT 
)ENGINE=InnoDB;

INSERT INTO juego VALUES ('1', '5', '3');
