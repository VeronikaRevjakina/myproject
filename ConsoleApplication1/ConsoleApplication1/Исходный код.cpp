
#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void error(char *mess)
{
	fprintf(stderr, "### %s\n", mess);
	exit(1);
}

int main(int argc, char **argv)
{
	int nFields,  i, j;
	PGresult *res1,*res2;

	//connect to database

	PGconn *conn = PQconnectdb(" dbname=v.revjakina user=postgres password=5114938w ");

	if (PQstatus(conn) != CONNECTION_OK)
		error(PQerrorMessage(conn));

	

	
	res1 = PQexec(conn, "SELECT * FROM sportsmen");
	if (PQresultStatus(res1) != PGRES_TUPLES_OK)
		error(PQresultErrorMessage(res1));

	nFields = PQnfields(res1);
	

	/* first, print out the attribute names */
	nFields = PQnfields(res1);
	for (i = 0; i < nFields; i++)
		printf("%-15s", PQfname(res1, i));
	printf("\n\n");

	/* next, print out the rows */
	for (i = 0; i < PQntuples(res1); i++)
	{
		for (j = 0; j < nFields; j++)
			printf("%-15s", PQgetvalue(res1, i, j));
		printf("\n");
	}

	res2 = PQexec(conn, "SELECT * FROM sportsmen where id=1");
	if (PQresultStatus(res2) != PGRES_TUPLES_OK)
		error(PQresultErrorMessage(res2));

	nFields = PQnfields(res2);

	/* first, print out the attribute names */
	nFields = PQnfields(res2);
	for (i = 0; i < nFields; i++)
		printf("%-15s", PQfname(res2, i));
	printf("\n\n\n\n\n\n\n\n");

	/* next, print out the rows */
	for (i = 0; i < PQntuples(res2); i++)
	{
		for (j = 0; j < nFields; j++)
			printf("%-15s", PQgetvalue(res2, i, j));
		printf("\n");
	}

	
	

	//disconnect
	PQfinish(conn);
	return 0;
}