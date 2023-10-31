#pragma once

bool detect_check_new_pos(char color, Piece position);
bool detect_checkmate(char color);
bool check_castle(char color, int target_file);
void add_pawn_moves(char color);
void add_knight_moves(char color);
void add_bishop_moves(char color);
void add_rook_moves(char color);
void add_queen_moves(char color);
void add_king_moves(char color);
void add_all_moves(char color);
bool legal(char color, char type, int id, int target_file, int target_rank);