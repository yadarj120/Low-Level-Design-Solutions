// author -> yadarj120

#include<bits/stdc++.h>
using namespace std;

class Game {
private:
    int n; // dimension of board
    vector<int> rsum; // row sum
    vector<int> csum; // column sum
    int dsum; // diagonal sum
    int adsum; // anti-diagonal sum

public:

    // initialzing board
    Game(int _n){
        n=_n;
        rsum.resize(n, 0);
        csum.resize(n, 0);
        dsum=0; adsum=0;
    }


    // move function -> to change the board state on a move
    // parameters -> int row, int col, int player -> player id
    // return value -> id of player if any player won else return 0. If the move is invalid return -1
    // player1 id -> 1, player2 id -> -1
    int move(int r, int c, int playerid){

        // invalid move
        if(min(r, c)<0 || max(r, c) >=n) return -1;


        // changing the state of board
        rsum[r]+=playerid;
        csum[c]+=playerid;
        if(r==c) dsum += playerid;
        if(r+c == (n-1)) adsum += playerid;


        // checking to see if any player won
        if(abs(rsum[r])==n || abs(csum[c])==n || abs(dsum)==n || abs(adsum)==n) return playerid;

        // if nobody won, then return 0
        return 0;
    }
};


// controller
int main(){
    // creating the game
    cout << "Enter the dimensions of the board: ";
    int n; cin >> n;
    Game game(n);

    // start the game loop
    bool finished=false;
    bool chanceOfPlayer1 = true;
    int winnerid;
    while(!finished){
        int retval; // return value of making a move
        if(chanceOfPlayer1){
            cout << "[PLAYER 1] Please enter your move in this format <row> <col>: ";
            int r, c; cin >> r >> c;
            retval = game.move(r, c, 1);  
        }
        else{
            cout << "[PLAYER 2] Please enter your move in this format <row> <col>: ";
            int r, c; cin >> r >> c;
            retval = game.move(r, c, -1);
        }


        if(retval!=0){
            finished=true;
            winnerid = (chanceOfPlayer1?1:2);
        }
        chanceOfPlayer1 = 1 - chanceOfPlayer1;
    }

    cout << "Player " << winnerid << " won the game";
    cout << "[GAME FINISHED]";
}
