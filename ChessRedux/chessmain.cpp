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
    char pieceRepresentation;
    std::pair<int, int> pieceLocation;
    std::vector<std::pair<int, int>> validMoves;
    bool firstMove;

public:
    
    ChessPiece(PieceType type){
        firstMove = true;
        piecetype = type;
        switch (type) {
            //invalid moves are also included
        case PieceType::KNIGHT:
        {
            pieceRepresentation = 'N';
            //add vertical Ls        
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
            downleftL.second = pieceLocation.second - 2;
            validMoves.push_back(downleftL);
            std::pair<int, int> downrightL;
            downrightL.first = pieceLocation.first - 1;
            downrightL.second = pieceLocation.second - 2;
            validMoves.push_back(downrightL);
        }
        case PieceType::BISHOP:
        {
            pieceRepresentation = 'B';
            std::pair<int, int> rightdiagonalMove = pieceLocation;
            std::pair<int, int> leftdiagonalMove = pieceLocation;
            for (int i = 0; rightdiagonalMove.second == 0; i++)
            {
                rightdiagonalMove.first = pieceLocation.first + i;
                rightdiagonalMove.second = pieceLocation.second - i;
                validMoves.push_back(rightdiagonalMove);
            }
            for (int i = 0; rightdiagonalMove.second == 7; i++)
            {
                rightdiagonalMove.first = pieceLocation.first + i;
                rightdiagonalMove.second = pieceLocation.second + i;
                validMoves.push_back(rightdiagonalMove);
            }
            for (int i = 0; leftdiagonalMove.second == 0; i++)
            {
                leftdiagonalMove.first = pieceLocation.first - i;
                leftdiagonalMove.second = pieceLocation.second - i;
                validMoves.push_back(leftdiagonalMove);
            }
            for (int i = 0; leftdiagonalMove.second == 7; i++)
            {
                leftdiagonalMove.first = pieceLocation.first - i;
                leftdiagonalMove.second = pieceLocation.second + i;
                validMoves.push_back(leftdiagonalMove);
            }
        }
        case PieceType::QUEEN:
        {
            pieceRepresentation = 'Q';
            std::pair<int, int> horizontalMove = pieceLocation;
            std::pair<int, int> verticalMove = pieceLocation;
            std::pair<int, int> rightdiagonalMove = pieceLocation;
            std::pair<int, int> leftdiagonalMove = pieceLocation;

            for (int i = 0; horizontalMove.first == 7; i++)
            {
                horizontalMove.first = pieceLocation.first + i;
                validMoves.push_back(horizontalMove);
            }
            for (int i = 0; horizontalMove.first == 0; i++)
            {
                horizontalMove.first = pieceLocation.first - i;
                validMoves.push_back(horizontalMove);
            }
            for (int i = 0; verticalMove.first == 7; i++)
            {
                verticalMove.second = pieceLocation.second + i;
                validMoves.push_back(verticalMove);
            }
            for (int i = 0; verticalMove.first == 0; i++)
            {
                verticalMove.second = pieceLocation.second - i;
                validMoves.push_back(verticalMove);
            }
            for (int i = 0; leftdiagonalMove.second == 0; i++)
            {
                leftdiagonalMove.first = pieceLocation.first - i;
                leftdiagonalMove.second = pieceLocation.second - i;
                validMoves.push_back(leftdiagonalMove);
            }
            for (int i = 0; leftdiagonalMove.second == 7; i++)
            {
                leftdiagonalMove.first = pieceLocation.first - i;
                leftdiagonalMove.second = pieceLocation.second + i;
                validMoves.push_back(leftdiagonalMove);
            }
        }
        case PieceType::KING:
        {
            pieceRepresentation = 'K';
            validMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 1));
            validMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second - 1));
            validMoves.push_back(std::make_pair(pieceLocation.first + 1, pieceLocation.second));
            validMoves.push_back(std::make_pair(pieceLocation.first - 1, pieceLocation.second));
            validMoves.push_back(std::make_pair(pieceLocation.first + 1, pieceLocation.second + 1));
            validMoves.push_back(std::make_pair(pieceLocation.first - 1, pieceLocation.second + 1));
            validMoves.push_back(std::make_pair(pieceLocation.first - 1, pieceLocation.second - 1));
            validMoves.push_back(std::make_pair(pieceLocation.first + 1, pieceLocation.second - 1));
        }
        case PieceType::PAWN:
        {
            pieceRepresentation = 'P';
            if (firstMove) {
                validMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 1));
                validMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 2));
            }
            else {
                validMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 1));
            }
        }
        case PieceType::ROOK:
        {
            pieceRepresentation = 'R';
            std::pair<int, int> horizontalMove = pieceLocation;
            std::pair<int, int> verticalMove = pieceLocation;
            for (int i = 0; horizontalMove.first == 7; i++)
            {
                horizontalMove.first = pieceLocation.first + i;
                validMoves.push_back(horizontalMove);
            }
            for (int i = 0; horizontalMove.first == 0; i++)
            {
                horizontalMove.first = pieceLocation.first - i;
                validMoves.push_back(horizontalMove);
            }
            for (int i = 0; verticalMove.first == 7; i++)
            {
                verticalMove.second = pieceLocation.second + i;
                validMoves.push_back(verticalMove);
            }
            for (int i = 0; verticalMove.first == 0; i++)
            {
                verticalMove.second = pieceLocation.second - i;
                validMoves.push_back(verticalMove);
            }
        }

        case PieceType::EMPTY:
        {
            validMoves.clear();
            //it's empty lol
        }
        }
        //cleanup
        for (int i = 0; i < validMoves.size(); i++)
        {
            if (validMoves[i].first < 0 || validMoves[i].first > 7 || validMoves[i].second < 0 || validMoves[i].second > 7) {
                validMoves.erase(validMoves.begin() + i);
            }
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
    char getPieceRepresentation() {
        return pieceRepresentation;
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
        whiteRook1.setPieceLocation(std::make_pair(0, 0));
        board[whiteRook1.getPieceLocation().first].push_back(whiteRook1);
    }
    void showBoard() {
        //create the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++)
            {
                std::cout << board[i][j].getPieceRepresentation();
            }            
        }
    }
    std::vector<std::vector<ChessPiece>> getBoard() {
        return board;
    }
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

    static void newGame() {
        std::cout << "hi!" << std::endl;
        /*for (int i = 0; i < chessboard.getPiece(std::make_pair(0, 0)).getValidMoves().size(); i++)
        {
            std::cout << "\n" << chessboard.getBoard()[0][0].getValidMoves()[i].first << "," << chessboard.getBoard()[0][0].getValidMoves()[i].second;
        }*/
    }
};

int main()
{
    ChessGame::newGame();

}