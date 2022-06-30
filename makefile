link: ai_player.o game_board.o main.o 
	gcc ai_player.o game_board.o main.o -o programName

main.o:
	gcc -c main.c

game_board.o: 
	gcc -c game_board.c

ai_player.o: 
	gcc -c ai_player.c

clear:
	rm -f ai_player.o game_board.o main.o programName //this one is to delete files faster