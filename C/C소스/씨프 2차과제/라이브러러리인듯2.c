#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_COLS 100000

int mapping(char c);
int highcard(char* player1, char* player2);
int pokerhands(char* player, int card[]);
void sort(int n[]);

int b[6], w[6];
int b_count=0;
void main() {
    FILE* f = fopen("input.txt", "rt");
    char s[MAX_COLS];
    while (fgets(s, MAX_COLS, f) != NULL) {
        int result = 0;
        char black[15];
        char white[15];
        white[14] = '\0';
        black[14] = '\0';
        memcpy(black, s, sizeof(char) * 14);
        memmove(white, s+15, sizeof(char) * 14);
        int i, j=0;
        
      for(i=0;i<13;i=i+3) {
            b[j] = mapping(black[i]);
            j++;
        }
        sort(b);
        j = 0;
        for(i=0;i<13;i=i+3) {
            w[j] = mapping(white[i]);
            j++;
        }
        sort(w);

        int rw, rb;
        rb = pokerhands(black, b); 
        rw = pokerhands(white, w); 

        if(rb > rw)
            b_count++;
        else if(rb < rw)
            printf("");//printf("White win!!\n");
        else if(rb == rw && rb!=0) {
            if(b[5] > w[5])
                b_count++;
            /*if(b[5] < w[5])
                printf("White win!!\n");
            if(b[5] == w[5])
                printf("tie!!\n");*/
        }
        else {
            int result = highcard(black, white);
            if(result == 0)
                b_count++;
            /*else if(result == 1)
                printf("White win!!\n");
            else 
                printf("tie!!\n");*/
        }
    }




    printf("total result b win %d", b_count);
}

// 0 player1 win || 1 player2 win || 2 tie
int highcard(char* player1, char* player2) {  
    int result = 2;
    int index  = 4;

    while(index>=0) {
        if(b[index] > w[index]) {
            result = 0;
            break;
        }
        if(b[index] < w[index]) {
            result = 1;
            break;
        }
        if(b[index] == w[index]) index--;
    }
    return result;
}

//straigt flush 8
//four card 7
//full house 6
//flush  5
//straigt  4
//three card 3
//two pair  2
//one pair  1

int pokerhands(char* player, int card[]) {
    bool straight_flush = true;
    bool flush = true;
    bool straight = true;
    char temp = player[1];
    int i = 0;
    for(i=4;i<13;i=i+3) {
        if(temp != player[i]) {
            straight_flush = false;
            flush = false;
        }
        temp = player[i];
    }
    
    for(i=0 ; i<5 ;i++) {
        if(card[0]+i != card[i]) {
            straight_flush = false;
            straight = false;
        }
    }

    if(straight_flush) {
        card[5] = card[4]; 
        //printf("straight flush!!!\n");
        return 8;
    }

    //------------------------------------
    bool four_card = false;
    bool three_card = false;
    bool one_pair = false;
    int count = 0;
   int j = 0;
    for(i=0 ; i<13 ;i=i+3) {
        count = 0;
        for(j=0 ; j<13 ;j=j+3) {
            if(mapping(player[i]) == mapping(player[j])) {
                count++;
                if(4==count) {
                    four_card = true;
                    card[5] = mapping(player[j]);
                }
                if(3==count) {
                    three_card = true;
                    card[5] = mapping(player[j]);
                }
                if(2==count) {
                    one_pair = true;
                    card[5] = mapping(player[j]);
                }
            }
        }
    }

    if(four_card) {
        //printf("four card!!!!\n");
        return 7;
    }
    //------------------------------------

    //------------------------------------
    bool full_house = false;
    bool two_pair = false;
    int f=0;
    j=0;
    for(i=0;i<5;i++) {
        if(card[j] == card[i])
            continue;
        else {
            j = i;
            f++;
        }
    }
    if(f == 1) full_house = true;
    if(f == 2) two_pair = true;
    if(full_house) {
        card[5] = card[2];
        //printf("full house!!!!\n");
        return 6;
    }
    //------------------------------------

    if(flush) {
        card[5] = card[4];
        //printf("flush!!!!\n");
        return 5;
    }
    if(straight) {
        card[5] = card[4];
        //printf("straight!!!!\n");
        return 4;
    }
    if(three_card) {
        //printf("three card!!!!\n");
        return 3;
    }

    if(two_pair) {
        card[5] = card[3];
        //printf("two_pair!!!!\n");
        return 2;
    }

    if(one_pair) {
        //printf("one_pair!!!!\n");
        return 1;
    }

    return 0;
}

int mapping(char c) {
    int val = 0;

    if(c=='A') val = 14;
    else if(c=='K') val = 13;
    else if(c=='Q') val = 12;
    else if(c=='J') val = 11;
    else if(c=='T') val = 10;
    else val = c-48;

    return val;
}

void sort(int n[]) {
    int min = 100;
    int temp, i, j;
    int index = 0;
    for(i = 0 ; i < 5; i++) {
        min = 100;
        for(j = i ; j<5; j++) {
            if(min > n[j]) {
                min = n[j];
                index = j;
            }
        }
        temp = n[i];
        n[i] = n[index];
        n[index] = temp;
    }
}
