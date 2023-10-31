#include <iostream>
#include "pieces.h"
#include "board_functions.h"
extern Piece piece;

bool detect_check_new_pos(char color, Piece position) {
	if (color == 'w') {
		int file = position.white_king.file;
		int rank = position.white_king.rank;
		if (detect_pawn_new_pos('b', file + 1, rank - 1, position)
			|| detect_pawn_new_pos('b', file - 1, rank - 1, position)) {
			return true;
		}
		if (detect_knight_new_pos('b', file + 1, rank + 2, position)
			|| detect_pawn_new_pos('b', file + 1, rank - 2, position)
			|| detect_knight_new_pos('b', file - 1, rank + 2, position)
			|| detect_pawn_new_pos('b', file - 1, rank - 2, position)
			|| detect_knight_new_pos('b', file + 2, rank + 1, position)
			|| detect_pawn_new_pos('b', file + 2, rank - 1, position)
			|| detect_knight_new_pos('b', file - 2, rank + 1, position)
			|| detect_pawn_new_pos('b', file - 2, rank - 1, position)) {
			return true;
		}
		bool plusplus = true, plusminus = true, minusplus = true, minusminus = true;
		bool plusfile = true, minusfile = true, plusrank = true, minusrank = true;
		for (int i = 1; i < 8; i++) {
			char pp = detect_piece_new_pos('b', file + i, rank + i, position);
			char pm = detect_piece_new_pos('b', file + i, rank - i, position);
			char mp = detect_piece_new_pos('b', file - i, rank + i, position);
			char mm = detect_piece_new_pos('b', file - i, rank - i, position);
			char pf = detect_piece_new_pos('b', file + i, rank, position);
			char mf = detect_piece_new_pos('b', file - i, rank, position);
			char pr = detect_piece_new_pos('b', file, rank + i, position);
			char mr = detect_piece_new_pos('b', file, rank - i, position);
			if ((pp == 'B' || pp == 'Q') && plusplus) {
				return true;
			}
			else if (pp != '0' || detect_piece_new_pos('w', file + i, rank + i, position) != 0) {
				plusplus = false;
			}
			if ((mp == 'B' || mp == 'Q') && minusplus) {
				return true;
			}
			else if (mp != '0' || detect_piece_new_pos('w', file - i, rank + i, position) != 0) {
				minusplus = false;
			}
			if ((pm == 'B' || pm == 'Q') && plusminus) {
				return true;
			}
			else if (pm != '0' || detect_piece_new_pos('w', file + i, rank - i, position) != 0) {
				plusminus = false;
			}
			if ((mm == 'B' || mm == 'Q') && minusminus) {
				return true;
			}
			else if (mm != '0' || detect_piece_new_pos('w', file - i, rank - i, position) != 0) {
				minusminus = false;
			}
			if ((pf == 'R' || pf == 'Q') && plusfile) {
				return true;
			}
			else if (pf != '0' || detect_piece_new_pos('w', file + i, rank, position) != 0) {
				plusfile = false;
			}
			if ((mf == 'R' || mp == 'Q') && minusfile) {
				return true;
			}
			else if (mf != '0' || detect_piece_new_pos('w', file - i, rank, position) != 0) {
				minusfile = false;
			}
			if ((pr == 'R' || pr == 'Q') && plusrank) {
				return true;
			}
			else if (pr != '0' || detect_piece_new_pos('w', file, rank + i, position) != 0) {
				plusrank = false;
			}
			if ((mr == 'R' || mr == 'Q') && minusrank) {
				return true;
			}
			else if (mr != '0' || detect_piece_new_pos('w', file, rank - i, position) != 0) {
				minusrank = false;
			}

		}
		return false;
	}
	else if (color == 'b') {
		int file = position.black_king.file;
		int rank = position.black_king.rank;
		if (detect_pawn_new_pos('w', file + 1, rank + 1, position)
			|| detect_pawn_new_pos('w', file - 1, rank + 1, position)) {
			return true;
		}
		if (detect_knight_new_pos('w', file + 1, rank + 2, position)
			|| detect_pawn_new_pos('w', file + 1, rank - 2, position)
			|| detect_knight_new_pos('w', file - 1, rank + 2, position)
			|| detect_pawn_new_pos('w', file - 1, rank - 2, position)
			|| detect_knight_new_pos('w', file + 2, rank + 1, position)
			|| detect_pawn_new_pos('w', file + 2, rank - 1, position)
			|| detect_knight_new_pos('w', file - 2, rank + 1, position)
			|| detect_pawn_new_pos('w', file - 2, rank - 1, position)) {
			return true;
		}
		bool plusplus = true, plusminus = true, minusplus = true, minusminus = true;
		bool plusfile = true, minusfile = true, plusrank = true, minusrank = true;
		for (int i = 1; i < 8; i++) {
			char pp = detect_piece_new_pos('w', file + i, rank + i, position);
			char pm = detect_piece_new_pos('w', file + i, rank - i, position);
			char mp = detect_piece_new_pos('w', file - i, rank + i, position);
			char mm = detect_piece_new_pos('w', file - i, rank - i, position);
			char pf = detect_piece_new_pos('w', file + i, rank, position);
			char mf = detect_piece_new_pos('w', file - i, rank, position);
			char pr = detect_piece_new_pos('w', file, rank + i, position);
			char mr = detect_piece_new_pos('w', file, rank - i, position);
			if ((pp == 'B' || pp == 'Q') && plusplus) {
				return true;
			}
			else if (pp != '0' || detect_piece_new_pos('b', file + i, rank + i, position) != 0) {
				plusplus = false;
			}
			if ((mp == 'B' || mp == 'Q') && minusplus) {
				return true;
			}
			else if (mp != '0' || detect_piece_new_pos('b', file - i, rank + i, position) != 0) {
				minusplus = false;
			}
			if ((pm == 'B' || pm == 'Q') && plusminus) {
				return true;
			}
			else if (pm != '0' || detect_piece_new_pos('b', file + i, rank - i, position) != 0) {
				plusminus = false;
			}
			if ((mm == 'B' || mm == 'Q') && minusminus) {
				return true;
			}
			else if (mm != '0' || detect_piece_new_pos('b', file - i, rank - i, position) != 0) {
				minusminus = false;
			}
			if ((pf == 'R' || pf == 'Q') && plusfile) {
				return true;
			}
			else if (pf != '0' || detect_piece_new_pos('b', file + i, rank, position) != 0) {
				plusfile = false;
			}
			if ((mf == 'R' || mp == 'Q') && minusfile) {
				return true;
			}
			else if (mf != '0' || detect_piece_new_pos('b', file - i, rank, position) != 0) {
				minusfile = false;
			}
			if ((pr == 'R' || pr == 'Q') && plusrank) {
				return true;
			}
			else if (pr != '0' || detect_piece_new_pos('b', file, rank + i, position) != 0) {
				plusrank = false;
			}
			if ((mr == 'R' || mr == 'Q') && minusrank) {
				return true;
			}
			else if (mr != '0' || detect_piece_new_pos('b', file, rank - i, position) != 0) {
				minusrank = false;
			}
		}
		return false;
	}
}
bool detect_checkmate(char color) {
	if (color == 'w') {
		for (int i = 0; i < piece.white_pawn.size(); i++)
			if (!piece.white_pawn[i].moves.empty() && !piece.white_pawn[i].taken)
				return false;
		for (int i = 0; i < piece.white_knight.size(); i++) 
			if (!piece.white_knight[i].moves.empty() && !piece.white_knight[i].taken)
				return false;
		for (int i = 0; i < piece.white_bishop.size(); i++) 
			if (!piece.white_bishop[i].moves.empty() && !piece.white_bishop[i].taken)
				return false;
		for (int i = 0; i < piece.white_rook.size(); i++) 
			if (!piece.white_rook[i].moves.empty() && !piece.white_rook[i].taken)
				return false;
		for (int i = 0; i < piece.white_queen.size(); i++) 
			if (!piece.white_queen[i].moves.empty() && !piece.white_queen[i].taken)
				return false;
		if (!piece.white_king.moves.empty())
			return false;
		return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_pawn.size(); i++)
			if (!piece.black_pawn[i].moves.empty() && !piece.black_pawn[i].taken)
				return false;
		for (int i = 0; i < piece.black_knight.size(); i++)
			if (!piece.black_knight[i].moves.empty() && !piece.black_knight[i].taken)
				return false;
		for (int i = 0; i < piece.black_bishop.size(); i++)
			if (!piece.black_bishop[i].moves.empty() && !piece.black_bishop[i].taken)
				return false;
		for (int i = 0; i < piece.black_rook.size(); i++)
			if (!piece.black_rook[i].moves.empty() && !piece.black_rook[i].taken)
				return false;
		for (int i = 0; i < piece.black_queen.size(); i++)
			if (!piece.black_queen[i].moves.empty() && !piece.black_queen[i].taken)
				return false;
		if (!piece.black_king.moves.empty())
			return false;
		return true;
	}
}
bool check_castle(char color, int target_file) {
	if (color == 'w') {
		if (!piece.white_king.can_castle) {
			return false;
		}
		else if (target_file == 2){
			Piece temp1 = piece;
			temp1.white_king.file = 1;
			temp1.white_king.rank = 7;
			Piece temp2 = piece;
			temp2.white_king.file = 2;
			temp2.white_king.rank = 7;
			Piece temp3 = piece;
			temp3.white_king.file = 3;
			temp3.white_king.rank = 7;
			if (piece.white_rook[0].can_castle && detect_piece('w', 1, 7) == '0' 
				&& detect_piece('w', 2, 7) == '0' && detect_piece('w', 3, 7) == '0' 
				&& detect_piece('b', 1, 7) == '0' && detect_piece('b', 2, 7) == '0' 
				&& detect_piece('b', 3, 7) == '0' && !detect_check_new_pos('w', temp1)
				&& !detect_check_new_pos('w', temp2) && !detect_check_new_pos('w', temp3)) {
				return true;
			}
		}
		else if (target_file == 6) {
			Piece temp1 = piece;
			temp1.white_king.file = 5;
			temp1.white_king.rank = 7;
			Piece temp2 = piece;
			temp2.white_king.file = 6;
			temp2.white_king.rank = 7;
			if (piece.white_rook[1].can_castle && detect_piece('w', 5, 7) == '0'
				&& detect_piece('w', 6, 7) == '0' && detect_piece('b', 5, 7) == '0'
				&& detect_piece('b', 6, 7) == '0' && !detect_check_new_pos('w', temp1)
				&& !detect_check_new_pos('w', temp2)) {
				return true;
			}
			return false;
		}
	}
	if (color == 'b') {
		if (!piece.black_king.can_castle) {
			return false;
		}
		else if (target_file == 2){
			Piece temp1 = piece;
			temp1.black_king.file = 1;
			temp1.black_king.rank = 0;
			Piece temp2 = piece;
			temp2.black_king.file = 2;
			temp2.black_king.rank = 0;
			Piece temp3 = piece;
			temp3.black_king.file = 3;
			temp3.black_king.rank = 0;
			if (piece.black_rook[0].can_castle && detect_piece('w', 1, 0) == '0' 
				&& detect_piece('w', 2, 0) == '0' && detect_piece('w', 3, 0) == '0' 
				&& detect_piece('b', 1, 0) == '0' && detect_piece('b', 2, 0) == '0' 
				&& detect_piece('b', 3, 0) == '0' && !detect_check_new_pos('b', temp1)
				&& !detect_check_new_pos('b', temp2) && !detect_check_new_pos('b', temp3)) {
				return true;
			}
		}
		else if (target_file == 6) {
			Piece temp1 = piece;
			temp1.black_king.file = 5;
			temp1.black_king.rank = 0;
			Piece temp2 = piece;
			temp2.black_king.file = 6;
			temp2.black_king.rank = 0;
			if (piece.black_rook[1].can_castle && detect_piece('w', 5, 0) == '0' 
				&& detect_piece('w', 6, 0) == '0' && detect_piece('b', 5, 0) == '0' 
				&& detect_piece('b', 6, 0) == '0' && !detect_check_new_pos('b', temp1)
				&& !detect_check_new_pos('b', temp2)) {
				return true;
			}
			return false;
		}
	}
}
void add_pawn_moves(char color) {
	if (color == 'w') {
		for (int i = 0; i < piece.white_pawn.size(); i++) {
			if (!piece.white_pawn[i].taken) {
				piece.white_pawn[i].moves.clear();
				int file = piece.white_pawn[i].file;
				int rank = piece.white_pawn[i].rank;
				Piece next_piece = piece;
				next_piece.white_pawn[i].file = file;
				next_piece.white_pawn[i].rank = rank - 1;
				if (detect_piece('b', file, rank - 1) == '0' && detect_piece('w', file, rank - 1) == '0' 
					&& !detect_check_new_pos('w', next_piece))
					piece.white_pawn[i].moves.push_back(std::make_pair(file, rank - 1));
				next_piece.white_pawn[i].file = file;
				next_piece.white_pawn[i].rank = rank - 2;
				if (rank == 6 && detect_piece('b', file, rank - 2) == '0' && detect_piece('w', file, rank - 2) == '0' 
					&& !detect_check_new_pos('w', next_piece))
					piece.white_pawn[i].moves.push_back(std::make_pair(file, rank - 2));
				next_piece.white_pawn[i].file = file - 1;
				next_piece.white_pawn[i].rank = rank - 1;
				if ((detect_piece('b', file - 1, rank - 1) != '0' || detect_enpassant('b', file - 1, rank - 1))
					&& !detect_check_new_pos('w', next_piece))
					piece.white_pawn[i].moves.push_back(std::make_pair(file - 1, rank - 1));
				next_piece.white_pawn[i].file = file + 1;
				next_piece.white_pawn[i].rank = rank - 1;
				if ((detect_piece('b', file + 1, rank - 1) != '0' || detect_enpassant('b', file + 1, rank - 1))
					&& !detect_check_new_pos('w', next_piece))
					piece.white_pawn[i].moves.push_back(std::make_pair(file + 1, rank - 1));
			}
		}
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_pawn.size(); i++) {
			if (!piece.black_pawn[i].taken) {
				piece.black_pawn[i].moves.clear();
				int file = piece.black_pawn[i].file;
				int rank = piece.black_pawn[i].rank;
				Piece next_piece = piece;
				next_piece.black_pawn[i].file = file;
				next_piece.black_pawn[i].rank = rank + 1;
				if (detect_piece('b', file, rank + 1) == '0' && detect_piece('w', file, rank + 1) == '0' 
					&& !detect_check_new_pos('b', next_piece))
					piece.black_pawn[i].moves.push_back(std::make_pair(file, rank + 1));
				next_piece.black_pawn[i].file = file;
				next_piece.black_pawn[i].rank = rank + 2;
				if (rank == 1 && detect_piece('b', file, rank + 2) == '0' && detect_piece('w', file, rank + 2) == '0'
					&& !detect_check_new_pos('b', next_piece))
					piece.black_pawn[i].moves.push_back(std::make_pair(file, rank + 2));
				next_piece.black_pawn[i].file = file - 1;
				next_piece.black_pawn[i].rank = rank + 1;
				if ((detect_piece('w', file - 1, rank + 1) != '0' || detect_enpassant('w', file - 1, rank + 1))
					&& !detect_check_new_pos('b', next_piece))
					piece.black_pawn[i].moves.push_back(std::make_pair(file - 1, rank + 1));
				next_piece.black_pawn[i].file = file + 1;
				next_piece.black_pawn[i].rank = rank + 1;
				if ((detect_piece('w', file + 1, rank + 1) != '0' || detect_enpassant('w', file + 1, rank + 1))
					&& !detect_check_new_pos('b', next_piece))
					piece.black_pawn[i].moves.push_back(std::make_pair(file + 1, rank + 1));
			}
		}
	}

}
void add_knight_moves(char color) {
	if (color == 'w') {
		for (int i = 0; i < piece.white_knight.size(); i++) {
			if (!piece.white_knight[i].taken) {
				piece.white_knight[i].moves.clear();
				int file = piece.white_knight[i].file;
				int rank = piece.white_knight[i].rank;
				piece.white_knight[i].file;
				piece.white_knight[i].rank;
				Piece next_piece = piece;
				next_piece.white_knight[i].file = file - 2;
				next_piece.white_knight[i].rank = rank - 1;
				if (detect_piece('w', file - 2, rank - 1) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file - 2, rank - 1));
				next_piece.white_knight[i].file = file - 1;
				next_piece.white_knight[i].rank = rank - 2;
				if (detect_piece('w', file - 1, rank - 2) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file - 1, rank - 2));
				next_piece.white_knight[i].file = file + 2;
				next_piece.white_knight[i].rank = rank + 1;
				if (detect_piece('w', file + 2, rank + 1) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file + 2, rank + 1));
				next_piece.white_knight[i].file = file + 1;
				next_piece.white_knight[i].rank = rank + 2;
				if (detect_piece('w', file + 1, rank + 2) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file + 1, rank + 2));
				next_piece.white_knight[i].file = file + 2;
				next_piece.white_knight[i].rank = rank - 1;
				if (detect_piece('w', file + 2, rank - 1) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file + 2, rank - 1));
				next_piece.white_knight[i].file = file + 1;
				next_piece.white_knight[i].rank = rank - 2;
				if (detect_piece('w', file + 1, rank - 2) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file + 1, rank - 2));
				next_piece.white_knight[i].file = file - 2;
				next_piece.white_knight[i].rank = rank + 1;
				if (detect_piece('w', file - 2, rank + 1) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file - 2, rank + 1));
				next_piece.white_knight[i].file = file - 1;
				next_piece.white_knight[i].rank = rank + 2;
				if (detect_piece('w', file - 1, rank + 2) == '0' && !detect_check_new_pos('w', next_piece))
					piece.white_knight[i].moves.push_back(std::make_pair(file - 1, rank + 2));
			}
		}
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_knight.size(); i++) {
			if (!piece.black_knight[i].taken) {
				piece.black_knight[i].moves.clear();
				int file = piece.black_knight[i].file;
				int rank = piece.black_knight[i].rank;
				piece.black_knight[i].file;
				piece.black_knight[i].rank;
				Piece next_piece = piece;
				next_piece.black_knight[i].file = file - 2;
				next_piece.black_knight[i].rank = rank - 1;
				if (detect_piece('b', file - 2, rank - 1) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file - 2, rank - 1));
				next_piece.black_knight[i].file = file - 1;
				next_piece.black_knight[i].rank = rank - 2;
				if (detect_piece('b', file - 1, rank - 2) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file - 1, rank - 2));
				next_piece.black_knight[i].file = file + 2;
				next_piece.black_knight[i].rank = rank + 1;
				if (detect_piece('b', file + 2, rank + 1) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file + 2, rank + 1));
				next_piece.black_knight[i].file = file + 1;
				next_piece.black_knight[i].rank = rank + 2;
				if (detect_piece('b', file + 1, rank + 2) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file + 1, rank + 2));
				next_piece.black_knight[i].file = file + 2;
				next_piece.black_knight[i].rank = rank - 1;
				if (detect_piece('b', file + 2, rank - 1) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file + 2, rank - 1));
				next_piece.black_knight[i].file = file + 1;
				next_piece.black_knight[i].rank = rank - 2;
				if (detect_piece('b', file + 1, rank - 2) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file + 1, rank - 2));
				next_piece.black_knight[i].file = file - 2;
				next_piece.black_knight[i].rank = rank + 1;
				if (detect_piece('b', file - 2, rank + 1) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file - 2, rank + 1));
				next_piece.black_knight[i].file = file - 1;
				next_piece.black_knight[i].rank = rank + 2;
				if (detect_piece('b', file - 1, rank + 2) == '0' && !detect_check_new_pos('b', next_piece))
					piece.black_knight[i].moves.push_back(std::make_pair(file - 1, rank + 2));
			}
		}
	}
}
void add_bishop_moves(char color) {
	if (color == 'w') {
		for (int i = 0; i < piece.white_bishop.size(); i++) {
			if (!piece.white_bishop[i].taken) {
				piece.white_bishop[i].moves.clear();
				int file = piece.white_bishop[i].file;
				int rank = piece.white_bishop[i].rank;
				bool plusplus = true, minusplus = true, plusminus = true, minusminus = true;
				for (int j = 1; j < 8; j++) {
					Piece next_piece = piece;
					next_piece.white_bishop[i].file = file + j;
					next_piece.white_bishop[i].rank = rank + j;
					if (detect_piece('w', file + j, rank + j) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusplus)
						piece.white_bishop[i].moves.push_back(std::make_pair(file + j, rank + j));
					else
						plusplus = false;
					next_piece.white_bishop[i].file = file - j;
					next_piece.white_bishop[i].rank = rank + j;
					if (detect_piece('w', file - j, rank + j) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusplus)
						piece.white_bishop[i].moves.push_back(std::make_pair(file - j, rank + j));
					else
						minusplus = false;
					next_piece.white_bishop[i].file = file + j;
					next_piece.white_bishop[i].rank = rank - j;
					if (detect_piece('w', file + j, rank - j) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusminus)
						piece.white_bishop[i].moves.push_back(std::make_pair(file + j, rank - j));
					else
						plusminus = false;
					next_piece.white_bishop[i].file = file - j;
					next_piece.white_bishop[i].rank = rank - j;
					if (detect_piece('w', file - j, rank - j) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusminus)
						piece.white_bishop[i].moves.push_back(std::make_pair(file - j, rank - j));
					else
						minusminus = false;
				}
			}
		}
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_bishop.size(); i++) {
			if (!piece.black_bishop[i].taken) {
				piece.black_bishop[i].moves.clear();
				int file = piece.black_bishop[i].file;
				int rank = piece.black_bishop[i].rank;
				bool plusplus = true, minusplus = true, plusminus = true, minusminus = true;
				for (int j = 1; j < 8; j++) {
					Piece next_piece = piece;
					next_piece.black_bishop[i].file = file + j;
					next_piece.black_bishop[i].rank = rank + j;
					if (detect_piece('b', file + j, rank + j) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusplus)
						piece.black_bishop[i].moves.push_back(std::make_pair(file + j, rank + j));
					else
						plusplus = false;
					next_piece.black_bishop[i].file = file - j;
					next_piece.black_bishop[i].rank = rank + j;
					if (detect_piece('b', file - j, rank + j) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusplus)
						piece.black_bishop[i].moves.push_back(std::make_pair(file - j, rank + j));
					else
						minusplus = false;
					next_piece.black_bishop[i].file = file + j;
					next_piece.black_bishop[i].rank = rank - j;
					if (detect_piece('b', file + j, rank - j) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusminus)
						piece.black_bishop[i].moves.push_back(std::make_pair(file + j, rank - j));
					else
						plusminus = false;
					next_piece.black_bishop[i].file = file - j;
					next_piece.black_bishop[i].rank = rank - j;
					if (detect_piece('b', file - j, rank - j) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusminus)
						piece.black_bishop[i].moves.push_back(std::make_pair(file - j, rank - j));
					else
						minusminus = false;
				}
			}
		}
	}
}
void add_rook_moves(char color) {
	if (color == 'w') {
		for (int i = 0; i < piece.white_rook.size(); i++) {
			if (!piece.white_rook[i].taken) {
				piece.white_rook[i].moves.clear();
				int file = piece.white_rook[i].file;
				int rank = piece.white_rook[i].rank;
				bool plusfile = true, minusfile = true, plusrank = true, minusrank = true;
				bool plusplus = true, minusplus = true, plusminus = true, minusminus = true;
				for (int j = 1; j < 8; j++) {
					Piece next_piece = piece;
					next_piece.white_rook[i].file = file + j;
					if (detect_piece('w', file + j, rank) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusfile)
						piece.white_rook[i].moves.push_back(std::make_pair(file + j, rank));
					else
						plusfile = false;
					next_piece.white_rook[i].file = file - j;
					if (detect_piece('w', file - j, rank) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusfile)
						piece.white_rook[i].moves.push_back(std::make_pair(file - j, rank));
					else
						minusfile = false;
					next_piece.white_rook[i].rank = rank + j;
					if (detect_piece('w', file, rank + j) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusrank)
						piece.white_rook[i].moves.push_back(std::make_pair(file, rank + j));
					else
						plusrank = false;
					next_piece.white_rook[i].rank = rank - j;
					if (detect_piece('w', file, rank - j) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusrank)
						piece.white_rook[i].moves.push_back(std::make_pair(file, rank - j));
					else
						minusrank = false;
				}
			}
		}
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_rook.size(); i++) {
			if (!piece.black_rook[i].taken) {
				piece.black_rook[i].moves.clear();
				int file = piece.black_rook[i].file;
				int rank = piece.black_rook[i].rank;
				bool plusfile = true, minusfile = true, plusrank = true, minusrank = true;
				bool plusplus = true, minusplus = true, plusminus = true, minusminus = true;
				for (int j = 1; j < 8; j++) {
					Piece next_piece = piece;
					next_piece.black_rook[i].file = file + j;
					if (detect_piece('b', file + j, rank) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusfile)
						piece.black_rook[i].moves.push_back(std::make_pair(file + j, rank));
					else
						plusfile = false;
					next_piece.black_rook[i].file = file - j;
					if (detect_piece('b', file - j, rank) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusfile)
						piece.black_rook[i].moves.push_back(std::make_pair(file - j, rank));
					else
						minusfile = false;
					next_piece.black_rook[i].rank = rank + j;
					if (detect_piece('b', file, rank + j) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusrank)
						piece.black_rook[i].moves.push_back(std::make_pair(file, rank + j));
					else
						plusrank = false;
					next_piece.black_rook[i].rank = rank - j;
					if (detect_piece('b', file, rank - j) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusrank)
						piece.black_rook[i].moves.push_back(std::make_pair(file, rank - j));
					else
						minusrank = false;
				}
			}
		}
	}
}
void add_queen_moves(char color) {
	if (color == 'w') {
		for (int i = 0; i < piece.white_queen.size(); i++) {
			if (!piece.white_queen[i].taken) {
				piece.white_queen[i].moves.clear();
				int file = piece.white_queen[i].file;
				int rank = piece.white_queen[i].rank;
				bool plusfile = true, minusfile = true, plusrank = true, minusrank = true;
				bool plusplus = true, minusplus = true, plusminus = true, minusminus = true;
				for (int j = 1; j < 8; j++) {
					Piece next_piece = piece;
					next_piece.white_queen[i].file = file + j;
					if (detect_piece('w', file + j, rank) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusfile)
						piece.white_queen[i].moves.push_back(std::make_pair(file + j, rank));
					else
						plusfile = false;
					next_piece.white_queen[i].file = file - j;
					if (detect_piece('w', file - j, rank) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusfile)
						piece.white_queen[i].moves.push_back(std::make_pair(file - j, rank));
					else
						minusfile = false;
					next_piece.white_queen[i].rank = rank + j;
					if (detect_piece('w', file, rank + j) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusrank)
						piece.white_queen[i].moves.push_back(std::make_pair(file, rank + j));
					else
						plusrank = false;
					next_piece.white_queen[i].rank = rank - j;
					if (detect_piece('w', file, rank - j) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusrank)
						piece.white_queen[i].moves.push_back(std::make_pair(file, rank - j));
					else
						minusrank = false;
					next_piece.white_queen[i].file = file + j;
					next_piece.white_queen[i].rank = rank + j;
					if (detect_piece('w', file + j, rank + j) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusplus)
						piece.white_queen[i].moves.push_back(std::make_pair(file + j, rank + j));
					else
						plusplus = false;
					next_piece.white_queen[i].file = file - j;
					next_piece.white_queen[i].rank = rank + j;
					if (detect_piece('w', file - j, rank + j) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusplus)
						piece.white_queen[i].moves.push_back(std::make_pair(file - j, rank + j));
					else
						minusplus = false;
					next_piece.white_queen[i].file = file + j;
					next_piece.white_queen[i].rank = rank - j;
					if (detect_piece('w', file + j, rank - j) == '0' && !detect_check_new_pos('w', next_piece)
						&& plusminus)
						piece.white_queen[i].moves.push_back(std::make_pair(file + j, rank - j));
					else
						plusminus = false;
					next_piece.white_queen[i].file = file - j;
					next_piece.white_queen[i].rank = rank - j;
					if (detect_piece('w', file - j, rank - j) == '0' && !detect_check_new_pos('w', next_piece)
						&& minusminus)
						piece.white_queen[i].moves.push_back(std::make_pair(file - j, rank - j));
					else
						minusminus = false;
				}
			}
		}
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_queen.size(); i++) {
			if (!piece.black_queen[i].taken) {
				piece.black_queen[i].moves.clear();
				int file = piece.black_queen[i].file;
				int rank = piece.black_queen[i].rank;
				bool plusfile = true, minusfile = true, plusrank = true, minusrank = true;
				bool plusplus = true, minusplus = true, plusminus = true, minusminus = true;
				for (int j = 1; j < 8; j++) {
					Piece next_piece = piece;
					next_piece.black_queen[i].file = file + j;
					if (detect_piece('b', file + j, rank) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusfile)
						piece.black_queen[i].moves.push_back(std::make_pair(file + j, rank));
					else
						plusfile = false;
					next_piece.black_queen[i].file = file - j;
					if (detect_piece('b', file - j, rank) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusfile)
						piece.black_queen[i].moves.push_back(std::make_pair(file - j, rank));
					else
						minusfile = false;
					next_piece.black_queen[i].rank = rank + j;
					if (detect_piece('b', file, rank + j) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusrank)
						piece.black_queen[i].moves.push_back(std::make_pair(file, rank + j));
					else
						plusrank = false;
					next_piece.black_queen[i].rank = rank - j;
					if (detect_piece('b', file, rank - j) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusrank)
						piece.black_queen[i].moves.push_back(std::make_pair(file, rank - j));
					else
						minusrank = false;
					next_piece.black_queen[i].file = file + j;
					next_piece.black_queen[i].rank = rank + j;
					if (detect_piece('b', file + j, rank + j) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusplus)
						piece.black_queen[i].moves.push_back(std::make_pair(file + j, rank + j));
					else
						plusplus = false;
					next_piece.black_queen[i].file = file - j;
					next_piece.black_queen[i].rank = rank + j;
					if (detect_piece('b', file - j, rank + j) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusplus)
						piece.black_queen[i].moves.push_back(std::make_pair(file - j, rank + j));
					else
						minusplus = false;
					next_piece.black_queen[i].file = file + j;
					next_piece.black_queen[i].rank = rank - j;
					if (detect_piece('b', file + j, rank - j) == '0' && !detect_check_new_pos('b', next_piece)
						&& plusminus)
						piece.black_queen[i].moves.push_back(std::make_pair(file + j, rank - j));
					else
						plusminus = false;
					next_piece.black_queen[i].file = file - j;
					next_piece.black_queen[i].rank = rank - j;
					if (detect_piece('b', file - j, rank - j) == '0' && !detect_check_new_pos('b', next_piece)
						&& minusminus)
						piece.black_queen[i].moves.push_back(std::make_pair(file - j, rank - j));
					else
						minusminus = false;
				}
			}
		}
	}
}
void add_king_moves(char color) {
	if (color == 'w') {
		piece.white_king.moves.clear();
		int file = piece.white_king.file;
		int rank = piece.white_king.rank;
		Piece next_piece = piece;
		next_piece.white_king.file = file + 1;
		if (detect_piece('w', file + 1, rank) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file + 1, rank));
		next_piece.white_king.file = file - 1;
		if (detect_piece('w', file - 1, rank) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file - 1, rank));
		next_piece.white_king.rank = rank + 1;
		if (detect_piece('w', file, rank + 1) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file, rank + 1));
		next_piece.white_king.rank = rank - 1;
		if (detect_piece('w', file, rank - 1) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file, rank - 1));
		next_piece.white_king.file = file + 1;
		next_piece.white_king.rank = rank + 1;
		if (detect_piece('w', file + 1, rank + 1) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file + 1, rank + 1));
		next_piece.white_king.file = file - 1;
		next_piece.white_king.rank = rank + 1;
		if (detect_piece('w', file - 1, rank + 1) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file - 1, rank + 1));
		next_piece.white_king.file = file + 1;
		next_piece.white_king.rank = rank - 1;
		if (detect_piece('w', file + 1, rank - 1) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file + 1, rank - 1));
		next_piece.white_king.file = file - 1;
		next_piece.white_king.rank = rank - 1;
		if (detect_piece('w', file - 1, rank - 1) == '0' && !detect_check_new_pos('w', next_piece))
			piece.white_king.moves.push_back(std::make_pair(file - 1, rank - 1));
	}
	else if (color == 'b') {
		piece.black_king.moves.clear();
		int file = piece.black_king.file;
		int rank = piece.black_king.rank;
		Piece next_piece = piece;
		next_piece.black_king.file = file + 1;
		if (detect_piece('b', file + 1, rank) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file + 1, rank));
		next_piece.black_king.file = file - 1;
		if (detect_piece('b', file - 1, rank) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file - 1, rank));
		next_piece.black_king.rank = rank + 1;
		if (detect_piece('b', file, rank + 1) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file, rank + 1));
		next_piece.black_king.rank = rank - 1;
		if (detect_piece('b', file, rank - 1) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file, rank - 1));
		next_piece.black_king.file = file + 1;
		next_piece.black_king.rank = rank + 1;
		if (detect_piece('b', file + 1, rank + 1) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file + 1, rank + 1));
		next_piece.black_king.file = file - 1;
		next_piece.black_king.rank = rank + 1;
		if (detect_piece('b', file - 1, rank + 1) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file - 1, rank + 1));
		next_piece.black_king.file = file + 1;
		next_piece.black_king.rank = rank - 1;
		if (detect_piece('b', file + 1, rank - 1) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file + 1, rank - 1));
		next_piece.black_king.file = file - 1;
		next_piece.black_king.rank = rank - 1;
		if (detect_piece('b', file - 1, rank - 1) == '0' && !detect_check_new_pos('b', next_piece))
			piece.black_king.moves.push_back(std::make_pair(file - 1, rank - 1));
	}
}
void add_all_moves(char color) {
	add_pawn_moves(color);
	add_knight_moves(color);
	add_bishop_moves(color);
	add_rook_moves(color);
	add_queen_moves(color);
	add_king_moves(color);
	if (color == 'w') {
		piece.white_enpassant = { -1, -1, true };
	}
	else if (color == 'b') {
		piece.black_enpassant = { -1, -1, true };
	}
}
bool legal(char color, char type, int id, int target_file, int target_rank){
	if (color == 'w') {
		if (type == 'p') {
			for (int i = 0; i < piece.white_pawn[id].moves.size(); i++) {
				//std::cout << piece.white_pawn[id].moves[i].first << " " << piece.white_pawn[id].moves[i].second << '\n';
				if (target_file == piece.white_pawn[id].moves[i].first
					&& target_rank == piece.white_pawn[id].moves[i].second) {
					return true;
				}
			}
		}
		else if (type == 'N') {
			for (int i = 0; i < piece.white_knight[id].moves.size(); i++)
				if (target_file == piece.white_knight[id].moves[i].first
					&& target_rank == piece.white_knight[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'B') {
			for (int i = 0; i < piece.white_bishop[id].moves.size(); i++)
				if (target_file == piece.white_bishop[id].moves[i].first
					&& target_rank == piece.white_bishop[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'R') {
			for (int i = 0; i < piece.white_rook[id].moves.size(); i++)
				if (target_file == piece.white_rook[id].moves[i].first
					&& target_rank == piece.white_rook[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'Q') {
			for (int i = 0; i < piece.white_queen[id].moves.size(); i++)
				if (target_file == piece.white_queen[id].moves[i].first
					&& target_rank == piece.white_queen[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'K') {
			if ((target_file == 2 && target_rank == 7) 
				|| (target_file == 6 && target_rank == 7)
				&& check_castle('w', target_file)) {
				return true;
			}
			for (int i = 0; i < piece.white_king.moves.size(); i++)
				if (target_file == piece.white_king.moves[i].first
					&& target_rank == piece.white_king.moves[i].second) {
					return true;
				}
		}
	}
	else if (color == 'b') {
		if (type == 'p') {
			for (int i = 0; i < piece.black_pawn[id].moves.size(); i++)
				if (target_file == piece.black_pawn[id].moves[i].first
					&& target_rank == piece.black_pawn[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'N') {
			for (int i = 0; i < piece.black_knight[id].moves.size(); i++)
				if (target_file == piece.black_knight[id].moves[i].first
					&& target_rank == piece.black_knight[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'B') {
			for (int i = 0; i < piece.black_bishop[id].moves.size(); i++)
				if (target_file == piece.black_bishop[id].moves[i].first
					&& target_rank == piece.black_bishop[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'R') {
			for (int i = 0; i < piece.black_rook[id].moves.size(); i++)
				if (target_file == piece.black_rook[id].moves[i].first
					&& target_rank == piece.black_rook[id].moves[i].second) {
					return true;
				}
		}
		else if (type == 'Q') {
			for (int i = 0; i < piece.black_queen[id].moves.size(); i++)
				if (target_file == piece.black_queen[id].moves[i].first
					&& target_rank == piece.black_queen[id].moves[i].second) {
					return true;
				}
		}
		if (type == 'K') {
			if ((target_file == 2 && target_rank == 0)
				|| (target_file == 6 && target_rank == 0)
				&& check_castle('b', target_file)) {
				return true;
			}
			for (int i = 0; i < piece.black_king.moves.size(); i++)
				if (target_file == piece.black_king.moves[i].first
					&& target_rank == piece.black_king.moves[i].second) {
					return true;
				}
		}
	}
	return false;
}