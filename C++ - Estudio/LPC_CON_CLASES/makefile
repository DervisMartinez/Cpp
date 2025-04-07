TARGET =	RUN
# Nombre del ejecutable
TARGET = lpc

LIBS =	-lm
CC =	g++
CFLAGS =	-g -std=gnu++98

.PHONY:	default all clean

default:	$(TARGET)
all:	default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o:	%.c $(HEADERS)
	$(CC)	$(CFLAGS) -c $< -o $@

.PRECIOUS:	$(TARGET)	$(OBJECTS)

$(TARGET):	$(OBJECTS)
	$(CC)	$(OBJECTS)	$(LIBS) -o $@

clean:
	-rm -f *o core

cleanall:
	-rm -f $(TARGET)
