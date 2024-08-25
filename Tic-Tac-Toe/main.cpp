#include<bits/stdc++.h>

using namespace std;

class Player{
public:
    string name;
    char point;
    Player(string n, char c){
        name= n;
        point=c;
    }
};

class Board{
public:
    int size;
    vector<vector<char>>board;

    Board(int n){
        size=n;
        board= vector<vector<char>>(size, vector<char>(size, ' '));
    }
    void printBoard(){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout<<board[i][j]<<" ";
                if (j < size - 1) cout << " | ";
            }
            cout<<"\n";
            if (i < size - 1) cout << "--+---+--" << endl;
        }
    }
    bool isFull(){
       for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(board[i][j] == ' ') return false;
        }
       }
       return true;
   }
   bool makeMove(int row, int col, char ch){
       if(row >=0 and row< size and col>=0 and col< size and board[row][col] == ' '){
            board[row][col]=ch;
            return true;
       }
       return false;
   }
   bool won(char ch, int row, int col){
        bool rowMatch = true, columnMatch = true, diagonalMatch = true, antiDiagonalMatch = true;

        //need to check in row
        for(int i=0;i<size;i++) {

            if(board[row][i] == ' ' || board[row][i] != ch) {
                rowMatch = false;
            }
        }

        //need to check in column
        for(int i=0;i<size;i++) {

            if(board[i][col] == ' ' || board[i][col] != ch) {
                columnMatch = false;
            }
        }

        //need to check diagonals
        for(int i=0, j=0; i<size;i++,j++) {
            if (board[i][j] == ' ' || board[i][j] != ch) {
                diagonalMatch = false;
            }
        }

        //need to check anti-diagonals
        for(int i=0, j=size-1; i<size;i++,j--) {
            if (board[i][j] ==  ' ' || board[i][j] != ch) {
                antiDiagonalMatch = false;
            }
        }

        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;

   }
};
class Game : public Board, Player{
   public:
   deque<Player>dq;
   Game() : Board(size), Player(name, point), dq(){

   }

   void initalizeGame(){
       cout<<"Welcome to Tic-Tac-Toe"<<endl;
       cout<<"Enter the size of the board : ";
       int n; cin>>n;
       Board b(n);

       cout<<"Player 1 name: ";
       string name1; cin>>name1;
       cout<<"Choose the piece out of 'X' and 'O' : ";
       char piece1; cin>>piece1;
       Player p1= Player(name1, piece1);

       cout<<"Player 2 name :";
       string name2; cin>>name2;
       char piece2;
       if(piece1=='X') piece2='O';
       else piece2='X';
       Player p2= Player(name2, piece2);
       dq.push_back(p1);
       dq.push_back(p2);
       startGame(b);
   }

   void startGame(Board b){
       cout<<"Starting the Game"<<endl;
       int row=0, col=0;
       while(true){
        b.printBoard();
        Player currentPlayer= dq.front();
        dq.pop_front();
        cout<<currentPlayer.name<<"'s turn , enter row and column you want your piece to be placed: "<<endl;
        cout<<"Enter row : ";
        cin>>row;
        cout<<"\n";
        cout<<"Enter column: ";
        cin>>col;

        if(b.makeMove(row, col, currentPlayer.point)){
            if(b.isFull()){
                cout<<"It's a draw!, Play next game."<<"\n";
                printBoard();
                break;
            }else{
                if(b.won(currentPlayer.point, row, col)){
                    cout<<"Congratulations, " <<currentPlayer.name<<" You won!"<<"\n";
                    printBoard();
                    break;
                }
            }
            dq.push_back(currentPlayer);
        }else{
            cout<<"Invalid Move, try again!"<<"\n";
            dq.push_front(currentPlayer);
        }
   }
}


};

int main(){
    cout<<"Hello World"<<endl;
    Game g;
    g.initalizeGame();
    return 0;
}
