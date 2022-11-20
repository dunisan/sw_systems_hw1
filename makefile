CC = gcc
FLAGS = -Wall
LDFLAGS = -shared
REC_SOURCES = basicClassification.o advancedClassificationRecursion.o
LOOP_SOURCES = basicClassification.o advancedClassificationLoop.o


all:  maindloop maindrec mains  


mains: main.o recursives
	$(CC) $(FLAGS) -o $@ $< libclassrec.a -lm
	
maindloop: main.o loopd
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so  -lm
	
maindrec: main.o recursived
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
	$(CC) -shared -o $@ $+
recursived: libclassrec.so

libclassloops.so:$(LOOP_SOURCES)
	$(CC) -shared -o $@ $+ 
loopd: libclassloops.so

clean: 
	rm *.o *.so *.a maindloop maindrec mains
	

