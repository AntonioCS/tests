CFLAGS=-Wall -g -std=c99 -o
CC=gcc
DEPENDENCIES_WILDCARD=wildcards_main.c wildcards.c wildcards.h

wildcard: $(DEPENDENCIES_WILDCARD)
	$(CC) $(CFLAGS) $@ $(DEPENDENCIES_WILDCARD)

DEPENDENCIES_CONSOLE_DATA=console_data_main.c console_data.c console_data.h

console_data: $(DEPENDENCIES_CONSOLE_DATA)
	$(CC) $(CFLAGS) $@ $(DEPENDENCIES_CONSOLE_DATA)


pointerTest: pointerTests.c
	$(CC) $(CFLAGS) $@ $^

structPassingTest: struct_passing_test.c
	$(CC) $(CFLAGS) $@ $^
	
stringTest: string_read.c
	$(CC) $(CFLAGS) $@ $^
	
clean:
	
