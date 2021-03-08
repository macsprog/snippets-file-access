default: file-access.exe fgetc-test.exe fgets-test.exe fputc-test.exe fputs-test.exe fprintf-test.exe

file-access.exe: file-access.o
	gcc -Wall file-access.o -o file-access.exe

file-access.o : file-access.c
	gcc -Wall -c file-access.c

fgetc-test.exe: fgetc-test.o
	gcc -Wall fgetc-test.o -o fgetc-test.exe

fgetc-test.o : fgetc-test.c
	gcc -Wall -c fgetc-test.c

fgets-test.exe: fgets-test.o
	gcc -Wall fgets-test.o -o fgets-test.exe

fgets-test.o : fgets-test.c
	gcc -Wall -c fgets-test.c

fputc-test.exe: fputc-test.o
	gcc -Wall fputc-test.o -o fputc-test.exe

fputc-test.o : fputc-test.c
	gcc -Wall -c fputc-test.c

fputs-test.exe: fputs-test.o
	gcc -Wall fputs-test.o -o fputs-test.exe

fputs-test.o : fputs-test.c
	gcc -Wall -c fputs-test.c

fprintf-test.exe: fprintf-test.o
	gcc -Wall fprintf-test.o -o fprintf-test.exe

fprintf-test.o : fprintf-test.c
	gcc -Wall -c fprintf-test.c

clean :
	rm -f *.exe *.o output_files/* 