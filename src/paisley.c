/****************************************\
 ======================================== 
                                          
                  PAISLEY                 
               Chess  Engine              
                                          
                    by                    
                                          
               Isaiah Steele              
                                          
 ======================================== 
\****************************************/

// SYSTEM HEADERS ===========================================

#include "base.h"

// ENUMS ====================================================

enum {
	a1, b1, c1, d1, e1, f1, g1, h1,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a8, b8, c8, d8, e8, f8, g8, h8
};

enum {white, black};


// BIT MANIPULATION MACROS =========================================

#define get_bit(bitboard, square) (bitboard & (1ULL << square))
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))
#define unset_bit(bitboard, square) (bitboard &= (0xFFFFFFFFFFFFFFFF ^ (1ULL << square)))
#define toggle_bit(bitboard, square) (bitboard ^= (1ULL << square))

// BIT MASKS ======================================================
const U64 A_FILE = 0x0101010101010101;
const U64 B_FILE = 0x0202020202020202;
const U64 C_FILE = 0x0404040404040404;
const U64 D_FILE = 0x0808080808080808;
const U64 E_FILE = 0x1010101010101010;
const U64 F_FILE = 0x2020202020202020;
const U64 G_FILE = 0x4040404040404040;
const U64 H_FILE = 0x8080808080808080;

const U64 AB_FILE = 0x0303030303030303;
const U64 GH_FILE = 0xC0C0C0C0C0C0C0C0;

const U64 ONE_COL	= 0x00000000000000FF;
const U64 TWO_COL	= 0x000000000000FF00;
const U64 THREE_COL	= 0x0000000000FF0000;
const U64 FOUR_COL	= 0x00000000FF000000;
const U64 FIVE_COL	= 0x000000FF00000000;
const U64 SIX_COL	= 0x0000FF0000000000;
const U64 SEVEN_COL	= 0x00FF000000000000;
const U64 EIGHT_COL	= 0xFF00000000000000;


// PRE-CALCULATED ATTACKS =========================================

U64 pawn_attacks[2][64];
U64 knight_attacks[64];

U64 mask_pawn_attacks(int side, int square){

	U64 attacks_bitboard = 0ULL;

	U64 piece_bitboard = 0ULL;
	set_bit(piece_bitboard, square);	

	if(side == white){
		attacks_bitboard |= ((piece_bitboard << 7) & ~H_FILE); // attack left (white perspective)
		attacks_bitboard |= ((piece_bitboard << 9) & ~A_FILE); // attack right (white perspective)
	}else if(side == black){
		attacks_bitboard |= ((piece_bitboard >> 7) & ~A_FILE); // attack left (black perspective)
		attacks_bitboard |= ((piece_bitboard >> 9) & ~H_FILE); // attack right (black perspective)
	}
	return attacks_bitboard;
}

U64 mask_knight_attacks(int square){
	U64 attacks_bitboard = 0ULL;

	U64 piece_bitboard = 0ULL;
	set_bit(piece_bitboard, square);

	attacks_bitboard |= ((piece_bitboard >> 6)  & ~AB_FILE);
	attacks_bitboard |= ((piece_bitboard >> 10) & ~GH_FILE);
	attacks_bitboard |= ((piece_bitboard >> 15) & ~A_FILE);
	attacks_bitboard |= ((piece_bitboard >> 17) & ~H_FILE);

	attacks_bitboard |= ((piece_bitboard << 6)  & ~GH_FILE);
	attacks_bitboard |= ((piece_bitboard << 10) & ~AB_FILE);
	attacks_bitboard |= ((piece_bitboard << 15) & ~H_FILE);
	attacks_bitboard |= ((piece_bitboard << 17) & ~A_FILE);

	return attacks_bitboard;
}


void init_pawn_attack_tables(){
	for(int square = 0; square < 64; square++){
		pawn_attacks[white][square] = mask_pawn_attacks(white, square);
		pawn_attacks[black][square] = mask_pawn_attacks(black, square);
	}
}

void init_knight_attack_tables(){
	for(int square = 0; square < 64; square++){
		knight_attacks[square] = mask_knight_attacks(square);
	}
}


// BOARD DEBUG PRINT =============================================

void print_bitboard(U64 bitboard){
	for(int rank = 7; rank >= 0; rank--){
		printf(" %d  ", rank + 1);
		for(int file = 0; file < 8; file++){
			int square = rank * 8 + file;
			printf(" %d", get_bit(bitboard, square) ? 1 : 0);

		}
		printf("\n");
	}
	printf("\n     A B C D E F G H \n\n");
	printf("      Bitboard:  %lu \n\n", bitboard);
}



// MAIN FUNCTION ==============================================

int main(int argc, char *argv[]){


/*	
	U64 kmask = mask_knight_attacks(c3);

	print_bitboard(kmask);

*/
	init_knight_attack_tables();
	
	for(int square = 0; square < 64; square++){
		printf("%d:\n", square);
		print_bitboard(knight_attacks[square]);
	}

	return 0;	
}
