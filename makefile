addressbook.exe : main.o contact.o file.o populate.o
	gcc -o addressbook.exe main.o contact.o file.o populate.o
main.o:main.c 
	gcc -c main.c 
contact.o:contact.c 
	gcc -c contact.c 
file.o:file.c 
	gcc -c file.c 
populate.o:populate.c 
	gcc -c populate.c 
clean:
	rm*.exe*.o