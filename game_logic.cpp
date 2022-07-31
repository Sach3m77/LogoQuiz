#include "game_logic.h"

void GameLoop(GameSystem &gameSystem, Menu &menu, Levels &levels, Game &game, Win &win, Lose &lose, MenuSystem &pause, MenuSystem &credits){

    int curX, curY;
    int result = 0;
    int level = 0;
    int window = 0;

    menu.done = false;

    while(!gameSystem.done){

        al_wait_for_event(gameSystem.eventQueque, &gameSystem.event); 

        if(gameSystem.event.type == ALLEGRO_EVENT_TIMER){

            if(gameSystem.event.timer.source == gameSystem.timer){
                gameSystem.redraw = true;
            }

        }else if(gameSystem.event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){

            result = al_show_native_message_box(gameSystem.display, gameTitle, "Uwaga", "Zamknięcie gry z poziomu karty kontrolnej może spowodować uszkodzenie danych.\nZamknąć?", NULL, ALLEGRO_MESSAGEBOX_WARN | ALLEGRO_MESSAGEBOX_YES_NO);
            if(result == 1) gameSystem.done = 1;

        }else if(gameSystem.event.type == ALLEGRO_EVENT_MOUSE_AXES){

            curX = gameSystem.event.mouse.x;
            curY = gameSystem.event.mouse.y;

        }else if(gameSystem.event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

            if(!menu.done){

                if(gameSystem.event.mouse.button == 1){

                    if(menu.overButton[0]){
                        menu.done = true;
                        credits.done = false;
                    }else if(menu.overButton[1]){
                        menu.done = true;
                        levels.done = false;
                    }else if(menu.overButton[2]){
                        gameSystem.done = true;
                    }
                }

            }else if(!levels.done){

                if(gameSystem.event.mouse.button == 1){

                    if(levels.overButton[0])
                        levels.switchLevels(LEFT);
                    else if(levels.overButton[1])
                        levels.switchLevels(RIGHT);
                    else if(levels.overButton[2]){
                        levels.done = true;
                        menu.done = false;
                    }

                    for(int i = 0; i < levels.levelsNumberOnDisplay; i++){
                        if(levels.overWindow[i]){
                            
                            window = i;
                            level = i + 9 * levels.levelSectionId;

                            if(levels.metaData[i][1] == 1){
                                levels.done = true;
                                game.resetLevel(level);
                                game.done = false;
                            }
                        }
                    }
                }

            }else if(!game.done){

                if(gameSystem.event.mouse.button == 1){

                    if(game.overButton[0]){
                        memset(game.selectedLetters, 0, 10);
                        game.selectedLettersNumber = 0;
                        for(int i = 0; i < 10; i++){
                            game.drawWindow[i] = true;
                        }
                        game.resetButtonClickNumber++;
                    }
                    
                    for(int i = 0; i < 10; i++){
                        if(game.overWindow[i]){
                            if(game.selectedLettersNumber < game.logoNameLength){
                                if(game.drawWindow[i]){
                                    game.selectedLettersNumber++;
                                    strncat(game.selectedLetters, &game.shuffledLetters[i], 1);
                                    game.drawWindow[i] = false;
                                }
                            }
                            if(strcmp(game.logoName[level], game.selectedLetters) == 0){
                                game.done = true;
                                game.editMetaData(levels, window);
                                if(game.resetButtonClickNumber <= 2)
                                    win.done = false;
                                else
                                    lose.done = false;
                            }
                        }
                    }
                }

            }else if(!win.done){

                if(gameSystem.event.mouse.button == 1){

                    if(win.overButton[0]){
                        win.done = true;
                        game.resetLevel(level);
                        game.done = false;
                    }else if(win.overButton[1]){
                        win.done = true;
                        levels.done = false;
                    }else if(win.overButton[2]){
                        win.done = true;
                        if(level + 1 < 27){
                            level++;
                            window++;
                        }else{
                            if(levels.levelSectionId == 1)
                                levels.switchLevels(LEFT);
                            else if(levels.levelSectionId == 2)
                                levels.switchLevels(RIGHT);
                            level = 0;
                            window = 0;
                        }
                        game.resetLevel(level);
                        game.done = false;
                    }
                }

            }else if(!lose.done){

                if(gameSystem.event.mouse.button == 1){

                    if(lose.overButton[0]){
                        lose.done = true;
                        game.resetLevel(level);
                        game.done = false;
                    }else if(lose.overButton[1]){
                        lose.done = true;
                        levels.done = false;
                    }
                }

            }else if(!pause.done){

                if(gameSystem.event.mouse.button == 1){

                    if(pause.overButton[0]){
                        pause.done = true;
                        game.resetLevel(level);
                        game.done = false;
                    }else if(pause.overButton[1]){
                        pause.done = true;
                        game.done = false;
                    }else if(pause.overButton[2]){
                        pause.done = true;
                        levels.done = false;
                    }
                }

            }else if(!credits.done){

                if(gameSystem.event.mouse.button == 1){

                    if(credits.overButton[0]){
                        credits.done = true;
                        menu.done = false;
                    }
                }

            }

        }else if(gameSystem.event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){

            if(menu.done && levels.done && pause.done && credits.done && !game.done){
                game.done = true;
                pause.done = false;
            }
            
        }

        if(gameSystem.redraw && al_is_event_queue_empty(gameSystem.eventQueque)){

            gameSystem.redraw = 0;

            if(!menu.done){

                menu.draw(75, 500, 100);
                menu.detectButtonHover(curX, curY);

            }else if(!levels.done){

                game.selectedLettersNumber = 0;
                al_draw_bitmap(menu.background, 0, 0, NULL);
                levels.draw(90, 150, 555, 185, 20, 20, 490, 135);
                levels.detectButtonHover(curX, curY);

            }else if(!game.done){

                al_draw_bitmap(menu.background, 0, 0, NULL);
                game.draw(110, 410, 490, 10, level);
                game.detectButtonHover(curX, curY);

            }else if(!win.done){

                al_draw_bitmap(menu.background, 0, 0, NULL);
                win.draw(70, 150, 590, 55, 250, game.resetButtonClickNumber);
                win.detectButtonHover(curX, curY);

            }else if(!lose.done){

                al_draw_bitmap(menu.background, 0, 0, NULL);
                lose.draw(120, 205, 515, 80, 300);
                lose.detectButtonHover(curX, curY);

            }else if(!pause.done){

                al_draw_bitmap(menu.background, 0, 0, NULL);
                pause.draw(120, 150, 515, 60);
                pause.detectButtonHover(curX, curY);

            }else if(!credits.done){

                al_draw_bitmap(menu.background, 0, 0, NULL);
                credits.draw(200, 540, 190, 0);
                credits.detectButtonHover(curX, curY);

            }

            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));

        }        
    }
}