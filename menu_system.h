#include "game_system.h"

#pragma once

enum KEYS {LEFT, RIGHT};

class MenuSystem{
protected:
    int buttonsNumber;
public:
    ALLEGRO_BITMAP *background;
    ALLEGRO_BITMAP *button[3];
    
    bool done;

    int backgroundX, backgroundY;
    int backgroundW, backgroundH;

    int buttonX[3], buttonY[3];
    int buttonW[3], buttonH[3];
    bool overButton[3];

    void init(char *backgroundPaths, char *buttonPaths[], int buttonsNumber);
    void draw(int bgY, int btnX, int btnY, int btnDistance);
    void detectButtonHover(int curX, int curY);
    void destroy();

};

class Menu : public MenuSystem{
public:

    ALLEGRO_FONT *font;

    void init(char *backgroundPaths, char *buttonPaths[], int buttonsNumber, char *fontPaht, int fontSize);
    void draw(int btnX, int btnY, int distance);
    void destroy();
};

class Levels : public MenuSystem{
private:
    int starsNumber;
    int levelsNumber;
    int dotsNumber;
public:
    ALLEGRO_BITMAP *star[4];
    ALLEGRO_BITMAP *window;
    ALLEGRO_BITMAP *lock;
    ALLEGRO_BITMAP *dot[2];

    ALLEGRO_FILE *metaDataFile;

    ALLEGRO_FONT * font;

    int  metaData[27][3];

    int levelSectionId;

    int levelsNumberOnDisplay;

    int starW, starH;
    int dotW, dotH;
    int dotX[3], dotY[3];

    int windowX[9], windowY[9];
    int windowW, windowH;
    bool overWindow[9];

    int lockW, lockH;

    void init(GameSystem &gameSystem, char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *starPaths[], int starsNumber, char *dotPaths[], int dotsNumber, char *windowPath, int levelsNumber, char *lockPath, char *fontPath, int fontSize);
    void draw(int bgY, int btnX, int btnY, int btnDistance, int windowDistance, int dotDistance, int closeX, int closeY);
    void detectButtonHover(int curX, int curY);
    int openMetaDataFile(GameSystem &gameSystem, char *metaDataPath, char *mode);
    int saveMetaDataFile(GameSystem &gameSystem);
    void switchLevels(int direction);
    int destroy(GameSystem &GameSystem);
};

class Game : public MenuSystem{
private:
    int logosNumber;
public:
    ALLEGRO_BITMAP *logo[27];
    ALLEGRO_BITMAP *insertWindow;
    ALLEGRO_BITMAP *window;

    ALLEGRO_FONT * font;

    bool refresh;

    char *logoName[27];
    int logoNameLength;

    char shuffledLetters[10];
    char selectedLetters[10];

    int logoW[27], logoH[27];

    int insertWindowX[10], insertWindowY[10];
    int insertWindowW, insertWindowH;

    int selectedLettersNumber;
    int resetButtonClickNumber;

    int windowX[10], windowY[10];
    int windowW, windowH;
    bool overWindow[10];
    bool drawWindow[10];

    void init(char *logoPaths[], char *logosName[], int logosNuber, char *buttonPath, int buttonsNumber, char *insertWindowPath, char *windowPath, char *fontPath, int fontSize);
    void draw(int logoY, int insertWindowAY, int windowAY, int windowDistance, int level);
    void detectButtonHover(int curX, int curY);
    void generateShuffledLetters(int level, int lentgth);
    void resetLevel(int level);
    void editMetaData(Levels &levels, int level);
    void destroy();
};

class Win : public MenuSystem{
private:
    int starsNumber;
public:
    ALLEGRO_BITMAP *star[4];
    ALLEGRO_FONT * font;

    int starW, starH;

    void init(char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *starPaths[], int starsNumber, char *fontPath, int fontSize);
    void draw(int bgY, int btnX, int btnY, int btnDistance, int starY, int resetButtonClickNumber);
    void destroy();
};

class Lose : public MenuSystem{
private:
    int starsNumber;
public:
    ALLEGRO_BITMAP *star;
    ALLEGRO_FONT * font;

    int starW, starH;

    void init(char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *starPath, char *fontPath, int fontSize);
    void draw(int bgY, int btnX, int btnY, int btnDistance, int starY);
    void destroy();
};

