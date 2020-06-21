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

$(info TARGET is $(TARGET))
$(info	SRC is $(SRC))
$(info	OBJ is $(OBJ))

#Flags, Libraries and Includes
CFLAGS		:= -fopenmp -Wall -O3 -g
LDLIBS		:= -lm
LDFLAGS		:= -Llib

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(OBJDIR) $(BINDIR)