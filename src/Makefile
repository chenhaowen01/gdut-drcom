#CC:=gcc
VERSION:=1.6.7
NAME=gdut-drcom

CFLAGS+= -Wall -O3 -fPIC -DDEBUG -DVERSION=$(VERSION)

objects= config.o auth.o logger.o

# detect OS
ifeq ($(OS), Windows_NT)
# windows
CC=gcc
LIBS+= -lws2_32
CFLAGS+= -DWIN32
DLLNAME=$(NAME).dll.$(VERSION)
BINNAME=$(NAME).exe
RM=del
else
# unix like
DLLNAME=$(NAME).so.$(VERSION)
BINNAME=$(NAME)
RM=rm -f
endif

# crypto lib
ifeq ($(cryptlib), polarssl)
CFLAGS+=-D__WITH_POLARSSL__
LIBS+=-lpolarssl
else ifeq ($(cryptlib), gcrypt)
CFLAGS+=-D__WITH_GCRYPT__
LIBS+=-lgcrypt
else ifeq ($(cryptlib), openssl)
CFLAGS+=-D__WITH_OPENSSL__
LIBS+=-lcrypto
else
# default
objects+= md5.o md4.o sha1.o
endif

all: $(BINNAME)

$(BINNAME): $(objects) gdut-drcom.o
	$(CC) *.o -o $(BINNAME) $(CFLAGS) $(LIBS)

dll: $(objects)
	$(CC) -shared $(objects) -o $(DLLNAME) $(CFLAGS) $(LIBS)

gdut-drcom.o: gdut-drcom.c
	$(CC) $(CFLAGS) -c $<

config.o: config.c config.h
	$(CC) $(CFLAGS) -c $<
auth.o: auth.c config.h
	$(CC) $(CFLAGS) -c $<

md5.o md4.o sha1.o:
	$(CC) -c crypt/*.c $(CFLAGS)

.PHONY : clean
clean:
	$(RM) $(BINNAME) $(DLLNAME) *.o 
