compile: frequency.o funcs.o distance.o decode.o
	@gcc -o frequency.out frequency.o funcs.o -lm
	@gcc -o distance.out distance.o funcs.o -lm
	@gcc -o decode.out decode.o funcs.o -lm
funcs.o: funcs.h funcs.c
	@gcc -c funcs.c
frequency.o: frequency.c
	@gcc -c frequency.c
distance.o: distance.c
	@gcc -c distance.c
decode.o: decode.c
	@gcc -c decode.c
frequency: compile
	@./frequency.out $(ARGS)
distance: compile
	@./distance.out $(ARGS)
decode: compile
	@./decode.out $(ARGS)
