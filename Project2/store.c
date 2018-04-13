#include "store.h"

struct product *init(){
    struct product *head = (struct product*) malloc(sizeof(struct product));
    head->next = NULL;
    return head;
}

void insert(struct product** head, char name[], float quantity_value, char quantity_unit[], float price_value, char price_unit[]){
    
    int found = 0;
    
    struct product *temp = (struct product*) malloc(sizeof(struct product));
    struct product *temp2 = (struct product*) malloc(sizeof(struct product));
    
    temp2 = *head;
    
//    found = findItem(temp2, temp2->name);
    
//    printf("%d", found);
    
//    if (!found){
    strcpy(temp->name, name);
    temp->quantity_value = quantity_value;
    strcpy(temp->quantity_unit, quantity_unit);
    temp->price_value = price_value;
    strcpy(temp->price_unit, price_unit);
    temp->next = NULL;

    temp->next = *head;
    *head = temp;
//    }else{
//        temp->quantity_value += quantity_value;
//    }
    
}

void rmItem(struct product* head, char* name){
    int found = 0;
    struct product *temp = (struct product*) malloc(sizeof(struct product));
    head = (struct product*) malloc(sizeof(struct product));
    temp = head;
    
    if(strcmp(head->name, name) == 0){
        temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
    else
        rmItem(head->next, name);
    
}


void inventory(struct product* head){
    struct product *temp = head;
    if (temp != NULL){
        printf("Product Name: %s\n", temp->name);
        printf("Product Quantity: %.2f\n", temp->quantity_value);
        printf("Product Unit(s): %s\n", temp->quantity_unit);
        printf("Product Price: $%.2f\n", temp->price_value);
        printf("Product Price Per Unit: %s\n\n", temp->price_unit);
        temp = temp->next;
    }
}

void showList(struct product* head){
//    head = init();
    struct product *temp = head;
//    temp = head;
    if(temp != NULL){
    while (temp != NULL) {
        inventory(temp);
        if(temp->next == NULL)
            break;
            temp = temp->next;
    }
    }
    else{
        printf("List is Empty\n");
    }
}

int findItem(struct product* head, char* name){
    struct product* temp = head;
    struct product* found = NULL;
    int booFound = 0;
    while (found == NULL) {
        if (temp == NULL) {
            printf("Item Not Found\n");
            break;
        }
        if (strcmp(temp->name, name) == 0) {
            found = temp;
            booFound = 1;
            break;
        }else{
            temp = temp->next;
        }
    }
    return booFound;
}

void check_price(struct product* head, char* name){
    struct product* temp = head;
//    temp = findItem(head, name);
    printf("The price of %s is $%2.f", name, temp->price_value);
}

/**************************************************************
 * FIXME
 **************************************************************/
float purchase(struct product* head, char* name, int quantity){
    float storeReturn;
    struct product *temp = head;
    temp->next->quantity_value = temp->next->quantity_value - quantity;
    storeReturn = temp->next->price_value * quantity;

    return storeReturn;
}

void printMenu(){
    printf("\t\t\t\t\tWelcome to Aron's Grocery Store\n");
    printf("Please let me know what you what you want to do by typing one of the numbers\n");
    printf("============================================================================\n");
    printf("0: Add product to store                  1: Purchase product from store\n\n");
    printf("2: Check price of a product              3: Show products in store\n\n");
    printf("4: Remove a product from a store         5: Find product\n\n");
    printf("6: Inventory                             7: Done for today\n\n");
    printf("8: Load Data                             9: Display Menu\n\n");
    printf("What do you want to do?\n\n");
}

struct product *loadData(struct product *head){
    char localName[N];
    float localQuantityValue = 0.0;
    char localQuantityUnit[N];
    float localPriceValue = 0.0;
    char localPriceUnit[N];
    int num;
    char *fn = "data";
    struct product *temp = head;
    
    FILE * fin = fopen(fn, "r");
    FILE * fout = fopen(fn, "a");
    
    if(fin == NULL) {
        printf("InLoad: File open failed (%s)\n\nCreating new file\n", fn);
        fgetc(fout);
        return NULL;
    }else{
        printf("File found loading (%s)\n", fn);
    }
        
        while(1){
            num = fscanf(fin, "%s %f %s %f %s\n", localName, &localQuantityValue, localQuantityUnit, &localPriceValue, localPriceUnit);
            if (num != 5){
                break;
            }
            insert(&temp, localName, localQuantityValue, localQuantityUnit, localPriceValue, localPriceUnit);
        }
        
    
    
    fclose(fin);
    return temp;
}


void saveData(struct product * head){
    char *fn = "data";
    FILE * fout = fopen(fn, "a");
    if(fout == NULL) {
        printf("InSave: File open failed (%s)\n", fn);
        return;
    }
    struct product * current = head;
    while (current != NULL) {
        fprintf(fout, "%s %f %s %f %s\n", current->name, current->quantity_value, current->quantity_unit, current->price_value, current->price_unit);
        current = current->next;
    }
    fclose(fout);
}

void doIt(){
    struct product *head = NULL;
    struct product *temp = NULL;
    printMenu();
    int choice;
    int open = 1;
    
    float quantity, price;
    static float total = 0.0;
    
    char fileName[N];
    char localName[N];
    
    float localQuantity = 0;
    char localQuantityUnit[N];
    float localPrice = 0;
    char localPriceUnit[N];

//    temp = head;
    
//    if (temp == NULL) {
        head = loadData(temp);
//    }
    
    while (open) {
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("\n");
                fflush(stdin);
                printf("Enter Product Name\n");
                scanf("%s", localName);
                fflush(stdin);
                printf("Enter Product Quantity\n");
                scanf("%f", &localQuantity);
                fflush(stdin);
                printf("Enter Quantity Unit (pounds, bottles, pieces, etc)\n");
                scanf("%s", localQuantityUnit);
                fflush(stdin);
                printf("Enter Product Price\n");
                scanf("%f", &localPrice);
                fflush(stdin);
                printf("Enter Price Unit (dollars-per-pound, dollars-per-bottle, dollars-each)\n");
                scanf("%s", localPriceUnit);
                fflush(stdin);
                
                insert(&head, localName, localQuantity, localQuantityUnit, localPrice, localPriceUnit);
                
                printf("\n");
                printMenu();
                break;
                
            case 1:
                localQuantity = 0;
                fflush(stdin);
                printf("Enter Product Name\n");
                scanf("%s", localName);
                fflush(stdin);
                printf("Enter Quantity\n");
                scanf("%s", localName);
                fflush(stdin);
                purchase(head, localName, localQuantity);
                free(localName);
                break;
                
            case 2:
                fflush(stdin);
                printf("Enter Product Name\n");
                scanf("%s", localName);
                fflush(stdin);
                check_price(head, localName);
                break;
                
            case 3:
                showList(head);
                break;
                
            case 4:
                temp = head;
                fflush(stdin);
                printf("Enter Product Name\n");
                scanf("%s", localName);
                fflush(stdin);
                rmItem(temp, localName);
                break;
                
            case 5:
                fflush(stdin);
                struct product* temp = head;
                printf("Enter Product Name\n");
                scanf("%s", localName);
                fflush(stdin);
//                temp = findItem(head, localName);
                findItem(head, localName);
                printf("Found %s\n", temp->name);
                break;
                
            case 6:
                printf("6");
                
                break;
                
            case 7:
                open = 0;
                temp = head;
                saveData(temp);
                free(head);
                break;
                
            case 8:
                temp = head;
                fflush(stdin);
                printf("Enter Filename Name\n");
                scanf("%s", fileName);
                head = loadData(temp);
                fflush(stdin);
                
            case 9:
                printMenu();
                
                
        }
    }
    
}
