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
            
            
            break;
        }
        case PieceType::BISHOP:
        {

            pieceRepresentation = 'B';
            
            break;
        }
        case PieceType::QUEEN:
        {
            pieceRepresentation = 'Q';
           
            break;
        }
        case PieceType::KING:
        {
            pieceRepresentation = 'K';
           
            break;
        }

        case PieceType::PAWN:
        {
            pieceRepresentation = 'P';
            
            break;
        }
        case PieceType::ROOK:
        {
            pieceRepresentation = 'R';
            
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
        /*for (int i = 0; i < validMoves.size(); i++)
        {
            if (validMoves[i].first < 0 || validMoves[i].first > 7 || validMoves[i].second < 0 || validMoves[i].second > 7) {
                validMoves.erase(validMoves.begin() + i);
            }
        }*/
    }
    std::vector<std::pair<int, int>> getValidMoves() {
        return validMoves;
    }
    void setValidMoves(std::vector<std::pair<int, int>> input) {
        validMoves.clear();
        for (int i = 0; i < input.size(); i++)
        {
            validMoves.push_back(input[i]);
        }
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
    void Moved() {
        firstMove = false;

    }
    bool getfirstMove() {
        return firstMove;
    }
};


class ChessBoard {
private:
    ChessPiece arrayboard[8][8];
    std::vector < std::pair<int, int>> newvalidMoves;
    


public:
    ChessBoard() {
        //the creation of pieces
        //empty spaces

        //white team
        ChessPiece blackRook1 = ChessPiece(PieceType::ROOK, Colour::BLACK, std::make_pair(0, 0));
        setPiece(blackRook1);
        reinstantiateValidMoves(blackRook1);
        ChessPiece blackRook2 = ChessPiece(PieceType::ROOK, Colour::BLACK, std::make_pair(7, 0));
        setPiece(blackRook2);
        reinstantiateValidMoves(blackRook2);
        ChessPiece blackKnight1 = ChessPiece(PieceType::KNIGHT, Colour::BLACK, std::make_pair(1, 0));
        setPiece(blackKnight1);
        reinstantiateValidMoves(blackKnight1);
        ChessPiece blackKnight2 = ChessPiece(PieceType::KNIGHT, Colour::BLACK, std::make_pair(6, 0));
        setPiece(blackKnight2);
        reinstantiateValidMoves(blackKnight2);
        ChessPiece blackBishop1 = ChessPiece(PieceType::BISHOP, Colour::BLACK, std::make_pair(2, 0));
        setPiece(blackBishop1);
        reinstantiateValidMoves(blackBishop1);
        ChessPiece blackBishop2 = ChessPiece(PieceType::BISHOP, Colour::BLACK, std::make_pair(5, 0));
        setPiece(blackBishop2);
        reinstantiateValidMoves(blackBishop2);
        ChessPiece blackKing1 = ChessPiece(PieceType::KING, Colour::BLACK, std::make_pair(4, 0));
        setPiece(blackKing1);
        reinstantiateValidMoves(blackKing1);
        ChessPiece blackQueen1 = ChessPiece(PieceType::QUEEN, Colour::BLACK, std::make_pair(3, 0));
        setPiece(blackQueen1);
        reinstantiateValidMoves(blackQueen1);
        ChessPiece blackPawn1 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(0, 1));
        setPiece(blackPawn1);
        reinstantiateValidMoves(blackPawn1);
        ChessPiece blackPawn2 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(1, 1));
        setPiece(blackPawn2);
        reinstantiateValidMoves(blackPawn2);
        ChessPiece blackPawn3 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(2, 1));
        setPiece(blackPawn3);
        reinstantiateValidMoves(blackPawn3);
        ChessPiece blackPawn4 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(3, 1));
        setPiece(blackPawn4);
        reinstantiateValidMoves(blackPawn4);
        ChessPiece blackPawn5 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(4, 1));
        setPiece(blackPawn5);
        reinstantiateValidMoves(blackPawn5);
        ChessPiece blackPawn6 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(5, 1));
        setPiece(blackPawn6);
        reinstantiateValidMoves(blackPawn6);
        ChessPiece blackPawn7 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(6, 1));
        setPiece(blackPawn7);
        reinstantiateValidMoves(blackPawn7);
        ChessPiece blackPawn8 = ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(7, 1));
        setPiece(blackPawn8);
        reinstantiateValidMoves(blackPawn8);
        //black pieces
        ChessPiece whiteRook1 = ChessPiece(PieceType::ROOK, Colour::WHITE, std::make_pair(0, 7));
        setPiece(whiteRook1);
        reinstantiateValidMoves(whiteRook1);
        ChessPiece whiteRook2 = ChessPiece(PieceType::ROOK, Colour::WHITE, std::make_pair(7, 7));
        setPiece(whiteRook2);
        reinstantiateValidMoves(whiteRook2);
        ChessPiece whiteKnight1 = ChessPiece(PieceType::KNIGHT, Colour::WHITE, std::make_pair(1, 7));
        setPiece(whiteKnight1);
        reinstantiateValidMoves(whiteKnight1);
        ChessPiece whiteKnight2 = ChessPiece(PieceType::KNIGHT, Colour::WHITE, std::make_pair(6, 7));
        setPiece(whiteKnight2);
        reinstantiateValidMoves(whiteKnight2);
        ChessPiece whiteBishop1 = ChessPiece(PieceType::BISHOP, Colour::WHITE, std::make_pair(2, 7));
        setPiece(whiteBishop1);
        reinstantiateValidMoves(whiteBishop1);
        ChessPiece whiteBishop2 = ChessPiece(PieceType::BISHOP, Colour::WHITE, std::make_pair(5, 7));
        setPiece(whiteBishop2);
        reinstantiateValidMoves(whiteBishop2);
        ChessPiece whiteKing1 = ChessPiece(PieceType::KING, Colour::WHITE, std::make_pair(4, 7));
        setPiece(whiteKing1);
        reinstantiateValidMoves(whiteKing1);
        ChessPiece whiteQueen1 = ChessPiece(PieceType::QUEEN, Colour::WHITE, std::make_pair(3, 7));
        setPiece(whiteQueen1);
        reinstantiateValidMoves(whiteQueen1);
        ChessPiece whitePawn1 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(0, 6));
        setPiece(whitePawn1);
        reinstantiateValidMoves(whitePawn1);
        ChessPiece whitePawn2 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(1, 6));
        setPiece(whitePawn2);
        reinstantiateValidMoves(whitePawn2);
        ChessPiece whitePawn3 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(2, 6));
        setPiece(whitePawn3);
        reinstantiateValidMoves(whitePawn3);
        ChessPiece whitePawn4 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(3, 6));
        setPiece(whitePawn4);
        reinstantiateValidMoves(whitePawn4);
        ChessPiece whitePawn5 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(4, 6));
        setPiece(whitePawn5);
        reinstantiateValidMoves(whitePawn5);
        ChessPiece whitePawn6 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(5, 6));
        setPiece(whitePawn6);
        reinstantiateValidMoves(whitePawn6);
        ChessPiece whitePawn7 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(6, 6));
        setPiece(whitePawn7);
        reinstantiateValidMoves(whitePawn7);
        ChessPiece whitePawn8 = ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(7, 6));
        setPiece(whitePawn8);
        reinstantiateValidMoves(whitePawn8);
    }
    void showBoard() {
        //create the board
        std::cout << "  " << "a" << "    " << "b" << "    " << "c" << "    " << "d" << "    " << "e" << "    " << "f" << "    " << "g" << "    " << "h" << std::endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
            {
                //std::cout << "  " << arrayboard[j][i].getPieceRepresentation() << "  ";
                if (arrayboard[j][i].getPieceLocation().first == 0 && arrayboard[j][i].getPieceType() != PieceType::EMPTY) {
                    std::cout << 8-i << " " << arrayboard[j][i].getPieceRepresentation() << "  ";
                }
                else
                {
                    if (j == 0) {
                        std::cout << 8-i << " " << arrayboard[j][i].getPieceRepresentation() << "  ";
                    }
                    else {
                        std::cout << "  " << arrayboard[j][i].getPieceRepresentation() << "  ";
                    }
                }
            }
            std::cout << "\n\n";
        }
    }

    void resetBoard() {
        system("cls");
    }
    bool isTherePieceHere(std::pair<int, int> location) {
        switch (arrayboard[location.first][location.second].getPieceType()) {
        case PieceType::EMPTY: {
            return false;
        }

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
    void reinstantiateValidMoves(ChessPiece input) {
        std::pair<int, int> pieceLocation = input.getPieceLocation();
        PieceType piecetype = input.getPieceType();
        char pieceRepresentation = input.getPieceRepresentation();
        Colour colour = input.getColour();
        newvalidMoves.clear();

        switch (piecetype) {
            //invalid moves are also included
        case PieceType::KNIGHT:
        {
            pieceRepresentation = 'N';
            //add vertical Ls        
            std::pair<int, int> upleftL;
            upleftL.first = pieceLocation.first - 1;
            upleftL.second = pieceLocation.second + 2;
            newvalidMoves.push_back(upleftL);
            std::pair<int, int> uprightL;
            uprightL.first = pieceLocation.first + 1;
            uprightL.second = pieceLocation.second + 2;
            newvalidMoves.push_back(uprightL);
            std::pair<int, int> downleftL;
            downleftL.first = pieceLocation.first + 1;
            downleftL.second = pieceLocation.second - 2;
            newvalidMoves.push_back(downleftL);
            std::pair<int, int> downrightL;
            downrightL.first = pieceLocation.first - 1;
            downrightL.second = pieceLocation.second - 2;
            newvalidMoves.push_back(downrightL);
            //add horizontal Ls
            newvalidMoves.push_back(std::make_pair(pieceLocation.first + 2, pieceLocation.second + 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first + 2, pieceLocation.second - 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first - 2, pieceLocation.second + 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first - 2, pieceLocation.second - 1));

            break;
        }
        case PieceType::BISHOP:
        {

            pieceRepresentation = 'B';
            std::pair<int, int> rightdiagonalMove = pieceLocation;
            std::pair<int, int> leftdiagonalMove = pieceLocation;
            int add = 0;
            do {
                //going up and right
                if (rightdiagonalMove.first == 7) {
                    break;
                }
                rightdiagonalMove.first = pieceLocation.first + add;
                rightdiagonalMove.second = pieceLocation.second - add;
                newvalidMoves.push_back(rightdiagonalMove);
                add++;

            } while (rightdiagonalMove.second != 0);
            //then
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going down and left
                if (rightdiagonalMove.first == 0) {
                    break;
                }
                rightdiagonalMove.first = pieceLocation.first - add;
                rightdiagonalMove.second = pieceLocation.second + add;
                newvalidMoves.push_back(rightdiagonalMove);
                add++;
            } while (rightdiagonalMove.second != 7);
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going up and left
                if (leftdiagonalMove.first == 0) {

                    break;
                }
                leftdiagonalMove.first = pieceLocation.first - add;
                leftdiagonalMove.second = pieceLocation.second - add;
                newvalidMoves.push_back(leftdiagonalMove);
                add++;

            } while (leftdiagonalMove.second != 0);
            //then
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going down and right
                if (leftdiagonalMove.second == 7) {

                    break;
                }
                leftdiagonalMove.first = pieceLocation.first - add;
                leftdiagonalMove.second = pieceLocation.second + add;
                newvalidMoves.push_back(leftdiagonalMove);
                add++;
            } while (leftdiagonalMove.first != 7);

            break;
        }
        case PieceType::QUEEN:
        {
            pieceRepresentation = 'Q';
            std::pair<int, int> horizontalMove = pieceLocation;
            std::pair<int, int> verticalMove = pieceLocation;
            std::pair<int, int> rightdiagonalMove = pieceLocation;
            std::pair<int, int> leftdiagonalMove = pieceLocation;

            int add = 0;
            do {
                //going right
                horizontalMove.first = pieceLocation.first + add;
                newvalidMoves.push_back(horizontalMove);
                add++;

            } while (horizontalMove.first != 7);
            add = 0;
            horizontalMove = pieceLocation;
            verticalMove = pieceLocation;
            do {
                //going left
                horizontalMove.first = pieceLocation.first - add;
                newvalidMoves.push_back(horizontalMove);
                add++;

            } while (horizontalMove.first != 0);
            add = 0;
            horizontalMove = pieceLocation;
            verticalMove = pieceLocation;
            do {
                //going up
                verticalMove.second = pieceLocation.second - add;
                newvalidMoves.push_back(verticalMove);
                add++;

            } while (verticalMove.second != 0);
            add = 0;
            horizontalMove = pieceLocation;
            verticalMove = pieceLocation;
            do {
                //going down
                verticalMove.second = pieceLocation.second + add;
                newvalidMoves.push_back(verticalMove);
                add++;

            } while (verticalMove.second != 7);
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going up and right
                if (rightdiagonalMove.first == 7) {
                    break;
                }
                rightdiagonalMove.first = pieceLocation.first + add;
                rightdiagonalMove.second = pieceLocation.second - add;
                newvalidMoves.push_back(rightdiagonalMove);
                add++;

            } while (rightdiagonalMove.second != 0);
            //then
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going down and left
                if (rightdiagonalMove.first == 0) {
                    break;
                }
                rightdiagonalMove.first = pieceLocation.first - add;
                rightdiagonalMove.second = pieceLocation.second + add;
                newvalidMoves.push_back(rightdiagonalMove);
                add++;
            } while (rightdiagonalMove.second != 7);
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going up and left
                if (leftdiagonalMove.first == 0) {

                    break;
                }
                leftdiagonalMove.first = pieceLocation.first - add;
                leftdiagonalMove.second = pieceLocation.second - add;
                newvalidMoves.push_back(leftdiagonalMove);
                add++;

            } while (leftdiagonalMove.second != 0);
            //then
            add = 0;
            rightdiagonalMove = pieceLocation;
            leftdiagonalMove = pieceLocation;
            do {
                //going down and right
                if (leftdiagonalMove.second == 7) {

                    break;
                }
                leftdiagonalMove.first = pieceLocation.first - add;
                leftdiagonalMove.second = pieceLocation.second + add;
                newvalidMoves.push_back(leftdiagonalMove);
                add++;
            } while (leftdiagonalMove.first != 7);
        }
        case PieceType::KING:
        {
            pieceRepresentation = 'K';
            newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second - 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first + 1, pieceLocation.second));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first - 1, pieceLocation.second));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first + 1, pieceLocation.second + 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first - 1, pieceLocation.second + 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first - 1, pieceLocation.second - 1));
            newvalidMoves.push_back(std::make_pair(pieceLocation.first + 1, pieceLocation.second - 1));
            break;
        }

        case PieceType::PAWN:
        {
            pieceRepresentation = 'P';
            if (colour == Colour::BLACK) {
                if (input.getfirstMove()) {
                    newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 1));
                    newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 2));
                    //going down
                }
                else {
                    newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second + 1));
                }
            }
            else if (colour == Colour::WHITE) {
                if (input.getfirstMove()) {
                    //going up
                    newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second - 1));
                    newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second - 2));
                }
                else {
                    newvalidMoves.push_back(std::make_pair(pieceLocation.first, pieceLocation.second - 1));
                }
            }
            break;
        }
        case PieceType::ROOK:
        {
            pieceRepresentation = 'R';
            std::pair<int, int> horizontalMove = pieceLocation;
            std::pair<int, int> verticalMove = pieceLocation;
            int add;
            add = 0;
            do {
                //going right
                horizontalMove.first = pieceLocation.first + add;
                newvalidMoves.push_back(horizontalMove);
                add++;

            } while (horizontalMove.first != 7);
            add = 0;
            horizontalMove = pieceLocation;
            verticalMove = pieceLocation;
            do {
                //going left
                horizontalMove.first = pieceLocation.first - add;
                newvalidMoves.push_back(horizontalMove);
                add++;

            } while (horizontalMove.first != 0);
            add = 0;
            horizontalMove = pieceLocation;
            verticalMove = pieceLocation;
            do {
                //going up
                verticalMove.second = pieceLocation.second - add;
                newvalidMoves.push_back(verticalMove);
                add++;

            } while (verticalMove.second != 0);
            add = 0;
            horizontalMove = pieceLocation;
            verticalMove = pieceLocation;
            do {
                //going down
                verticalMove.second = pieceLocation.second + add;
                newvalidMoves.push_back(verticalMove);
                add++;

            } while (verticalMove.second != 7);
            break;
        }

        case PieceType::EMPTY:
        {
            pieceRepresentation = ' ';
            newvalidMoves.clear();
            //it's empty lol
            break;
        }
        default:
            std::cout << "ERROR";
        }
        input.setValidMoves(newvalidMoves);
    }
    bool checkifValidMove(std::pair<int, int> inputcoords) {
        for (int i = 0; i < newvalidMoves.size(); i++)
        {
            if (inputcoords == newvalidMoves[i]) {
                return true;
            }
            else return false;
        }
    }
    void movePiece(std::pair<int, int> chessPieceLocation, std::pair<int, int> newLocation) {
        if (isTherePieceHere(newLocation) == 1) {
            if (arrayboard[chessPieceLocation.first][chessPieceLocation.second].getPieceType() != PieceType::PAWN){
                if (arrayboard[chessPieceLocation.first][chessPieceLocation.second].getColour() != arrayboard[newLocation.first][newLocation.second].getColour()) {
                    arrayboard[newLocation.first][newLocation.second] = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                    arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);
                    arrayboard[chessPieceLocation.first][chessPieceLocation.second] = ChessPiece(chessPieceLocation);
                    setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                    setPiece(arrayboard[newLocation.first][newLocation.second]);
                    arrayboard[newLocation.first][newLocation.second].Moved();



                }
                else {
                    std::cout << "check back at line 640 to see what went wrong" << std::endl;
                }
            }
            else {
                if (arrayboard[chessPieceLocation.first][chessPieceLocation.second].getColour() == Colour::WHITE) {
                    if (chessPieceLocation.first + 1 == newLocation.first && chessPieceLocation.second - 1 == newLocation.second) {
                        if (getPiece(newLocation).getPieceType() != PieceType::EMPTY) {


                            //if it is to the right of it
                            arrayboard[newLocation.first][newLocation.second] = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                            arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);
                            arrayboard[chessPieceLocation.first][chessPieceLocation.second] = ChessPiece(chessPieceLocation);
                            setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                            setPiece(arrayboard[newLocation.first][newLocation.second]);
                            arrayboard[newLocation.first][newLocation.second].Moved();
                        }
                    }
                    else if (chessPieceLocation.first - 1 == newLocation.first && chessPieceLocation.second - 1 == newLocation.second){
                        //if it is to the left of it
                        if (getPiece(newLocation).getPieceType() != PieceType::EMPTY) {
                            arrayboard[newLocation.first][newLocation.second] = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                            arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);
                            arrayboard[chessPieceLocation.first][chessPieceLocation.second] = ChessPiece(chessPieceLocation);
                            setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                            setPiece(arrayboard[newLocation.first][newLocation.second]);
                            arrayboard[newLocation.first][newLocation.second].Moved();
                        }
                    }
                }
                else {
                    if (chessPieceLocation.first + 1 == newLocation.first && chessPieceLocation.second + 1 == newLocation.second) {
                        //if it is to the right of it
                        if (getPiece(newLocation).getPieceType() != PieceType::EMPTY) {
                            arrayboard[newLocation.first][newLocation.second] = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                            arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);
                            arrayboard[chessPieceLocation.first][chessPieceLocation.second] = ChessPiece(chessPieceLocation);
                            setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                            setPiece(arrayboard[newLocation.first][newLocation.second]);
                            arrayboard[newLocation.first][newLocation.second].Moved();
                        }
                    }
                    else if (chessPieceLocation.first - 1 == newLocation.first && chessPieceLocation.second + 1 == newLocation.second) {
                        //if it is to the left of it
                        if (getPiece(newLocation).getPieceType() != PieceType::EMPTY) {
                            arrayboard[newLocation.first][newLocation.second] = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                            arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);
                            arrayboard[chessPieceLocation.first][chessPieceLocation.second] = ChessPiece(chessPieceLocation);
                            setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                            setPiece(arrayboard[newLocation.first][newLocation.second]);
                            arrayboard[newLocation.first][newLocation.second].Moved();
                        }
                    }
                }
            }
        }
        else {
            if (arrayboard[newLocation.first][newLocation.second].getPieceType() == PieceType::EMPTY) {

                auto storebeforechange = arrayboard[chessPieceLocation.first][chessPieceLocation.second];
                arrayboard[chessPieceLocation.first][chessPieceLocation.second] = arrayboard[newLocation.first][newLocation.second];
                arrayboard[newLocation.first][newLocation.second] = storebeforechange;
                arrayboard[chessPieceLocation.first][chessPieceLocation.second].setPieceLocation(storebeforechange.getPieceLocation());
                arrayboard[newLocation.first][newLocation.second].setPieceLocation(newLocation);


                setPiece(arrayboard[chessPieceLocation.first][chessPieceLocation.second]);
                setPiece(arrayboard[newLocation.first][newLocation.second]);
                arrayboard[newLocation.first][newLocation.second].Moved();

            } else if (arrayboard[chessPieceLocation.first][chessPieceLocation.second].getColour() == arrayboard[newLocation.first][newLocation.second].getColour())
            {
                std::cout << "not possible"; //.. is trying to take their own team
            }
            else {
                    std::cout << "error";
                }

            }
        }
    
    auto getchesspiecearray(){
        return arrayboard;
    }
};

class ChessGame {
private:
    Colour currentTurn = Colour::WHITE;
    bool restartMove = false;
    bool gameRunning = true;
    ChessBoard chessboard;
    bool checkEvent = false;
    bool validNewPieceLocation(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {

                if (chessboard.getPiece(newPieceLocation).getPieceType() == PieceType::EMPTY) {
                    if (chessboard.getPiece(pieceLocation).getPieceType() != PieceType::KNIGHT) {
                        if (checkforSpace(pieceLocation, newPieceLocation)) {
                            return true; //there is space for it to move there
                        }
                        else {
                            if (chessboard.isTherePieceHere(newPieceLocation)) {
                                return true;
                            }
                            else {
                                std::cout << "no space to move" << std::endl;
                                return false;
                            }
                        }
                    }
                    else {
                        return true; //knight can phase through pieces
                    }

                }
                else if (chessboard.getPiece(pieceLocation).getColour() != chessboard.getPiece(newPieceLocation).getColour()) {
                    return true; //taking another piece

                }
                else {
                    std::cout << "error has occured, piece is not able to be moved";
                    return false;
                    
                }
        return false;
    }

    bool checkforSpace(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        int move = 1;
        switch (chessboard.getPiece(pieceLocation).getPieceType()) {
        case PieceType::BISHOP:
        {
            if (pieceLocation.first < newPieceLocation.first) {
                //traveling to the right
                if (pieceLocation.second < newPieceLocation.second) {
                    //travelling right downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first + move - 1, pieceLocation.second + move + 1) != newPieceLocation);
                    return true;
                }
                else {
                    //travelling right upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first + move - 1, pieceLocation.second - move + 1) != newPieceLocation);
                    return true;
                }

            }
            else {
                //travelling to the left
                if (pieceLocation.second < newPieceLocation.second) {
                    //travelling left downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first - move + 1, pieceLocation.second + move - 1) != newPieceLocation);
                    return true;

                }
                else {
                    //travelling left upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first - move + 1, pieceLocation.second - move + 1) != newPieceLocation);
                    return true;
                }
            }
            break;
        }
        case PieceType::QUEEN:
        {
            if (pieceLocation.first == newPieceLocation.first) {
                if (pieceLocation.second < newPieceLocation.second) {
                    //travelling downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first, pieceLocation.second + move - 1) != newPieceLocation);
                    return true;
                }
                else {
                    //travelling upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first, pieceLocation.second - move + 1) != newPieceLocation);
                    return true;
                }
            }
            else if (pieceLocation.first < newPieceLocation.first) {
                //traveling to the right
                if (pieceLocation.second == newPieceLocation.second) {
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first + move - 1, pieceLocation.second) != newPieceLocation);
                    return true;
                }
                else if (pieceLocation.second < newPieceLocation.second) {
                    //travelling right downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first + move - 1, pieceLocation.second + move - 1) != newPieceLocation);
                    return true;
                }
                else {
                    //travelling right upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first + move - 1, pieceLocation.second - move + 1) != newPieceLocation);
                    return true;
                }

            }
            else {
                //travelling to the left
                if (pieceLocation.second == newPieceLocation.second) {
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first - move + 1, pieceLocation.second) != newPieceLocation);
                    return true;
                }
                else if (pieceLocation.second < newPieceLocation.second) {
                    //travelling left downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first - move, pieceLocation.second + move) != newPieceLocation);
                    return true;

                }
                else {
                    //travelling left upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first - move, pieceLocation.second - move) != newPieceLocation);
                    return true;
                }
            }
            break;
        }
        case PieceType::ROOK: {
            if (pieceLocation.first == newPieceLocation.first) {
                if (pieceLocation.second < newPieceLocation.second) {
                    //travelling downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first, pieceLocation.second + move - 1) != newPieceLocation);
                    return true;
                }
                else {
                    //travelling upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first, pieceLocation.second - move + 1) != newPieceLocation);
                    return true;
                }
            }
            else if (pieceLocation.first < newPieceLocation.first) {
                //traveling to the right
                if (pieceLocation.second == newPieceLocation.second) {
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first + move - 1, pieceLocation.second) != newPieceLocation);
                    return true;
                }
            }
            else {
                if (pieceLocation.second == newPieceLocation.second) {
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            move++;
                        }
                    } while (std::make_pair(pieceLocation.first - move + 1, pieceLocation.second) != newPieceLocation);
                    return true;
                }
            }
            break;
        }
        case PieceType::KING: {
            move = 1;

            if (pieceLocation.first == newPieceLocation.first) {
                if (pieceLocation.second < newPieceLocation.second) {
                    //travelling downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first, pieceLocation.second + move) != newPieceLocation);

                }
                else {
                    //travelling upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first, pieceLocation.second - move) != newPieceLocation);

                }
            }
            else if (pieceLocation.first < newPieceLocation.first) {
                //traveling to the right
                if (pieceLocation.second == newPieceLocation.second) {
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first + move, pieceLocation.second) != newPieceLocation);

                }
                else if (pieceLocation.second < newPieceLocation.second) {
                    //travelling right downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first + move, pieceLocation.second + move) != newPieceLocation);
                }
                else {
                    //travelling right upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first + move, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first + move, pieceLocation.second - move) != newPieceLocation);
                }

            }
            else {
                //travelling to the left
                if (pieceLocation.second == newPieceLocation.second) {
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first - move, pieceLocation.second) != newPieceLocation);
                }
                else if (pieceLocation.second < newPieceLocation.second) {
                    //travelling left downwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second + move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first - move, pieceLocation.second + move) != newPieceLocation);

                }
                else {
                    //travelling left upwards
                    move = 1;
                    do {
                        if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first - move, pieceLocation.second - move))) {
                            //there is a piece in the way, return false
                            return false;
                        }
                        else {
                            return true;
                        }
                    } while (std::make_pair(pieceLocation.first - move, pieceLocation.second - move) != newPieceLocation);

                }
            }
            break;
        }
        case PieceType::PAWN: {
            if (pieceLocation.first == newPieceLocation.first) {
                if (chessboard.getPiece(pieceLocation).getColour() == Colour::WHITE) {
                    if (chessboard.getPiece(pieceLocation).getfirstMove()) {
                        //if it is the first move,
                        /*

                        */

                        if (pieceLocation.second - 1 == newPieceLocation.second)
                        {
                            //pieceLocation.second - 1 == newPieceLocation.second
                            if (!chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 1))) {
                                //check if there's nothing there
                                return true;
                            }
                            else if (pieceLocation.second - 2 == newPieceLocation.second) {
                                //chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 2))
                                //
                                if (chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 2))) {
                                    //check if there's something there
                                    return true;
                                }
                                else {
                                    //something is blocking the pawn
                                    return false;
                                }
                            }
                        }
                        else if (pieceLocation.second - 2 == newPieceLocation.second) {
                            //check if the movement is within bounds
                            if (!chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 2))) {
                                //check if there's nothing there
                                return true;
                            }

                            else {
                                return false;
                            }
                        }
                    }



                    else if (pieceLocation.second - 1 == newPieceLocation.second)
                    {
                        //chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 1))
                        if (!chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 1))) {
                            //check if the coast is clear
                            return true;
                        }
                        else {
                            //something is blocking the pawn
                            return false;
                        }
                    }


                    else {
                        return false;
                    }
                }

                else {
                    if (chessboard.getPiece(pieceLocation).getfirstMove()) {
                        //if it is the first move,
                    /*

                    */
                        if (pieceLocation.second + 1 == newPieceLocation.second)
                        {
                            //pieceLocation.second - 1 == newPieceLocation.second
                            if (!chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second + 1))) {
                                //check if there's nothing there
                                return true;
                            }
                        }
                        else if (pieceLocation.second + 2 == newPieceLocation.second) {
                            //chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 2))
                            //
                            if (!chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second + 2))) {
                                //check if there's something there
                                return true;
                            }
                            else {
                                //something is blocking the pawn
                                return false;
                            }
                        }
                        else {
                            if (pieceLocation.second + 2 == newPieceLocation.second) {
                                //check if the movement is within bounds
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }



                    else if (pieceLocation.second + 1 == newPieceLocation.second)
                    {
                        //chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second - 1))
                        if (!chessboard.isTherePieceHere(std::make_pair(pieceLocation.first, pieceLocation.second + 1))) {
                            //check if the coast is clear
                            return true;
                        }
                        else {
                            //something is blocking the pawn
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }

            }
        }



        }
    }
        
        
        

        
    
        
    
        
        

    bool isMoveCheck(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        Colour ColourinQuestion = chessboard.getPiece(newPieceLocation).getColour();
        std::pair<int, int> kingsLocation;
        if (ColourinQuestion == Colour::WHITE) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++)
                {
                    if (chessboard.getchesspiecearray()[j][i].getColour() == Colour::BLACK && chessboard.getchesspiecearray()[j][i].getPieceType() == PieceType::KING) {
                        kingsLocation = chessboard.getchesspiecearray()[j][i].getPieceLocation();
                    }
                }

            }
            if (!checkforSpace(newPieceLocation, kingsLocation)) {
                //look for the black king, if the king is blocking the path,
                chessboard.reinstantiateValidMoves(chessboard.getPiece(newPieceLocation));
                if (chessboard.checkifValidMove(kingsLocation)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            else {
                return false;
            }
        }
        else {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++)
                {
                    if (chessboard.getchesspiecearray()[j][i].getColour() == Colour::WHITE && chessboard.getchesspiecearray()[j][i].getPieceType() == PieceType::KING) {
                        kingsLocation = chessboard.getchesspiecearray()[j][i].getPieceLocation();
                        break;
                    }
                }

            }
            if (!checkforSpace(newPieceLocation, kingsLocation)) {
                //look for the white king, if the king is blocking the path,
                chessboard.reinstantiateValidMoves(chessboard.getPiece(newPieceLocation));
                if (chessboard.checkifValidMove(kingsLocation)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    bool isMoveCheckMate(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};

public:
    void pieceMove(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        if (validNewPieceLocation(pieceLocation, newPieceLocation) && chessboard.isTherePieceHere(pieceLocation)) {
            PieceType movingPieceType = chessboard.getPiece(pieceLocation).getPieceType();
            chessboard.movePiece(pieceLocation, newPieceLocation);
            chessboard.resetBoard();
            chessboard.showBoard();
            if (isMoveCheck(pieceLocation, newPieceLocation)) {
                checkEvent = true;
                std::cout << "in check";
            }
        }
        else {
            std::cout << "that move was not possible" << std::endl;
            restartMove = true;

        }

    };

    ChessBoard getchessboard() {
        return chessboard;
    }
    void setrestartMove(bool a) {
        restartMove = a;
    }
    bool getrestartMove() {
        return restartMove;
    }
    void newGame() {

        Colour nextTurn;
        std::string colourinTurn = "white";
        currentTurn = Colour::WHITE;
        chessboard.showBoard();    
        //example of move: a1->a2
        std::string playerinput;
        do {
            do {
                std::getline(std::cin, playerinput);
                if (playerinput[2] != '-') {
                    std::cout << "invalid input" << std::endl;
                    continue;
                }
                if (chessboard.getPiece(std::make_pair(chessNotationtranslatechar(playerinput[0]), 8 - atoi(&playerinput[1]))).getColour() != currentTurn) {
                    std::cout << "It is "<< colourinTurn << "'s turn" << std::endl;
                    continue;
                }
            } while (chessboard.getPiece(std::make_pair(chessNotationtranslatechar(playerinput[0]), 8 - atoi(&playerinput[1]))).getColour() != currentTurn);
            if (currentTurn == Colour::WHITE) {
                nextTurn = Colour::BLACK;
                colourinTurn = "black";
            }
            else {
                nextTurn = Colour::WHITE;
                colourinTurn = "white";

            }
            pieceMove((std::make_pair(chessNotationtranslatechar(playerinput[0]), 8 - atoi(&playerinput[1]))), std::make_pair(chessNotationtranslatechar(playerinput[4]), 8 - atoi(&playerinput[5])));
            if (restartMove) {
                setrestartMove(false);
                continue;
            }
            else {
                currentTurn = nextTurn;
            }
        } while (gameRunning);
        
        //by the way, pair input is basically like '1a' because rest of program is program with .first being x and .second being y
        //test knight by b8->c6, keeping these comments here in case some conversion goes awry

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