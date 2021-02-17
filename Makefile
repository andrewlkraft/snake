# Compiler
CC          := gcc

# The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR		:= src
OBJDIR		:= obj
BINDIR		:= bin

# The files to be used in the make process
TARGET		:= $(BINDIR)/snake
DEBUG		:= $(BINDIR)/debug
SRC			:= $(wildcard $(SRCDIR)/*.c)
OBJ 		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

#Flags, Libraries and Includes
CFLAGS		:= -fopenmp -Wall -O3 --std=c99
LDLIBS		:= -lm
LDFLAGS		:= -Llib
SDLFLAGS	:= `sdl2-config --cflags --libs` -lSDL2_image
GFLAGS		:= -mconsole

.PHONY: all clean debug

all: $(TARGET)

debug: $(DEBUG)

$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) $(SDLFLAGS) -o $@

$(DEBUG): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) $(SDLFLAGS) $(GFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(OBJDIR) $(BINDIR)