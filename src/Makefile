#CC:=gcc
CFLAGS+=-DDEBUG
#cryptlib=openssl
#ifeq ($(lib), openssl)
#	CFLAGS+=-D_WITH_OPENSSL_
#	LIBS:=-lcrypto 
#else
#	LIBS:=-lpolarssl
#endif

ifeq ($(cryptlib), polarssl)
	CFLAGS+=-D__WITH_POLARSSL__
	LIBS:=-lpolarssl
else ifeq ($(cryptlib), gcrypt)
	CFLAGS+=-D__WITH_GCRYPT__
	LIBS:=-lgcrypt
else
	LIBS:=-lcrypto
endif
	

all: gdut-drcom 
	@echo gdut-drcom
gdut-drcom: gdut-drcom.o config.o auth.o
	$(CC) gdut-drcom.o config.o auth.o -o gdut-drcom $(CFLAGS) $(LIBS)

gdut-drcom.o: gdut-drcom.c
	$(CC) $(CFLAGS) -c $<

config.o: config.c config.h
	$(CC) $(CFLAGS) -c $<
auth.o: auth.c config.h
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f gdut-drcom *.o
