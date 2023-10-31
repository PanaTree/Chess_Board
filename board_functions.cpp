#include <iostream>
#include "pieces.h"
#include "move_take.h"
#include "check_legal.h"
#include <windows.h>
extern Piece piece;

bool detect_pawn(char color, int file, int rank) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < piece.white_pawn.size(); i++)
			if (file == piece.white_pawn[i].file && rank == piece.white_pawn[i].rank && !piece.white_pawn[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_pawn.size(); i++)
			if (file == piece.black_pawn[i].file && rank == piece.black_pawn[i].rank && !piece.black_pawn[i].taken)
				return true;
	}
	return false;
}
bool detect_knight(char color, int file, int rank) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < piece.white_knight.size(); i++)
			if (file == piece.white_knight[i].file && rank == piece.white_knight[i].rank && !piece.white_knight[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_knight.size(); i++)
			if (file == piece.black_knight[i].file && rank == piece.black_knight[i].rank && !piece.black_knight[i].taken)
				return true;
	}
	return false;
}
bool detect_bishop(char color, int file, int rank) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < piece.white_bishop.size(); i++)
			if (file == piece.white_bishop[i].file && rank == piece.white_bishop[i].rank && !piece.white_bishop[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_bishop.size(); i++)
			if (file == piece.black_bishop[i].file && rank == piece.black_bishop[i].rank && !piece.black_bishop[i].taken)
				return true;
	}
	return false;
}
bool detect_rook(char color, int file, int rank) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < piece.white_rook.size(); i++)
			if (file == piece.white_rook[i].file && rank == piece.white_rook[i].rank && !piece.white_rook[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_rook.size(); i++)
			if (file == piece.black_rook[i].file && rank == piece.black_rook[i].rank && !piece.black_rook[i].taken)
				return true;
	}
	return false;
}
bool detect_queen(char color, int file, int rank) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < piece.white_queen.size(); i++)
			if (file == piece.white_queen[i].file && rank == piece.white_queen[i].rank && !piece.white_queen[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < piece.black_queen.size(); i++)
			if (file == piece.black_queen[i].file && rank == piece.black_queen[i].rank && !piece.black_queen[i].taken)
				return true;
	}
	return false;
}
bool detect_king(char color, int file, int rank) {
	if (file > 7 || rank > 7) 
		return false;
	else if (color == 'w') {
		if (file == piece.white_king.file && rank == piece.white_king.rank)
			return true;
	}
	else if (color == 'b') {
		if (file == piece.black_king.file && rank == piece.black_king.rank)
			return true;
	}
	return false;
}
bool detect_enpassant(char color, int file, int rank) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		if (file == piece.white_enpassant.file && rank == piece.white_enpassant.rank && !piece.white_enpassant.taken)
			return true;
		else
			return false;
	}
	else if (color == 'b') {
		if (file == piece.black_enpassant.file && rank == piece.black_enpassant.rank && !piece.black_enpassant.taken)
			return true;
		else
			return false;
	}
	return false;
}
char detect_piece(char color, int file, int rank) {
	if (rank > 7 || file > 7 || rank < 0 || file < 0)
		return '-';
	else if (detect_pawn(color, file, rank))
		return 'p';
	else if (detect_knight(color, file, rank))
		return 'N';
	else if (detect_bishop(color, file, rank))
		return 'B';
	else if (detect_rook(color, file, rank))
		return 'R';
	else if (detect_queen(color, file, rank))
		return 'Q';
	else if (detect_king(color, file, rank))
		return 'K';
	else
		return '0';
}
bool detect_pawn_new_pos(char color, int file, int rank, Piece position) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < position.white_pawn.size(); i++)
			if (file == position.white_pawn[i].file && rank == position.white_pawn[i].rank && !position.white_pawn[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < position.black_pawn.size(); i++)
			if (file == position.black_pawn[i].file && rank == position.black_pawn[i].rank && !position.black_pawn[i].taken)
				return true;
	}
	return false;
}
bool detect_knight_new_pos(char color, int file, int rank, Piece position) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < position.white_knight.size(); i++)
			if (file == position.white_knight[i].file && rank == position.white_knight[i].rank && !position.white_knight[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < position.black_knight.size(); i++)
			if (file == position.black_knight[i].file && rank == position.black_knight[i].rank && !position.black_knight[i].taken)
				return true;
	}
	return false;
}
bool detect_bishop_new_pos(char color, int file, int rank, Piece position) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < position.white_bishop.size(); i++)
			if (file == position.white_bishop[i].file && rank == position.white_bishop[i].rank && !position.white_bishop[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < position.black_bishop.size(); i++)
			if (file == position.black_bishop[i].file && rank == position.black_bishop[i].rank && !position.black_bishop[i].taken)
				return true;
	}
	return false;
}
bool detect_rook_new_pos(char color, int file, int rank, Piece position) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < position.white_rook.size(); i++)
			if (file == position.white_rook[i].file && rank == position.white_rook[i].rank && !position.white_rook[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < position.black_rook.size(); i++)
			if (file == position.black_rook[i].file && rank == position.black_rook[i].rank && !position.black_rook[i].taken)
				return true;
	}
	return false;
}
bool detect_queen_new_pos(char color, int file, int rank, Piece position) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		for (int i = 0; i < position.white_queen.size(); i++)
			if (file == position.white_queen[i].file && rank == position.white_queen[i].rank && !position.white_queen[i].taken)
				return true;
	}
	else if (color == 'b') {
		for (int i = 0; i < position.black_queen.size(); i++)
			if (file == position.black_queen[i].file && rank == position.black_queen[i].rank && !position.black_queen[i].taken)
				return true;
	}
	return false;
}
bool detect_king_new_pos(char color, int file, int rank, Piece position) {
	if (file > 7 || rank > 7)
		return false;
	else if (color == 'w') {
		if (file == position.white_king.file && rank == position.white_king.rank)
			return true;
	}
	else if (color == 'b') {
		if (file == position.black_king.file && rank == position.black_king.rank)
			return true;
	}
	return false;
} 
char detect_piece_new_pos(char color, int file, int rank, Piece position) {
	if (rank > 7 || file > 7 || rank < 0 || file < 0)
		return '-';
	else if (detect_pawn_new_pos(color, file, rank, position))
		return 'p';
	else if (detect_knight_new_pos(color, file, rank, position))
		return 'N';
	else if (detect_bishop_new_pos(color, file, rank, position))
		return 'B';
	else if (detect_rook_new_pos(color, file, rank, position))
		return 'R';
	else if (detect_queen_new_pos(color, file, rank, position))
		return 'Q';
	else if (detect_king_new_pos(color, file, rank, position))
		return 'K';
	else
		return '0';
}
int translate_file(char input_file) {
	char compare[8] = { 'a','b','c','d','e','f','g','h' };
	int num;
	for (int i = 0; i < 8; i++)
		if (input_file == compare[i]) {
			num = i;
		}
	return num;
}
int translate_rank(int input_rank) {
	return 8 - input_rank;
}
char opposite_color(char color) {
	if (color == 'w')
		return 'b';
	else if (color == 'b')
		return 'w';
}
std::pair<char, int> id_piece(char color,int file, int rank) {
	char type = detect_piece(color, file, rank);
	if (rank > 7 || file > 7 || rank < 0 || file < 0)
		return std::make_pair('-', -1);
	else if (color == 'w') {
		if (type == 'p') {
			for (int i = 0; i < piece.white_pawn.size(); i++)
				if (piece.white_pawn[i].file == file && piece.white_pawn[i].rank == rank &&
					!piece.white_pawn[i].taken)
					return std::make_pair('p', i);
		}
		else if (type == 'N') {
			for (int i = 0; i < piece.white_knight.size(); i++)
				if (piece.white_knight[i].file == file && piece.white_knight[i].rank == rank &&
					!piece.white_knight[i].taken)
					return std::make_pair('N', i);
		}
		else if (type == 'B') {
			for (int i = 0; i < piece.white_bishop.size(); i++)
				if (piece.white_bishop[i].file == file && piece.white_bishop[i].rank == rank &&
					!piece.white_bishop[i].taken)
					return std::make_pair('B', i);
		}
		else if (type == 'R') {
			for (int i = 0; i < piece.white_rook.size(); i++)
				if (piece.white_rook[i].file == file && piece.white_rook[i].rank == rank &&
					!piece.white_rook[i].taken)
					return std::make_pair('R', i);
		}
		else if (type == 'Q') {
			for (int i = 0; i < piece.white_queen.size(); i++)
				if (piece.white_queen[i].file == file && piece.white_queen[i].rank == rank &&
					!piece.white_queen[i].taken)
					return std::make_pair('Q', i);
		}
		else if (type == 'K') {
			if (piece.white_king.file == file && piece.white_king.rank == rank)
				return std::make_pair('K', 0);
		}
	}
	else if (color == 'b') {
		if (type == 'p') {
			for (int i = 0; i < piece.black_pawn.size(); i++)
				if (piece.black_pawn[i].file == file && piece.black_pawn[i].rank == rank &&
					!piece.black_pawn[i].taken)
					return std::make_pair('p', i);
		}
		else if (type == 'N') {
			for (int i = 0; i < piece.black_knight.size(); i++)
					if (piece.black_knight[i].file == file && piece.black_knight[i].rank == rank &&
						!piece.black_knight[i].taken)
						return std::make_pair('N', i);
		}
		else if (type == 'B') {
			for (int i = 0; i < piece.black_bishop.size(); i++)
				if (piece.black_bishop[i].file == file && piece.black_bishop[i].rank == rank &&
					!piece.black_bishop[i].taken)
					return std::make_pair('B', i);
		}
		else if (type == 'R') {
			for (int i = 0; i < piece.black_rook.size(); i++)
				if (piece.black_rook[i].file == file && piece.black_rook[i].rank == rank &&
					!piece.black_rook[i].taken)
					return std::make_pair('R', i);
		}
		else if (type == 'Q') {
			for (int i = 0; i < piece.black_queen.size(); i++)
				if (piece.black_queen[i].file == file && piece.black_queen[i].rank == rank &&
					!piece.black_queen[i].taken)
					return std::make_pair('Q', i);
		}
		else if (type == 'K') {
			if (piece.black_king.file == file && piece.black_king.rank == rank)
				return std::make_pair('K', 0);
		}
	}
	return std::make_pair('0', 0);
}
char turn(char color) {
	char input_file, input_target_file;
	int rank, file, target_file, input_rank, target_rank, input_target_rank;
	if (color == 'w') {
		std::cout << "White's Turn!" << '\n';
	}
	else if (color == 'b') {
		std::cout << "Black's Turn!" << '\n';
	}
	std::cout << "Input Original Position : ";
	std::cin >> input_file >> input_rank;
	file = translate_file(input_file);
	rank = translate_rank(input_rank);
	std::cout << "Input Target Position : ";
	std::cin >> input_target_file >> input_target_rank;
	target_file = translate_file(input_target_file);
	target_rank = translate_rank(input_target_rank);
	std::pair<char, int> use_piece = id_piece(color, file, rank);
	char type = use_piece.first;
	int id = use_piece.second;;
	if (legal(color, type, id, target_file, target_rank)) {
		move(color, type, id, target_file, target_rank);
		system("CLS");
		return opposite_color(color);
	}
	else {
		system("CLS");
		std::cout << "Illegal Move" << '\n';
		return color;
	}
}
void print_board() {
	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	int white = 15, black = 8, non = 6, rim = 2;
	for (int i = 0; i < 8; i++) {
		SetConsoleTextAttribute(console, rim);
		std::cout << 8 - i << " : ";
		for (int j = 0; j < 8; j++) {
			char ans_w = detect_piece('w', j, i);
			char ans_b = detect_piece('b', j, i);
			if (ans_w != '0') {
				SetConsoleTextAttribute(console, white);
				std::cout << ans_w << " ";
			}
			else if (ans_b != '0') {
				SetConsoleTextAttribute(console, black);
				std::cout << ans_b << " ";
			}
			else {
				SetConsoleTextAttribute(console, non);
				std::cout << "- ";
			}
		}
		std::cout << '\n';
	}
	SetConsoleTextAttribute(console, rim);
	std::cout << "    " << "................" << '\n';
	std::cout << "    " << "a b c d e f g h" << '\n';
	SetConsoleTextAttribute(console, white);

}
bool same_pos(Piece pos1, Piece pos2) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (detect_piece_new_pos('w', i, j, pos1) != detect_piece_new_pos('w', i, j, pos2)
				|| detect_piece_new_pos('b', i, j, pos1) != detect_piece_new_pos('b', i, j, pos2))
				return false;
		}
	}
	return true;
}
