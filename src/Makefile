#CC:=gcc
VERSION:=1.6.7

CFLAGS+= -Wall -fPIC -DDEBUG -DVERSION=$(VERSION)

objects= config.o auth.o

# detect OS
ifeq ($(OS), Windows_NT)
# windows
LIBS+= -lws2_32
CFLAGS+= -DWIN32
#CFLAGS+=-m32
DLLNAME=gdut-drcom.dll.$(VERSION)
RM=del
else
# unix like
DLLNAME=gdut-drcom.so.$(VERSION)
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

all: gdut-drcom 
	@echo gdut-drcom

gdut-drcom: $(objects) gdut-drcom.o
	$(CC) *.o -o gdut-drcom $(CFLAGS) $(LIBS)

dll: $(objects)
	@echo gdut-drcom shared library
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
	$(RM) gdut-drcom $(DLLNAME) *.o 
