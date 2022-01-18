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
    ChessPiece(std::pair<int, int> inputposition) {
        piecetype = PieceType::EMPTY;
        colour = Colour::BLACK;
        pieceRepresentation = ' ';
        pieceLocation = inputposition;
        firstMove = true;

    }
    ChessPiece(PieceType type, Colour colourinput, std::pair<int, int> inputposition) {
        firstMove = true;
        colour = colourinput;
        piecetype = type;
        pieceLocation = inputposition;
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
            //add horizontal Ls
            validMoves.push_back(std::make_pair(pieceLocation.first + 2, pieceLocation.second + 1));
            validMoves.push_back(std::make_pair(pieceLocation.first + 2, pieceLocation.second - 1));
            validMoves.push_back(std::make_pair(pieceLocation.first - 2, pieceLocation.second + 1));
            validMoves.push_back(std::make_pair(pieceLocation.first - 2, pieceLocation.second - 1));
            
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

        //white team
        ChessPiece whiteRook1 = ChessPiece(PieceType::ROOK, Colour::WHITE, std::make_pair(0, 0));
        setPiece(whiteRook1);
        ChessPiece whiteRook2 = ChessPiece(PieceType::ROOK, Colour::WHITE, std::make_pair(7, 0));
        setPiece(whiteRook2);
        ChessPiece whiteKnight1 = ChessPiece(PieceType::KNIGHT, Colour::WHITE, std::make_pair(1, 0));
        setPiece(whiteKnight1);
        ChessPiece whiteKnight2 = ChessPiece(PieceType::KNIGHT, Colour::WHITE, std::make_pair(6, 0));
        setPiece(whiteKnight2);
        ChessPiece whiteBishop1 = ChessPiece(PieceType::BISHOP, Colour::WHITE, std::make_pair(2, 0));
        setPiece(whiteBishop1);
        ChessPiece whiteBishop2 = ChessPiece(PieceType::BISHOP, Colour::WHITE, std::make_pair(5, 0));
        setPiece(whiteBishop2);
        ChessPiece whiteKing1 = ChessPiece(PieceType::KING, Colour::WHITE, std::make_pair(4, 0));
        setPiece(whiteKing1);
        ChessPiece whiteQueen1 = ChessPiece(PieceType::QUEEN, Colour::WHITE, std::make_pair(3, 0));
        setPiece(whiteQueen1);
        ChessPiece whitePawn1 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(0, 1));
        setPiece(whitePawn1);
        ChessPiece whitePawn2 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(1, 1));
        setPiece(whitePawn2);
        ChessPiece whitePawn3 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(2, 1));
        setPiece(whitePawn3);
        ChessPiece whitePawn4 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(3, 1));
        setPiece(whitePawn4);
        ChessPiece whitePawn5 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(4, 1));
        setPiece(whitePawn5);
        ChessPiece whitePawn6 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(5, 1));
        setPiece(whitePawn6);
        ChessPiece whitePawn7 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(6, 1));
        setPiece(whitePawn7);
        ChessPiece whitePawn8 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(7, 1));
        setPiece(whitePawn8);
        //black pieces
        ChessPiece blackRook1 = ChessPiece(PieceType::ROOK, Colour::BLACK, std::make_pair(0, 7));
        setPiece(blackRook1);
        ChessPiece blackRook2 = ChessPiece(PieceType::ROOK, Colour::BLACK, std::make_pair(7, 7));
        setPiece(blackRook2);
        ChessPiece blackKnight1 = ChessPiece(PieceType::KNIGHT, Colour::BLACK, std::make_pair(1, 7));
        setPiece(blackKnight1);
        ChessPiece blackKnight2 = ChessPiece(PieceType::KNIGHT, Colour::BLACK, std::make_pair(6, 7));
        setPiece(blackKnight2);
        ChessPiece blackBishop1 = ChessPiece(PieceType::BISHOP, Colour::BLACK, std::make_pair(2, 7));
        setPiece(blackBishop1);
        ChessPiece blackBishop2 = ChessPiece(PieceType::BISHOP, Colour::BLACK, std::make_pair(5, 7));
        setPiece(blackBishop2);
        ChessPiece blackKing1 = ChessPiece(PieceType::KING, Colour::BLACK, std::make_pair(4, 7));
        setPiece(blackKing1);
        ChessPiece blackQueen1 = ChessPiece(PieceType::QUEEN, Colour::BLACK, std::make_pair(3, 7));
        setPiece(blackQueen1);
        ChessPiece blackPawn1 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(0, 6));
        setPiece(blackPawn1);
        ChessPiece blackPawn2 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(1, 6));
        setPiece(blackPawn2);
        ChessPiece blackPawn3 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(2, 6));
        setPiece(blackPawn3);
        ChessPiece blackPawn4 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(3, 6));
        setPiece(blackPawn4);
        ChessPiece blackPawn5 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(4, 6));
        setPiece(blackPawn5);
        ChessPiece blackPawn6 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(5, 6));
        setPiece(blackPawn6);
        ChessPiece blackPawn7 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(6, 6));
        setPiece(blackPawn7);
        ChessPiece blackPawn8 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(7, 6));
        setPiece(blackPawn8);
        
    }
    void showBoard() {
        //create the board
        std::cout << "  " << "a" << "    " << "b" << "    " << "c" << "    " << "d" << "    " << "e" << "    " << "f" << "    " << "g" << "    " << "h" << std::endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
            {
                //std::cout << "  " << arrayboard[j][i].getPieceRepresentation() << "  ";
                std::cout << "  " << arrayboard[j][i].getPieceRepresentation() << "  ";
            }
            std::cout << "\n\n";
        }
    }

    void resetBoard() {
        system("cls");
    }
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
        if (isTherePieceHere(newLocation) != 1) {
            //take the piece
            arrayboard[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
            //to program
        }
        else {
            if (arrayboard[chessPieceLocation.first][chessPieceLocation.second].getColour() == arrayboard[newLocation.first][newLocation.second].getColour()) {
                std::cout << "not possible"; //.. is trying to take their own team
            }
            else {
                if (arrayboard[newLocation.first][newLocation.second].getPieceType() == PieceType::EMPTY) {
                    
                    auto storebeforechange = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                    arrayboard[chessPieceLocation.first][chessPieceLocation.second] = arrayboard[newLocation.first][newLocation.second];
                    arrayboard[newLocation.first][newLocation.second] = storebeforechange;

                    /*
                    arrayboard[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(newLocation);
                    arrayboard[newLocation.first][newLocation.second].setPieceLocation(storebeforechange.getPieceLocation());
                    */
                    arrayboard[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(storebeforechange.getPieceLocation());
                    arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);
                    

                    setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                    setPiece(arrayboard[newLocation.first][newLocation.second]);
                }
                else {
                    std::cout << "error";
                }

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

            if (newPieceLocation == chessboard.getPiece(pieceLocation).getValidMoves()[i]) {
                if (chessboard.getPiece(newPieceLocation).getPieceType() == PieceType::EMPTY) {
                    return true; //bruh, there's nothing there, go on.

                }
                else if (chessboard.getPiece(pieceLocation).getColour() != chessboard.getPiece(newPieceLocation).getColour()) {
                    return true; //taking another piece

                }
                else {
                    std::cout << "error has occured, piece is not able to be moved";
                    return false;
                    break;
                }

                //if the movement is from one colour to another, and that chess piece location is in that type's valid moves, then return true
            }
            else {
                continue;
            }
        }
        return false;
    }

    bool isMoveCheck(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};
    bool isMoveCheckMate(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};

public:
    void pieceMove(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        if (validNewPieceLocation(pieceLocation, newPieceLocation) && chessboard.isTherePieceHere(pieceLocation)) {
            PieceType movingPieceType = chessboard.getPiece(pieceLocation).getPieceType();
            chessboard.movePiece(pieceLocation, newPieceLocation);
            chessboard.resetBoard();
            chessboard.showBoard();
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
        

        /*
        for (int i = 0; i < chessboard.getPiece(std::make_pair(0, 0)).getValidMoves().size(); i++)
        {
            std::cout << "\n" << chessboard.getBoard()[0][0].getValidMoves()[i].first << "," << chessboard.getBoard()[0][0].getValidMoves()[i].second;
        }
        */
        chessboard.showBoard();
        
        std::string playerinput;
        std::getline(std::cin, playerinput);
        //example of move: a1->a2

        //pieceMove((std::make_pair(atoi(&playerinput[1])-8, chessNotationtranslatechar(playerinput[0]))), std::make_pair(8-atoi(&playerinput[5]), chessNotationtranslatechar(playerinput[4])));
        pieceMove((std::make_pair(chessNotationtranslatechar(playerinput[0]), atoi(&playerinput[1]) - 8)), std::make_pair(8-atoi(&playerinput[5]), chessNotationtranslatechar(playerinput[4])));
        //pieceMove(std::make_pair(chessNotationtranslatechar(playerinput[0]) - 1, atoi(&playerinput[1])), std::make_pair(chessNotationtranslatechar(playerinput[4]) - 1, atoi(&playerinput[5])));
        //by the way, pair input is basically like '1a' because rest of program is program with .first being x and .second being y
        //test knight by b1->c3
        //b1 = (1, 0) b -> 1 1 -> 0
        //c3 = (2, 2) c -> 2 3 -> 2
        //b8 = (1, 0)
        //c6 = (2, 2)
        std::cout << "break";
    }
    int chessNotationtranslatechar(char a) {
        return int(a) - 97;
    }
};

int main()
{
    ChessGame game;
    game.newGame();


}