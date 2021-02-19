# Compiler
CC          := gcc

# The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR		:= src
OBJDIR		:= obj
BINDIR		:= bin

# The files to be used in the make process
TARGET			:= $(BINDIR)/snake
DEBUGEXE		:= $(BINDIR)/debug
SRC				:= $(wildcard $(SRCDIR)/*.c)
OBJ 			:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

#Flags, Libraries and Includes
CFLAGS		:= -fopenmp -Wall -O3 --std=c99
LDLIBS		:= -lm
LDFLAGS		:= -Llib
SDLFLAGS	:= `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) $(SDLFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(GFLAGS) $(CFLAGS) -c $< -o $@

debug: GFLAGS = -g
debug: $(DEBUGEXE)

$(DEBUGEXE): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) $(SDLFLAGS) -mconsole -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(OBJDIR) $(BINDIR)