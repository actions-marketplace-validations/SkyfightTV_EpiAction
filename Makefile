##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

.SILENT:

OUT = bsq
OUT_T = unit_tests
COVERAGE_DIR = coverage

COMP = cc
COMP_FLAGS = -O3 -I./includes -g

SRC = bsq.c \
	process.c \
	read.c
TESTS = tests/tests_bsq.c \
	tests/tests_process.c \
	tests/tests_read.c
OBJ = $(SRC:.c=.o)

all: $(OUT)

%.o : %.c
	$(COMP) $(COMP_FLAGS) -o $@ -c $<

$(OUT): $(OBJ)
	$(COMP) $(COMP_FLAGS) -o $(OUT) $(OBJ)

unit_tests: fclean $(OUT)
	$(COMP) $(COMP_FLAGS) -o $(OUT_T) $(TESTS) \
	$(SRC:bsq.c=) --coverage -lcriterion

tests_run: unit_tests
	./tests/tests_maps.sh bsq
	./$(OUT_T)

coverage: tests_run
	rm -rf $(COVERAGE_DIR)
	gcovr --branches --exclude tests
	mkdir $(COVERAGE_DIR)
	gcovr --branches --exclude tests --html-details -o \
	./$(COVERAGE_DIR)/index.html
	make fclean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)
	rm -f *.g*
	rm -f $(OUT_T)

c_fclean : fclean
	rm -rf $(COVERAGE_DIR)

re : fclean $(OUT)
