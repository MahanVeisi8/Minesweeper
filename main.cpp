#include <iostream>
#include "clui.h"
#include <stdlib.h>
#include <time.h>
#include "SBDL.h"
#include "SDL.h"
#include <fstream>
#include <string>
using namespace std;
struct player_info
{
    char name[20];
    int score = 0;
};

int the_score=0;
char the_player_name[10];
int first_minesweeper_array[30][30];
int second_minesweeper_array[30][30];
int auxiliary_array[30][30];
int board_col_and_row_counter[30][30];
char board_for_the_player[30][30];
int row_size = 5;
int column_size = 5;
int number_of_main_array_cells = 25;
int number_of_mines = 4;
int number_of_flags = 0;
int current_neutral_cells_shown=1;
long long int first_time = time(0);
int total_time_of_game = 50;
int number_of_neutral_cells = 21;
int flag_for_exit_from_game_and_return_to_menu = 0;
int flag_for_slot_one = 0;
int flag_for_slot_two = 0;
int flag_for_slot_three = 0;
int flag_for_slot_four = 0;
int flag_for_if_the_game_has_been_loaded = 0;
int number_of_lines_of_text = 0;
int flag_for_change_user = 0;
int flag_for_wrong_input = 0;

void asset_loader();
void house_zeroing_func(int a[30][30], int b[30][30]);
int Game_preparations();
void mine_placer(int a[30][30]);
void around_mine_shower(int a[30][30], int b[30][30]);
void margin_of_the_board(int a[30][30]);
void board_shower();
void users_board_preparation(char a[30][30]);
void game_start();
void lose_function();
void flag_selection();
void  show_the_cells_around_zero_cell(int i, int j);
int current_neutral_cells_counter(int x);
void  game_poster();
void  pre_game_menu();
void new_game_func();
void map_size();
void game_saver();
void menu_poster();
void game_loader();
void load_game_function();
void lentgh_of_array();
int length_of_array(char* a);
bool compare_two_arrays(char* first_array, char* second_array);
int char_number_to_int_convertor(char* char_number);
void win_function();
void leaderboard();
void custom_game_option();
void time_operation();
void background_of_game_map();
void final_board_cells();
void music_setting();

Texture cell;
Texture flag;
Texture n0;
Texture n1;
Texture n2;
Texture n3;
Texture n4;
Texture n5;
Texture n6;
Texture n7;
Texture n8;
Texture bomb;
Texture lose;
Texture poster;
Texture poster_with_free_line;
Texture slots;
Texture mapsize_pic;
Texture win_poster;
Texture leaderboard_poster;
Texture background_of_map;
Texture time1;
Texture time2;
Texture time3;
Texture time4;
Texture time5;
Texture time6;
Texture custom;
Texture wrong_input;
Texture bombing1;
Texture bombing2;
Texture bombing3;
Texture bombing4;
Texture bombing5;
Texture bombing6;
Texture bombing7;
Texture bombing8;
Texture firework0_0;
Texture firework0_1;
Texture firework0_2;
Texture firework1;
Texture firework2;
Texture firework3;
Texture firework4;
Texture firework5;
Texture firework6;
Texture firework7;
Texture firework8;
Texture firework9;
Texture right_margin1;
Music *music1;
Music *music2;
Texture setting_of_music;
Texture mahan_company;
Font *font; // for username enterance
Font *first_player_rank;
Font *second_player_rank;
Font *third_player_rank;
Font *fourth_player_rank;
Font *fifth_player_rank;
Font *first_player_rank_score;
Font *second_player_rank_score;
Font *third_player_rank_score;
Font *fourth_player_rank_score;
Font *fifth_player_rank_score;
Texture menu;
fstream myFile;

void asset_loader()
{
    cell = SBDL::loadTexture("assets/cells/n.png");
    flag = SBDL::loadTexture("assets/cells/f.png");
    n0   = SBDL::loadTexture("assets/cells/0.png");
    n1   = SBDL::loadTexture("assets/cells/1.png");
    n2   = SBDL::loadTexture("assets/cells/2.png");
    n3   = SBDL::loadTexture("assets/cells/3.png");
    n4   = SBDL::loadTexture("assets/cells/4.png");
    n5   = SBDL::loadTexture("assets/cells/5.png");
    n6   = SBDL::loadTexture("assets/cells/6.png");
    n7   = SBDL::loadTexture("assets/cells/7.png");
    n8   = SBDL::loadTexture("assets/cells/8.png");
    bomb = SBDL::loadTexture("assets/cells/b.png");
    lose = SBDL::loadTexture("assets/cells/lose.png");
    poster = SBDL::loadTexture("assets/poster/1.jpg");
    background_of_map = SBDL::loadTexture("assets/poster/map_background.jpg");
    font = SBDL::loadFont("assets/font/times.ttf",30);
    first_player_rank = SBDL::loadFont("assets/font/times.ttf",30);
    second_player_rank = SBDL::loadFont("assets/font/times.ttf",30);
    third_player_rank = SBDL::loadFont("assets/font/times.ttf",30);
    fourth_player_rank = SBDL::loadFont("assets/font/times.ttf",30);
    fifth_player_rank = SBDL::loadFont("assets/font/times.ttf",30);
    first_player_rank_score = SBDL::loadFont("assets/font/times.ttf",30);
    second_player_rank_score = SBDL::loadFont("assets/font/times.ttf",30);
    third_player_rank_score = SBDL::loadFont("assets/font/times.ttf",30);
    fourth_player_rank_score = SBDL::loadFont("assets/font/times.ttf",30);
    fifth_player_rank_score = SBDL::loadFont("assets/font/times.ttf",30);
    poster_with_free_line =  SBDL::loadTexture("assets/poster/1-1.jpg");
    menu = SBDL::loadTexture("assets/poster/2.jpg");
    slots = SBDL::loadTexture("assets/poster/slots.jpg");
    mapsize_pic = SBDL::loadTexture("assets/poster/mapsize.jpg");
    win_poster = SBDL::loadTexture("assets/poster/win_poster.jpg");
    leaderboard_poster = SBDL::loadTexture("assets/poster/leaderboard.jpg");
    time1 = SBDL::loadTexture("assets/poster/time1.jpg");
    time2 = SBDL::loadTexture("assets/poster/time2.jpg");
    time3 = SBDL::loadTexture("assets/poster/time3.jpg");
    time4 = SBDL::loadTexture("assets/poster/time4.jpg");
    time5 = SBDL::loadTexture("assets/poster/time5.jpg");
    time6 = SBDL::loadTexture("assets/poster/time6.jpg");
    custom = SBDL::loadTexture("assets/poster/custom.png");
    wrong_input = SBDL::loadTexture("assets/poster/wrong_input.png");
    bombing1 = SBDL::loadTexture("assets/cells/bombing1.jpg");
    bombing2 = SBDL::loadTexture("assets/cells/bombing2.jpg");
    bombing3 = SBDL::loadTexture("assets/cells/bombing3.jpg");
    bombing4 = SBDL::loadTexture("assets/cells/bombing4.jpg");
    bombing5 = SBDL::loadTexture("assets/cells/bombing5.jpg");
    bombing6 = SBDL::loadTexture("assets/cells/bombing6.jpg");
    bombing7 = SBDL::loadTexture("assets/cells/bombing7.jpg");
    bombing8 = SBDL::loadTexture("assets/cells/bombing8.jpg");
    firework0_0 = SBDL::loadTexture("assets/poster/firework0_0.png");
    firework0_1 = SBDL::loadTexture("assets/poster/firework0_1.png");
    firework0_2 = SBDL::loadTexture("assets/poster/firework0_2.png");
    firework1 = SBDL::loadTexture("assets/poster/firework1.jpg");
    firework2 = SBDL::loadTexture("assets/poster/firework2.jpg");
    firework3 = SBDL::loadTexture("assets/poster/firework3.jpg");
    firework4 = SBDL::loadTexture("assets/poster/firework4.jpg");
    firework5 = SBDL::loadTexture("assets/poster/firework5.jpg");
    firework6 = SBDL::loadTexture("assets/poster/firework6.jpg");
    firework7 = SBDL::loadTexture("assets/poster/firework7.jpg");
    firework8 = SBDL::loadTexture("assets/poster/firework8.jpg");
    firework9 = SBDL::loadTexture("assets/poster/firework9.jpg");
    right_margin1 = SBDL::loadTexture("assets/poster/right_margin1.png");
    music1 = SBDL::loadMusic("assets/music/Halparke.wav");
    music2 = SBDL::loadMusic("assets/music/Ishq.wav");
    setting_of_music = SBDL::loadTexture("assets/poster/setting.jpg");
    mahan_company = SBDL::loadTexture("assets/poster/mahan_company.jpg");
}

int main()
{
    if(flag_for_change_user == 1)
    {
        pre_game_menu();
        flag_for_change_user = 0;
    }
    else
    {
        if(flag_for_exit_from_game_and_return_to_menu == 0)
        {
            srand(time(NULL));
            first_time = time(0);
            SBDL::InitEngine("Window Title",650, 600);
            asset_loader();
            SBDL::playMusic(music1,-1);
            game_poster();
            pre_game_menu();
        }
        else if(flag_for_exit_from_game_and_return_to_menu == 1)
        {   flag_for_exit_from_game_and_return_to_menu = 0;   }
    }
    menu_poster();
    first_time = time(0);
    if(flag_for_change_user == 1)
    {   main();  }
    if(flag_for_if_the_game_has_been_loaded == 0)
    {   number_of_neutral_cells = Game_preparations(); }
    else if(flag_for_if_the_game_has_been_loaded == 1)
    { flag_for_if_the_game_has_been_loaded = 0;}
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(background_of_map,0,0);
        board_shower();
        time_operation();
        game_start();
        if(flag_for_exit_from_game_and_return_to_menu == 1)
        {   break;  }
        if(current_neutral_cells_shown >= number_of_neutral_cells)
        {
            win_function();
        }
        SBDL::updateRenderScreen();
        SBDL::delay(60);
    }
    if(flag_for_exit_from_game_and_return_to_menu == 1)
    {   main();    }
}
int Game_preparations()
{
    number_of_neutral_cells = number_of_main_array_cells - number_of_mines;
    house_zeroing_func(first_minesweeper_array , auxiliary_array);
    mine_placer(first_minesweeper_array);
    around_mine_shower(first_minesweeper_array,second_minesweeper_array);
    margin_of_the_board(board_col_and_row_counter);
    users_board_preparation(board_for_the_player);
    return number_of_neutral_cells;
}
void house_zeroing_func(int a[30][30], int b[30][30]) //This function resets the amount of marginal and internal cells to zero
{
    for(int i=0; i <= row_size + 1; ++i)
    {
        for(int j=0; j <= column_size + 1; ++j)
        { first_minesweeper_array[i][j] = auxiliary_array[i][j] = 0;}
    }
}

void mine_placer(int a[30][30])
{
    for(int i=1; i <= number_of_mines; ++i)
    {
        int random_mine_place = ( rand()  % (row_size * column_size) );
        int row_bomb = (random_mine_place / row_size ) + 1;
        int column_bomb = (random_mine_place % column_size ) + 1;
        if(first_minesweeper_array [row_bomb] [column_bomb] == 1)//if the random mine place is repeated in a same previous mine position
        {--i; continue;}
        first_minesweeper_array [row_bomb] [column_bomb] = 1;
    }
}

void around_mine_shower(int a[30][30], int b[30][30]) // Represents the surrounding land
{
    for(int i=0; i<=row_size + 1; ++i)
    {
        for(int j=0; j<=column_size + 1; ++j)
        {
            if(i==0 || i==row_size + 1)
            { b[i][j] = -2;}      //for the margin cells of second array i set them to -2 because it is needed in the (show_cells_..) function later
            else if( j==0 || j == column_size + 1)
            { b[i][j] = -2;}

            else if(a[i][j] == 1)
            {b[i][j] = -1;}
            else if( a[i][j] == 0)
            {
                int total_mines_around = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i][j-1] +  a[i][j+1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1] ;
                b[i][j] = total_mines_around;
            }
        }
    }
}

void margin_of_the_board(int a[30][30])
{
    for(int i=0; i <= row_size; ++i)
    {
        for(int j=0; j <= column_size; ++j)
        {
            if(i==0)
            {a[i][j] = j;}
            else if( (i >= 1) && (j==0) )
            {a[i][j] = i;}
        }
    }
}

void users_board_preparation(char a[30][30])
{
    for(int i=1; i <= row_size; ++i)
    {
        for(int j=1; j <= column_size; ++j)
        {
            board_for_the_player[i][j] = '#';
        }
    }
}

void board_shower()
{
    for(int i=1; i<= row_size; ++i)
    {
        for(int j=1; j <= column_size; ++j)
        {
            if(auxiliary_array[i][j] == 0)//if it is not choosen yet then print # or if it is a flag print ?
            {
                if(board_for_the_player[i][j] == '#')
                {
                    SBDL::showTexture(cell,(i-1)*30,(j-1)*30);
                }
                else if(board_for_the_player[i][j] == '?')
                {
                    SBDL::showTexture(flag,(i-1)*30,(j-1)*30);
                }
            }
            else if(auxiliary_array[i][j] == 1) // if it is choosen right now or before then print the number of mines around that cell
            {
                if(second_minesweeper_array[i][j] == 0)
                {SBDL::showTexture(n0,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 1)
                {SBDL::showTexture(n1,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 2)
                {SBDL::showTexture(n2,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 3)
                {SBDL::showTexture(n3,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 4)
                {SBDL::showTexture(n4,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 5)
                {SBDL::showTexture(n5,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 6)
                {SBDL::showTexture(n6,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 7)
                {SBDL::showTexture(n7,(i-1)*30,(j-1)*30);}
                else if(second_minesweeper_array[i][j] == 8)
                {SBDL::showTexture(n8,(i-1)*30,(j-1)*30);}
            }
        }
    }
}

void game_start() // with number inputs
{
    if(SBDL::keyPressed(SDL_SCANCODE_Q))
    {
        flag_for_exit_from_game_and_return_to_menu = 1;
    }
    else if(SBDL::keyPressed(SDL_SCANCODE_O))
    {
        flag_for_exit_from_game_and_return_to_menu = 1;
        game_saver();
    }
    else if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
    {
        if(SBDL::Mouse.x>600 && SBDL::Mouse.x<650 && SBDL::Mouse.y>10 && SBDL::Mouse.y<90)
        {    
            exit(0);
        }
        else if(SBDL::Mouse.x>600 && SBDL::Mouse.x<650 && SBDL::Mouse.y>110 && SBDL::Mouse.y<180)
        {    flag_for_exit_from_game_and_return_to_menu = 1;  }
        else if(SBDL::Mouse.x>600 && SBDL::Mouse.x<650 && SBDL::Mouse.y>200 && SBDL::Mouse.y<280)
        {
            flag_for_exit_from_game_and_return_to_menu = 1;
            game_saver();
        }
        else
        {
            int player_row_guess = ((SBDL::Mouse.x)/30)+1;
            int player_col_guess = ((SBDL::Mouse.y)/30)+1;
            if(board_for_the_player[player_row_guess][player_col_guess] == '?')
            {  --current_neutral_cells_shown; }
            else
            {
                auxiliary_array[player_row_guess][player_col_guess] = 1;
                if(first_minesweeper_array[player_row_guess][player_col_guess] == 1) // if it is mine cell
                { lose_function();}
                else if(first_minesweeper_array[player_row_guess][player_col_guess] == 0)
                {
                    if(second_minesweeper_array[player_row_guess][player_col_guess] == 0) // if a cell is zero then print the neutral cells around
                    { show_the_cells_around_zero_cell(player_row_guess,player_col_guess); }
                    // time_operation();
                }
            }
        }
        SBDL::updateEvents();
    }
    else if(SBDL::Mouse.clicked(SDL_BUTTON_RIGHT,1,SDL_RELEASED))
    {
        --current_neutral_cells_shown;
        flag_selection();
        board_shower();
        SBDL::updateEvents();
    }
    else
    {return;}
    current_neutral_cells_shown = current_neutral_cells_counter(current_neutral_cells_shown);
}

void lose_function()
{
    int x=0;
    play_beep();
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        if(x<100)
        {SBDL::showTexture(bombing1,0,0);}
        else if(x<200)
        {SBDL::showTexture(bombing2,0,0);}
        else if(x<300)
        {SBDL::showTexture(bombing3,0,0);}
        else if(x<400)
        {SBDL::showTexture(bombing4,0,0);}
        else if(x<500)
        {SBDL::showTexture(bombing5,0,0);}
        else if(x<600)
        {SBDL::showTexture(bombing6,0,0);}
        else if(x<700)
        {SBDL::showTexture(bombing7,0,0);}
        else if(x<800)
        {SBDL::showTexture(bombing8,0,0);}
        else
        {break;}
        SBDL::updateRenderScreen();
        SBDL::delay(50);
        x+=6;
    }
    cout << endl;
    cout << "MADE AND WRITTEN BY MAHAN VEISI\n";
    cout << "\nHere this is the final minsweeper map:" << endl;
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(lose,0,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if (SBDL::Mouse.x > 380 && SBDL::Mouse.x < 640 && SBDL::Mouse.y > 130 && SBDL::Mouse.y < 210)
            {
                final_board_cells();
                break;
            }
            else if (SBDL::Mouse.x > 490 && SBDL::Mouse.x < 630 && SBDL::Mouse.y > 260 && SBDL::Mouse.y < 390)
            {
                flag_for_change_user = 1;
                main();
                break;
            }
            else if (SBDL::Mouse.x > 490 && SBDL::Mouse.x < 630 && SBDL::Mouse.y > 420 && SBDL::Mouse.y < 540)
            {
                exit(0);
                break;
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void  show_the_cells_around_zero_cell(int i, int j) //in this function if a selected cell is zero the neutral cells around can be shown
// also if one of them is zero again it shows the cells around that one too
// by using recursy function
{
    if(auxiliary_array[i - 1][j - 1 ] != 1)
    { auxiliary_array[i - 1][j - 1 ] = 1 ;
        if( second_minesweeper_array[i - 1][j - 1] == 0)
        { show_the_cells_around_zero_cell(i - 1,j - 1) ;} }

    if(auxiliary_array[i - 1][j] != 1)
    {auxiliary_array[i - 1][j] = 1;
        if( second_minesweeper_array[i-1][j] == 0)
        { show_the_cells_around_zero_cell(i - 1,j) ;} }

    if(auxiliary_array[i - 1][j + 1 ] != 1)
    { auxiliary_array[i - 1][j + 1 ] = 1;
        if( second_minesweeper_array[i - 1][j + 1] == 0)
        { show_the_cells_around_zero_cell(i - 1,j + 1) ;} }

    if(auxiliary_array[i][j - 1] != 1)
    { auxiliary_array[i][j - 1] = 1,++current_neutral_cells_shown;
        if( second_minesweeper_array[i][j - 1] == 0)
        { show_the_cells_around_zero_cell(i,j - 1) ;}  }

    if(auxiliary_array[i][j + 1] != 1)
    { auxiliary_array[i][j + 1] = 1;
        if( second_minesweeper_array[i][j + 1] == 0)
        { show_the_cells_around_zero_cell(i,j + 1) ;} }

    if(auxiliary_array[i + 1][j - 1] != 1)
    { auxiliary_array[i + 1][j - 1] = 1;
        if( second_minesweeper_array[i + 1][j - 1] == 0)
        { show_the_cells_around_zero_cell(i + 1,j - 1) ;} }

    if(auxiliary_array[i + 1][j ] != 1)
    { auxiliary_array[i + 1][j ] = 1;
        if( second_minesweeper_array[i + 1][j] == 0)
        { show_the_cells_around_zero_cell(i + 1,j) ;} }

    if(auxiliary_array[i + 1][j + 1] != 1)
    { auxiliary_array[i + 1][j + 1] = 1;
        if( second_minesweeper_array[i + 1][j + 1] == 0)
        { show_the_cells_around_zero_cell(i + 1,j + 1) ;} }
}

int current_neutral_cells_counter(int x)
{
    x=0;
    for(int i=1; i<=row_size; ++i)
    {
        for(int j=1; j<=column_size; ++j)
        {
            if(auxiliary_array[i][j] == 1)
            {++x;}
        }
    }
    return x;
}

void flag_selection()
{
    ++number_of_flags;
    int player_row_guess = ((SBDL::Mouse.x)/30)+1;
    int player_col_guess = ((SBDL::Mouse.y)/30)+1;
    if(board_for_the_player[player_row_guess][player_col_guess] == '?')
    {
        board_for_the_player[player_row_guess][player_col_guess] = '#';
        number_of_flags -= 2;
    }
    else
    {
        if(number_of_flags > number_of_mines)
        {  --number_of_flags; }                            // inja mitoni begi max reached
        else
        {  board_for_the_player[player_row_guess][player_col_guess] = '?'; }
    }
}
void game_poster()
{
    int x=0;
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(mahan_company,0,0);
        ++x;
        if(x>50)
        {break;}
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(poster,0,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if(SBDL::Mouse.x>230 && SBDL::Mouse.x<450 && SBDL::Mouse.y>190 && SBDL::Mouse.y<240)
            {return;}
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}
void  pre_game_menu() {
    player_info first_user;
    int i_for_player = 0;
    first_user.name[0] = '\0';
    first_user.score = 0;
    int flag_for_break = 0;
    Texture fontTexture = SBDL::createFontTexture(font, "enter your name please :)", 0, 0, 0);
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(poster_with_free_line, 0, 0);
        SBDL::showTexture(fontTexture, 50, 300);
        if (flag_for_break == 1)
        {
            player_info player;
            player.name[0] = '\0';
            for(int i=0; first_user.name[i] != '\0'; ++i)
            {
                player.name[i] = first_user.name[i];
                if(first_user.name[i+1] == '\0')
                {  player.name[i+1] = '\0';    }
            }
            player.score = 0;
            char** file_keeper = new char*[20] ;
            for(int i=0; i<20; ++i)
            {  file_keeper[i] = new char[20] ; }
            int i_for_lines_of_text = 0;
            myFile.open("players_name_and_score.txt", ios::in);
            if (myFile.is_open())
            {
                for(int i=0; i<20 ; ++i)
                {
                    if(!myFile.eof())
                    {
                        string line_carrier;
                        myFile >> line_carrier ;
                        for(int j=0; line_carrier[j] != '\0'; ++j)
                        {
                            file_keeper[i][j] = line_carrier[j];
                            if(line_carrier[j+1] == '\0')
                            {file_keeper[i][j+1] = '\0';}
                        }
                    }
                    else if(myFile.eof())
                    {
                        i_for_lines_of_text = i-1;
                        break;
                    }
                }
            }
            myFile.close();
            // check
            bool check_if_the_name_has_been_in_the_text_befor = false;
            for(int i=0; i<i_for_lines_of_text ;++i)
            {
                char name_part_of_file_carrier[20];
                for(int z=0; file_keeper[i][z] != '.' && file_keeper[i][z] != '\0'; ++z)
                {
                    name_part_of_file_carrier[z] = file_keeper[i][z];
                    if(file_keeper[i][z+1] == '.' || file_keeper[i][z+1] == '\0')
                    {name_part_of_file_carrier[z+1] = '\0';}
                }
                bool comparison_answer = compare_two_arrays(name_part_of_file_carrier, player.name);

                if(comparison_answer) // puting the score that the player had befor on player.score
                {
                    check_if_the_name_has_been_in_the_text_befor = true;
                    char number_part_of_file_carrier[4];
                    int dot_place_counter = 0;
                    while (file_keeper[i][dot_place_counter] != '.')
                    {++dot_place_counter;}
                    ++dot_place_counter;
                    for(int i_for_number_carrier=0; file_keeper[i][dot_place_counter] != '\0'; ++dot_place_counter,++i_for_number_carrier)
                    {
                        number_part_of_file_carrier[i_for_number_carrier] = file_keeper[i][dot_place_counter];
                        if(file_keeper[i][dot_place_counter+1] == '\0')
                        {number_part_of_file_carrier[i_for_number_carrier+1] = '\0';}
                    }
                    player.score = char_number_to_int_convertor(number_part_of_file_carrier);
                    break;
                }
            }

            if(!check_if_the_name_has_been_in_the_text_befor)
            {
                myFile.open("players_name_and_score.txt", ios::app);
                for (int i = 0; player.name[i] != '\0'; ++i)
                { myFile << player.name[i]; }
                myFile << "." ;
                myFile << player.score;
                myFile << endl;
                myFile.close();
            }
            else
            {
                myFile.open("players_name_and_score.txt", ios::out);
                for(int i=0; i<i_for_lines_of_text ; ++i)
                {
                    for(int j=0; file_keeper[i][j] != '\0'; ++j)
                    {
                        myFile << file_keeper[i][j];
                    }
                    myFile << endl;
                }
                myFile.close();
            }
            bool flag_for_backslash_zero = false;
            for(int i=0; i<20; ++i)
            {
                if(!flag_for_backslash_zero)
                {
                    the_player_name[i] = player.name[i];
                    if(player.name[i+1] == '\0')
                    { flag_for_backslash_zero = true;}
                }
                else
                {the_player_name[i] = '\0';}
            }
            the_score = player.score;
            for(int i=0; i<20; ++i)
            {   delete[] file_keeper[i];    }
            delete[] file_keeper;
            delay(100);
            flag_for_break = 0;
            return;
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_A))
        {
            first_user.name[i_for_player] = 'A';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_B))
        {
            first_user.name[i_for_player] = 'B';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_C))
        {
            first_user.name[i_for_player] = 'C';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_D))
        {
            first_user.name[i_for_player] = 'D';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_E))
        {
            first_user.name[i_for_player] = 'E';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_F))
        {
            first_user.name[i_for_player] = 'F';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_G))
        {
            first_user.name[i_for_player] = 'G';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_H))
        {
            first_user.name[i_for_player] = 'H';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_I))
        {
            first_user.name[i_for_player] = 'I';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_J))
        {
            first_user.name[i_for_player] = 'J';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_K))
        {
            first_user.name[i_for_player] = 'K';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_L))
        {
            first_user.name[i_for_player] = 'L';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_M))
        {
            first_user.name[i_for_player] = 'M';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_N))
        {
            first_user.name[i_for_player] = 'N';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_O))
        {
            first_user.name[i_for_player] = 'O';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_P))
        {
            first_user.name[i_for_player] = 'P';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_Q))
        {
            first_user.name[i_for_player] = 'Q';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_R))
        {
            first_user.name[i_for_player] = 'R';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_S))
        {
            first_user.name[i_for_player] = 'S';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_T))
        {
            first_user.name[i_for_player] = 'T';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        } else if (SBDL::keyPressed(SDL_SCANCODE_U))
        {
            first_user.name[i_for_player] = 'U';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_V))
        {
            first_user.name[i_for_player] = 'V';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_W))
        {
            first_user.name[i_for_player] = 'W';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_X))
        {
            first_user.name[i_for_player] = 'X';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_Y))
        {
            first_user.name[i_for_player] = 'Y';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_Z))
        {
            first_user.name[i_for_player] = 'Z';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_SPACE))
        {
            first_user.name[i_for_player] = ' ';
            ++i_for_player;
            first_user.name[i_for_player] = ' ';
            ++i_for_player;
            first_user.name[i_for_player] = '\0';
            fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_RETURN))
        {
            fontTexture = SBDL::createFontTexture(font, "OK :)", 0, 0, 0);
            flag_for_break = 1;
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_DELETE))
        {
            if (i_for_player == 0) { first_user.name[i_for_player] = ' '; }
            else {
                --i_for_player;
                first_user.name[i_for_player] = '\0';
                if (i_for_player == 0) { first_user.name[i_for_player] = ' '; }
                fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
            }
        }
        else if (SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
        {
            if (i_for_player == 0) { first_user.name[i_for_player] = ' '; }
            else {
                --i_for_player;
                first_user.name[i_for_player] = '\0';
                if (i_for_player == 0) { first_user.name[i_for_player] = ' '; }
                fontTexture = SBDL::createFontTexture(font, first_user.name, 0, 0, 0);
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void custom_game_option()
{
    Texture fontTexture_row = SBDL::createFontTexture(font, "enter rows (5 , 20)", 0, 0, 0);
    Texture fontTexture_col = SBDL::createFontTexture(font, "enter cols (5 , 20)", 0, 0, 0);
    Texture fontTexture_bombs = SBDL::createFontTexture(font, "enter bombs (1 , 200)", 0, 0, 0);
    Texture fontTexture_time = SBDL::createFontTexture(font, "enter time (20s , 400s)", 0, 0, 0);
    char player_row_guess[3];
    char player_col_guess[3];
    char player_bomb_guess[3];
    char player_time_guess[3];
    player_row_guess[0] = player_col_guess[0] = player_bomb_guess[0] = player_time_guess[0] = '\0';
    int i_for_player = 0;
    int row_guess = 0, col_guess = 0, bomb_guess = 0, time_guess = 0;
    int flag_for_row_guess = 0, flag_for_col_guess = 0, flag_for_bomb_guess = 0, flag_for_time_guess = 0;
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(custom, 0, 0);
        SBDL::showTexture(fontTexture_row, 80, 50);
        SBDL::showTexture(fontTexture_col, 80, 180);
        SBDL::showTexture(fontTexture_bombs, 80, 300);
        SBDL::showTexture(fontTexture_time, 80, 420);
        if(flag_for_wrong_input == 1)
        {   SBDL::showTexture(wrong_input, 80, 490);    }
        if(flag_for_row_guess == 0)
        {
            if (SBDL::keyPressed(SDL_SCANCODE_1))
            {
                player_row_guess[i_for_player] = '1';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_2))
            {
                player_row_guess[i_for_player] = '2';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_3))
            {
                player_row_guess[i_for_player] = '3';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_4))
            {
                player_row_guess[i_for_player] = '4';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_5))
            {
                player_row_guess[i_for_player] = '5';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_row_guess[i_for_player] = '6';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_row_guess[i_for_player] = '6';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_7))
            {
                player_row_guess[i_for_player] = '7';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_8))
            {
                player_row_guess[i_for_player] = '8';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_9))
            {
                player_row_guess[i_for_player] = '9';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_0))
            {
                player_row_guess[i_for_player] = '0';
                ++i_for_player;
                player_row_guess[i_for_player] = '\0';
                fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_DELETE))
            {
                if (i_for_player == 0) { player_row_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_row_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_row_guess[i_for_player] = ' '; }
                    fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
            {
                if (i_for_player == 0) { player_row_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_row_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_row_guess[i_for_player] = ' '; }
                    fontTexture_row = SBDL::createFontTexture(font, player_row_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_RETURN))
            {
                flag_for_row_guess = 1;
                i_for_player = 0;
            }
        }
        else if(flag_for_col_guess == 0)
        {
            if (SBDL::keyPressed(SDL_SCANCODE_1))
            {
                player_col_guess[i_for_player] = '1';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_2))
            {
                player_col_guess[i_for_player] = '2';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_3))
            {
                player_col_guess[i_for_player] = '3';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_4))
            {
                player_col_guess[i_for_player] = '4';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_5))
            {
                player_col_guess[i_for_player] = '5';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_col_guess[i_for_player] = '6';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_col_guess[i_for_player] = '6';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_7))
            {
                player_col_guess[i_for_player] = '7';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_8))
            {
                player_col_guess[i_for_player] = '8';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_9))
            {
                player_col_guess[i_for_player] = '9';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_0))
            {
                player_col_guess[i_for_player] = '0';
                ++i_for_player;
                player_col_guess[i_for_player] = '\0';
                fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_DELETE))
            {
                if (i_for_player == 0)
                { player_col_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_col_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_col_guess[i_for_player] = ' '; }
                    fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
            {
                if (i_for_player == 0)
                { player_col_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_col_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_col_guess[i_for_player] = ' '; }
                    fontTexture_col = SBDL::createFontTexture(font, player_col_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_RETURN))
            {
                flag_for_col_guess = 1;
                i_for_player = 0;
            }
        }

        else if(flag_for_bomb_guess == 0)
        {
            if (SBDL::keyPressed(SDL_SCANCODE_1))
            {
                player_bomb_guess[i_for_player] = '1';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_2))
            {
                player_bomb_guess[i_for_player] = '2';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_3))
            {
                player_bomb_guess[i_for_player] = '3';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_4))
            {
                player_bomb_guess[i_for_player] = '4';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_5))
            {
                player_bomb_guess[i_for_player] = '5';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_bomb_guess[i_for_player] = '6';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_bomb_guess[i_for_player] = '6';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_7))
            {
                player_bomb_guess[i_for_player] = '7';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_8))
            {
                player_bomb_guess[i_for_player] = '8';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_9))
            {
                player_bomb_guess[i_for_player] = '9';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_0))
            {
                player_bomb_guess[i_for_player] = '0';
                ++i_for_player;
                player_bomb_guess[i_for_player] = '\0';
                fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_DELETE))
            {
                if (i_for_player == 0)
                { player_bomb_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_bomb_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_bomb_guess[i_for_player] = ' '; }
                    fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
            {
                if (i_for_player == 0)
                { player_bomb_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_bomb_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_bomb_guess[i_for_player] = ' '; }
                    fontTexture_bombs = SBDL::createFontTexture(font, player_bomb_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_RETURN))
            {
                flag_for_bomb_guess = 1;
                i_for_player = 0;
            }
        }
        else if(flag_for_time_guess == 0)
        {
            if (SBDL::keyPressed(SDL_SCANCODE_1))
            {
                player_time_guess[i_for_player] = '1';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_2))
            {
                player_time_guess[i_for_player] = '2';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_3))
            {
                player_time_guess[i_for_player] = '3';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_4))
            {
                player_time_guess[i_for_player] = '4';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_5))
            {
                player_time_guess[i_for_player] = '5';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_time_guess[i_for_player] = '6';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_6))
            {
                player_time_guess[i_for_player] = '6';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_7))
            {
                player_time_guess[i_for_player] = '7';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_8))
            {
                player_time_guess[i_for_player] = '8';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_9))
            {
                player_time_guess[i_for_player] = '9';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if(SBDL::keyPressed(SDL_SCANCODE_0))
            {
                player_time_guess[i_for_player] = '0';
                ++i_for_player;
                player_time_guess[i_for_player] = '\0';
                fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_DELETE))
            {
                if (i_for_player == 0)
                { player_time_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_time_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_time_guess[i_for_player] = ' '; }
                    fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_BACKSPACE))
            {
                if (i_for_player == 0)
                { player_time_guess[i_for_player] = ' '; }
                else {
                    --i_for_player;
                    player_time_guess[i_for_player] = '\0';
                    if (i_for_player == 0) { player_time_guess[i_for_player] = ' '; }
                    fontTexture_time = SBDL::createFontTexture(font, player_time_guess, 0, 0, 0);
                }
            }
            else if (SBDL::keyPressed(SDL_SCANCODE_RETURN))
            {
                flag_for_time_guess = 1;
                i_for_player = 0;
                break;
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
    row_guess = char_number_to_int_convertor(player_row_guess);
    col_guess = char_number_to_int_convertor(player_col_guess);
    bomb_guess = char_number_to_int_convertor(player_bomb_guess);
    time_guess = char_number_to_int_convertor(player_time_guess);
    if(row_guess<5 || row_guess>20 || col_guess<5 || col_guess>20 || time_guess<20 || time_guess>400 || bomb_guess<1 || bomb_guess>200)
    {
        flag_for_wrong_input = 1;
        custom_game_option();
    }
    else
    {
        row_size = row_guess;
        column_size = col_guess;
        number_of_main_array_cells = row_guess*col_guess;
        number_of_mines = bomb_guess;
        number_of_flags = 0;
        current_neutral_cells_shown=1;
        total_time_of_game = time_guess;
        number_of_neutral_cells = number_of_main_array_cells - bomb_guess;
    }
}

void menu_poster()
{
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(menu,0,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if(SBDL::Mouse.x>290 && SBDL::Mouse.x<490 && SBDL::Mouse.y>100 && SBDL::Mouse.y<160) //newgame
            { new_game_func();break; }
            else if(SBDL::Mouse.x>320 && SBDL::Mouse.x<540 && SBDL::Mouse.y>170 && SBDL::Mouse.y<230) // loadgame
            {
                load_game_function() ;
                flag_for_if_the_game_has_been_loaded = 1 ;
                break;
            }
            else if(SBDL::Mouse.x>350 && SBDL::Mouse.x<560 && SBDL::Mouse.y>245 && SBDL::Mouse.y<300)
            {
                flag_for_change_user = 1;
                break;
            }
            else if(SBDL::Mouse.x>360 && SBDL::Mouse.x<570 && SBDL::Mouse.y>310 && SBDL::Mouse.y<365)
            {
                leaderboard();
            }
                // setting
            else if(SBDL::Mouse.x>330 && SBDL::Mouse.x<530 && SBDL::Mouse.y>375 && SBDL::Mouse.y<480)
            {
                music_setting();
            }
            else if(SBDL::Mouse.x>290 && SBDL::Mouse.x<500 && SBDL::Mouse.y>440 && SBDL::Mouse.y<510)
            {   
                exit(0);
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void music_setting()
{
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(setting_of_music, 0, 0);
        if (SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_RELEASED))
        {
            if(SBDL::Mouse.x>530 && SBDL::Mouse.x<620 && SBDL::Mouse.y>20 && SBDL::Mouse.y<120)
            {
                flag_for_exit_from_game_and_return_to_menu = 1;
                main();
                break;
            }
            else if(SBDL::Mouse.x>90 && SBDL::Mouse.x<220 && SBDL::Mouse.y>160 && SBDL::Mouse.y<390)
            {
                SBDL::playMusic(music1,-1);
            }
            else if(SBDL::Mouse.x>270 && SBDL::Mouse.x<410 && SBDL::Mouse.y>200 && SBDL::Mouse.y<400)
            {
                SBDL::stopMusic();
            }
            else if(SBDL::Mouse.x>450 && SBDL::Mouse.x<590 && SBDL::Mouse.y>170 && SBDL::Mouse.y<390)
            {
                SBDL::playMusic(music2,-1);
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void new_game_func()
{
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(slots,0,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if(SBDL::Mouse.x>100 && SBDL::Mouse.x<170 && SBDL::Mouse.y>290 && SBDL::Mouse.y<370)
            {
                flag_for_slot_one = 1;
                flag_for_slot_two = 0;
                flag_for_slot_three = 0;
                flag_for_slot_four = 0;
                map_size();
                break;
            }
            else if(SBDL::Mouse.x>220 && SBDL::Mouse.x<300 && SBDL::Mouse.y>390 && SBDL::Mouse.y<470)
            {
                flag_for_slot_one = 0;
                flag_for_slot_two = 1;
                flag_for_slot_three = 0;
                flag_for_slot_four = 0;
                map_size();
                break;
            }
            else if(SBDL::Mouse.x>360 && SBDL::Mouse.x<450 && SBDL::Mouse.y>400 && SBDL::Mouse.y<480)
            {
                flag_for_slot_one = 0;
                flag_for_slot_two = 0;
                flag_for_slot_three = 1;
                flag_for_slot_four = 0;
                map_size();
                break;
            }
            else if(SBDL::Mouse.x>480 && SBDL::Mouse.x<570 && SBDL::Mouse.y>300 && SBDL::Mouse.y<390)
            {
                flag_for_slot_one = 0;
                flag_for_slot_two = 0;
                flag_for_slot_three = 0;
                flag_for_slot_four = 1;
                map_size();
                break;
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void map_size()
{
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(mapsize_pic,0,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if(SBDL::Mouse.x>100 && SBDL::Mouse.x<170 && SBDL::Mouse.y>290 && SBDL::Mouse.y<370) // 5*5
            {
                row_size = 5;
                column_size = 5;
                number_of_main_array_cells = 25;
                number_of_mines = 4;
                number_of_flags = 0;
                current_neutral_cells_shown=1;
                total_time_of_game = 60;
                number_of_neutral_cells = 21;
                break;
            }
            else if(SBDL::Mouse.x>220 && SBDL::Mouse.x<300 && SBDL::Mouse.y>390 && SBDL::Mouse.y<470) // 12*12
            {
                row_size = 12;
                column_size = 12;
                number_of_main_array_cells = 144;
                number_of_mines = 28;
                number_of_flags = 0;
                current_neutral_cells_shown=1;
                total_time_of_game = 120;
                number_of_neutral_cells = 116;
                break;
            }
            else if(SBDL::Mouse.x>360 && SBDL::Mouse.x<450 && SBDL::Mouse.y>400 && SBDL::Mouse.y<480) // 20*20
            {
                row_size = 20;
                column_size = 20;
                number_of_main_array_cells = 400;
                number_of_mines = 96;
                number_of_flags = 0;
                current_neutral_cells_shown=1;
                total_time_of_game = 250;
                number_of_neutral_cells = 304;
                break;
            }
            else if(SBDL::Mouse.x>480 && SBDL::Mouse.x<570 && SBDL::Mouse.y>300 && SBDL::Mouse.y<390) // custom
            {
                custom_game_option();
                break;
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void game_saver()
{
    if(flag_for_slot_one == 1)// free up save slot 1 and transfer datas and arrays
    {
        fstream save_slot_one_first_array("save_slot_one_first_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_one_first_array << first_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_one_first_array.close();

        fstream save_slot_one_second_array("save_slot_one_second_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_one_second_array << second_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_one_second_array.close();
        fstream save_slot_one_auxiliary_array("save_slot_one_auxiliary_array.txt", ios::out );
        if(save_slot_one_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_one_auxiliary_array << auxiliary_array[i][j] << endl;
                }
            }
            save_slot_one_auxiliary_array.close();
        }
        fstream save_slot_one_board_for_the_player_array("save_slot_one_board_for_the_player_array.txt", ios::out );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_one_board_for_the_player_array << board_for_the_player[i][j] << endl;
            }
        }
        save_slot_one_board_for_the_player_array.close();

        fstream save_slot_one_board_col_and_row_counter_array("save_slot_one_board_col_and_row_counter_array.txt", ios::out );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_one_board_col_and_row_counter_array << board_col_and_row_counter[i][j] << endl;
            }
        }
        save_slot_one_board_col_and_row_counter_array.close();

        fstream save_slot_one_variables("save_slot_one_variables.txt", ios::out ); // free up save slot 1 and transfer datas
        save_slot_one_variables << row_size << endl;
        save_slot_one_variables << column_size << endl;
        save_slot_one_variables << number_of_main_array_cells << endl;
        save_slot_one_variables << number_of_mines << endl;
        save_slot_one_variables << number_of_flags << endl;
        save_slot_one_variables << current_neutral_cells_shown << endl;
        save_slot_one_variables << total_time_of_game << endl;
        save_slot_one_variables << number_of_neutral_cells << endl;
        save_slot_one_variables << number_of_lines_of_text << endl;
        save_slot_one_variables << first_time << endl;
        save_slot_one_variables.close();
    }
    else if(flag_for_slot_two == 1)
    {
        fstream save_slot_two_first_array("save_slot_two_first_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_two_first_array << first_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_two_first_array.close();

        fstream save_slot_two_second_array("save_slot_two_second_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_two_second_array << second_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_two_second_array.close();
        fstream save_slot_two_auxiliary_array("save_slot_two_auxiliary_array.txt", ios::out );
        if(save_slot_two_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_two_auxiliary_array << auxiliary_array[i][j] << endl;
                }
            }
            save_slot_two_auxiliary_array.close();
        }
        fstream save_slot_two_board_for_the_player_array("save_slot_two_board_for_the_player_array.txt", ios::out );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_two_board_for_the_player_array << board_for_the_player[i][j] << endl;
            }
        }
        save_slot_two_board_for_the_player_array.close();

        fstream save_slot_two_board_col_and_row_counter_array("save_slot_two_board_col_and_row_counter_array.txt", ios::out );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_two_board_col_and_row_counter_array << board_col_and_row_counter[i][j] << endl;
            }
        }
        save_slot_two_board_col_and_row_counter_array.close();

        fstream save_slot_two_variables("save_slot_two_variables.txt", ios::out ); // free up save slot 1 and transfer datas
        save_slot_two_variables << row_size << endl;
        save_slot_two_variables << column_size << endl;
        save_slot_two_variables << number_of_main_array_cells << endl;
        save_slot_two_variables << number_of_mines << endl;
        save_slot_two_variables << number_of_flags << endl;
        save_slot_two_variables << current_neutral_cells_shown << endl;
        save_slot_two_variables << total_time_of_game << endl;
        save_slot_two_variables << number_of_neutral_cells << endl;
        save_slot_two_variables << number_of_lines_of_text << endl;
        save_slot_two_variables << first_time << endl;
        save_slot_two_variables.close();
    }
    else if(flag_for_slot_three == 1)
    {
        fstream save_slot_three_first_array("save_slot_three_first_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_three_first_array << first_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_three_first_array.close();
        fstream save_slot_three_second_array("save_slot_three_second_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_three_second_array << second_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_three_second_array.close();
        fstream save_slot_three_auxiliary_array("save_slot_three_auxiliary_array.txt", ios::out );
        if(save_slot_three_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_three_auxiliary_array << auxiliary_array[i][j] << endl;
                }
            }
            save_slot_three_auxiliary_array.close();
        }
        fstream save_slot_three_board_for_the_player_array("save_slot_three_board_for_the_player_array.txt", ios::out );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_three_board_for_the_player_array << board_for_the_player[i][j] << endl;
            }
        }
        save_slot_three_board_for_the_player_array.close();

        fstream save_slot_three_board_col_and_row_counter_array("save_slot_three_board_col_and_row_counter_array.txt", ios::out );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_three_board_col_and_row_counter_array << board_col_and_row_counter[i][j] << endl;
            }
        }
        save_slot_three_board_col_and_row_counter_array.close();
        fstream save_slot_three_variables("save_slot_three_variables.txt", ios::out ); // free up save slot 1 and transfer datas
        save_slot_three_variables << row_size << endl;
        save_slot_three_variables << column_size << endl;
        save_slot_three_variables << number_of_main_array_cells << endl;
        save_slot_three_variables << number_of_mines << endl;
        save_slot_three_variables << number_of_flags << endl;
        save_slot_three_variables << current_neutral_cells_shown << endl;
        save_slot_three_variables << total_time_of_game << endl;
        save_slot_three_variables << number_of_neutral_cells << endl;
        save_slot_three_variables << number_of_lines_of_text << endl;
        save_slot_three_variables << first_time << endl;
        save_slot_three_variables.close();
    }
    else if(flag_for_slot_four == 1)
    {
        fstream save_slot_four_first_array("save_slot_four_first_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_four_first_array << first_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_four_first_array.close();

        fstream save_slot_four_second_array("save_slot_four_second_array.txt", ios::out );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_four_second_array << second_minesweeper_array[i][j] << endl;
            }
        }
        save_slot_four_second_array.close();
        fstream save_slot_four_auxiliary_array("save_slot_four_auxiliary_array.txt", ios::out );
        if(save_slot_four_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_four_auxiliary_array << auxiliary_array[i][j] << endl;
                }
            }
            save_slot_four_auxiliary_array.close();
        }
        fstream save_slot_four_board_for_the_player_array("save_slot_four_board_for_the_player_array.txt", ios::out );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_four_board_for_the_player_array << board_for_the_player[i][j] << endl;
            }
        }
        save_slot_four_board_for_the_player_array.close();
        fstream save_slot_four_board_col_and_row_counter_array("save_slot_four_board_col_and_row_counter_array.txt", ios::out );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_four_board_col_and_row_counter_array << board_col_and_row_counter[i][j] << endl;
            }
        }
        save_slot_four_board_col_and_row_counter_array.close();
        fstream save_slot_four_variables("save_slot_four_variables.txt", ios::out ); // free up save slot 1 and transfer datas
        save_slot_four_variables << row_size << endl;
        save_slot_four_variables << column_size << endl;
        save_slot_four_variables << number_of_main_array_cells << endl;
        save_slot_four_variables << number_of_mines << endl;
        save_slot_four_variables << number_of_flags << endl;
        save_slot_four_variables << current_neutral_cells_shown << endl;
        save_slot_four_variables << total_time_of_game << endl;
        save_slot_four_variables << number_of_neutral_cells << endl;
        save_slot_four_variables << number_of_lines_of_text << endl;
        save_slot_four_variables << first_time << endl;
        save_slot_four_variables.close();
    }
}

void game_loader()
{
    if(flag_for_slot_one == 1)// free up save slot 1 and transfer datas and arrays
    {
        fstream save_slot_one_variables("save_slot_one_variables.txt", ios::in ); // free up save slot one and transfer datas
        save_slot_one_variables >> row_size ;
        save_slot_one_variables >> column_size ;
        save_slot_one_variables >> number_of_main_array_cells;
        save_slot_one_variables >> number_of_mines ;
        save_slot_one_variables >> number_of_flags ;
        save_slot_one_variables >> current_neutral_cells_shown;
        save_slot_one_variables >> total_time_of_game;
        save_slot_one_variables >> number_of_neutral_cells;
        save_slot_one_variables >> number_of_lines_of_text;
        save_slot_one_variables >> first_time;
        save_slot_one_variables.close();

        fstream save_slot_one_first_array("save_slot_one_first_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_one_first_array >> first_minesweeper_array[i][j] ;
            }
        }
        save_slot_one_first_array.close();

        fstream save_slot_one_second_array("save_slot_one_second_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_one_second_array >> second_minesweeper_array[i][j];
            }
        }
        save_slot_one_second_array.close();
        fstream save_slot_one_auxiliary_array("save_slot_one_auxiliary_array.txt", ios::in );
        if(save_slot_one_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_one_auxiliary_array >> auxiliary_array[i][j] ;
                }
            }
            save_slot_one_auxiliary_array.close();
        }
        fstream save_slot_one_board_for_the_player_array("save_slot_one_board_for_the_player_array.txt", ios::in );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_one_board_for_the_player_array >> board_for_the_player[i][j] ;
            }
        }
        save_slot_one_board_for_the_player_array.close();

        fstream save_slot_one_board_col_and_row_counter_array("save_slot_one_board_col_and_row_counter_array.txt", ios::in );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_one_board_col_and_row_counter_array >> board_col_and_row_counter[i][j] ;
            }
        }
        save_slot_one_board_col_and_row_counter_array.close();
    }
    else if(flag_for_slot_two == 1)
    {
        fstream save_slot_two_variables("save_slot_two_variables.txt", ios::in ); // free up save slot two and transfer datas
        save_slot_two_variables >> row_size ;
        save_slot_two_variables >> column_size ;
        save_slot_two_variables >> number_of_main_array_cells;
        save_slot_two_variables >> number_of_mines ;
        save_slot_two_variables >> number_of_flags ;
        save_slot_two_variables >> current_neutral_cells_shown;
        save_slot_two_variables >> total_time_of_game;
        save_slot_two_variables >> number_of_neutral_cells;
        save_slot_two_variables >> number_of_lines_of_text;
        save_slot_two_variables >> first_time;
        save_slot_two_variables.close();

        fstream save_slot_two_first_array("save_slot_two_first_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_two_first_array >> first_minesweeper_array[i][j] ;
            }
        }
        save_slot_two_first_array.close();

        fstream save_slot_two_second_array("save_slot_two_second_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_two_second_array >> second_minesweeper_array[i][j];
            }
        }
        save_slot_two_second_array.close();
        fstream save_slot_two_auxiliary_array("save_slot_two_auxiliary_array.txt", ios::in );
        if(save_slot_two_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_two_auxiliary_array >> auxiliary_array[i][j] ;
                }
            }
            save_slot_two_auxiliary_array.close();
        }
        fstream save_slot_two_board_for_the_player_array("save_slot_two_board_for_the_player_array.txt", ios::in );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_two_board_for_the_player_array >> board_for_the_player[i][j] ;
            }
        }
        save_slot_two_board_for_the_player_array.close();

        fstream save_slot_two_board_col_and_row_counter_array("save_slot_two_board_col_and_row_counter_array.txt", ios::in );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_two_board_col_and_row_counter_array >> board_col_and_row_counter[i][j] ;
            }
        }
        save_slot_two_board_col_and_row_counter_array.close();
    }
    else if(flag_for_slot_three == 1)
    {
        fstream save_slot_three_variables("save_slot_three_variables.txt", ios::in ); // free up save slot three and transfer datas
        save_slot_three_variables >> row_size ;
        save_slot_three_variables >> column_size ;
        save_slot_three_variables >> number_of_main_array_cells;
        save_slot_three_variables >> number_of_mines ;
        save_slot_three_variables >> number_of_flags ;
        save_slot_three_variables >> current_neutral_cells_shown;
        save_slot_three_variables >> total_time_of_game;
        save_slot_three_variables >> number_of_neutral_cells;
        save_slot_three_variables >> number_of_lines_of_text;
        save_slot_three_variables >> first_time;
        save_slot_three_variables.close();
        fstream save_slot_three_first_array("save_slot_three_first_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_three_first_array >> first_minesweeper_array[i][j] ;
            }
        }
        save_slot_three_first_array.close();

        fstream save_slot_three_second_array("save_slot_three_second_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_three_second_array >> second_minesweeper_array[i][j];
            }
        }
        save_slot_three_second_array.close();
        fstream save_slot_three_auxiliary_array("save_slot_three_auxiliary_array.txt", ios::in );
        if(save_slot_three_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_three_auxiliary_array >> auxiliary_array[i][j] ;
                }
            }
            save_slot_three_auxiliary_array.close();
        }
        fstream save_slot_three_board_for_the_player_array("save_slot_three_board_for_the_player_array.txt", ios::in );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_three_board_for_the_player_array >> board_for_the_player[i][j] ;
            }
        }
        save_slot_three_board_for_the_player_array.close();

        fstream save_slot_three_board_col_and_row_counter_array("save_slot_three_board_col_and_row_counter_array.txt", ios::in );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_three_board_col_and_row_counter_array >> board_col_and_row_counter[i][j] ;
            }
        }
        save_slot_three_board_col_and_row_counter_array.close();
    }
    else if(flag_for_slot_four == 1)
    {
        fstream save_slot_four_variables("save_slot_four_variables.txt", ios::in ); // free up save slot four and transfer datas
        save_slot_four_variables >> row_size ;
        save_slot_four_variables >> column_size ;
        save_slot_four_variables >> number_of_main_array_cells;
        save_slot_four_variables >> number_of_mines ;
        save_slot_four_variables >> number_of_flags ;
        save_slot_four_variables >> current_neutral_cells_shown;
        save_slot_four_variables >> total_time_of_game;
        save_slot_four_variables >> number_of_neutral_cells;
        save_slot_four_variables >> number_of_lines_of_text;
        save_slot_four_variables >> first_time;
        save_slot_four_variables.close();
        fstream save_slot_four_first_array("save_slot_four_first_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_four_first_array >> first_minesweeper_array[i][j] ;
            }
        }
        save_slot_four_first_array.close();
        fstream save_slot_four_second_array("save_slot_four_second_array.txt", ios::in );
        for(int i=0; i<=row_size + 1; ++i)
        {
            for(int j=0; j<=column_size + 1; ++j)
            {
                save_slot_four_second_array >> second_minesweeper_array[i][j];
            }
        }
        save_slot_four_second_array.close();
        fstream save_slot_four_auxiliary_array("save_slot_four_auxiliary_array.txt", ios::in );
        if(save_slot_four_auxiliary_array.is_open())
        {
            for (int i = 0; i < row_size + 1; ++i) {
                for (int j = 0; j < column_size + 1; ++j) {
                    save_slot_four_auxiliary_array >> auxiliary_array[i][j] ;
                }
            }
            save_slot_four_auxiliary_array.close();
        }
        fstream save_slot_four_board_for_the_player_array("save_slot_four_board_for_the_player_array.txt", ios::in );
        for(int i=1; i<=row_size; ++i)
        {
            for(int j=1; j<=column_size; ++j)
            {
                save_slot_four_board_for_the_player_array >> board_for_the_player[i][j] ;
            }
        }
        save_slot_four_board_for_the_player_array.close();

        fstream save_slot_four_board_col_and_row_counter_array("save_slot_four_board_col_and_row_counter_array.txt", ios::in );
        for(int i=0; i<=row_size; ++i)
        {
            for(int j=0; j<=column_size; ++j)
            {
                save_slot_four_board_col_and_row_counter_array >> board_col_and_row_counter[i][j] ;
            }
        }
        save_slot_four_board_col_and_row_counter_array.close();
        save_slot_four_variables.close();
    }
}
void  load_game_function()
{
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(slots,0,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if(SBDL::Mouse.x>100 && SBDL::Mouse.x<170 && SBDL::Mouse.y>290 && SBDL::Mouse.y<370)
            {
                flag_for_slot_one = 1;
                flag_for_slot_two = 0;
                flag_for_slot_three = 0;
                flag_for_slot_four = 0;
                game_loader();
                break;
            }
            else if(SBDL::Mouse.x>220 && SBDL::Mouse.x<300 && SBDL::Mouse.y>390 && SBDL::Mouse.y<470)
            {
                flag_for_slot_one = 0;
                flag_for_slot_two = 1;
                flag_for_slot_three = 0;
                flag_for_slot_four = 0;
                game_loader();
                break;
            }
            else if(SBDL::Mouse.x>360 && SBDL::Mouse.x<450 && SBDL::Mouse.y>400 && SBDL::Mouse.y<480)
            {
                flag_for_slot_one = 0;
                flag_for_slot_two = 0;
                flag_for_slot_three = 1;
                flag_for_slot_four = 0;
                game_loader();
                break;
            }
            else if(SBDL::Mouse.x>480 && SBDL::Mouse.x<570 && SBDL::Mouse.y>300 && SBDL::Mouse.y<390)
            {
                flag_for_slot_one = 0;
                flag_for_slot_two = 0;
                flag_for_slot_three = 0;
                flag_for_slot_four = 1;
                game_loader();
                break;
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

int length_of_array(char* a)
{
    int length=0;
    for(; a[length] != '\0'; ++length)
    {}
    return length;
}

bool compare_two_arrays(char* first_array, char* second_array)
{
    int length_of_first = length_of_array(first_array);
    int length_of_second = length_of_array(second_array);
    if(length_of_first != length_of_second)
    {   return false;   }
    else
    {
        for(int i=0; i<length_of_first; ++i)
        {
            if(first_array[i] != second_array[i])
            {   return false;}
        }
    }
    return true;
}

int char_number_to_int_convertor(char* char_number)
{
    int number = 0;
    for(int i=0; char_number[i] != '\0'; ++i)
    {
        char letter = char_number[i];
        if(letter == '0')
        {   number = number*10 + 0; }
        else if(letter == '1')
        {   number = number*10 + 1; }
        else if(letter == '2')
        {   number = number*10 + 2; }
        else if(letter == '3')
        {   number = number*10 + 3; }
        else if(letter == '4')
        {   number = number*10 + 4; }
        else if(letter == '5')
        {   number = number*10 + 5; }
        else if(letter == '6')
        {   number = number*10 + 6; }
        else if(letter == '7')
        {   number = number*10 + 7; }
        else if(letter == '8')
        {   number = number*10 + 8; }
        else if(letter == '9')
        {   number = number*10 + 9; }
    }
    return  number;
}

void win_function()
{
    //clear_screen();  /// ///// احتمالا این باک بشه
    player_info player;
    player.score = the_score;
    for(int i=0; the_player_name[i] != '\0'; ++i)
    {
        player.name[i] = the_player_name[i];
        if(the_player_name[i+1] == '\0')
        {player.name[i+1] = '\0';}
    }
    player.score = player.score + (row_size*column_size)+(number_of_mines*2);

    char** file_keeper = new char*[20] ;
    for(int i=0; i<20; ++i)
    {  file_keeper[i] = new char[20] ; }
    int i_for_lines_of_text = 0;
    myFile.open("players_name_and_score.txt", ios::in);
    if (myFile.is_open())
    {
        for(int i=0; i<20 ; ++i)
        {
            int j=0;
            if(!myFile.eof())
            {
                string line_carrier;
                myFile >> line_carrier;
                for(; line_carrier[j] != '\0'; ++j)
                {
                    file_keeper[i][j] = line_carrier[j];
                    if(line_carrier[j+1] == '\0')
                    {file_keeper[i][j+1] = '\0';}
                }
            }
            else if(myFile.eof())
            {
                file_keeper[i][j] = '\0';
                i_for_lines_of_text = i-1;
                break;
            }
        }
    }
    myFile.close();
    int i_for_edit_score_line = 0;
    for(int i=0; i<i_for_lines_of_text ;++i)
    {
        char name_part_of_file_carrier[20];
        for(int z=0; file_keeper[i][z] != '.'; ++z)
        {
            name_part_of_file_carrier[z] = file_keeper[i][z];
            if(file_keeper[i][z+1] == '.' || file_keeper[i][z+1] == '\0')
            {name_part_of_file_carrier[z+1] = '\0';}
        }
        bool comparison_answer = compare_two_arrays(name_part_of_file_carrier, player.name);

        if(comparison_answer) // puting the score that the player had befor on player.score
        {
            i_for_edit_score_line = i;
            break;
        }
    }

    myFile.open("players_name_and_score.txt", ios::out);
    for(int i=0; i<i_for_lines_of_text ; ++i)
    {
        if(i == i_for_edit_score_line)
        {
            for(int j=0; file_keeper[i][j] != '.'; ++j)
            {
                myFile << file_keeper[i][j];
            }
            myFile << '.';
            myFile << player.score;
            myFile << endl;
        }
        else
        {
            for(int j=0; file_keeper[i][j] != '\0'; ++j)
            {
                myFile << file_keeper[i][j];
            }
            myFile << endl;
        }
    }
    myFile.close();
    for(int i=0; i<20; ++i)
    {   delete[] file_keeper[i];    }
    delete[] file_keeper;

    cout << endl;
    cout << "MADE AND WRITTEN BY MAHAN VEISI\n";
    cout << "\nHere this is the final minsweeper map:" << endl;
    int x=0;
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        if(x<10)
        {SBDL::showTexture(firework0_0,0,0);x+=1;}
        else if(x<20)
        {SBDL::showTexture(firework0_1,0,0);x+=1;}
        else if(x<30)
        {SBDL::showTexture(firework0_0,0,0);x+=1;}
        else if(x<40)
        {SBDL::showTexture(firework0_2,0,0);x+=1;}
        else if(x<50)
        {SBDL::showTexture(firework0_0,0,0);x+=1;}
        else if(x<60)
        {SBDL::showTexture(firework1,0,0);x+=1;}
        else if(x<70)
        {SBDL::showTexture(firework2,0,0);x+=1;}
        else if(x<80)
        {SBDL::showTexture(firework3,0,0);x+=1;}
        else if(x<90)
        {SBDL::showTexture(firework4,0,0);x+=1;}
        else if(x<100)
        {SBDL::showTexture(firework5,0,0);x+=1;}
        else if(x<110)
        {SBDL::showTexture(firework6,0,0);x+=1;}
        else if(x<120)
        {SBDL::showTexture(firework7,0,0);x+=1;}
        else if(x<130)
        {SBDL::showTexture(firework8,0,0);x+=1;}
        else if(x<140)
        {SBDL::showTexture(firework9,0,0);x+=1;}
        else
        {
            SBDL::showTexture(win_poster,0,0);
            if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
            {
                if (SBDL::Mouse.x > 350 && SBDL::Mouse.x < 470 && SBDL::Mouse.y > 140 && SBDL::Mouse.y < 240) // finalboard
                {
                    final_board_cells();
                    break;
                }
                else if(SBDL::Mouse.x > 480 && SBDL::Mouse.x < 545 && SBDL::Mouse.y > 130 && SBDL::Mouse.y < 230)
                {
                    flag_for_change_user = 1;
                    main();
                    break;
                }
                else if(SBDL::Mouse.x > 580 && SBDL::Mouse.x < 640 && SBDL::Mouse.y > 130 && SBDL::Mouse.y < 230)
                {
                    exit(0);
                    break;
                }
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void leaderboard()
{
    char** file_keeper = new char*[20] ;             //  inja badan age khasti toolesh ro bishtar kon
    for(int i=0; i<20; ++i)
    {  file_keeper[i] = new char[20]; }
    for(int i=0; i<20; ++i)
    {   file_keeper[i][0] = '\0';   }
    int i_for_lines_of_text = 0;
    myFile.open("players_name_and_score.txt", ios::in);
    if (myFile.is_open())
    {
        for(int i=0; i<20 ; ++i)
        {
            int j=0;
            if(!myFile.eof())
            {
                string line_carrier;
                myFile >> line_carrier;
                for(; line_carrier[j] != '\0'; ++j)
                {
                    file_keeper[i][j] = line_carrier[j];
                    if(line_carrier[j+1] == '\0')
                    {file_keeper[i][j+1] = '\0';}
                }
            }
            else if(myFile.eof())
            {
                file_keeper[i][j] = '\0';
                i_for_lines_of_text = i-1;
                break;
            }
        }
    }
    myFile.close();
    int flag_for_names[20];                     //  inja badan age khasti toolesh ro bishtar kon
    for(int i=0; i<20; ++i)
    {flag_for_names[i] = 0;}
    int top_five_scores[5];
    for(int i=0; i<5; ++i)
    {top_five_scores[i] = 0;}
    char** top_five_names = new char*[5] ;
    for(int i=0; i<5; ++i)
    {  top_five_names[i] = new char[20]; }
    for(int i=0; i<5; ++i)
    {
        top_five_names[i][0] = ' ';
        top_five_names[i][1] = '\0';
    }

    int max_of_scores = 0;
    int i_for_max=0;
    int t = 5;
    if(i_for_lines_of_text < 5)
    {
        t=i_for_lines_of_text;
    }
    for(int j=0; j<t; ++j, max_of_scores = 0, i_for_max=0)
    {
        for(int i=0; i<i_for_lines_of_text; ++i)
        {
            char number_part_of_file_carrier[4];
            int dot_place_counter = 0;
            while (file_keeper[i][dot_place_counter] != '.')
            {++dot_place_counter;}
            ++dot_place_counter;
            for(int i_for_number_carrier = 0; file_keeper[i][dot_place_counter] != '\0'; ++dot_place_counter,++i_for_number_carrier)
            {
                number_part_of_file_carrier[i_for_number_carrier] = file_keeper[i][dot_place_counter];
                if(file_keeper[i][dot_place_counter+1] == '\0')
                {number_part_of_file_carrier[i_for_number_carrier+1] = '\0';}
            }
            int score = char_number_to_int_convertor(number_part_of_file_carrier);
            if(score >= max_of_scores && flag_for_names[i] == 0)
            {
                max_of_scores = score;
                i_for_max = i;
            }
        }
        top_five_scores[j] = max_of_scores;
        for(int z=0; file_keeper[i_for_max][z] != '\0' && file_keeper[i_for_max][z] != '.'; ++z)
        {
            top_five_names[j][z] = file_keeper[i_for_max][z];
            if (file_keeper[i_for_max][z+1] == '\0' || file_keeper[i_for_max][z+1] == '.')
            {   top_five_names[j][z+1] = '\0' ;   }
        }
        flag_for_names[i_for_max] = 1;
    }
    for(int i=0; i<20; ++i)
    {   delete[] file_keeper[i];    }
    delete[] file_keeper;
    Texture first_player_rank_letter = SBDL::createFontTexture(first_player_rank ,top_five_names[0],0,0,0);
    Texture first_player_rank_number = SBDL::createFontTexture(first_player_rank_score , to_string(top_five_scores[0]),0,0,0);
    Texture second_player_rank_letter = SBDL::createFontTexture(second_player_rank ,top_five_names[1],0,0,0);
    Texture second_player_rank_number = SBDL::createFontTexture(second_player_rank_score , to_string(top_five_scores[1]),0,0,0);
    Texture third_player_rank_letter = SBDL::createFontTexture(third_player_rank ,top_five_names[2],0,0,0);
    Texture third_player_rank_number = SBDL::createFontTexture(third_player_rank_score , to_string(top_five_scores[2]),0,0,0);
    Texture fourth_player_rank_letter = SBDL::createFontTexture(fourth_player_rank ,top_five_names[3],0,0,0);
    Texture fourth_player_rank_number = SBDL::createFontTexture(fourth_player_rank_score , to_string(top_five_scores[3]),0,0,0);
    Texture fifth_player_rank_letter = SBDL::createFontTexture(fifth_player_rank ,top_five_names[4],0,0,0);
    Texture fifth_player_rank_number = SBDL::createFontTexture(fifth_player_rank_score , to_string(top_five_scores[4]),0,0,0);
    for(int i=0; i<5; ++i)
    {   delete[] top_five_names[i]; }
    delete[] top_five_names;
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        SBDL::showTexture(leaderboard_poster,0,0);
        SBDL::showTexture(first_player_rank_letter,100,30);
        SBDL::showTexture(first_player_rank_number,400,30);
        SBDL::showTexture(second_player_rank_letter,100,160);
        SBDL::showTexture(second_player_rank_number,400,160);
        SBDL::showTexture(third_player_rank_letter,100,280);
        SBDL::showTexture(third_player_rank_number,400,280);
        SBDL::showTexture(fourth_player_rank_letter,100,400);
        SBDL::showTexture(fourth_player_rank_number,400,400);
        SBDL::showTexture(fifth_player_rank_letter,100,520);
        SBDL::showTexture(fifth_player_rank_number,400,520);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if(SBDL::Mouse.x>600 && SBDL::Mouse.x<650 && SBDL::Mouse.y>10 && SBDL::Mouse.y<90)
            {
                flag_for_exit_from_game_and_return_to_menu = 1;
                main();
                break;
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}

void time_operation()
{
    long long int time_spend = time(0) - first_time;
    if (time_spend >= total_time_of_game )
    {   lose_function();    }
    else if(time_spend >= (total_time_of_game-10))
    {   SBDL::showTexture(time6,600,350);   }

    else if(time_spend >= (total_time_of_game-25))
    {   SBDL::showTexture(time5,600,350);    }
    else if(time_spend >= (total_time_of_game-50))
    {   SBDL::showTexture(time4,600,350);    }
    else if(time_spend >= (total_time_of_game-100))
    {   SBDL::showTexture(time3,600,350);    }
    else if(time_spend >= (total_time_of_game-200))
    {   SBDL::showTexture(time2,600,350);    }
    else
    {   SBDL::showTexture(time1,600,350);    }
}

void final_board_cells()
{
    while (SBDL::isRunning())
    {
        SBDL::updateEvents();
        SBDL::clearRenderScreen();
        for(int i=1; i<= row_size; ++i)
        {
            for(int j=1; j <= column_size; ++j)
            {
                if(first_minesweeper_array[i][j] == 1) //if it is a bomb cell
                {   SBDL::showTexture(bomb,(i-1)*30,(j-1)*30); }
                else if(first_minesweeper_array[i][j] == 0 ) // if it is not a bomb cell
                {
                    if(second_minesweeper_array[i][j] == 0)
                    {SBDL::showTexture(n0,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 1)
                    {SBDL::showTexture(n1,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 2)
                    {SBDL::showTexture(n2,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 3)
                    {SBDL::showTexture(n3,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 4)
                    {SBDL::showTexture(n4,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 5)
                    {SBDL::showTexture(n5,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 6)
                    {SBDL::showTexture(n6,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 7)
                    {SBDL::showTexture(n7,(i-1)*30,(j-1)*30);}
                    else if(second_minesweeper_array[i][j] == 8)
                    {SBDL::showTexture(n8,(i-1)*30,(j-1)*30);}
                }
            }
        }
        SBDL::showTexture(right_margin1,600,0);
        if(SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_RELEASED))
        {
            if (SBDL::Mouse.x > 600 && SBDL::Mouse.x < 650 && SBDL::Mouse.y > 100 && SBDL::Mouse.y < 170) {
                flag_for_change_user = 1;
                main();
                break;
            } 
            else if (SBDL::Mouse.x > 600 && SBDL::Mouse.x < 650 && SBDL::Mouse.y > 10 && SBDL::Mouse.y < 80) 
            {
                exit(0);
            }
        }
        SBDL::updateRenderScreen();
        SBDL::delay(50);
    }
}