#include <iostream>
#include <string>
#include <vector>
#include <utility>

enum class PieceType { PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING, EMPTY };
enum class Colour { BLACK, WHITE };

class ChessGame {
private:
    ChessBoard chessboard;
    bool validNewPieceLocation(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        for (int i = 0; i < chessboard.getPiece(pieceLocation).getValidMoves().size(); i++)
        {

            if (chessboard.getPiece(pieceLocation).getColour() != chessboard.getPiece(newPieceLocation).getColour() && newPieceLocation == chessboard.getPiece(pieceLocation).getValidMoves()[i]) {
                //if the movement is from one colour to another, and that chess piece location is in that type's valid moves, then return true
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    bool isMoveCheck(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};
    bool isMoveCheckMate(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};

public:
    void pieceMove(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        if (validNewPieceLocation(pieceLocation, newPieceLocation) && chessboard.isTherePieceHere(pieceLocation)) {
            PieceType movingPieceType = chessboard.getPiece(pieceLocation).getPieceType();
            chessboard.setPiece(pieceLocation, newPieceLocation);
            /*switch (movingPieceType) {
            case PieceType::PAWN:
                //is this valid? return true if yes, false if no
            case PieceType::BISHOP:
                //
            case PieceType::KNIGHT:


            }*/
        }
    };
   
    static void newGame();
    void makeMove(pair<int, int> pieceLocation, pair<int, int> newPieceLocation);
};

class ChessPiece {
private:
    PieceType piecetype;
    Colour colour;
    std::pair<int, int> pieceLocation;
    std::vector<std::pair<int, int>> validMoves;


public:
    
    ChessPiece(PieceType type){
        piecetype = type;
        switch (type) {
        case PieceType::KNIGHT:
            //add vertical Ls
            //invalid moves are also included
            std::pair<int, int> upleftL;
            upleftL.first = pieceLocation.first - 1;
            upleftL.second = pieceLocation.second + 2;
            validMoves.push_back(upleftL);
            std::pair<int, int> uprightL;
            uprightL.first = pieceLocation.first + 1;
            uprightL.second = pieceLocation.second + 2;
            validMoves.push_back(uprightL);
            std::pair<int, int> downleftL;
            downleftL.first = pieceLocation.first - 1;
            downleftL.second = pieceLocation.first - 2;
            validMoves.push_back(downleftL);
            std::pair<int, int> downrightL;
            downrightL.first = pieceLocation.first - 1;
            downrightL.second = pieceLocation.first - 2;
            validMoves.push_back(downrightL);
            
            
        }
    }
    std::vector<std::pair<int, int>> getValidMoves() {
        return validMoves;
    }
    PieceType getPieceType() {
        return piecetype;
    }
    void setPieceType(PieceType input) {
        piecetype = input;
    }
    Colour getColour() {
        return colour;
    }
    void setColour(Colour input) {
        colour = input;
    }
    std::pair<int, int> getPieceLocation(){
        return pieceLocation;
    }
    void setPieceLocation(std::pair<int, int> input) {
        pieceLocation = input;
    }
};

class ChessBoard {
private:
    std::vector<std::vector<ChessPiece>> board;
    std::vector<std::vector<ChessPiece>>::iterator x;
    std::vector<ChessPiece>::iterator y;

public:
    ChessBoard() {
        board[8][8];
        ChessPiece whiteRook1 = ChessPiece(PieceType::ROOK);
    }
    void showBoard();
    void resetBoard();
    bool isTherePieceHere(std::pair<int, int> location) {
        switch (board[location.first][location.second].getPieceType()) {
        
        default:
            return true;
        }
    }
    ChessPiece getPiece(std::pair<int, int> chessPieceLocation) {
        return board[chessPieceLocation.first][chessPieceLocation.second];
    }
    void setPiece(std::pair<int, int> chessPieceLocation, std::pair<int, int> newLocation) {
        if (isTherePieceHere(chessPieceLocation) != 1) {
            board[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
        }
        else {
            if (board[chessPieceLocation.first][chessPieceLocation.second].getColour() == board[newLocation.first][newLocation.second].getColour()) {
                std::cout << "not possible"; //.. is trying to take their own team
            }
            else {
                board[newLocation.first][newLocation.second] = ChessPiece(PieceType::EMPTY);
                board[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
            }
        }
    }
};


int main()
{
    ChessGame::newGame();

}