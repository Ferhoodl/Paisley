#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdint.h>

// Enum for names to reduce state's board data
// uppercase is white. Lowercase is black
enum Pieces{
	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN,
	king,
	queen,
	rook,
	bishop,
	knight,
	pawn	
};

// Struct to represent game state. Equivalent in meaning to FEN.
typedef struct State{
	uint8_t board[120]; // We are using the 'Mailbox' board representation
	char turn; // w or b

	struct{
		unsigned int whiteCastleKingside  : 1;
		unsigned int whiteCastleQueenside : 1;
		unsigned int blackCastleKingside  : 1;
		unsigned int blackCastleQueenside : 1;
	} castlingAbilities;

	uint8_t whiteEnPassant;
	uint8_t blackEnPassant;

	uint8_t halfmoveClock;
	uint8_t fullmoveNumber;
};

#endif
