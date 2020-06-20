#Compiler and Linker
CC          := gcc

#The Target Binary Program
TARGET      := snake

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
BUILDDIR    := obj
TARGETDIR   := bin
SRCEXT      := c
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -fopenmp -Wall -O3 -g
LIB         := 

.PHONY: All clean

All: $(TARGET)

$(TARGET): %.o : %.c
	$(CC) $(CFLAGS)

clean:

