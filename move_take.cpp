#include <iostream>
#include "pieces.h"
#include "board_functions.h"
extern Piece piece;

void promote(char color, int id) {
	if (color == 'w') {
		char type;
		piece.white_pawn[id].taken = true;
		std::cout << "Promote Pawn To? (N/B/R/Q) : ";
		std::cin >> type;
		if (type == 'N') {
			piece.white_knight.push_back(
				{ piece.white_pawn[id].file,piece.white_pawn[id].rank, false });
		}
		else if (type == 'B') {
			piece.white_bishop.push_back(
				{ piece.white_pawn[id].file,piece.white_pawn[id].rank, false });
		}
		else if (type == 'R') {
			piece.white_rook.push_back(
				{ piece.white_pawn[id].file,piece.white_pawn[id].rank, false, });
		}
		else if (type == 'Q') {
			piece.white_queen.push_back(
				{ piece.white_pawn[id].file,piece.white_pawn[id].rank, false });
		}
	}
	else if (color == 'b') {
		char type;
		piece.black_pawn[id].taken = true;
		std::cout << "Promote Pawn To? (N/B/R/Q) : ";
		std::cin >> type;
		if (type == 'N') {
			piece.black_knight.push_back(
				{ piece.black_pawn[id].file,piece.black_pawn[id].rank, false });
		}
		else if (type == 'B') {
			piece.black_bishop.push_back(
				{ piece.black_pawn[id].file,piece.black_pawn[id].rank, false });
		}
		else if (type == 'R') {
			piece.black_rook.push_back(
				{ piece.black_pawn[id].file,piece.black_pawn[id].rank, false, });
		}
		else if (type == 'Q') {
			piece.black_queen.push_back(
				{ piece.black_pawn[id].file,piece.black_pawn[id].rank, false });
		}
	}
}
void take(char color, char type, int target_file, int target_rank) {
	char target_color = opposite_color(color);
	std::pair<char, int> target_piece = id_piece(target_color, target_file, target_rank);
	if (target_color == 'w') {
		if (target_piece.first == 'p')
			piece.white_pawn[target_piece.second].taken = true;
		else if (target_piece.first == 'N')
			piece.white_knight[target_piece.second].taken = true;
		else if (target_piece.first == 'B')
			piece.white_bishop[target_piece.second].taken = true;
		else if (target_piece.first == 'R')
			piece.white_rook[target_piece.second].taken = true;
		else if (target_piece.first == 'Q')
			piece.white_queen[target_piece.second].taken = true;
		else if (type == 'p' && detect_enpassant('w', target_file, target_rank)) {
			int pawn_id = id_piece(target_color, target_file, target_rank - 1).second;
			piece.white_pawn[pawn_id].taken = true;
		}
	}
	else if (target_color == 'b') {
		if (target_piece.first == 'p')
			piece.black_pawn[target_piece.second].taken = true;
		else if (target_piece.first == 'N')
			piece.black_knight[target_piece.second].taken = true;
		else if (target_piece.first == 'B')
			piece.black_bishop[target_piece.second].taken = true;
		else if (target_piece.first == 'R')
			piece.black_rook[target_piece.second].taken = true;
		else if (target_piece.first == 'Q')
			piece.black_queen[target_piece.second].taken = true;
		else if (type == 'p' && detect_enpassant('b', target_file, target_rank)) {
			int pawn_id = id_piece(target_color, target_file, target_rank + 1).second;
			piece.black_pawn[pawn_id].taken = true;
		}
	}
}
void move(char color, char type, int id, int target_file, int target_rank) {
	if (color == 'w') {
		if (type == 'p') {
			if (target_rank == piece.white_pawn[id].rank - 2)
				piece.white_enpassant = { target_file, target_rank + 1, false };
			piece.white_pawn[id].file = target_file;
			piece.white_pawn[id].rank = target_rank;
		}
		if (type == 'N') {
			piece.white_knight[id].file = target_file;
			piece.white_knight[id].rank = target_rank;
		}
		if (type == 'B') {
			piece.white_bishop[id].file = target_file;
			piece.white_bishop[id].rank = target_rank;
		}
		if (type == 'R') {
			piece.white_rook[id].file = target_file;
			piece.white_rook[id].rank = target_rank;
			piece.white_rook[id].can_castle = false;
		}
		if (type == 'Q') {
			piece.white_queen[id].file = target_file;
			piece.white_queen[id].rank = target_rank;
		}
		if (type == 'K') {
			if (piece.white_king.file == target_file - 2) {
				piece.white_rook[1].file = target_file - 1;
			}
			if (piece.white_king.file == target_file + 2) {
				piece.white_rook[0].file = target_file + 1;
			}
			piece.white_king.file = target_file;
			piece.white_king.rank = target_rank;
			piece.white_king.can_castle = false;
		}
	}
	else if (color == 'b') {
		if (type == 'p') {
			if (target_rank == piece.black_pawn[id].rank + 2)
				piece.black_enpassant = { target_file, target_rank - 1, false };
			piece.black_pawn[id].file = target_file;
			piece.black_pawn[id].rank = target_rank;
		}
		if (type == 'N') {
			piece.black_knight[id].file = target_file;
			piece.black_knight[id].rank = target_rank;
		}
		if (type == 'B') {
			piece.black_bishop[id].file = target_file;
			piece.black_bishop[id].rank = target_rank;
		}
		if (type == 'R') {
			piece.black_rook[id].file = target_file;
			piece.black_rook[id].rank = target_rank;
			piece.black_rook[id].can_castle = false;
		}
		if (type == 'Q') {
			piece.black_queen[id].file = target_file;
			piece.black_queen[id].rank = target_rank;
		}
		if (type == 'K') {
			if (piece.black_king.file == target_file - 2) {
				piece.black_rook[1].file = target_file - 1;
			}
			if (piece.black_king.file == target_file + 2) {
				piece.black_rook[0].file = target_file + 1;
			}
			piece.black_king.file = target_file;
			piece.black_king.rank = target_rank;
			piece.black_king.can_castle = false;
		}
	}
	take(color, type, target_file, target_rank);
	if (type == 'p' && ((target_rank == 0 && color == 'w') 
		|| (target_rank == 7 && color == 'b')))
		promote(color, id);
}
