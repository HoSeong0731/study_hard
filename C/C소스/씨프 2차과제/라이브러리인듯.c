#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shuffle(int wDeck[][ 13 ] );
void deal (int wDeck[] [ 13 ], const char *wFace[], const char *wSuit[] );

int main(void)
{
 const char *suit[ 4 ] = {"¢À", "¡Þ", "¢½", "¢¼"};

 const char *face[ 13 ] =
 {"2", "3", "4", "5",
 "6", "7", "8", "9",
 "10", "J", "Q", "K", "A"};

 int deck[4][13] = {0};
 int winner;

 srand((unsigned int)time(0));

 shuffle(deck);
 deal(deck, face, suit);

    winner = check_win(deck, face, suit);
    printf("Player%d Winer\n", winner);

     return (0);

}

void shuffle(int wDeck[][13])
{
 int row;
 int column;
 int card;

 for (card = 1; card <=52; card++) {

  do {
   row = rand() % 4;
   column = rand() % 13;
  } while(wDeck[row][column] !=0);

  wDeck[row][column] = card;
 }
}

void deal(int wDeck[][13], const char *wFace[], const char *wSuit[]){
 int card;
 int row;
 int column;
 int i;

 for (card = 1; card <= 10; card++){
  for ( row = 0; row <= 3; row++){
   for (column = 0; column <= 12; column++) {
    if (wDeck[row][column] == card) {
     if(card ==1){
      printf("Player1's Card \n");
      i=1;
     }
     if(card ==6){
      printf("Player2's Card \n");
      i=1;
     }
     printf("\t Card %1d: %s%s   \n", i,  wSuit[row], wFace[column]);
     i++;
    }
   }
  }
 }
 printf("\n");
}

enum CARD_SUIT { UNDEF, SPADE, DIAMOND, HEART, CLOVER };

struct Card
{
    int suit;
    int face;
};

int get_suit(char *suit)
{
    if( strcmp(suit, "¢À") )
        return CLOVER;
    else if( strcmp(suit, "¡Þ") )
        return DIAMOND;
    else if( strcmp(suit, "¢½") )
        return HEART;
    else if( strcmp(suit, "¢¼") )
        return SPADE;
    else
        return UNDEF;
}

int get_face(char *face)
{
    int ret = 0;

        if( face[0] == 'J' )
        ret = 11;
    else if( face[0] == 'Q' )
        ret = 12;
    else if( face[0] == 'K' )
        ret = 13;
    else
        ret = strtol(face, NULL, 10);
    return ret;
}

enum CARD_LEVEL { RSF, SF, FULL_HOUSE, FLUSH, STRAIT, TRIPLE, TOW_PAIR, ONE_PAIR, TOP };

int get_card_level(struct Card p_card[])
{
    // check RSF, SF, FLUSH
    int flush_flag;
    int strait_flag;
	
	int i, j;
	flush_flag = 1;
    for( i=1 ; i<5 ; i++ ) {
        if( p_card[0].suit != p_card[i].suit ) {
            flush_flag = 0;
            break;
        }
    }

        // sort card
    for( i=4 ; i>0 ; i-- ) {
        for( j=i ; j>0 ; j-- ) {
            if( p_card[j].face < p_card[j-1].face ) {
                tmp_card = p_card[j];
                p_card[j] = p_card[j-1];
                p_card[j-1] = tmp_card;
            }
        }
    }

        // strait check
    strait_flag = 1;
    for(;0;);

        // if both not other check

    }

struct Card find_card(int card)
{
    int row, col;
    struct Card ret = { 0, };

        for( row=0 ; row<4 ; row++ ) {
        for( col=0 ; col<13 ; col++ ) {
            if( wDeck[row][col] == card ) {
                ret.suit = get_suit( wSuit[row] );
                ret.face = get_face( wFace[col] );
                return ret;
            }
        }
    }
    return ret;
}
int check_win(int wDeck[][13], const char* wFace[], const char* wSuit[])
{
    struct Card player1[5], player2[5];
    int idx;
    int p1_level, p2_level;

        idx = 0;
    for( card=1 ; card<=5 ; card++ )
    {
        player1[idx] = find_card(wDeck, card);
        ++idx;
    }   

        idx = 0;
    for( card=6 ; card<=10 ; card++ )
    {
        player2[idx] = find_card(card);
        ++idx;
    }

        p1_level = get_card_level(player1);
    p2_level = get_card_level(player2);
    if( p1_level > p2_level )
        return 1;
    else if( p1_level < p2_level )
        return 2;
    else
        return detail_check(p1_level, player1, player2);
}
