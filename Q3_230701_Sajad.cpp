#include <stdio.h>

          
struct Card {
    int s;                      // Define card structure
    int r;
};


int rank(void) {
    int r = getchar();
                                // Function to get rank of a card
    if (r == 84)
        return 10;
    if (r == 74)
        return 11;
    if (r == 81)
        return 12;
    if (r == 75)
        return 13;
    if (r == 65)
        return 14;
    return r - 48;
}


int suit(void) {
    int s = getchar();
                                    // Function to get suit of a card
    if (s == 68)
        return 0;
    if (s == 83)
        return 1;
    if (s == 72)
        return 2;
    return 3;
}


int search(struct Card hand[], int n) {
    int i;                                   // Function to search for a card with a given rank in a hand

    for (i = 0; i < 5; i++) {
        if (hand[i].r == n)
            return 1;
    }

    return 0;
}


int isStraight(struct Card hand[], int *type) {
    int i, min;
                                                    // Function to check if hand contains a straight
    min = 20;

    for (i = 0; i < 5; i++)
        if (hand[i].r < min)
            min = hand[i].r;

    if (search(hand, min + 1))
        if (search(hand, min + 2))
            if (search(hand, min + 3))
                if (search(hand, min + 4)) {
                    *type = min + 4;
                    return 1;
                }

    return 0;
}


int isStraightFlush(struct Card hand[]) {                       // Function to check if hand contains a straight flush
    int s = hand[0].s;
    int i;

    for (i = 1; i < 5; i++)
        if (hand[i].s != s)
            return 0;

    return 1;
}


int isRoyal(struct Card hand[]) {                            // Function to check if hand contains a royal flush
    if (search(hand, 14))
        return 1;
    return 0;
}

                                                            // Function to check if hand contains four of a kind
int isFour(struct Card hand[], int *type) {
    if (hand[0].r == hand[1].r && hand[1].r == hand[2].r && hand[2].r == hand[3].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[1].r && hand[1].r == hand[2].r && hand[2].r == hand[4].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[1].r && hand[1].r == hand[3].r && hand[3].r == hand[4].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[2].r && hand[2].r == hand[3].r && hand[3].r == hand[4].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[1].r == hand[2].r && hand[2].r == hand[3].r && hand[3].r == hand[4].r) {
        *type = hand[1].r;
        return 1;
    }
    return 0;
}


int isThree(struct Card hand[], int *type) {                              // Function to check if hand contains three of a kind
    if (hand[0].r == hand[1].r && hand[1].r == hand[2].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[1].r && hand[1].r == hand[3].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[1].r && hand[1].r == hand[4].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[3].r && hand[3].r == hand[4].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[2].r && hand[2].r == hand[3].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[0].r == hand[2].r && hand[2].r == hand[4].r) {
        *type = hand[0].r;
        return 1;
    }
    if (hand[2].r == hand[3].r && hand[3].r == hand[4].r) {
        *type = hand[2].r;
        return 1;
    }
    if (hand[1].r == hand[2].r && hand[2].r == hand[3].r) {
        *type = hand[1].r;
        return 1;
    }
    if (hand[1].r == hand[2].r && hand[2].r == hand[4].r) {
        *type = hand[1].r;
        return 1;
    }
    if (hand[1].r == hand[3].r && hand[3].r == hand[4].r) {
        *type = hand[1].r;
        return 1;
    }

    return 0;
}

int isFull(struct Card hand[], int *type) {
    int second;                                                            
                                                                // Function to check if hand contains a full house
    int i = 0;
    while (hand[i].r == *type)
        i++;
    second = hand[i].r;

    for (i = i + 1; i < 5; i++) {
        if (hand[i].r != *type && hand[i].r != second)
            return 0;
    }
    return 1;
}

int isPair(struct Card hand[], int *type) {
    int i, j;                                                  
                                                        // Function to check if hand contains a pair

    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (hand[i].r == hand[j].r) {
                *type = hand[i].r;
                return 1;
            }

    return 0;
}

int isTwoPairs(struct Card hand[], int *type, int *secondType) {                                             
                                                                            // Function to check if hand contains two pairs
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (hand[i].r == hand[j].r && hand[i].r != *type) {
                if (hand[i].r < *type) {
                    *secondType = hand[i].r;
                    return 1;
                } else {
                    *secondType = *type;
                    *type = hand[i].r;
                    return 1;
                }

            }

    return 0;
}

                                                                                         // Function to find highest card in hand with two pairs
int findHighDouble(struct Card hand[], int *type, int *secondType, int *highCard) {
    int i;

    for (i = 0; i < 5; i++)
        if (hand[i].r != (*type) && hand[i].r != (*secondType)) {
            *highCard = hand[i].r;
            return 1;
        }

    return 0;
}

                                                                                      // Function to find highest card in hand with one pair
int findHighSimple(struct Card hand[], int *type, int *highCard) {
    int i;
    int max = 0;

    for (i = 0; i < 5; i++)
        if (hand[i].r != *type && hand[i].r > max) {
            max = hand[i].r;
        }

    *highCard = max;
    return 1;
}

                                                                                      // Function to find highest card in hand
int findHigh(struct Card hand[], int *highCard) {
    int i;
    int max = 0;

    for (i = 0; i < 5; i++)
        if (hand[i].r > max)
            max = hand[i].r;

    *highCard = max;
    return 1;
}

                                                                                   // Function to check if hand contains a flush
int isFlush(struct Card hand[], int *highCard) {
    int i;
    int suit;

    suit = hand[0].s;

    for (i = 1; i < 5; i++)
        if (hand[i].s != suit)
            return 0;

    return 1;
}

                                                                                       // Function to assign points to a hand based on its strength
int getPoints(struct Card hand[], int *type, int *highCard, int *secondType) {
    if (isFour(hand, type))
        return 8;
    if (isThree(hand, type)) {
        if (isFull(hand, type))
            return 7;
        else
            return 4;
    }

    if (isStraight(hand, type)) {
        if (isStraightFlush(hand)) {
            if (isRoyal(hand))
                return 10;
            else
                return 9;
        }
        return 5;
    }

    if (isFlush(hand, highCard))
        return 6;

    if (isPair(hand, type)) {
        if (isTwoPairs(hand, type, secondType)) {
            findHighDouble(hand, type, secondType, highCard);
            return 3;
        } else {
            findHighSimple(hand, type, highCard);
            return 2;
        }
    }

    findHigh(hand, highCard);
    return 1;

}

                                                                                   // Function to find winner between two hands
int findWinner(struct Card hand1[], struct Card hand2[]) {
    int points1, points2;
    int type1, highCard1, type2, highCard2;
    int secondType1, secondType2;

    points1 = getPoints(hand1, &type1, &highCard1, &secondType1);
    points2 = getPoints(hand2, &type2, &highCard2, &secondType2);

    printf("points1 = %d points2 = %d\n", points1, points2);

    if (points1 > points2)
        return 1;
    else if (points2 > points1)
        return 0;
    else {
        if (points1 == 1) {
            if (highCard1 > highCard2)
                return 1;
            else
                return 0;
        }
        if (points1 == 2) {
            if (type1 > type2)
                return 1;
            else if (type2 > type1)
                return 0;
            else {
                if (highCard1 > highCard2)
                    return 1;
                else
                    return 0;
            }
        }
        if (points1 == 3) {
            if (type1 > type2)
                return 1;
            else if (type2 > type1)
                return 0;
            else {
                if (secondType1 > secondType2)
                    return 1;
                else if (secondType2 > secondType1)
                    return 0;
                else {
                    if (highCard1 > highCard2)
                        return 1;
                    else
                        return 0;
                }
            }
        }
        if (points1 == 4) {
            if (type1 > type2)
                return 1;
            else
                return 0;
        }
        if (points1 == 5) {
            if (type1 > type2)
                return 1;
            else
                return 0;
        }
        if (points1 == 9) {
            if (type1 > type2)
                return 1;
            else
                return 0;
        }
        if (points1 == 6) {
            if (highCard1 > highCard2)
                return 1;
            else
                return 0;
        }
    }

    return 2;
}


int main() {
    struct Card h1[5];
    struct Card h2[5];
    int i, r;
    int w = 0;

    for (r = 0; r < 1000; r++) {

        
        for (i = 0; i < 4; i++) {         //Geting input from user 1
            h1[i].r = rank();
            h1[i].s = suit();
            getchar();
        }
        h1[4].r = rank();
        h1[4].s = suit();
        getchar();

        for (i = 0; i < 4; i++) {
            h2[i].r = rank();                      //Geting input from user 2
            h2[i].s = suit();
            getchar();
        }
        h2[4].r = rank();
        h2[4].s = suit();
        getchar();
        getchar();

        if (findWinner(h1, h2)) {
            printf("Player One Win\n");
            w++;
        } else
            printf("Player Two Win\n");

    }

    printf("Player One wins %d\n ", w);
    printf("Player Two wins %d \n", 1000 - w);

    return 0;
}

