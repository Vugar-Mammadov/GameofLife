# _*_MakeFile_*_

CC=gcc

SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
INCLUDES=$(wildcard *.h)
EXECUTABLE=gameoflife

#########################
# Rules
#########################

all : $(EXECUTABLE)


$(EXECUTABLE) : $(OBJECTS)
	${CC} -o $@ $^ ${LIBS}

.c.o:
	$(CC) -c $^ -o $@

clean :
	rm $(OBJECTS) *~

doc:
	doxygen

dist:
	 tar -czvf gameoflife.tar.gz $(SOURCES) $(INCLUDES) Makefile