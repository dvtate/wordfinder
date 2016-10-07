#ifndef WORDFINDER_UTILS_HPP
#define WORDFINDER_UTILS_HPP
#pragma once
extern uint16_t rows, cols;
extern char** game;

// ppm is better imo
#define CHAR_AT(MAT, ROW, COL)\
	*(*((MAT) + (ROW)) + (COL))

inline char& charAt(const uint16_t& row, const uint16_t& col)
	{ return *(*(game + row) + col); }

inline char& charAt(char**& mat, const uint16_t& row, const uint16_t& col)
	{ return *(*(mat + row) + col); }


inline bool& charAt(bool**& mat, const uint16_t& row, const uint16_t& col)
	{ return *(*(mat + row) + col); }



template <class T, class INDEX_T>
inline T& elemAt(T** mat, const INDEX_T& row, const INDEX_T& col)
	{ return *(*(mat + row * sizeof(T)) + col * sizeof(T)); }


void deleteNewline(char* str);


#endif
