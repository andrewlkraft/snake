# Compiler
CC          := gcc

# The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR		:= src
OBJDIR		:= obj
BINDIR		:= bin

# The files to be used in the make process
TARGET		:= $(BINDIR)/snake
SRC			:= $(wildcard $(SRCDIR)/*.c)
OBJ 		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

#Flags, Libraries and Includes
CFLAGS		:= -fopenmp -Wall -O3 --std=c99
LDLIBS		:= -lm
LDFLAGS		:= -Llib
SDLFLAGS	:= -lmingw32 -lSDL2main -lSDL2
DEBUG		:= -g

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) $(SDLFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(OBJDIR) $(BINDIR)