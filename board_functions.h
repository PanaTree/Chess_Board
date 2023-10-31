#pragma once
#include <iostream>

bool detect_pawn(char color, int file, int rank);
bool detect_knight(char color, int file, int ranke);
bool detect_bishop(char color, int file, int rank);
bool detect_rook(char color, int file, int rank);
bool detect_queen(char color, int file, int rank);
bool detect_king(char color, int file, int rank);
bool detect_king_new_pos(char color, int file, int rank, Piece position);
bool detect_enpassant(char color, int file, int rank);
bool detect_pawn_new_pos(char color, int file, int rank, Piece position);
bool detect_knight_new_pos(char color, int file, int rank, Piece position);
bool detect_bishop_new_pos(char color, int file, int rank, Piece position);
bool detect_rook_new_pos(char color, int file, int rank, Piece position);
bool detect_queen_new_pos(char color, int file, int rank, Piece position);
char detect_piece_new_pos(char color, int file, int rank, Piece position);
char detect_piece(char color, int file, int rank);
int translate_file(char input_file);
int translate_rank(int input_rank);
char opposite_color(char color);
std::pair<char, int> id_piece(char color, int file, int rank);
char turn(char color);
void print_board();
bool same_pos(Piece pos1, Piece pos2);