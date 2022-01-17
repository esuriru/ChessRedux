#include <iostream>
#include <string>
#include <vector>
#include <utility>

enum class PieceType { PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING, EMPTY };
enum class Colour { BLACK, WHITE };

class ChessPiece {
private:
    PieceType piecetype;
    Colour colour;
    std::pair<int, int> pieceLocation;


public:
    ChessPiece(){
        piecetype = PieceType::EMPTY;
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
        return board[chessPieceLocation.first][chessPieceLocation.second].getPieceType();
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
                board[newLocation.first][newLocation.second] = ChessPiece();
                board[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
            }
        }
    }
};

class ChessGame {
private:
    ChessBoard chessboard;
    bool isMoveLegal(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        if (validPieceLocation() && validNewPieceLocation() && pieceLocationchessboard.isTherePieceHere(pieceLocation)) {
            ChessPiece movingPieceType = chessboard.getPiece(pieceLocation).getPieceType();
            switch (movingPieceType) {
            case PieceType::PAWN:
                //is this valid? return true if yes, false if no
            case PieceType::BISHOP:
                ...
                    ...
            }
        }
    };
    bool isMoveCheck(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};
    bool isMoveCheckMate(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};

public:
    void newGame();
    void makeMove(pair<int, int> pieceLocation, pair<int, int> newPieceLocation);
};

int main()
{

}