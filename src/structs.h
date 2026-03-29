#include <stdio.h>
#include <stdint.h>

// Enum for names to reduce state's board data
typedef enum pieces{
	W_KING,
	W_QUEEN,
	W_ROOK,
	W_BISHOP,
	W_KNIGHT,
	W_PAWN,
	B_KING,
	B_QUEEN,
	B_ROOK,
	B_BISHOP,
	B_KNIGHT,
	B_PAWN
};

typedef enum castlingAbility{
	WHITE_KINGSIDE,
	WHITE_QUEENSIDE,
	WHITE_BOTH,
	BLACK_KINGSIDE,
	BLACK_QUEENSIDE,
	BLACK_BOTH
};

typedef enum activePiece{
	WHITE,
	BLACK
};

// We use a single byte to keep track of en-passant-able squares for each color.
// Each pawn-rank square is a bit in the color's byte. We can flip bits using 
// the appropriate bit-flip mask and the bitwise exclusive OR operator (^).
// This enum defines all needed bit-flip masks.
typedef enum enPassBitManips{
	C1 = 0x80,
	C2 = 0x40,
	C3 = 0x20,
	C4 = 0x10,
	C5 = 0x08,
	C6 = 0x04,
	C7 = 0x02,
	C8 = 0x01
};

// Struct to represent game state. Equivalent in meaning to FEN.
typedef struct State{
	uint8_t board[12][12]; // We are using the 'Mailbox' board representation
	uint8_t activeColor;
	uint8_t whiteCastlingAbility;
	uint8_t blackCastlingAbility;
	uint8_t whiteEnPassant;
	uint8_t blackEnPassant;
	uint8_t halfmoveClock;
	uint8_t fullmoveNumber;
};
