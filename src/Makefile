CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
COVERAGE = --coverage

SRC_DIR := ./MAIN_TASK
TESTS_DIR := TESTS
GCOV_DIR := BUILD
REPORT_DIR := report_gcov

TEST_BINARY := $(TESTS_DIR)/test.out
REPORT_BINARY := $(REPORT_DIR)/report.out

REPORT_FILE := $(REPORT_DIR)/report.html
OPEN_REPORT := open $(REPORT_FILE)
HEADERS := matrix.h

SOURCES := $(shell find $(SRC_DIR) -name '*.c')
OBJECTS := $(SOURCES:%.c=%.o)

GCOV_OBJECTS := $(SOURCES:%=$(GCOV_DIR)/%.o)

UNAME_S := $(shell uname -s)
UNAME_O := $(shell uname -o)
ifeq ($(UNAME_S),Linux)
	GCOV_FLAGS := --gcov-exclude $(TESTS_DIR)
	LEAKS_CMD := CK_FORK=no valgrind --tool=memcheck --leak-check=full --track-origins=yes -s  $(TEST_BINARY)
endif

ifeq ($(UNAME_S),Darwin)
	GCOV_FLAGS := --gcov-exclude-directories $(TESTS_DIR)
	LEAKS_CMD := CK_FORK=no leaks --atExit -- $(TEST_BINARY)
endif
ifeq ($(UNAME_O), Linux)
	CFLAGS += -DALPINE
endif

# Build step for C source
$(GCOV_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COVERAGE) -c $< -o $@

matrix.a: $(OBJECTS)
	ar rc matrix.a $(OBJECTS)
	ranlib matrix.a
	rm -rf ./**/*.o

compile_gcov: $(GCOV_OBJECTS)
	ar rc matrix.a $(GCOV_OBJECTS)
	ranlib matrix.a
	rm -rf ./**/*.o

gcov_report: clean compile_gcov $(SOURCES)
	mkdir -p $(REPORT_DIR)
	$(CC) $(CFLAGS) $(COVERAGE) $(TESTS_DIR)/*.c $(HEADERS) matrix.a -o $(REPORT_BINARY) `pkg-config --cflags --libs check`
	$(REPORT_BINARY)
	gcovr $(GCOV_FLAGS) -o $(REPORT_FILE) --html-details
	make clean_coverage
	$(OPEN_REPORT)

test: clean compile_gcov $(SOURCES)
	$(CC) $(CFLAGS) $(COVERAGE) $(TESTS_DIR)/*.c matrix.a -o $(TEST_BINARY) `pkg-config --cflags --libs check`
	$(TEST_BINARY)
	gcovr $(GCOV_FLAGS) -s

leaks: clean matrix.a $(SOURCES)
	$(CC) $(CFLAGS) $(COVERAGE) $(TESTS_DIR)/*.c matrix.a -o $(TEST_BINARY) `pkg-config --cflags --libs check`
	$(LEAKS_CMD) || true

all: matrix.a

rebuild: clean all

clean_coverage:
	rm -rf $(GCOV_DIR) 2> /dev/null
	find . -name "*.gcno" -type f -delete
	find . -name "*.gcda" -type f -delete
	find . -name "*.o" -type f -delete
	find . -name "*.out" -type f -delete

clean: clean_coverage
	rm -rf ./**/*.a ./**/*.info ./**/*.gcov 2> /dev/null
	rm -f matrix.a 2> /dev/null
	rm -rf $(REPORT_DIR) 2> /dev/null

cppcheck:
	cppcheck --std=c11 --enable=all --suppress=missingIncludeSystem ./**/*.c

lint:
	find . -name "*.c" -exec clang-format -i --style=Google {} \;
	find . -name "*.h" -exec clang-format -i --style=Google {} \;
