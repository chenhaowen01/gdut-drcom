#CC:=gcc
CFLAGS+= -Wall -DDEBUG -DVERSION=\"1.6-0\"

objects=gdut-drcom.o config.o auth.o

all: gdut-drcom 
	@echo gdut-drcom

ifeq ($(cryptlib), polarssl)
CFLAGS+=-D__WITH_POLARSSL__
LIBS:=-lpolarssl
else ifeq ($(cryptlib), gcrypt)
CFLAGS+=-D__WITH_GCRYPT__
LIBS:=-lgcrypt
else ifeq ($(cryptlib), openssl)
CFLAGS+=-D__WITH_OPENSSL__
LIBS:=-lcrypto
else
objects+= md5.o md4.o sha1.o
endif

ifeq ($(LANG),)
LIBS+= -lws2_32
endif

gdut-drcom: $(objects)
	$(CC) *.o -o gdut-drcom $(CFLAGS) $(LIBS)

gdut-drcom.o: gdut-drcom.c
	$(CC) $(CFLAGS) -c $<

config.o: config.c config.h
	$(CC) $(CFLAGS) -c $<
auth.o: auth.c config.h
	$(CC) $(CFLAGS) -c $<

md5.o md4.o sha1.o:
	$(CC) -c crypt/*.c

.PHONY : clean
clean:
ifeq ($(LANG),)
	del gdut-drcom.exe *.o
else
	$(RM) gdut-drcom *.o
endif
