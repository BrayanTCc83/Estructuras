.PHONY: run

SOURCE=src
HEADERS=$(SOURCE)/headers
MAIN=$(SOURCE)/main.c
STRUCTS=$(SOURCE)/structs/*.c

DISTRIBUTION=dist
OUTPUT=$(DISTRIBUTION)/Estructuras

CC:=gcc

run: $(MAIN) $(STRUCTS) $(HEADERS)/*.h | $(DISTRIBUTION)
	@echo Compile program.
	$(CC) -o $(OUTPUT) $(MAIN) $(STRUCTS) -I $(HEADERS) -DDEV

$(DISTRIBUTION):
	@echo Making directory $(DISTRIBUTION).
	mkdir $(DISTRIBUTION)