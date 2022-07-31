#include "game_system.h"
#include "menu_system.h"
#include "game_logic.h"

#define MENU_BUTTONS_NUMBER 3
#define LEVELS_BUTTONS_NUMBER 3 
#define GAME_BUTTONS_NUMBER 1
#define WIN_BUTTONS_NUMBER 3
#define LOSE_BUTTONS_NUMBER 2
#define PAUSE_BUTTONS_NUMBER 3
#define CREDITS_BUTTONS_NUMBER 1

#define MENU_FONT_SIZE 70
#define FONT_SIZE 40


int main(){
    
    GameSystem gameSystem;
    Menu menu;
    Levels levels;
    Game game;
    MenuSystem pause;
    Win win;
    Lose lose;
    MenuSystem credits;

    char *menuButtonPaths[] = {"assets/button/about.png", "assets/button/play_menu.png", "assets/button/close.png"};

    char *levelsButtonPaths[] = {"assets/levels/prew.png", "assets/levels/next.png", "assets/button/close_2.png"};
    char *levelsDotPaths[] = {"assets/levels/dot_a.png", "assets/levels/dot_d.png"};
    char *levelStarPaths[] = {"assets/levels/star_0.png", "assets/levels/star_1.png", "assets/levels/star_2.png", "assets/levels/star_3.png"};

    char *gameLogoPaths[] = {"assets/logos/apple.png", "assets/logos/facebook.png", "assets/logos/youtube.png", "assets/logos/netflix.png", "assets/logos/linux.png", "assets/logos/gimp.png", "assets/logos/pepsi.png", "assets/logos/twitter.png", "assets/logos/starbucks.png", "assets/logos/xiaomi.png", "assets/logos/instagram.png", "assets/logos/opera.png", "assets/logos/steam.png", "assets/logos/razer.png", "assets/logos/shazam.png", "assets/logos/shell.png", "assets/logos/google.png", "assets/logos/spotify.png", "assets/logos/nike.png", "assets/logos/xbox.png", "assets/logos/firefox.png", "assets/logos/gmail.png", "assets/logos/android.png", "assets/logos/mcdonalds.png", "assets/logos/adidas.png", "assets/logos/motorola.png", "assets/logos/chrome.png"};
    char *gameLogosName[] = {"APPLE", "FACEBOOK", "YOUTUBE", "NETFLIX", "LINUX", "GIMP", "PEPSI", "TWITTER", "STARBUCKS", "XIAOMI", "INSTAGRAM", "OPERA", "STEAM", "RAZER", "SHAZAM", "SHELL", "GOOGLE", "SPOTIFY", "NIKE", "XBOX", "FIREFOX", "GMAIL", "ANDROID", "MCDONALDS", "ADIDAS", "MOTOROLA", "CHROME"};

    char *winButtonPaths[] = {"assets/button/restart.png", "assets/button/menu.png", "assets/button/next.png"};
    char *winStarPaths[] = {"assets/stars/star_0.png", "assets/stars/star_1.png", "assets/stars/star_2.png", "assets/stars/star_3.png"};

    char *loseButtonPaths[] = {"assets/button/restart.png", "assets/button/menu.png"};

    char *pauseButtonPaths[] = {"assets/button/restart.png", "assets/button/play.png", "assets/button/menu.png"};
    char *creditsButtonPaths[] = {"assets/button/close_2.png"};

    gameSystem.init();
    menu.init("assets/background/main_bg.png", menuButtonPaths, MENU_BUTTONS_NUMBER, "assets/fonts/Futurino.ttf", MENU_FONT_SIZE);
    levels.init(gameSystem, "assets/background/levels_bg.png", levelsButtonPaths, LEVELS_BUTTONS_NUMBER, levelStarPaths, 4, levelsDotPaths, 2, "assets/levels/window.png", 27, "assets/levels/lock.png", "assets/fonts/Futurino.ttf", FONT_SIZE);
    game.init(gameLogoPaths, gameLogosName, 27, "assets/button/close_2.png", GAME_BUTTONS_NUMBER, "assets/game/insert_window.png", "assets/game/window.png", "assets/fonts/Futurino.ttf", 50);
    win.init("assets/background/win_bg.png", winButtonPaths, WIN_BUTTONS_NUMBER, winStarPaths, 4, "assets/fonts/Futurino.ttf", FONT_SIZE);
    lose.init("assets/background/lose_bg.png", loseButtonPaths, LOSE_BUTTONS_NUMBER, "assets/stars/star_3.png", "assets/fonts/Futurino.ttf", FONT_SIZE);
    pause.init("assets/background/pause_bg.png", pauseButtonPaths, PAUSE_BUTTONS_NUMBER);
    credits.init("assets/background/credits_bg.png", creditsButtonPaths, CREDITS_BUTTONS_NUMBER);

    GameLoop(gameSystem, menu, levels, game, win, lose, pause, credits);

    gameSystem.destroy();
    menu.destroy();
    levels.destroy(gameSystem);
    game.destroy();
    win.destroy();
    pause.destroy();
    credits.destroy();

    return 0;
}