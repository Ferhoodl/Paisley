#include "game.h"


void parseFEN(char* fenStr, State* stt){
	int idx = 0;
	int section = 0;
	char currentChar = fenStr[idx];
	while(currentChar != '\n'){
		if(currentChar == ' ' || currentChar == '/'){
			section++;	
		}
		if(section < 8){
				
		}else if(section == 8){
			(currentChar == 'w')? stt->turn = WHITE_TURN : stt->turn = BLACK_TURN; 
		}else if(section == 9){
			(currentChar == 'Q')? stt->	
		}
		
		
		
		currentChar = fenStr[];
	}
}
