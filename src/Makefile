#CC:=gcc
VERSION:=1.6.1
CFLAGS+= -Wall -fPIC -DDEBUG -DVERSION=\"$(VERSION)\"

objects= config.o auth.o

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
DLLNAME=gdut-drcom.dll
else
DLLNAME=gdut-drcom.so
endif

gdut-drcom: $(objects) gdut-drcom.o
	$(CC) *.o -o gdut-drcom $(CFLAGS) $(LIBS)

dll: $(objects)
	$(CC) -shared $(objects) -o $(DLLNAME) $(CFLAGS) $(LIBS)

tarball: *.c *.h
	tar cjf ../release/gdut-drcom-$(VERSION).tar.bz2 -C ../.. gdut-drcom --exclude=gdut-drcom/release --exclude=gdut-drcom/.git
	md5sum ../release/gdut-drcom-$(VERSION).tar.bz2

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
ifeq ($(LANG),)
	del gdut-drcom.exe *.o *.dll
else
	$(RM) gdut-drcom *.o *.so
endif
