
EXECUTABLE = trab

OBJS = JogoConsole.o JogoPC.o Jogo.o EmpresaDesenvolvedora.o PlataformaDigital.o Main.o
SRCS = $(OBJS:.o=.cpp)
OBJDIR = obj
BINDIR = bin

CPP = g++
CFLAGS = -Wall -std=c++11

.cpp.o:	; $(CPP) -c $(CFLAGS) -o $(OBJDIR)/$@ $*.cpp

all : dirs $(OBJS)
	$(CPP) $(OBJDIR)/* -o $(BINDIR)/$(EXECUTABLE)

dirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

clean :
	rm -rf $(BINDIR) $(OBJDIR) *.o *.ln *.exe $(EXECUTABLE) *.html *.txt
