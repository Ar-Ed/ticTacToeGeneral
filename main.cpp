#include "utilities.h"

int main(void){
    short size; // n where game square is n x n
    short player_turn = 0;
    
    system("clear");
    std::vector<std::vector<char> > position(size,std::vector<char>(size, ' '));
    std::cout << "\n\n\t\t\t\t****** Welcome to the game of Tic Tac Toe ******\n\n\n\n\n"<< std::endl;
    std::cout << "Enter game size : ";

    while(!(std::cin >> size)){
        std::cout << "Please Enter Valid Values :  ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
    }    

    while(1){
        
        display_game(position, size);
        take_input(position, player_turn, size);
        system("clear");
        std::cout << "\n\n\n\n\t\t\t\t****** Welcome to the game of Tic Tac Toe ******"<< std::endl;

        if(char winner = game_status(position, size)){
            display_game(position, size);
            std::cout <<"\n\t\t\t\t\t\t****** "<< winner << " is The Winner ****** \n\n\n\n\n" << std::endl;
            break;
        }else{std::cout<< "\n\n\n\n\n\n";}

        player_turn++;
        // Max play count is size*size
        if(player_turn == size*size){std::cout << "\n\t\t\t\t\t\t\t****** It's a tie! ******\n\n\n\n\n"; break;} 
        
    }
    return 0;
}
