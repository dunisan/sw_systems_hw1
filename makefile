
CC = gcc
FLAGS = -Wall
LDFLAGS = -shared
REC_SOURCES = basicClassification.o advancedClassificationRecursion.o
LOOP_SOURCES = basicClassification.o advancedClassificationLoop.o
SRCS = basicClassification.o advancedClassificationRecursion.o advancedClassificationLoop.o
OBJS = $(SRCS:.c=.o)

all:  maindloop maindrec mains loops
	
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o $@ $< libclassrec.a -lm
	
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) main.o ./libclassloops.so -o maindloop   -lm
	
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

libclassloops.a: $(LOOP_SOURCES)
	ar rcs $@ $+
	ranlib libclassloops.a
loops: libclassloops.a

libclassrec.a: $(REC_SOURCES)
	ar rcs $@ $+
	ranlib libclassrec.a
recursives: libclassrec.a

libclassrec.so: $(REC_SOURCES)
	$(CC) -shared -fPIC -o $@ $+
recursived: libclassrec.so

libclassloops.so:$(LOOP_SOURCES)
	$(CC) -shared -fPic -o $@ $+ 
loopd: libclassloops.so

%.o: %.c Numclass.h
	$(CC) -Wall -c $< -o $@
    
clean: 
	rm *.o *.so *.a maindloop maindrec mains
	
