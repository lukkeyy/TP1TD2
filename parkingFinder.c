#include "parkingFinder.h"

char* strDuplicate(char* src) {

    // COMPLETAR

    return 0;
}

int strCompare(char* a, char* b) {

    // COMPLETAR

    return 0;
}

char* strConcatenate(char* src1, char* src2) {

    // COMPLETAR

    return 0;
}

struct parkingFinder* parkingFinderNew(char* street) {
    struct parkingFinder* pf = (struct parkingFinder*) malloc(sizeof(struct parkingFinder));
    pf->street = strDuplicate(street);
    pf->first = 0;
    pf->last = 0;
    pf->totalLength = 0.0;
    pf->freeLength = 0.0;
    return pf;
}

void parkingFinderAddLast(struct parkingFinder* parking, int status, float length, char* plate) {

    // COMPLETAR

}

int parkingFinderReleaseSpace(struct parkingFinder* parking, char* plate) {

    // COMPLETAR

    return 0;
}

int parkingFinderFindSpace(struct parkingFinder* parking, char* plate, float length) {

    // COMPLETAR

    return 0;
}

void parkingFinderSplit(struct parkingFinder* parking, struct parkingFinder** pTaken, struct parkingFinder** pFree) {

    // COMPLETAR
   
}

void parkingFinderPrint(struct parkingFinder* parking) {
    printf("%s : %f/%f\n",parking->street, parking->freeLength, parking->totalLength);
    struct node* n = parking->first;
    while(n != 0) {
        if(n->status == FREE) {
            printf("(%f)",n->length);
        } else {
            printf("[%f:%s]",n->length,n->plate);
        }
        n = n->next;
    }
    if(parking->first != 0) {
        printf("\n");
    }
}

char* parkingFinderGetPlates(struct parkingFinder* parking) {

    // COMPLETAR

    return 0;
}

void parkingFinderDelete(struct parkingFinder* parking) {
    struct node* n = parking->first;
    while(n != 0) {
        struct node* next = n->next;
        if(n->status == FREE) {
            free(n);
        } else {
            free(n->plate);
            free(n);
        }
        n = next;
    }
    free(parking->street);
    free(parking);
}

