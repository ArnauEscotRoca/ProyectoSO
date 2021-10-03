USE Tablas;

SELECT Juegos.Cantidad, Pruebas.Nombre, Pruebas.Puntos FROM (Juegos, Pruebas)
WHERE Juegos.idP = SELECT MAX(Historial.idP) FROM (Historial)
AND Juegos.idPb = Pruebas.idPb