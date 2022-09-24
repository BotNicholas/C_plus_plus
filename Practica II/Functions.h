#include <fstream>

using namespace std;

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

extern int n, m;
extern HANDLE handle;
extern bool flag;
extern int path[100];
extern int c;



void draw_a_map(string **, int **);
void Insert_col_row(string, int **&, string **&);
void Exclude_col_row(string, int **&, string **&);
void local_minimum_areas(string**, int**);
float find_AV_height_of_cover(string, int**, string**);
void order_rocks(string **);
void find_lines_with_same_rock(string**, int**);
void Thanks_for_using();
void find_max_area(int **, int, int, int, int);
void draw_alpinists_map(string **, int **, int, int);
void find_path(int **, string **, int, int);

#endif // FUNCTIONS_H_INCLUDED
