#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

char gameCheck(vector< vector<char> > &Vgame, int &playerX, int &playerO);

int main(){
    string gameLine="";
    int gameAmount=0;
    vector< vector<char> > Vgame(4, vector<char>(4));
    int playerX=0;
    int playerO=0;
    char gameStatus=' ';

    ifstream googleInput;
    ofstream googleOutput;

    googleInput.open("A-large.in");
    googleOutput.open("A-Large.out");

    //cout << "enter game amount: ";
    googleInput >> gameAmount;
    //cout << endl;

    //cout << gameAmount << endl;
    for(int i=1; i<=gameAmount; i++){

        for(int v=0; v<4; v++){
            //cout <<"|>>";
            googleInput >> gameLine;

            for(int x=0; x<4; x++){
                Vgame[v][x]=gameLine[x];
            }
            gameLine="";
            std::cin.clear();


        }
        gameStatus = gameCheck(Vgame, playerX, playerO);

        if(gameStatus=='!'){
            googleOutput << "Case #" << i << ": Draw\n";
        }
        if(gameStatus=='.'){
            googleOutput << "Case #" << i << ": Game has not completed\n";
        }
        if(gameStatus=='X'){
            googleOutput << "Case #" << i << ": X won\n";
        }
        if(gameStatus=='O'){
            googleOutput << "Case #" << i << ": O won\n";
        }
    }




    return 0;
}

char gameCheck( vector< vector<char> > &Vgame, int &playerX, int &playerO){
    char gameStatus = '!';


    for(int v=0; v<4;v++){
        for (int i = 0; i <4; ++i){

            if(Vgame[v][i]=='X'||Vgame[v][i]=='T'){
                playerX++;

                if(playerX==4)
                    return gameStatus='X';
            }

            if(Vgame[v][i]=='O'||Vgame[v][i]=='T'){
                playerO++;

                if(playerO==4)
                    return gameStatus='O';
            }
        }
        playerX=0;
        playerO=0;
    }

    for(int v=0; v<4;v++){
        for (int i = 0; i <4; ++i){

            if(Vgame[i][v]=='X'||Vgame[i][v]=='T'){
                playerX++;

                if(playerX==4)
                    return gameStatus='X';
            }

            if(Vgame[i][v]=='O'||Vgame[i][v]=='T'){
                playerO++;

                if(playerO==4)
                    return gameStatus='O';
            }
        }
        playerX=0;
        playerO=0;
    }


    if( ((Vgame[0][0]==('X')||(Vgame[0][0]==('T')))) && ((Vgame[1][1]==('X')||(Vgame[1][1]==('T')))) && ((Vgame[2][2]==('X')||(Vgame[2][2]==('T')))) && ((Vgame[3][3]==('X')||(Vgame[3][3]==('T')))) ){
        return gameStatus='X';
    }

    if(((Vgame[0][0]==('O')||(Vgame[0][0]==('T'))))&&((Vgame[1][1]==('O')||(Vgame[1][1]==('T'))))&&((Vgame[2][2]==('O')||(Vgame[2][2]==('T'))))&&((Vgame[3][3]==('O')||(Vgame[3][3]==('T')))) ){
        return gameStatus='O';
    }

    if(((Vgame[0][3]==('X')||(Vgame[0][3]==('T'))))&&((Vgame[1][2]==('X')||(Vgame[1][2]==('T'))))&&((Vgame[2][1]==('X')||(Vgame[2][1]==('T'))))&&((Vgame[3][0]==('X')||(Vgame[3][0]==('T')))) ){
        return gameStatus='X';
    }

    if(((Vgame[0][3]==('O')||(Vgame[0][3]==('T'))))&&((Vgame[1][2]==('O')||(Vgame[1][2]==('T'))))&&((Vgame[2][1]==('O')||(Vgame[2][1]==('T'))))&&((Vgame[3][0]==('O')||(Vgame[3][0]==('T')))) ){
        return gameStatus='O';
    }


    for(int v=0; v<4;v++){
        for (int i = 0; i < 4; ++i){
            if(Vgame[v][i]=='.'){
                gameStatus='.';
            }
        }
    }


    return gameStatus;
}