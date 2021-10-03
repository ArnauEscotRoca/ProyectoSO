//programa en C para consultar los datos de la base de datos
//Incluir esta libreria para poder hacer las llamadas en shiva2.upc.es

#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;

	// Estructura especial para almacenar resultados de consultas 

	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int cantidad, puntos;
	char nombre[20];
	char consulta [80];

	//Creamos una conexion al servidor MYSQL 

	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	//inicializar la conexion

	conn = mysql_real_connect (conn, "localhost","user", "pass", "Tablas",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	printf ("Vamos a buscar la ultima partida que se jugo y cuantas veces aparecio cada prueba, que pruebas eran y cuantos puntos daban.\n"); 

	// consulta SQL para obtener una tabla los datos que queremos
	// de la base de datos

	err=mysql_query (conn, "SELECT Pruebas.Nombre, Juegos.Cantidad, Pruebas.Puntos FROM (Juegos, Pruebas)
	WHERE Juegos.idP = SELECT MAX(Historial.idP) FROM (Historial)
	AND Juegos.idPb = Pruebas.idPb");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}

	//recogemos el resultado de la consulta. El resultado de la
	//consulta se devuelve en una variable del tipo puntero a
	//MYSQL_RES tal y como hemos declarado anteriormente.
	//Se trata de una tabla virtual en memoria que es la copia
	//de la tabla real en disco.

	resultado = mysql_store_result (conn);

	// El resultado es una estructura matricial en memoria
	
	// Ahora obtenemos la primera fila que se almacena en una
	// variable de tipo MYSQL_ROW

	row = mysql_fetch_row (resultado);

	// En una fila hay tantas columnas como datos tiene una
	// la busqueda que queremos. En nuestro caso hay tres columnas: cuantas pruebas(row[0]),
	// nombre de la prueba(row[1]) y cuantos puntos(row[2]).

	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			// las columnas 1 y 2 contienen una palabra que son la cantidad y los puntos
			// las convertimos a entero 

			cantidad = atoi (row[1]);
			puntos = atoi (row[2]);

			// la columna 1 tiene el nombre y las 2 siguientes los puntos y el numero de veces jugados.

			printf ("La prueba: %s, se ha jugado %s veces y da: %d puntos\n", row[0], cantidad, puntos);

			// obtenemos la siguiente fila

			row = mysql_fetch_row (resultado);
	}

		// cerrar la conexion con el servidor MYSQL 

		mysql_close (conn);
		exit(0);
}