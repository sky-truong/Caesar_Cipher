#define ALPHABET_MAX 26
#define ALPHABET_MIN 0
#define LENGTH 500
#define NAME 20
#define ROT13 0
#define NOT_ROT13 1
#define OVER 0
#define NOT_OVER 1
#define EXIST 1
#define NOT_EXIST 0
#define DEFAULT_SHIFT 13


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * ceasar_shift (char letter, int shift) {
    int upper_case, lower_case, new_shift, temp = 0;
    char * rot_letter = malloc(sizeof(char));
    lower_case = letter - 'a'; /*determine lower case starting letter*/
    upper_case = letter - 'A'; /*determine upper case starting letter*/
    if ( lower_case >= ALPHABET_MIN && lower_case < ALPHABET_MAX ) {
        if ( shift > 0 ) {
            temp = ((lower_case + shift) % 26) + 97;
        } else if ( shift < 0 ) {
            new_shift = 26 + shift;
            temp = ((lower_case + new_shift) % 26) + 97;
        }
        //temp = ((lower_case + shift) % 26) + 97;
        *rot_letter = (char) temp;
    } else if ( upper_case >= ALPHABET_MIN && upper_case < ALPHABET_MAX ) {
        if ( shift > 0 ) {
            temp = ((upper_case + shift) % 26) + 65;
        } else if ( shift < 0 ) {
            new_shift = 26 + shift;
            temp = ((upper_case + new_shift) % 26) + 65;
        }
        //temp = ((upper_case + shift) % 26) + 65;
        *rot_letter = (char) temp;
    } else {
        *rot_letter = letter;
    }
    return rot_letter;
}

int check_shift ( int shift ) {
    if ( abs(shift) >= 26 ) {
        return OVER;
    } else {
        return NOT_OVER;
    }
}

int main ( int argc, char * argv[] ) {
    int num_shift = 0;
    int i;
    int flag = ROT13;
    char input_file[NAME];
    char output_file[NAME];
    char string[LENGTH];
    char *encoded = NULL;
    int output = NOT_EXIST;
    int input = NOT_EXIST;
    int input_flag = 0;
    int output_flag = 0;
    FILE * original_file;
    FILE * copied_file;



    if ( argc == 6 ) { /* All arguments present */
        for (i = 0; i < 6; i++) {
            if (atoi(argv[i]) != 0) {
                num_shift = (atoi)(argv[i]);
                //printf("num %d\n", num_shift);
                if (check_shift(num_shift) == OVER) {
                    fprintf(stderr, "%s\n", "The shift value is between -25 and 25.");
                    return 0;
                }
                if ( num_shift == 0 && strcmp("0", argv[i]) != 0 ) {
                    fprintf(stderr, "%s\n", "Please enter numeric value for shift.");
                    return 0;
                }
            }

            if (strcmp("-F", argv[i]) == 0) { /* Checking for input file name */
                strcpy(input_file, argv[i + 1]);
            }

            if (strcmp("-O", argv[i]) == 0) { /* Checking for output file name */
                strcpy(output_file, argv[i + 1]);
            }
        }

        if ( num_shift == 0 ) { /* NO SHIFT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                copied_file = fopen(output_file, "w+");
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    fputc(string[i], copied_file);
                    i++;
                }
            }
            fclose(original_file);
            fclose(copied_file);
            return 0;
        }

        if ((original_file = fopen(input_file, "r")) == NULL) {
            printf("No file to read.\n");
            return 0;
        } else {
            copied_file = fopen(output_file, "w+");
            i = 0;
            /*Put encoded string to specified file*/
            while ( (string[i] = fgetc(original_file)) != EOF ) {
                encoded = ceasar_shift(string[i], num_shift);
                fputc(*encoded, copied_file);
                i++;
            }
        }
        fclose(original_file);
        fclose(copied_file);

    } else if ( argc == 5 ) { /* Spaces between file names with regards to -F and -O but no shift number*/
        for (i = 0; i < 5; i++) {
            if (strcmp("-F", argv[i]) == 0) { /* Checking for input file name */
                strcpy(input_file, argv[i + 1]);
            }

            if (strcmp("-O", argv[i]) == 0) { /* Checking for output file name */
                strcpy(output_file, argv[i + 1]);
            }
        }

        if ((original_file = fopen(input_file, "r")) == NULL) {
            printf("No file to read.\n");
            return 0;
        } else {
            copied_file = fopen(output_file, "w+");
            i = 0;
            /*Put encoded string to specified file*/
            while ( (string[i] = fgetc(original_file)) != EOF ) {
                encoded = ceasar_shift(string[i], DEFAULT_SHIFT);
                fputc(*encoded, copied_file);
                i++;
            }
        }
        fclose(original_file);
        fclose(copied_file);

    } else if ( argc == 4 ) { /* No spaces between file names with -F and -O*/
        //printf("argc = 4\n");
        /* Check if output and input files are on command line */
        for ( i = 0; i < 4; i++ ) {
            if ( strncmp("-F", argv[i], 2) == 0 ) {
                input = EXIST;
                input_flag = 1;
            } else if ( strncmp("-F", argv[i], 2) != 0 && input_flag == 0 ) {
                input = NOT_EXIST;
            }
            if ( strncmp("-O", argv[i], 2) == 0 ) {
                output = EXIST;
                output_flag = 1;
            } else if ( strncmp("-O", argv[i], 2) != 0 && output_flag == 0 ) {
                output = NOT_EXIST;
            }
        }

        for ( i = 0; i < 4; i++ ) {
            if ( atoi(argv[i]) != 0 ) {
                num_shift = (atoi)(argv[i]);
                //printf("num %d\n", num);
                if ( check_shift(num_shift) == OVER ) {
                    fprintf(stderr, "%s\n", "The shift value is between -25 and 25.");
                    return 0;
                }
            }

            if ( strncmp("-F", argv[i], 2) == 0 && output == EXIST ) { /* Checking for input file name */
                strncpy(input_file, argv[i]+2, NAME);
                input = EXIST;
                //printf("input here %s\n", input);
            } else if ( strncmp("-F", argv[i], 2) == 0 && output == NOT_EXIST) {
                strncpy(input_file, argv[i+1], NAME);
            }

            if ( strncmp("-O", argv[i], 2) == 0 && input == EXIST ) { /* Checking for output file name */
                strncpy(output_file, argv[i]+2, NAME);
                output = EXIST;
                //printf("output here %s\n", output);
            } else if ( strncmp("-O", argv[i], 2) == 0 && input == NOT_EXIST ) {
                strncpy(output_file, argv[i+1], NAME);
            }
        }

        if ( num_shift == 0 ) { /* NO SHIFT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                copied_file = fopen(output_file, "w+");
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    fputc(string[i], copied_file);
                    i++;
                }
            }
            fclose(original_file);
            fclose(copied_file);
            return 0;
        }

        if ( output == EXIST && input == EXIST ) { /* BOTH OUTPUT AND INPUT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                copied_file = fopen(output_file, "w+");
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    encoded = ceasar_shift(string[i], num_shift);
                    fputc(*encoded, copied_file);
                    i++;
                }
            }
            fclose(original_file);
            fclose(copied_file);
        }  else if ( output == NOT_EXIST && input == EXIST ) { /* NO OUTPUT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    encoded = ceasar_shift(string[i], num_shift);
                    fputc(*encoded, stdout);
                    i++;
                }
                printf("\n");
            }
            fclose(original_file);
        } else if ( output == EXIST && input == NOT_EXIST ) { /* NO INPUT */
            copied_file = fopen(output_file, "w+");
            printf("Please enter a string to encode:\n");
            /*Get input from stdin*/
            i = 0;
            fgets(&string[i], LENGTH, stdin);
            /*Print encoded string to stdout*/
            i = 0;
            while ( string[i] != '\0') {
                encoded = ceasar_shift(string[i], num_shift);
                fputc(*encoded, copied_file);
                i++;
            }
            fclose(copied_file);
        }
    } else if ( argc == 3 ) { /* No space between file names and -F or -O, OR no shift number */
        //printf("argc = 3\n");
        /* Check if output and input files are on command line */
        for ( i = 0; i < 3; i++ ) {
            if ( strncmp("-F", argv[i], 2) == 0 ) {
                input = EXIST;
                input_flag = 1;
            } else if ( strncmp("-F", argv[i], 2) != 0 && input_flag == 0 ) {
                input = NOT_EXIST;
            }
            if ( strncmp("-O", argv[i], 2) == 0 ) {
                output = EXIST;
                output_flag = 1;
            } else if ( strncmp("-O", argv[i], 2) != 0 && output_flag == 0 ) {
                output = NOT_EXIST;
            }
        }

        //printf("test 1\n");

        for ( i = 0; i < 3; i++ ) {
            if (atoi(argv[i]) != 0) {
                num_shift = (atoi)(argv[i]);
                //printf("num %d\n", num);
                if (check_shift(num_shift) == OVER) {
                    fprintf(stderr, "%s\n", "The shift value is between -25 and 25.");
                    return 0;
                }
            }

            if (strncmp("-F", argv[i], 2) == 0) { /* Checking for input file name */
                strncpy(input_file, argv[i] + 2, NAME);
                //printf("input here %s\n", input);
            }

            if (strncmp("-O", argv[i], 2) == 0) { /* Checking for output file name */
                strncpy(output_file, argv[i] + 2, NAME);
                //printf("output here %s\n", output);
            }
        }

        if ( num_shift == 0 ) { /* NO SHIFT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                copied_file = fopen(output_file, "w+");
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    fputc(string[i], copied_file);
                    i++;
                }
            }
            fclose(original_file);
            fclose(copied_file);
            return 0;
        }

        //printf("test 2\n");

        if ( output == EXIST && input == EXIST ) { /* BOTH OUTPUT AND INPUT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                copied_file = fopen(output_file, "w+");
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    encoded = ceasar_shift(string[i], DEFAULT_SHIFT);
                    fputc(*encoded, copied_file);
                    i++;
                }
            }
            fclose(original_file);
            fclose(copied_file);
        }  else if ( output == NOT_EXIST && input == EXIST ) { /* NO OUTPUT */
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    encoded = ceasar_shift(string[i], num_shift);
                    fputc(*encoded, stdout);
                    i++;
                }
                printf("\n");
            }
            fclose(original_file);
        } else if ( output == EXIST && input == NOT_EXIST ) { /* NO INPUT */
            copied_file = fopen(output_file, "w+");
            printf("Please enter a string to encode:\n");
            /*Get input from stdin*/
            i = 0;
            fgets(&string[i], LENGTH, stdin);
            /*Print encoded string to stdout*/
            i = 0;
            while ( string[i] != '\0') {
                encoded = ceasar_shift(string[i], num_shift);
                fputc(*encoded, copied_file);
                i++;
            }
            fclose(copied_file);
        }

    } else if ( argc == 2 ) { /* ONLY 1 ARGUMENT */
        /* Check if output and input files are on command line */
        for ( i = 0; i < 2; i++ ) {
            if ( strncmp("-F", argv[i], 2) == 0 ) {
                input = EXIST;
                input_flag = 1;
            } else if ( strncmp("-F", argv[i], 2) != 0 && input_flag == 0 ) {
                input = NOT_EXIST;
            }
            if ( strncmp("-O", argv[i], 2) == 0 ) {
                output = EXIST;
                output_flag = 1;
            } else if ( strncmp("-O", argv[i], 2) != 0 && output_flag == 0 ) {
                output = NOT_EXIST;
            }
        }

        for ( i = 0; i < 2; i++ ) {
            if (atoi(argv[i]) != 0) {
                num_shift = (atoi)(argv[i]);
                //printf("num %d\n", num);
                if (check_shift(num_shift) == OVER) {
                    fprintf(stderr, "%s\n", "The shift value is between -25 and 25.");
                    return 0;
                }
                flag = NOT_ROT13;
            } else if (atoi(argv[i]) == 0) {
                flag = ROT13;
            }

            if (strncmp("-F", argv[i], 2) == 0) { /* Checking for input file name */
                strncpy(input_file, argv[i] + 2, NAME);
                //printf("input here %s\n", input);
            }

            if (strncmp("-O", argv[i], 2) == 0) { /* Checking for output file name */
                strncpy(output_file, argv[i] + 2, NAME);
                //printf("output here %s\n", output);
            }
        }

        if ( flag == NOT_ROT13 ) { /* SHIFT ARGUMENT */
            printf("Please enter a string to encode:\n");
            /*Get input from stdin*/
            i = 0;
            fgets(&string[i], LENGTH, stdin);
            /*Print encoded string to stdout*/
            i = 0;
            while ( string[i] != '\0') {
                encoded = ceasar_shift(string[i], num_shift);
                fputc(*encoded, stdout);
                i++;
            }
            printf("\n");
        } else if ( input == EXIST ) {
            if ((original_file = fopen(input_file, "r")) == NULL) {
                printf("No file to read.\n");
                return 0;
            } else {
                i = 0;
                /*Put encoded string to specified file*/
                while ( (string[i] = fgetc(original_file)) != EOF ) {
                    encoded = ceasar_shift(string[i], DEFAULT_SHIFT);
                    fputc(*encoded, stdout);
                    i++;
                }
                printf("\n");
            }
            fclose(original_file);
        } else if ( output == EXIST ) {
            copied_file = fopen(output_file, "w+");
            printf("Please enter a string to encode:\n");
            /*Get input from stdin*/
            i = 0;
            fgets(&string[i], LENGTH, stdin);
            /*Print encoded string to stdout*/
            i = 0;
            while ( string[i] != '\0') {
                encoded = ceasar_shift(string[i], DEFAULT_SHIFT);
                fputc(*encoded, copied_file);
                i++;
            }
            fclose(copied_file);
        }
    } else if ( argc == 1 ) { /* NO ARGUMENT */
        printf("Please enter a string to encode:\n");
        /*Get input from stdin*/
        i = 0;
        fgets(&string[i], LENGTH, stdin);
        /*Print encoded string to stdout*/
        i = 0;
        while ( string[i] != '\0') {
            encoded = ceasar_shift(string[i], DEFAULT_SHIFT);
            fputc(*encoded, stdout);
            i++;
        }
    }
    free(encoded);
    return 0;
}