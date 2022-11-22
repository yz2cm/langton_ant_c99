CC            = gcc
CFLAGS        = -O2 -std=c99 -pedantic -Wall -Wextra \
                -Wbad-function-cast -Wcast-align -Wcast-qual -Wconversion -Wdouble-promotion -Wfloat-equal \
				-Winit-self -Wjump-misses-init -Wlogical-op -Wmissing-declarations -Wmissing-prototypes \
				-Wsign-conversion -Wmultichar -Wold-style-definition -Wpacked -Wpointer-arith \
				-Wredundant-decls -Wshadow -Wstack-protector -Wstrict-prototypes -Wsuggest-attribute=format \
				-Wsuggest-attribute=noreturn -Wswitch-default -Wswitch-enum -Wtraditional-conversion \
				-Wunsafe-loop-optimizations -Wunsuffixed-float-constants -Wvariadic-macros -Wvector-operation-performance \
				-Wwrite-strings -Wunused-macros
#LDFLAGS       = -L/usr/local/lib
#LIBS          = -lhoge -lm
OBJS          = main.o src/common.o src/ant.o src/matrix.o src/matrix_line_list.o src/matrix_line.o src/black_point_list.o src/play.o
PROGRAM       = build/langton_ant

all:            $(PROGRAM)

$(PROGRAM):		$(OBJS)
				$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;         rm -f *.o src/*.o src/*.gch *~ $(PROGRAM)
