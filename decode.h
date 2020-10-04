#define ALPHABET_MIN 0
#define ALPHABET_MAX 26
#define EF {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.0228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, \
0.04025, 0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, \
0.00150, 0.01974, 0.00074}
#define SHIFT_MIN 0
#define SHIFT_MAX 25
#define ON 1
#define OFF 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char letter;
    struct element * next;
} Node;

typedef struct data {
    char first_string[24];
    double double_values[24];
    char second_string[144];
    int int_values[12];
} record;

int letter_count ( char * string );
int character_count ( char * string );
int * frequency_table_func (char * string );
void print_frequency_table ( int * freq_array );

/* Source: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/ */
void insert_last ( Node ** head, char main_letter );
char encode ( char c, int shift );
char * decoded_text ( char * string, int size, int shift );
int offset ( char c );
int encode_shift ( char * string );
void print_chi_sq_values ( char * string );
int to_decode ( int shift );
void free_list ( Node * head );
double power ( double num, int pow);
int file_size ( FILE *fp );
int num_records ( int record_size );




