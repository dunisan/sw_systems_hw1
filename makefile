CC = gcc
FLAGS = -Wall
LDFLAGS = -shared
REC_SOURCES = basicClassification.o advancedClassificationRecursion.o
LOOP_SOURCES = basicClassification.o advancedClassificationLoop.o


.PHONY: all
all:  maindloop maindrec mains  


#main programs 	
mains: main.o recursives
	$(CC) $(FLAGS) -o $@ $< libclassrec.a -lm
	
maindloop: main.o loopd
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so  -lm
	
maindrec: main.o recursived
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

#static libraries 		
loops: $(LOOP_SOURCES)
	ar rcs libclassloops.a $+
	ranlib libclassloops.a
	

recursives: $(REC_SOURCES)
	ar rcs libclassrec.a $+
	ranlib libclassrec.a

#dynamic libraries
recursived: $(REC_SOURCES)
	$(CC) -shared -o libclassrec.so $+
    

loopd:$(LOOP_SOURCES)
	$(CC) -shared -o libclassloops.so $+ 
    


.PHONY:clean	
clean: 
	rm *.o *.so *.a maindloop maindrec mains
	

