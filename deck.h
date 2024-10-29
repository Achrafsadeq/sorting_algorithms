#ifndef DECK_H
#define DECK_H

#include <stdio.h>

/**
 * enum kind_e - Enumeration for card suits.
 *
 * @SPADE: Represents the spade suit.
 * @HEART: Represents the heart suit.
 * @CLUB: Represents the club suit.
 * @DIAMOND: Represents the diamond suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card.
 *
 * @value: The face value of the card, from "Ace" to "King".
 * @kind: The suit of the card, represented by `kind_t`.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node structure for a doubly linked list
 * representing a deck of cards.
 *
 * @card: Pointer to the card contained in this node.
 * @prev: Pointer to the previous node in the deck.
 * @next: Pointer to the next node in the deck.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function Prototypes */
void sort_deck(deck_node_t **deck);
int less_than(const card_t *a, const card_t *b);
void cocktail_sort_list(deck_node_t **list);

#endif /* DECK_H */
