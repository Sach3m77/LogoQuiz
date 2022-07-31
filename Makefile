HEADERS = C:\Users\Sachem\Desktop\Logo_Quiz\allegro\include
LIBRARIES = C:\Users\Sachem\Desktop\Logo_Quiz\allegro\lib

rule:
	g++ -g main.cpp game_system.cpp menu_system.cpp game_logic.cpp -o main.exe -I $(HEADERS) -L $(LIBRARIES) -l allegro_monolith-debug