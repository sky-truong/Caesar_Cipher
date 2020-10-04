There are 2 programs in this repo.
The first is a stand-alone encode.c, the rest belongs to decode.c.

Disclaimer: At the moment, the command line flags are quite strict.
            More work will be done to make it flow better.

>>>>>>>>> ENCODE.C <<<<<<<<<
Encodes a message from a file using the Caesar Cipher with a shift as entered as a command line argument.
The results will be placed in a new file.
The program accepts positive and negative shift values from -25 to 25.
The program takes in a three command line arguments:
1/ the shift number
    If no shift number is present, the program uses a Rot13 encoding.

2/ -F <input_file_name>
    If the -F argument is missing, the program reads from stdin.
    (to end the input, press ^d on the keyboard, which inserts the EOF character)

3/ -O <output_file_name>
    If the -O argument is missing, the output goes to stdout.

To compile encode.c:
gcc -std=c99 -Wall -c encode.c -o encode
./encode 10 -F sample.txt -O output.txt
./encode 15
and so on...

>>>>>>>>> DECODE.C <<<<<<<<<
Decodes a message that has been shifted.
The program takes in these command line arguments:
1/ -F <input_file_name>
    If the -F argument is missing, the program reads from stdin.
    (to end the input, press ^d on the keyboard, which inserts the EOF character)

2/ -O <output_file_name>
    If the -O argument is missing, the output goes to stdout.

3/ -n Suppresses the printing of the decoded file to stdout. Useful in combination with -s or –S.
    If -O is included as a command line argument -n does nothing.

4/ -s Prints the Caesar shift value used to decode the message to stdout (e.g. shift = 4).

5/ -S Prints the original Caesar shift value used to encode the message to stdout (e.g. shift = 4).

6/ -t Prints the character/letter count summary and frequency table to stdout.

7/ -x Prints the chi squared value for all shifts along with their corresponding shift values.

-To compile decode.c:
    make all
-To clean all object files:
    make clean
-Examples of command line arguments:
./decode -stx -F encoded_sample1.txt -O decoded.txt
./decoded -F encoded_sample1.txt
./decoded -S -F encoded_sample2.txt -O new_file.txt
and so on...

2 sample files are included but try as many as you like!
Have fun!