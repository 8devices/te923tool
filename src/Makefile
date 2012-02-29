all: te923con 

clean:
	rm -f *.o te923con

te923con: te923con.c te923con.h te923.h te923_com.h te923_usb.h
	$(CC) $(CFLAGS) -Wall -o te923con te923con.c -lusb $(LIBS)

