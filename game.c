#include "card.h"

 int main(void) 
 {
     int game = 1;
     card* Deck;
    card *mainDeck = make_deck();
    Deck = shuffle(mainDeck);
    card* player;
    card* dealer;
    
    //shuufling of deck
    mainDeck = shuffle(Deck);
    int pTotal = 0; 
    int dTotal = 0;
    show(mainDeck);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nWelcome to the Moddle Casino\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nThis Casino offers one game ONLY\n");
    printf("            BLACK JACK!            ");
    printf("\n\nYou are playing the dealer. The first to hit 21 or \nbe the closest to it without going over wins");
    printf("\n\nYour cards are : ");
    player = deal(mainDeck); player->next = deal(mainDeck);
    pTotal += total(player);
    player = player->next;
    printf("\n\nYour total is : %d\n",pTotal);
    
    printf("\nDealer's card : ");
    dealer = deal(mainDeck);
    dTotal += total(dealer);
    printf("\n\nThe Dealer's total is : %d",dTotal);
    
    //initializing the variables for Hit and for Stand
    char p[6];
    int hit = 0;
    printf("\n\nHit or Stand?\n");
    scanf("%s", p);
    
    //while loop that checks for any invalid inputs
    while(strcmp(p, "H") != 0 && strcmp(p, "h") != 0 && strcmp(p, "hit") != 0 && strcmp(p, "S") != 0 && strcmp(p, "s") != 0 && strcmp(p, "stand") != 0)
    {
            
        printf("Invalid input! TRY AGAIN\n");
        printf("hit or stand\n");
        scanf("%s", p);
    }
    
    while (strcmp(p, "H") == 0 || strcmp(p, "h") == 0 || strcmp(p, "hit") == 0)
        {
        printf("Your turn:");
        player = deal(mainDeck);
        pTotal += total(player);
        player = player->next;
        printf("\nYour total is : %d\n",pTotal);
        
        if (pTotal > 21)  
        {
            printf("-----------\nYOU LOST :(\n-----------\n\n");
            hit = 0;
            game = 0;
            break;
        }
        printf("Hit or Stand?\n");
        scanf("%s", p);
        while(strcmp(p, "H") != 0 && strcmp(p, "h") != 0 && strcmp(p, "hit") != 0 && strcmp(p, "S") != 0 && strcmp(p, "s") != 0 && strcmp(p, "stand") != 0)
            {
            printf("Invalid input! TRY AGAIN\n");
            printf("hit or stand\n");
            scanf("%s", p);
        }
    }
printf("Dealer's turn : ");
    if(game == 1){
        while(dTotal < 17)
        {
            dealer = deal(mainDeck);
            dTotal += total(dealer);
            dealer = dealer->next;
            
        }
        printf("\nDealer's total : %d\n",dTotal);
        if(dTotal > 21)
        {
            printf("-----------\nYOU WIN!!!!\n-----------\n\n");
        }else{
            if (dTotal >= pTotal)
            {
                printf("-----------\nYOU LOST :(\n-----------\n\n");
            }
            else
            {
                printf("-----------\nYOU WIN!!!!\n-----------\n\n");
                }
            }
        
        }
    destroy_deck(mainDeck);
    return 0;
 }
