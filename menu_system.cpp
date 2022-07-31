#include "menu_system.h"

void MenuSystem::init(char *backgroundPath, char *buttonPaths[], int buttonsNumber){
    done = true;
    this->buttonsNumber = buttonsNumber;

    background = al_load_bitmap(backgroundPath);
    backgroundW = al_get_bitmap_width(background);
    backgroundH = al_get_bitmap_height(background);

    for(int i = 0; i < buttonsNumber; i++){
        button[i] = al_load_bitmap(buttonPaths[i]);
        buttonW[i] = al_get_bitmap_width(button[i]);
        buttonH[i] = al_get_bitmap_height(button[i]);
        overButton[i] = false;
    }
}

void Menu::init(char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *fontPath, int fontSize){
    done = true;
    this->buttonsNumber = buttonsNumber;

    background = al_load_bitmap(backgroundPath);
    backgroundW = al_get_bitmap_width(background);
    backgroundH = al_get_bitmap_height(background);

    for(int i = 0; i < buttonsNumber; i++){
        button[i] = al_load_bitmap(buttonPaths[i]);
        buttonW[i] = al_get_bitmap_width(button[i]);
        buttonH[i] = al_get_bitmap_height(button[i]);
        overButton[i] = false;
    }

    font = al_load_font(fontPath, fontSize, NULL);
}


void Levels::init(GameSystem &gameSystem, char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *starPaths[], int starsNumber, char *dotPaths[], int dotsNumber, char *windowPath, int levelsNumber, char *lockPath, char *fontPath, int fontSize){

    openMetaDataFile(gameSystem, "assets/levels/meta_data.txt", "r+");

    done = true;
    this->buttonsNumber = buttonsNumber;
    this->starsNumber = starsNumber;
    this->levelsNumber = levelsNumber;
    
    if(metaData[0][0] == 1)
        levelSectionId = 0;
    else if(metaData[0][0] == 10)
        levelSectionId = 1;
    else if(metaData[0][0] == 19)
        levelSectionId = 2;

    levelsNumberOnDisplay  = 9;

    background = al_load_bitmap(backgroundPath);
    backgroundW = al_get_bitmap_width(background);
    backgroundH = al_get_bitmap_height(background);
    
    for(int i = 0; i < buttonsNumber; i++){
        button[i] = al_load_bitmap(buttonPaths[i]);
        buttonW[i] = al_get_bitmap_width(button[i]);
        buttonH[i] = al_get_bitmap_height(button[i]);
        overButton[i] = false;
    }

    for(int i = 0; i < starsNumber; i++){
        star[i] = al_load_bitmap(starPaths[i]);
    }
    starW = al_get_bitmap_width(star[0]);
    starH = al_get_bitmap_height(star[0]);

    for(int i = 0; i < dotsNumber; i++){
        dot[i] = al_load_bitmap(dotPaths[i]);
    }
    dotW = al_get_bitmap_width(dot[0]);
    dotH = al_get_bitmap_height(dot[0]);

    window = al_load_bitmap(windowPath);
    windowW = al_get_bitmap_width(window);
    windowH = al_get_bitmap_height(window);

    for(int i = 0; i < levelsNumberOnDisplay; i++){
        overWindow[i] = false;
    }

    lock = al_load_bitmap(lockPath);
    lockW = al_get_bitmap_width(lock);
    lockH = al_get_bitmap_height(lock);

    font = al_load_font(fontPath, fontSize, NULL);

}

void Game::init(char *logoPaths[], char *logosName[], int logosNumber, char *buttonPath, int buttonsNumber, char *insertWindowPath, char *windowPath, char *fontPath, int fontSize){

    done = true;
    refresh = true;
    selectedLettersNumber = 0;
    resetButtonClickNumber = 0;
    this->logosNumber = logosNumber;
    this->buttonsNumber = buttonsNumber;

    for(int i = 0; i < 10; i++){
        drawWindow[i] = true;
    }

    for(int i = 0; i < logosNumber; i++){
        logo[i] = al_load_bitmap(logoPaths[i]);
        logoW[i] = al_get_bitmap_width(logo[i]);
        logoH[i] = al_get_bitmap_height(logo[i]);
        logoName[i] = logosName[i];
    }
    
    button[0] = al_load_bitmap(buttonPath);
    buttonW[0] = al_get_bitmap_width(button[0]);
    buttonH[0] = al_get_bitmap_width(button[0]);

    insertWindow = al_load_bitmap(insertWindowPath);
    insertWindowW = al_get_bitmap_width(insertWindow);
    insertWindowH = al_get_bitmap_height(insertWindow);

    window = al_load_bitmap(windowPath);
    windowW = al_get_bitmap_width(window);
    windowH = al_get_bitmap_height(window);

    font = al_load_font(fontPath, fontSize, NULL);
}

void Win::init(char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *starPaths[], int starsNumber, char *fontPath, int fontSize){

    done = true;
    this->buttonsNumber = buttonsNumber;
    this->starsNumber = starsNumber;

    background = al_load_bitmap(backgroundPath);
    backgroundW = al_get_bitmap_width(background);
    backgroundH = al_get_bitmap_height(background);

    for(int i = 0; i < buttonsNumber; i++){
        button[i] = al_load_bitmap(buttonPaths[i]);
        buttonW[i] = al_get_bitmap_width(button[i]);
        buttonH[i] = al_get_bitmap_height(button[i]);
        overButton[i] = false;
    }

    for(int i = 0; i < starsNumber; i++){
        star[i] = al_load_bitmap(starPaths[i]);
    }
    starW = al_get_bitmap_width(star[0]);
    starH = al_get_bitmap_height(star[0]);

    font = al_load_font(fontPath, fontSize, NULL);
}

void Lose::init(char *backgroundPath, char *buttonPaths[], int buttonsNumber, char *starPath, char *fontPath, int fontSize){

    done = true;
    this->buttonsNumber = buttonsNumber;
    this->starsNumber = starsNumber;

    background = al_load_bitmap(backgroundPath);
    backgroundW = al_get_bitmap_width(background);
    backgroundH = al_get_bitmap_height(background);

    for(int i = 0; i < buttonsNumber; i++){
        button[i] = al_load_bitmap(buttonPaths[i]);
        buttonW[i] = al_get_bitmap_width(button[i]);
        buttonH[i] = al_get_bitmap_height(button[i]);
        overButton[i] = false;
    }

    star = al_load_bitmap(starPath);

    starW = al_get_bitmap_width(star);
    starH = al_get_bitmap_height(star);

    font = al_load_font(fontPath, fontSize, NULL);
}

void MenuSystem::draw(int bgY, int btnX, int btnY, int btnDistance){

    backgroundX = (gameWidth - backgroundW) / 2;
    backgroundY = bgY;

    al_draw_bitmap(background, backgroundX, backgroundY, NULL);

    for(int i = 0; i < buttonsNumber; i++){
        buttonX[i] = btnX;
        buttonY[i] = btnY;

        btnX += buttonW[i] + btnDistance;

        al_draw_bitmap(button[i], buttonX[i], buttonY[i], 0);
    }
}

void Menu::draw(int btnX, int btnY, int btnDistance){

    al_draw_bitmap(background, 0, 0, NULL);
    al_draw_text(font, al_map_rgb(0, 0, 0), (gameWidth / 2), 180, ALLEGRO_ALIGN_CENTER, "LOGO QUIZ");

    for(int i = 0; i < buttonsNumber; i++){
        buttonX[i] = btnX;

        if(i != 1)
            buttonY[i] = btnY;
        else
            buttonY[i] = btnY - 50;

        btnX += buttonW[i] + btnDistance;

        al_draw_bitmap(button[i], buttonX[i], buttonY[i], 0);
    }
} 

void Levels::draw(int bgY, int btnX, int btnY, int btnDistance, int windowDistance, int dotDistance, int closeX, int closeY){

    backgroundX = (gameWidth - backgroundW) / 2;
    backgroundY = bgY;

    al_draw_bitmap(background, backgroundX, backgroundY, NULL);

    int windowAX = backgroundX + 65;
    int windowAY = backgroundY + 120;

    int l = 0;
    int m = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            windowX[l] = windowAX;
            windowY[l] = windowAY;

            al_draw_bitmap(window, windowX[l], windowY[l], NULL);

            if(metaData[m][1] == 0)
                al_draw_bitmap(lock, windowX[l] + 20, windowY[l] + 15, NULL);
            else if(metaData[m][1] == 1){
                al_draw_textf(font, al_map_rgb(0, 0, 0), windowX[l] + (windowW / 2), windowY[l] + 5, ALLEGRO_ALIGN_CENTER, "%d", metaData[m][0]);
                al_draw_bitmap(star[metaData[m][2]], windowX[l] + 7.5, windowY[l] + 55, NULL);
            }
            l++;
            m++;
            windowAX += windowW + windowDistance;
        }
        windowAY += windowH + windowDistance;
        windowAX = backgroundX + 65;
    }

    for(int i = 0; i < buttonsNumber - 1; i++){
        buttonX[i] = btnX;
        buttonY[i] = btnY;

        btnX += buttonW[0] + btnDistance;
        
        al_draw_bitmap(button[i], buttonX[i], buttonY[i], NULL);
    }

    buttonX[2] = closeX;
    buttonY[2] = closeY;
    al_draw_bitmap(button[2], buttonX[2], buttonY[2], NULL);

    int dotAX = buttonX[0] + buttonW[0] + 30;
    int dotAY = buttonY[0] + buttonH[0] / 4;

    for(int i = 0; i < 3; i++){
        dotX[i] = dotAX;
        dotY[i] = dotAY;
        
        dotAX += dotW + dotDistance;
        
        if(i == levelSectionId)
            al_draw_bitmap(dot[0], dotX[i], dotY[i], NULL);
        else
            al_draw_bitmap(dot[1], dotX[i], dotY[i], NULL);
    }

}

void Game::draw(int logoY, int insertWindowAY, int windowAY, int windowDistance, int level){

    int logoX = (gameWidth - logoW[level]) / 2;
    
    al_draw_bitmap(logo[level], logoX, logoY, NULL);

    generateShuffledLetters(level, logoNameLength);

    int insertWindowAX = (gameWidth - ((insertWindowW * logoNameLength) + (windowDistance * (logoNameLength - 1)))) / 2;


    for(int i = 0; i < logoNameLength; i++){
        insertWindowX[i] = insertWindowAX;
        insertWindowY[i] = insertWindowAY;

        insertWindowAX += insertWindowW + windowDistance;

        al_draw_bitmap(insertWindow, insertWindowX[i], insertWindowY[i], NULL);

    }

    for(int i = 0; i < selectedLettersNumber; i++){
        al_draw_textf(font, al_map_rgb(0, 0, 0), insertWindowX[i] + (insertWindowW / 2), insertWindowY[i] - 10, ALLEGRO_ALIGN_CENTER, "%c", selectedLetters[i]);
    }


    buttonX[0] = windowX[4] + windowW + 20;
    buttonY[0] = windowY[4];

    if(selectedLettersNumber > 0)
        al_draw_bitmap(button[0], buttonX[0], buttonY[0], NULL);

    int n = 0, m = 0;
    int windowAX = (gameWidth - ((windowW * 5) + (windowDistance * 4))) / 2;
    int tmpWindowAX = windowAX;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 5; j++){
            windowX[n] = windowAX;
            windowY[n] = windowAY;

            windowAX += windowW + windowDistance;
            if(drawWindow[n]){
                al_draw_bitmap(window, windowX[n], windowY[n], NULL);
                al_draw_textf(font, al_map_rgb(0, 0, 0), windowX[n] + (windowW / 2), windowY[n], ALLEGRO_ALIGN_CENTER, "%c", shuffledLetters[n]);
            }
            n++;
        }
        windowAY += windowH + windowDistance;
        windowAX = tmpWindowAX;
    }
}

void Win::draw(int bgY, int btnX, int btnY, int btnDistance, int starY, int resetButtonClickNumber){

    backgroundX = (gameWidth - backgroundW) / 2;
    backgroundY = bgY;

    int starX = (gameWidth - starW) / 2;

    al_draw_bitmap(background, backgroundX, backgroundY, NULL);

    for(int i = 0; i < buttonsNumber; i++){
        buttonX[i] = btnX;
        buttonY[i] = btnY;

        btnX += buttonW[i] + btnDistance;

        al_draw_bitmap(button[i], buttonX[i], buttonY[i], 0);
    }

    if(resetButtonClickNumber >= 0 && resetButtonClickNumber <= 2){
        if(resetButtonClickNumber == 0){
            al_draw_text(font, al_map_rgb(7, 126, 156), backgroundX + (backgroundW / 2), starY + 175, ALLEGRO_ALIGN_CENTER, "EXCELLENT");
        }else{
            al_draw_text(font, al_map_rgb(0, 0, 0), backgroundX + (backgroundW / 2), starY + 150, ALLEGRO_ALIGN_CENTER, "WRONG TYPING");
            al_draw_textf(font, al_map_rgb(7, 126, 156), backgroundX + (backgroundW / 2), starY + 200, ALLEGRO_ALIGN_CENTER, "%d", resetButtonClickNumber);
        }

        al_draw_bitmap(star[resetButtonClickNumber], starX, starY, NULL);

    }
}

void Lose::draw(int bgY, int btnX, int btnY, int btnDistance, int starY){

    backgroundX = (gameWidth - backgroundW) / 2;
    backgroundY = bgY;

    int starX = (gameWidth - starW) / 2;

    al_draw_bitmap(background, backgroundX, backgroundY, NULL);

    for(int i = 0; i < buttonsNumber; i++){
        buttonX[i] = btnX;
        buttonY[i] = btnY;

        btnX += buttonW[i] + btnDistance;

        al_draw_bitmap(button[i], buttonX[i], buttonY[i], 0);
    }

    al_draw_bitmap(star, starX, starY, NULL);
}

void MenuSystem::detectButtonHover(int curX, int curY){

    for(int i = 0; i < buttonsNumber; i++){
        if(curX >= buttonX[i] && curX <= buttonX[i] + buttonW[i] && curY >= buttonY[i] && curY <= buttonY[i] + buttonH[i])
            overButton[i] = true;
        else
            overButton[i] = false;
    }
}

void Levels::detectButtonHover(int curX, int curY){

    for(int i = 0; i < buttonsNumber; i++){
        if(curX >= buttonX[i] && curX <= buttonX[i] + buttonW[i] && curY >= buttonY[i] && curY <= buttonY[i] + buttonH[i])
            overButton[i] = true;
        else
            overButton[i] = false;
    }
    for(int i = 0; i < levelsNumberOnDisplay; i++){
        if(curX >= windowX[i] && curX <= windowX[i] + windowW && curY >= windowY[i] && curY <= windowY[i] + windowH)
            overWindow[i] = true;
        else
            overWindow[i] = false;
    }
}

void Game::detectButtonHover(int curX, int curY){

    for(int i = 0; i < buttonsNumber; i++){
        if(curX >= buttonX[i] && curX <= buttonX[i] + buttonW[i] && curY >= buttonY[i] && curY <= buttonY[i] + buttonH[i])
            overButton[i] = true;
        else
            overButton[i] = false;
    }
    for(int i = 0; i < 10; i++){
        if(curX >= windowX[i] && curX <= windowX[i] + windowW && curY >= windowY[i] && curY <= windowY[i] + windowH)
            overWindow[i] = true;
        else
            overWindow[i] = false;
    }
}

int Levels::openMetaDataFile(GameSystem &gameSystem, char *metaDataPath, char *mode){

    metaDataFile = al_fopen(metaDataPath, mode);

    if(metaDataFile == NULL){
        al_show_native_message_box(gameSystem.display, gameTitle, "Uwaga", "Bład otwarcia pliku gry! \n Proszę ponownie uruchomić grę", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    int j = 0;
    int k = 0;

    char line[8];
    char temp[3];

    memset(line, '\0', 8);
    memset(temp, '\0', 3);

    for(int i = 0; i < 27; i++){
        memset(metaData[i], 0, 3);
    }

    while(al_fgets(metaDataFile, line, 8)){

        if(al_feof(metaDataFile)){
            strncat(line, "\n", 1);
        }
        
        for(int i = 0; i < strlen(line); i++){
            if(line[i] != ',' && line[i] != '\n'){
                strncat(temp, &line[i], 1);
            }else{
                metaData[k][j] = atoi(temp);
                memset(temp, '\0', 3);
                j++;
            }
        }
        k++;
        j = 0;
    }

    return 0;
}

void Game::editMetaData(Levels &levels, int level){
    int stars = 3 - resetButtonClickNumber;

    if(levels.metaData[level][2] < stars)
        levels.metaData[level][2] = stars;

    if(levels.metaData[level+1][1] == 0)
        levels.metaData[level+1][1] = 1;
}

int Levels::saveMetaDataFile(GameSystem &gameSystem){

    if(!al_fseek(metaDataFile, 0, ALLEGRO_SEEK_SET)){
        al_show_native_message_box(gameSystem.display, gameTitle, "Uwaga", "Blad operacji przesuwania wskaznika pliku gry! \n Prosze uruchomic ponownie gre", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    char line[8];
    char buffer[3];

    memset(line, '\0', 8);
    memset(buffer, '\0', 2);

    for(int i = 0; i < 27; i ++){
        for(int j = 0; j < 3; j++){
            itoa(metaData[i][j], buffer, 10);
            strcat(line, buffer);
            if(j != 2)
                strcat(line, ",");
        }
        strcat(line, "\n");
        
        if(al_fputs(metaDataFile, line) == EOF){
            al_show_native_message_box(gameSystem.display, gameTitle, "Uwaga", "Blad zapisu pliku gry! \n Prosze uruchomic ponownie gre", NULL, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

        memset(line, '\0', 8);
    }

    if(!al_fclose(metaDataFile)){
        al_show_native_message_box(gameSystem.display, gameTitle, "Uwaga", "Bład zamknięcia pliku gry! \n Proszę ponownie uruchomić grę", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

}

void Levels::switchLevels(int direction){

    int tmpMetaData[9][3];

    int levelSections = levelsNumber / 9;

    if(direction == LEFT){
        for(int i = 0; i < 9; i++){
            tmpMetaData[i][0] = metaData[levelsNumber-9+i][0];
            tmpMetaData[i][1] = metaData[levelsNumber-9+i][1];
            tmpMetaData[i][2] = metaData[levelsNumber-9+i][2];
        }
        for(int i = levelsNumber - 1; i >= 9; i--){
            metaData[i][0] = metaData[i-9][0];
            metaData[i][1] = metaData[i-9][1];
            metaData[i][2] = metaData[i-9][2];
        }
        for(int i = 0; i < 9; i++){
            metaData[i][0] = tmpMetaData[i][0];
            metaData[i][1] = tmpMetaData[i][1];
            metaData[i][2] = tmpMetaData[i][2];
        }
        if(levelSectionId == 0)
            levelSectionId = 2;
        else
            levelSectionId--;

    }else if(direction == RIGHT){
        for(int i = 0; i < 9; i++){
            tmpMetaData[i][0] = metaData[i][0];
            tmpMetaData[i][1] = metaData[i][1];
            tmpMetaData[i][2] = metaData[i][2];
        }
        for(int i = 0; i < levelSections - 1; i++){
            for(int j = i*9; j < levelsNumber - 9; j++){
                metaData[j][0] = metaData[j+9][0];
                metaData[j][1] = metaData[j+9][1];
                metaData[j][2] = metaData[j+9][2];
            }
        }
        for(int i = 0; i < 9; i++){
            metaData[levelsNumber-9+i][0] = tmpMetaData[i][0];
            metaData[levelsNumber-9+i][1] = tmpMetaData[i][1];
            metaData[levelsNumber-9+i][2] = tmpMetaData[i][2];
        }
        if(levelSectionId == 2)
            levelSectionId = 0;
        else
            levelSectionId++;
    }
}

void Game::generateShuffledLetters(int level, int length){

    srand(time(NULL));

    if(refresh){
        refresh = false;

        char buffer[10-length];
        char tmp;
        int randomIndex;

        for(int i = 0; i < 10-length; i++){
            buffer[i] = 65 + rand() % 26;
        }

        strcpy(shuffledLetters, logoName[level]);
        strncat(shuffledLetters, buffer, 10-length);

        for(int i = 0; i < 10; i++){
            tmp = shuffledLetters[i];
            randomIndex = rand() % 10;
            shuffledLetters[i] = shuffledLetters[randomIndex];
            shuffledLetters[randomIndex] = tmp;
        }
    }
}

void Game::resetLevel(int level){

    selectedLettersNumber = 0;
    memset(selectedLetters, 0, 10);
    logoNameLength = strlen(logoName[level]);
    resetButtonClickNumber = 0;

    for(int i = 0; i < 10; i++){
        drawWindow[i] = true;
    }

    refresh = true;
}

void MenuSystem::destroy(){

    al_destroy_bitmap(background);

    for(int i = 0; i < buttonsNumber; i++){
        al_destroy_bitmap(button[i]);
    }
}

void Menu::destroy(){

    al_destroy_bitmap(background);

    for(int i = 0; i < buttonsNumber; i++){
        al_destroy_bitmap(button[i]);
    }

    al_destroy_font(font);
}

int Levels::destroy(GameSystem &gameSystem){
    al_destroy_bitmap(background);
    al_destroy_bitmap(window);
    al_destroy_bitmap(lock);

    for(int i = 0; i < buttonsNumber; i++){
        al_destroy_bitmap(button[i]);
    }
    for(int i = 0; i < starsNumber; i++){
        al_destroy_bitmap(star[i]);
    }

    al_destroy_font(font);

    saveMetaDataFile(gameSystem);

    return 0;
}

void Game::destroy(){
    al_destroy_bitmap(window);

    for(int i = 0; i < logosNumber; i++){
        al_destroy_bitmap(logo[i]);
    }

    for(int i = 0; i < buttonsNumber; i++){
        al_destroy_bitmap(button[i]);
    }
    
    al_destroy_font(font);
    
}

void Win::destroy(){
    al_destroy_bitmap(background);

    for(int i = 0; i < buttonsNumber; i++){
        al_destroy_bitmap(button[i]);
    }
    for(int i = 0; i < starsNumber; i++){
        al_destroy_bitmap(star[i]);
    }

    al_destroy_font(font);
}

void Lose::destroy(){
    al_destroy_bitmap(background);

    for(int i = 0; i < buttonsNumber; i++){
        al_destroy_bitmap(button[i]);
    }
    al_destroy_bitmap(star);

    al_destroy_font(font);
}