#include <stdio.h>
#include <stdlib.h>
#include "parkingFinder.h"
  
 
int main() {

    // COMPLETAR
  
    // A Continuacion dejamos algunos ejemplos de como
    // llama a las funciones pedidas. Este codigo debe
    // ser borrado / modificado.


    // strDuplicate
    char* dup = strDuplicate("hola");
    printf("strDuplicate(\"hola\") -> \"%s\"\n", dup);
    free(dup);

    // strCompare
    printf("strCompare(\"abc\",\"abc\") -> %i\n", strCompare("abc","abc"));
    printf("strCompare(\"abcd\",\"abc\") -> %i\n", strCompare("abcd","abc"));
    printf("strCompare(\"abc\",\"abcd\") -> %i\n", strCompare("abc","abcd"));

    // strConcatenate
    char* concat = strConcatenate(strDuplicate("123"),strDuplicate("456"));
    printf("strConcatenate(\"123\",\"456\") -> \"%s\"\n", concat);
    free(concat);

    // Estructura parkingFinder
    struct parkingFinder* pf = parkingFinderNew("Zapiola 400");

    // Crear una parkingFinder con distintos autos ubicados
    parkingFinderAddLast(pf, FREE, 100, 0);
    parkingFinderAddLast(pf, FREE, 100, 0);
    parkingFinderAddLast(pf, TAKEN, 10, "AAA123");
    parkingFinderAddLast(pf, TAKEN, 10, "BBB123");
    parkingFinderAddLast(pf, FREE, 100, 0);
    parkingFinderAddLast(pf, TAKEN, 10, "CCC123");
    parkingFinderAddLast(pf, FREE, 100, 0);
    parkingFinderAddLast(pf, TAKEN, 10, "DDD123");

    // Imprimir un parkingFinder
    char * plates = parkingFinderGetPlates(pf);
    printf("%s\n",plates);
    free(plates);

    // Imprimir un parkingFinder
    parkingFinderPrint(pf);

    // Liberar algunos
    printf("DEL AAA123 = %i\n",parkingFinderReleaseSpace(pf, "AAA123"));
    printf("DEL XXX000 = %i\n",parkingFinderReleaseSpace(pf, "XXX000"));
    printf("DEL DDD123 = %i\n",parkingFinderReleaseSpace(pf, "DDD123"));

    // Imprimir un parkingFinder
    parkingFinderPrint(pf);

    // Ubicar dos mas
    printf("ADD MRP170 = %i\n",parkingFinderFindSpace(pf, "MRB170", 5.2));
    printf("ADD XXXXXX = %i\n",parkingFinderFindSpace(pf, "XXXXXX", 1000));

    // Imprimir un parkingFinder
    plates = parkingFinderGetPlates(pf);
    printf("%s\n",plates);
    free(plates);

    // Imprimir un parkingFinder
    parkingFinderPrint(pf);

    // Borrar un parkingFinder
    parkingFinderDelete(pf);

    return 0;
}
