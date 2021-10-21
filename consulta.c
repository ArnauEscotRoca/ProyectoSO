//programa en C para consultar los datos de la base de datos
//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
	
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char nom [60];
	char consulta [500];
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL)
	{
		printf ("Error al crear la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//Inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "tablas",0, NULL, 0);
	if (conn==NULL)
	{
		printf ("Error al inicializar la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	// Vamos a buscar las tres ultimas partidas de la persona cuyo nombre es uno
	// dado por el usuario
	printf ("Dame el nombre de la persona que quieres buscar\n"); 
	scanf ("%s", nom);
	
	// Construimos la consulta SQL
	strcpy (consulta,"SELECT historial.idP, historial.puntuacion, partida.ganador FROM (historial, jugador, partida) WHERE jugador.nombre = '"); 
	strcat (consulta, nom);
	strcat (consulta,"' AND jugador.idJ = historial.idJ AND historial.idP = partida.idP ORDER BY historial.idP DESC LIMIT 3");
	
	// Hacemos la consulta 
	err=mysql_query (conn, consulta);
	if (err!=0)
	{
		printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	// Recogemos el resultado de la consulta
	resultado = mysql_store_result (conn);
	// El resultado es una estructura matricial 
	
	row = mysql_fetch_row (resultado);
	// Recorremos una a una cada fila del resultado
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else{
		while (row !=NULL){
			if (strcmp(row[2], nom) == 0){
				printf ("idP: %s Puntuacion: %s Ganador? Si\n", row[0], row[1]);
				// Las columnas 0,1,2 contienen (idP,puntuacion,ganador);
			}
			else
				printf ("idP: %s Puntuacion: %s Ganador? No\n", row[0], row[1]);
				
			// Obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
		}
	}
		// Cerrar la conexion con el servidor MYSQL
		mysql_close (conn);
}
