#include "utilities.h"

short input_check(short x, short y, std::vector<std::vector<char> > &position, short size){
    if(x > size || x < 1 || y > size || y < 1){
        std::cout << "Invalid Position! \n";
        return 1;
    }else if(position[y-1][x-1] != ' '){
        std::cout << "This position is already taken! \n";
        return 1;
    }
    return 0;
}

void take_input(std::vector<std::vector<char> > &position, short turn, short size){
    short x,y;
    do{
        if(turn % 2 == 0){
            std::cout << "\nX's Turn, Enter column and row : ";
            while(!(std::cin >> x >> y)){      // check if input is a valid number
                std::cout << "Please Enter Valid Values :  ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        }
        else{
            std::cout << "\nO's Turn, Enter column and row : ";
            while(!(std::cin >> x >> y)){
                std::cout << "Please Enter Valid Values :  ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }       
        }
    }while(input_check(x, y, position, size));// loop until passes input_check
    if(turn % 2 == 0)position[y-1][x-1] = 'X';
    else position[y-1][x-1] = 'O';
}

void display_game(std::vector<std::vector<char> > &position, short size){
    int k = 0;
    std::cout << "\n\n\n\n\n\n\t\t\t\t\t\t";
    for(int i = 0; i < 8*size; i++){
        if( (i+4) % 8 == 0 )std::cout << (i+4)/8;
        else std::cout << " ";
    }
    std::cout << "\n\n\t\t\t\t\t\t";
    while(k < size){
        for(int i = 0 ; i <= 8*size; i++){
            std::cout << "-";
        }
        std::cout << "\n\t\t\t\t\t\t";
        for(int i = 0 ; i <= 8*size; i++){
            if(i % 8 == 0)std::cout << "|";
            else std::cout << " ";
        }
        std::cout << "\n\t\t\t\t\t\t|";
        for(int i = 0 ; i < size; i++){
            std::cout << "   " << position[k][i] << "   |";;
        }
        std::cout << "    "<< k+1 <<  "\n\t\t\t\t\t\t";
        for(int i = 0 ; i <= 8*size; i++){
            if(i % 8 == 0)std::cout << "|";
            else std::cout << " ";
        }
        std::cout << "\n\t\t\t\t\t\t";

        k++;
    }
    for(int i = 0 ; i <= 8*size; i++){
        std::cout << "-";
    }std::cout << "\n\n\n";
}
//Game Engine
char game_status(std::vector<std::vector<char> > position,short size){
    short boolean = 1;
    //Check columns
    for(int x=0; x <size;x++){
        boolean = 1;
        for(int y=1; y<size;y++){
            if(position[x][0] != position[x][y]){boolean = 0;break;}
        }
        if(boolean && position[x][0] != ' ') return position[x][0];
    }
    //Check rows
    for(int y=0; y <size;y++){
        boolean = 1;
        for(int x=1; x<size;x++){
            if(position[0][y] != position[x][y]){boolean = 0;break;}
        }
        if(boolean && position[0][y] != ' ') return position[0][y];
    }

    //Check cross 00-11-22  
    boolean = 1;
    for(int i = 1; i<size;i++){
        if(position[0][0] != position[i][i]){boolean = 0;break;}
    }
    if(boolean && position[0][0] != ' ')return position[0][0];

    //Check cross 20-11-02
    boolean = 1;
    for(int i = 1; i<size;i++){
        if(position[size-1][0] != position[size-1-i][i]){boolean = 0;break;}
    }
    if(boolean && position[size-1][0] != ' ')return position[size-1][0];
    
    return 0;
}