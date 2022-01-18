#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <array>


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
    ChessPiece() {
        piecetype = PieceType::EMPTY;
        colour = Colour::BLACK;
        pieceRepresentation = ' ';
        pieceLocation = std::make_pair(NULL, NULL);
        firstMove = true;

    }
    ChessPiece(PieceType type, Colour colourinput) {
        firstMove = true;
        colour = colourinput;
        piecetype = type;
        switch (piecetype) {
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
            break;
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
            break;
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
            break;
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
            break;
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
            break;
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
            for (int i = 0; verticalMove.second == 7; i++)
            {
                verticalMove.second = pieceLocation.second + i;
                validMoves.push_back(verticalMove);
            }
            for (int i = 0; verticalMove.second == 0; i++)
            {
                verticalMove.second = pieceLocation.second - i;
                validMoves.push_back(verticalMove);
            }
            break;
        }

        case PieceType::EMPTY:
        {
            pieceRepresentation = ' ';
            validMoves.clear();
            //it's empty lol
            break;
        }
        default:
            std::cout << "ERROR";
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
    std::pair<int, int> getPieceLocation() {
        return pieceLocation;
    }
    void setPieceLocation(std::pair<int, int> input) {
        pieceLocation = input;
    }
    char getPieceRepresentation() {
        return pieceRepresentation;
    }
    void setPieceRepresentation(char a) {
        pieceRepresentation = a;
    }
};


class ChessBoard {
private:
    //std::vector<std::vector<ChessPiece>> board;
    ChessPiece arrayboard[8][8];


public:
    ChessBoard() {
        //the creation of pieces
        //empty spaces
        ChessPiece emptySpace1 = ChessPiece(PieceType::EMPTY, Colour::BLACK);
        emptySpace1.setPieceLocation(std::make_pair(0, 2));
        setPiece(emptySpace1);

        //white team
        ChessPiece whiteRook1 = ChessPiece(PieceType::ROOK, Colour::WHITE);
        whiteRook1.setPieceLocation(std::make_pair(0, 0));
        setPiece(whiteRook1);
        ChessPiece whiteRook2 = ChessPiece(PieceType::ROOK, Colour::WHITE);
        whiteRook2.setPieceLocation(std::make_pair(7, 0));
        setPiece(whiteRook2);
        ChessPiece whiteKnight1 = ChessPiece(PieceType::KNIGHT, Colour::WHITE);
        whiteKnight1.setPieceLocation(std::make_pair(1, 0));
        setPiece(whiteKnight1);
        ChessPiece whiteKnight2 = ChessPiece(PieceType::KNIGHT, Colour::WHITE);
        whiteKnight2.setPieceLocation(std::make_pair(6, 0));
        setPiece(whiteKnight2);
        ChessPiece whiteBishop1 = ChessPiece(PieceType::BISHOP, Colour::WHITE);
        whiteBishop1.setPieceLocation(std::make_pair(2, 0));
        setPiece(whiteBishop1);
        ChessPiece whiteBishop2 = ChessPiece(PieceType::BISHOP, Colour::WHITE);
        whiteBishop2.setPieceLocation(std::make_pair(5, 0));
        setPiece(whiteBishop2);
        ChessPiece whiteKing1 = ChessPiece(PieceType::KING, Colour::WHITE);
        whiteKing1.setPieceLocation(std::make_pair(4, 0));
        setPiece(whiteKing1);
        ChessPiece whiteQueen1 = ChessPiece(PieceType::QUEEN, Colour::WHITE);
        whiteQueen1.setPieceLocation(std::make_pair(3, 0));
        setPiece(whiteQueen1);
        ChessPiece whitePawn1 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn1.setPieceLocation(std::make_pair(0, 1));
        setPiece(whitePawn1);
        ChessPiece whitePawn2 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn2.setPieceLocation(std::make_pair(1, 1));
        setPiece(whitePawn2);
        ChessPiece whitePawn3 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn3.setPieceLocation(std::make_pair(2, 1));
        setPiece(whitePawn3);
        ChessPiece whitePawn4 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn4.setPieceLocation(std::make_pair(3, 1));
        setPiece(whitePawn4);
        ChessPiece whitePawn5 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn5.setPieceLocation(std::make_pair(4, 1));
        setPiece(whitePawn5);
        ChessPiece whitePawn6 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn6.setPieceLocation(std::make_pair(5, 1));
        setPiece(whitePawn6);
        ChessPiece whitePawn7 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn7.setPieceLocation(std::make_pair(6, 1));
        setPiece(whitePawn7);
        ChessPiece whitePawn8 = ChessPiece(PieceType::PAWN, Colour::WHITE);
        whitePawn8.setPieceLocation(std::make_pair(7, 1));
        setPiece(whitePawn8);
        //black pieces
        ChessPiece blackRook1 = ChessPiece(PieceType::ROOK, Colour::BLACK);
        blackRook1.setPieceLocation(std::make_pair(0, 0));
        setPiece(blackRook1);
        ChessPiece blackRook2 = ChessPiece(PieceType::ROOK, Colour::BLACK);
        blackRook2.setPieceLocation(std::make_pair(7, 0));
        setPiece(blackRook2);
        ChessPiece blackKnight1 = ChessPiece(PieceType::KNIGHT, Colour::BLACK);
        blackKnight1.setPieceLocation(std::make_pair(1, 0));
        setPiece(blackKnight1);
        ChessPiece blackKnight2 = ChessPiece(PieceType::KNIGHT, Colour::BLACK);
        blackKnight2.setPieceLocation(std::make_pair(6, 0));
        setPiece(blackKnight2);
        ChessPiece blackBishop1 = ChessPiece(PieceType::BISHOP, Colour::BLACK);
        blackBishop1.setPieceLocation(std::make_pair(2, 0));
        setPiece(blackBishop1);
        ChessPiece blackBishop2 = ChessPiece(PieceType::BISHOP, Colour::BLACK);
        blackBishop2.setPieceLocation(std::make_pair(5, 0));
        setPiece(blackBishop2);
        ChessPiece blackKing1 = ChessPiece(PieceType::KING, Colour::BLACK);
        blackKing1.setPieceLocation(std::make_pair(4, 0));
        setPiece(blackKing1);
        ChessPiece blackQueen1 = ChessPiece(PieceType::QUEEN, Colour::BLACK);
        blackQueen1.setPieceLocation(std::make_pair(3, 0));
        setPiece(blackQueen1);
        ChessPiece blackPawn1 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn1.setPieceLocation(std::make_pair(0, 1));
        setPiece(blackPawn1);
        ChessPiece blackPawn2 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn2.setPieceLocation(std::make_pair(1, 1));
        setPiece(blackPawn2);
        ChessPiece blackPawn3 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn3.setPieceLocation(std::make_pair(2, 1));
        setPiece(blackPawn3);
        ChessPiece blackPawn4 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn4.setPieceLocation(std::make_pair(3, 1));
        setPiece(blackPawn4);
        ChessPiece blackPawn5 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn5.setPieceLocation(std::make_pair(4, 1));
        setPiece(blackPawn5);
        ChessPiece blackPawn6 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn6.setPieceLocation(std::make_pair(5, 1));
        setPiece(blackPawn6);
        ChessPiece blackPawn7 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn7.setPieceLocation(std::make_pair(6, 1));
        setPiece(blackPawn7);
        ChessPiece blackPawn8 = ChessPiece(PieceType::PAWN, Colour::BLACK);
        blackPawn8.setPieceLocation(std::make_pair(7, 1));
        setPiece(blackPawn8);
        
    }
    void showBoard() {
        //create the board

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++)
            {
                std::cout << arrayboard[i][j].getPieceRepresentation();
            }
        }
    }

    void resetBoard();
    bool isTherePieceHere(std::pair<int, int> location) {
        switch (arrayboard[location.first][location.second].getPieceType()) {

        default:
            return true;
        }
    }
    ChessPiece getPiece(std::pair<int, int> chessPieceLocation) {
        return arrayboard[chessPieceLocation.first][chessPieceLocation.second];
    }
    void setPiece(ChessPiece input) {
        arrayboard[input.getPieceLocation().first][input.getPieceLocation().second] = input;
    }
    void movePiece(std::pair<int, int> chessPieceLocation, std::pair<int, int> newLocation) {
        if (isTherePieceHere(chessPieceLocation) != 1) {
            arrayboard[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
        }
        else {
            if (arrayboard[chessPieceLocation.first][chessPieceLocation.second].getColour() == arrayboard[newLocation.first][newLocation.second].getColour()) {
                std::cout << "not possible"; //.. is trying to take their own team
            }
            else {
                arrayboard[newLocation.first][newLocation.second] = ChessPiece(PieceType::EMPTY, Colour::BLACK);
                arrayboard[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
            }
        }
    }
    auto getchesspiecearray(){
        return arrayboard;
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
            chessboard.movePiece(pieceLocation, newPieceLocation);
            /*switch (movingPieceType) {
            case PieceType::PAWN:
                //is this valid? return true if yes, false if no
            case PieceType::BISHOP:
                //
            case PieceType::KNIGHT:


            }*/
        }

    };

    ChessBoard getchessboard() {
        return chessboard;
    }
    void newGame() {
        std::cout << "hi!" << std::endl;
        /*
        for (int i = 0; i < chessboard.getPiece(std::make_pair(0, 0)).getValidMoves().size(); i++)
        {
            std::cout << "\n" << chessboard.getBoard()[0][0].getValidMoves()[i].first << "," << chessboard.getBoard()[0][0].getValidMoves()[i].second;
        }
        */
        chessboard.showBoard();
    }
};

int main()
{
    ChessGame game;
    game.newGame();


}