#ifndef H_FUNCTIONS
#define H_FUNCTIONS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

struct product
{
    char name[N];
    float quantity_value;
    char quantity_unit[N];
    float price_value;
    char price_unit[N];
    struct product *next;
};

struct product *init(void);

// insert a node to the list
void insert(struct product **head, char name[], float quantity_value, char quantity_unit[], float price_value, char prince_unit[]);
//int insert(struct product **head, struct product node);

// remove a node from list
void rmItem(struct product *head, char *name);

// show list
void showList(struct product *l);

// load data from file inf
struct product *loadData(struct product *l);

void inventory(struct product *l);

// save data to file outf
void saveData(struct product *l);

// sell product product of quantity 
float purchase(struct product *l, char *name, int quantity);

// check out price of product p from list l
void check_price(struct product *l, char *name);

// find a product p from list l
int findItem(struct product *l, char *name);

void printMenu();

void doIt();
#endif
