compile: funcs.o encode.o decode.o cracker.o getkey.o
	@gcc -o encode.out encode.o funcs.o -lm
	@gcc -o decode.out decode.o funcs.o -lm
	@gcc -o crack.out cracker.o funcs.o -lm
	@gcc -o getkey.out getkey.o funcs.o -lm
funcs.o: funcs.h funcs.c
	@gcc -c funcs.c
encode.o: encode.c
	@gcc -c encode.c
decode.o: decode.c
	@gcc -c decode.c
cracker.o: cracker.c
	@gcc -c cracker.c
getkey.o: getkey.c
	@gcc -c getkey.c
encode: compile
	@./encode.out $(ARGS)
decode: compile
	@./decode.out $(ARGS)
crack: compile
	@./crack.out $(ARGS)
getkey: compile
	@./getkey.out $(ARGS)
