OBJ = caesar_decode.o letter_count.o character_count.o frequency_table_func.o insert_last.o free_list.o encode.o decoded_text.o \
		offset.o encode_shift.o print_chi_sq_values.o to_decode.o print_frequency_table.o power.o
DEPS = decode.h
CC = gcc
CFLAGS = -Wall

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $ $@ $<

caesar_decode: $(OBJ)
	$(CC) $(CFLAGS) -o $ $@ $^

all: caesar_decode

clean:
	rm -f $(OBJ) caesar_decode
