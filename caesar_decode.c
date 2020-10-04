//
// Created by Sky Truong on 2020-02-27.
//

#include "decode.h"

int main ( int argc, char ** argv ) {
    int i, j;

    if ( argc > 10 ) {
        printf("Too many arguments.\n");
        return 0;
    }

    /* SETTING FLAGS */
    char * input_file = NULL;
    char * output_file = NULL;
    //char output_file[50];
    int flag_F = OFF, flag_O = OFF, flag_n = OFF, flag_s = OFF, flag_S = OFF, flag_t = OFF, flag_x = OFF;
    for ( i = 1; i < argc; i++ ) {
        if ( argv[i][0] == '-' ) {
            j = 0;
            while ( argv[i][j] != '\0' ) {
                if ( argv[i][1] == 'F' && flag_F == OFF ) {
                    flag_F = ON;
                    //printf("-F present.\n");
                    input_file = malloc(sizeof(char) * (strlen(argv[i+1]))); /* input file length */
                    strcpy(input_file, argv[i+1]); /* input file name */
                }
                if ( argv[i][1] == 'O' && flag_O == OFF ) {
                    flag_O = ON;
                    //printf("-O present.\n");
                    output_file = malloc(sizeof(char) * (strlen(argv[i+1]))); /* output file length */
                    strcpy(output_file, argv[i+1]); /* output file name */
                }
                if ( argv[i][j] == 'n' && flag_O == OFF && flag_n == OFF ) {
                    flag_n = ON;
                    //printf("-n present.\n");
                }
                if ( argv[i][j] == 's' && flag_s == OFF ) {
                    flag_s = ON;
                    //printf("-s present.\n");
                }
                if ( argv[i][j] == 'S' && flag_S == OFF ) {
                    flag_S = ON;
                    //printf("-S present.\n");
                }
                if ( argv[i][j] == 't' && flag_t == OFF ) {
                    flag_t = ON;
                    //printf("-t present.\n");
                }
                if ( argv[i][j] == 'x' && flag_x == OFF ) {
                    flag_x = ON;
                    //printf("-x present.\n");
                }
                j++;
            }
        }
    }

    /* GETTING INPUT variables */
    Node * list = NULL;
    Node * temp_ptr = NULL;
    int num_count = 0; /* Used to malloc text's content */
    char * string = NULL;
    int count_of_letters, count_of_characters = 0;
    int * table_count = NULL; /* holds frequency_table_func */
    char letter;
    int num_encode = 0, num_decode = 0;
    FILE * f1;

    /* OBTAINING TEXT FILE */
    i = 0;
    if ( flag_F == OFF ) {
        printf("Please enter a string longer than 200 characters:\n");
        while ( (letter = fgetc(stdin)) != EOF ) {
            num_count++;
            insert_last(&list, letter); /* Create a linked list of characters */
        }
        string = malloc(sizeof(char) * num_count);
        temp_ptr = list; /* Used to freeing the list later */
        while ( list != NULL ) { /* Convert linked list of characters into a string */
            string[i] = list->letter;
            list = list->next;
            i++;
        }
        string[i] = '\0';
        //printf("The string is: %s", string);
    } else {
        if ( (f1 = fopen(input_file, "r" )) != NULL ) {
            while ( (letter = fgetc(f1)) != EOF ) {
                num_count++;
                insert_last(&list, letter); /* Create a linked list of characters */
            }
            string = malloc(sizeof(char) * num_count);
            temp_ptr = list; /* Used to freeing the list later */
            while ( list != NULL ) { /* Convert linked list of characters into a string */
                string[i] = list->letter;
                list = list->next;
                i++;
            }
            string[i] = '\0';
            //printf("The file's content is:\n%s", string);
            //printf("\n");
        } else {
            printf("There is no file to read.\n");
        }
        fclose(f1);
    }

    /* Set the count */
    count_of_letters = letter_count(string);
    count_of_characters = character_count(string);
    table_count = frequency_table_func(string);
    num_encode = encode_shift(string);
    num_decode = to_decode(num_encode);

    /* Decode the file */
    char * decoded_file;
    decoded_file = decoded_text(string, num_count, num_decode);
    //printf("Decoded file is: %s\n", decoded_file);

    /* PRINTING using flags */
    FILE * f2;
    if ( flag_O == ON ) {
        f2 = fopen(output_file, "w+");
        fprintf(f2, "%s" , decoded_file);
        if (flag_s == ON) {
            printf("The shift value to decode the message is: %d\n", num_decode);
        }
        if (flag_S == ON) {
            printf("The shift value to encode the message is: %d\n", num_encode);
        }
        if ( flag_x == ON ) {
            print_chi_sq_values(string);
        }
        if (flag_t == ON) {
            printf("Number of letters in the text: %d\n", count_of_letters);
            printf("Total number of characters in the text: %d\n", count_of_characters);
            print_frequency_table(table_count);
            printf("\n");
        }
    }

    if ( flag_O == OFF ) {
        if ( flag_n == OFF ) { /* Print decoded text to stdout */
            if (flag_s == ON) {
                printf("The shift value to decode the message is: %d\n", num_decode);
                //printf("\n");
                //fprintf(stdout, "%s", decoded_file);
            }
            if (flag_S == ON) {
                printf("The shift value to encode the message is: %d\n", num_encode);
                //printf("\n");
                //fprintf(stdout, "%s", decoded_file);
            }
            if ( flag_x == ON ) {
                print_chi_sq_values(string);
            }
            if (flag_t == ON) {
                printf("Number of letters in the text: %d\n", count_of_letters);
                printf("Total number of characters in the text: %d\n", count_of_characters);
                print_frequency_table(table_count);
                printf("\n");
            }
            fprintf(stdout, "%s", decoded_file);
            printf("\n");
        } else if ( flag_n == ON ) { /* Suppress printing decoded text to stdout */
            if (flag_s == ON) {
                printf("The shift value to decode the message is: %d\n", num_decode);
            }
            if (flag_S == ON) {
                printf("The shift value to encode the message is: %d\n", num_encode);
            }
            if ( flag_x == ON ) {
                print_chi_sq_values(string);
            }
            if (flag_t == ON) {
                printf("Number of letters in the text: %d\n", count_of_letters);
                printf("Total number of characters in the text: %d\n", count_of_characters);
                print_frequency_table(table_count);
                printf("\n");
            }
        }
    }

    /* FREEING */
    list = temp_ptr; /* Set to the head of list */
    free_list(list);
    list = NULL;

    free(string);
    free(decoded_file);
    free(table_count);
    if ( flag_F == ON ) {
        free(input_file);
    }
    if ( flag_O == ON ) {
        free(output_file);
    }
    return 0;
}
