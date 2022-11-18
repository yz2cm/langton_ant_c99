CC            = gcc
CFLAGS        = -O2 -std=c99 -pedantic -Wall -Wextra
#LDFLAGS       = -L/usr/local/lib
#LIBS          = -lhoge -lm
OBJS          = main.o common.o  ant.o matrix.o black_point_list.o play.o
PROGRAM       = langton_ant

all:            $(PROGRAM)

$(PROGRAM):		$(OBJS)
				$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;         rm -f *.o *~ $(PROGRAM)
