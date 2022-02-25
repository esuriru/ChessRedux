#include <iostream>
#include <array>
#include <string>

enum class PieceType { PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING, EMPTY };
enum class Colour { BLACK, WHITE, NIL };

class ChessPiece {
private:
    PieceType piecetype;
    Colour colour;
    char pieceRepresentation;
    std::pair<int, int> pieceLocation;


public:
    ChessPiece() {
        piecetype = PieceType::EMPTY;
        colour = Colour::NIL;
        pieceRepresentation = ' ';
        pieceLocation = std::make_pair(NULL, NULL);
    }
    ChessPiece(PieceType pt, Colour c, std::pair<int, int> startingLocation) {
        piecetype = pt;
        colour = c;
        pieceLocation = startingLocation;
        switch (pt) {
        case PieceType::PAWN:
            pieceRepresentation = 'P';
            break;
        case PieceType::BISHOP:
            pieceRepresentation = 'B';
            break;
        case PieceType::KNIGHT:
            pieceRepresentation = 'N';
            break;
        case PieceType::ROOK:
            pieceRepresentation = 'R';
            break;
        case PieceType::QUEEN:
            pieceRepresentation = 'Q';
            break;
        case PieceType::KING:
            pieceRepresentation = 'K';
            break;
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
    char getpieceRepresentation() {
        return pieceRepresentation;
    }
    void setpieceRepresentation(char input) {
        pieceRepresentation = input;
    }
    std::pair<int, int> getpieceLocation() {
        return pieceLocation;
    }
    void setpieceLocation(std::pair<int, int> input) {
        pieceLocation = input;
    }

};

class ChessBoard {
private:
    ChessPiece arrayboard[8][8];

public:
    ChessBoard() {
        //create pieces
        ChessPiece blackRook1 =  ChessPiece(PieceType::ROOK, Colour::BLACK, std::make_pair(0, 0));
        setPiece(blackRook1, blackRook1.getpieceLocation());

        ChessPiece blackRook2 =  ChessPiece(PieceType::ROOK, Colour::BLACK, std::make_pair(7, 0));
        setPiece(blackRook2, blackRook2.getpieceLocation());

        ChessPiece blackKnight1 =  ChessPiece(PieceType::KNIGHT, Colour::BLACK, std::make_pair(1, 0));
        setPiece(blackKnight1, blackKnight1.getpieceLocation());

        ChessPiece blackKnight2 =  ChessPiece(PieceType::KNIGHT, Colour::BLACK, std::make_pair(6, 0));
        setPiece(blackKnight2, blackKnight2.getpieceLocation());

        ChessPiece blackBishop1 =  ChessPiece(PieceType::BISHOP, Colour::BLACK, std::make_pair(2, 0));
        setPiece(blackBishop1, blackBishop1.getpieceLocation());

        ChessPiece blackBishop2 =  ChessPiece(PieceType::BISHOP, Colour::BLACK, std::make_pair(5, 0));
        setPiece(blackBishop2, blackBishop2.getpieceLocation());

        ChessPiece blackKing1 =  ChessPiece(PieceType::KING, Colour::BLACK, std::make_pair(4, 0));
        setPiece(blackKing1, blackKing1.getpieceLocation());

        ChessPiece blackQueen1 =  ChessPiece(PieceType::QUEEN, Colour::BLACK, std::make_pair(3, 0));
        setPiece(blackQueen1, blackQueen1.getpieceLocation());

        ChessPiece blackPawn1 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(0, 1));
        setPiece(blackPawn1, blackPawn1.getpieceLocation());

        ChessPiece blackPawn2 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(1, 1));
        setPiece(blackPawn2, blackPawn2.getpieceLocation());

        ChessPiece blackPawn3 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(2, 1));
        setPiece(blackPawn3, blackPawn3.getpieceLocation());

        ChessPiece blackPawn4 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(3, 1));
        setPiece(blackPawn4, blackPawn4.getpieceLocation());

        ChessPiece blackPawn5 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(4, 1));
        setPiece(blackPawn5, blackPawn5.getpieceLocation());

        ChessPiece blackPawn6 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(5, 1));
        setPiece(blackPawn6, blackPawn6.getpieceLocation());

        ChessPiece blackPawn7 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(6, 1));
        setPiece(blackPawn7, blackPawn7.getpieceLocation());

        ChessPiece blackPawn8 =  ChessPiece(PieceType::PAWN, Colour::BLACK, std::make_pair(7, 1));
        setPiece(blackPawn8, blackPawn8.getpieceLocation());

        //black pieces
        ChessPiece whiteRook1 =  ChessPiece(PieceType::ROOK, Colour::WHITE, std::make_pair(0, 7));
        setPiece(whiteRook1, whiteRook1.getpieceLocation());

        ChessPiece whiteRook2 =  ChessPiece(PieceType::ROOK, Colour::WHITE, std::make_pair(7, 7));
        setPiece(whiteRook2, whiteRook2.getpieceLocation());

        ChessPiece whiteKnight1 =  ChessPiece(PieceType::KNIGHT, Colour::WHITE, std::make_pair(1, 7));
        setPiece(whiteKnight1, whiteKnight1.getpieceLocation());

        ChessPiece whiteKnight2 =  ChessPiece(PieceType::KNIGHT, Colour::WHITE, std::make_pair(6, 7));
        setPiece(whiteKnight2, whiteKnight2.getpieceLocation());

        ChessPiece whiteBishop1 =  ChessPiece(PieceType::BISHOP, Colour::WHITE, std::make_pair(2, 7));
        setPiece(whiteBishop1, whiteBishop1.getpieceLocation());

        ChessPiece whiteBishop2 =  ChessPiece(PieceType::BISHOP, Colour::WHITE, std::make_pair(5, 7));
        setPiece(whiteBishop2, whiteBishop2.getpieceLocation());

        ChessPiece whiteKing1 =  ChessPiece(PieceType::KING, Colour::WHITE, std::make_pair(4, 7));
        setPiece(whiteKing1, whiteKing1.getpieceLocation());

        ChessPiece whiteQueen1 =  ChessPiece(PieceType::QUEEN, Colour::WHITE, std::make_pair(3, 7));
        setPiece(whiteQueen1, whiteQueen1.getpieceLocation());

        ChessPiece whitePawn1 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(0, 6));
        setPiece(whitePawn1, whitePawn1.getpieceLocation());

        ChessPiece whitePawn2 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(1, 6));
        setPiece(whitePawn2, whitePawn2.getpieceLocation());

        ChessPiece whitePawn3 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(2, 6));
        setPiece(whitePawn3, whitePawn3.getpieceLocation());

        ChessPiece whitePawn4 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(3, 6));
        setPiece(whitePawn4, whitePawn4.getpieceLocation());

        ChessPiece whitePawn5 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(4, 6));
        setPiece(whitePawn5, whitePawn5.getpieceLocation());

        ChessPiece whitePawn6 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(5, 6));
        setPiece(whitePawn6, whitePawn6.getpieceLocation());

        ChessPiece whitePawn7 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(6, 6));
        setPiece(whitePawn7, whitePawn7.getpieceLocation());

        ChessPiece whitePawn8 =  ChessPiece(PieceType::PAWN, Colour::WHITE, std::make_pair(7, 6));
        setPiece(whitePawn8, whitePawn8.getpieceLocation());

    }
    void showBoard() {
        //create the board
        std::cout << "  " << "a" << "    " << "b" << "    " << "c" << "    " << "d" << "    " << "e" << "    " << "f" << "    " << "g" << "    " << "h" << std::endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
            {
                if (arrayboard[j][i].getpieceLocation().first == 0 && arrayboard[j][i].getPieceType() != PieceType::EMPTY) {
                    std::cout << 8 - i << " " << arrayboard[j][i].getpieceRepresentation() << "  ";
                }
                else
                {
                    if (j == 0) {
                        std::cout << 8 - i << " " << arrayboard[j][i].getpieceRepresentation() << "  ";
                    }
                    else {
                        std::cout << "  " << arrayboard[j][i].getpieceRepresentation() << "  ";
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
        if (getPiece(location).getPieceType() == PieceType::EMPTY) {
            return false;
        }
        else return true;
    }
    ChessPiece getPiece(std::pair<int, int> chessPieceLocation) {
        return arrayboard[chessPieceLocation.first][chessPieceLocation.second];
    }
    void setPiece(ChessPiece inputpiece, std::pair<int, int> inputLocation) {
        
        inputpiece.setpieceLocation(inputLocation);
        arrayboard[inputLocation.first][inputLocation.second] = inputpiece;
    }
    auto getBoard() {
        return arrayboard;
    }
    void movePiece(ChessPiece from, std::pair<int, int> newLocation) {
        /*if (getPiece(newLocation).getPieceType() == PieceType::EMPTY) {
            //to empty space
            setPiece(from, newLocation);
        }
        else if (getPiece(newLocation).getColour() != from.getColour()) {
            //taking another piece           
            auto beforeLocation = from.getpieceLocation();
            setPiece(from, newLocation);
            setPiece(ChessPiece(), beforeLocation);
        }*/

        auto beforeLocation = from.getpieceLocation();
        setPiece(from, newLocation);
        
        setPiece(ChessPiece(), beforeLocation);
        

        
    }

    bool isMoveLegal(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        bool takingPiece;
        if (getPiece(newPieceLocation).getPieceType() == PieceType::EMPTY) {
            takingPiece = false;
        }
        else if (getPiece(pieceLocation).getColour() == Colour::WHITE) {
            takingPiece = (getPiece(newPieceLocation).getColour() == Colour::BLACK) ? true : false;
        }
        else if (getPiece(pieceLocation).getColour() == Colour::BLACK) {
            takingPiece = (getPiece(newPieceLocation).getColour() == Colour::WHITE) ? true : false;
        }
        switch (getPiece(pieceLocation).getPieceType()) {
        case PieceType::KNIGHT: {
            if (std::make_pair(pieceLocation.first + 1, pieceLocation.second - 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second - 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 1, pieceLocation.second + 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second + 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 2, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 2, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 2, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 2, pieceLocation.second + 1) == newPieceLocation
                ) {
                return true;
            }
            else return false;
            
        }
        case PieceType::BISHOP: {
            if (pieceLocation.first > newPieceLocation.first) {
                //moving to the left
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 0; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else {
                //moving to the right
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;

                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 0; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            break;
        }
        case PieceType::ROOK: {
            if (pieceLocation.second == newPieceLocation.second) {

                if (pieceLocation.first > newPieceLocation.first) {
                    //moving to the left
                    for (int i = 0; i < pieceLocation.first - newPieceLocation.first; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving to the right
                    for (int i = 0; i < newPieceLocation.first - pieceLocation.first; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else {
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;

                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 0; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            break;
        }
        case PieceType::KING: {
            if (std::make_pair(pieceLocation.first + 1, pieceLocation.second) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second) == newPieceLocation ||
                std::make_pair(pieceLocation.first, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 1, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 1, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second - 1) == newPieceLocation
                ) {
                return true;
            }
            else return false;
        }
        case PieceType::PAWN: {
            if (takingPiece) {
                if (getPiece(pieceLocation).getColour() == Colour::WHITE) {
                    if (std::make_pair(pieceLocation.first + 1, pieceLocation.second - 1) == newPieceLocation || std::make_pair(pieceLocation.first - 1, pieceLocation.second - 1) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }
                else {
                    if (std::make_pair(pieceLocation.first + 1, pieceLocation.second + 1) == newPieceLocation || std::make_pair(pieceLocation.first - 1, pieceLocation.second + 1) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }

            }
            else {
                if (getPiece(pieceLocation).getColour() == Colour::WHITE) {
                    if (pieceLocation.second == 6) {
                        if (std::make_pair(pieceLocation.first, pieceLocation.second - 1) == newPieceLocation || std::make_pair(pieceLocation.first, pieceLocation.second - 2) == newPieceLocation) {
                            return true;
                        }
                        else return false;
                    }
                    else if (std::make_pair(pieceLocation.first, pieceLocation.second - 1) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }
                else if (pieceLocation.second == 1){
                    if (std::make_pair(pieceLocation.first, pieceLocation.second + 1) == newPieceLocation || std::make_pair(pieceLocation.first, pieceLocation.second + 2) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }
                else if (std::make_pair(pieceLocation.first, pieceLocation.second + 1) == newPieceLocation) {
                    return true;
                }
                else return false;
            }
            return false;
        }
        case PieceType::QUEEN: {
            if (pieceLocation.first > newPieceLocation.first) {
                //moving to the left
                if (pieceLocation.second == pieceLocation.second) {
                    for (int i = 0; i < pieceLocation.first - newPieceLocation.first; i++) {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                }
                else if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 0; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else if (pieceLocation.first < newPieceLocation.first){
                //moving to the right
                if (pieceLocation.second == pieceLocation.second) {
                    for (int i = 0; i < newPieceLocation.first - pieceLocation.first; i++) {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                }
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;

                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 0; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else if (pieceLocation.first == newPieceLocation.first) {
                //moving in the y-axis
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                } 
                else {
                    //moving downwards
                    for (int i = 0; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                }
            }
        }
        }
    }
    bool isMoveLegal(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation, bool takingPiece) {        
        switch (getPiece(pieceLocation).getPieceType()) {
        case PieceType::KNIGHT: {
            if (std::make_pair(pieceLocation.first + 1, pieceLocation.second - 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second - 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 1, pieceLocation.second + 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second + 2) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 2, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 2, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 2, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 2, pieceLocation.second + 1) == newPieceLocation
                ) {
                return true;
            }
            else return false;

        }
        case PieceType::BISHOP: {
            if (pieceLocation.second == newPieceLocation.second || pieceLocation.first == newPieceLocation.first) {
                return false;
            }
            if (pieceLocation.first > newPieceLocation.first) {
                //moving to the left
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 1; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else {
                //moving to the right
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;

                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 1; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            break;
        }
        case PieceType::ROOK: {
            if (pieceLocation.second != newPieceLocation.second && pieceLocation.first != newPieceLocation.first) {
                return false;
            }
            if (pieceLocation.second == newPieceLocation.second) {

                if (pieceLocation.first > newPieceLocation.first) {
                    //moving to the left
                    for (int i = 1; i < pieceLocation.first - newPieceLocation.first; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving to the right
                    for (int i = 1; i < newPieceLocation.first - pieceLocation.first; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else {
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;

                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 1; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            break;
        }
        case PieceType::KING: {
            if (std::make_pair(pieceLocation.first + 1, pieceLocation.second) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second) == newPieceLocation ||
                std::make_pair(pieceLocation.first, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 1, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first + 1, pieceLocation.second - 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second + 1) == newPieceLocation ||
                std::make_pair(pieceLocation.first - 1, pieceLocation.second - 1) == newPieceLocation
                ) {
                return true;
            }
            else return false;
        }
        case PieceType::PAWN: {
            if (takingPiece) {
                if (getPiece(pieceLocation).getColour() == Colour::WHITE) {
                    if (std::make_pair(pieceLocation.first + 1, pieceLocation.second - 1) == newPieceLocation || std::make_pair(pieceLocation.first - 1, pieceLocation.second - 1) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }
                else {
                    if (std::make_pair(pieceLocation.first + 1, pieceLocation.second + 1) == newPieceLocation || std::make_pair(pieceLocation.first - 1, pieceLocation.second + 1) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }

            }
            else {
                if (getPiece(pieceLocation).getColour() == Colour::WHITE) {
                    if (pieceLocation.second == 6) {
                        if (std::make_pair(pieceLocation.first, pieceLocation.second - 1) == newPieceLocation || std::make_pair(pieceLocation.first, pieceLocation.second - 2) == newPieceLocation) {
                            return true;
                        }
                        else return false;
                    }
                    else if (std::make_pair(pieceLocation.first, pieceLocation.second - 1) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }
                else if (pieceLocation.second == 1) {
                    if (std::make_pair(pieceLocation.first, pieceLocation.second + 1) == newPieceLocation || std::make_pair(pieceLocation.first, pieceLocation.second + 2) == newPieceLocation) {
                        return true;
                    }
                    else return false;
                }
                else if (std::make_pair(pieceLocation.first, pieceLocation.second + 1) == newPieceLocation) {
                    return true;
                }
                else return false;
            }
            return false;
        }
        case PieceType::QUEEN: {
            if (pieceLocation.first > newPieceLocation.first) {
                //moving to the left
                if (pieceLocation.second == pieceLocation.second) {
                    for (int i = 1; i < pieceLocation.first - newPieceLocation.first; i++) {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                }
                else if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 1; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first - i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first - i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else if (pieceLocation.first < newPieceLocation.first) {
                //moving to the right
                if (pieceLocation.second == pieceLocation.second) {
                    for (int i = 1; i < newPieceLocation.first - pieceLocation.first; i++) {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                }
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;

                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 1; i < newPieceLocation.second - pieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first + i, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first + i, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    // finally, if it is possible
                    return true;
                }
            }
            else if (pieceLocation.first == newPieceLocation.first) {
                //moving in the y-axis
                if (pieceLocation.second > newPieceLocation.second) {
                    //moving upwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second - i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second - i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    return true;
                }
                else {
                    //moving downwards
                    for (int i = 1; i < pieceLocation.second - newPieceLocation.second; i++)
                    {
                        //check if empty
                        if (getPiece(std::make_pair(pieceLocation.first, pieceLocation.second + i)).getPieceType() == PieceType::EMPTY) {
                            continue;
                        }
                        else if (std::make_pair(pieceLocation.first, pieceLocation.second + i) == newPieceLocation) {
                            return takingPiece;
                        }
                        else return false;
                    }
                    return true;
                }
            }
        }
        }
    }
};

class ChessGame {
private:
    ChessBoard chessboard;
    bool gameRunning;
    Colour currentTurn;
    
    bool isMoveCheck(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};
    bool isMoveCheckMate(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {};

public:
    void newGame() {
        gameRunning = true;
        currentTurn = Colour::WHITE;
        std::string playerInput;
        chessboard.showBoard();
        while (gameRunning) {
            getline(std::cin, playerInput);
            
            if (playerInput.length() == 2) {
                //pawn movement, no taking of pieces
                std::pair<int, int>newLocation = std::make_pair(int(playerInput[0]) - 97, 8 - atoi(&playerInput[1]));
                ChessPiece movingPiece = findMovablePiece(PieceType::PAWN, newLocation, false);
                //theroetically, it should not return an empty grid.
                if (movingPiece.getColour() == currentTurn) {
                    makeMove(movingPiece, newLocation);
                }
                else {
                    switch (currentTurn) {
                    case Colour::WHITE:
                        std::cout << "It is currently white's turn" << std::endl;
                        break;
                    case Colour::BLACK:
                        std::cout << "It is currently black's turn" << std::endl;
                        break;
                    }
                }
            }
            else if (playerInput.length() == 3) {
                std::pair<int, int>newLocation = std::make_pair(int(playerInput[1]) - 97, 8 - atoi(&playerInput[2]));
                ChessPiece movingPiece;
                switch (playerInput[0]) {
                case 'B':
                    movingPiece = findMovablePiece(PieceType::BISHOP, newLocation, false);
                    break;
                case 'K':
                    movingPiece = findMovablePiece(PieceType::KING, newLocation, false);
                    break;
                case 'Q':
                    movingPiece = findMovablePiece(PieceType::QUEEN, newLocation, false);
                    break;
                case 'N':
                    movingPiece = findMovablePiece(PieceType::KNIGHT, newLocation, false);
                    break;
                case 'R':
                    movingPiece = findMovablePiece(PieceType::ROOK, newLocation, false);
                    break;
                default:
                    std::cout << "Invalid input" << std::endl;
                    continue;
                }
                if (movingPiece.getColour() == currentTurn) {
                    makeMove(movingPiece, newLocation);
                }
                else {
                    switch (currentTurn) {
                    case Colour::WHITE:
                        std::cout << "It is currently white's turn" << std::endl;
                        break;
                    case Colour::BLACK:
                        std::cout << "It is currently black's turn" << std::endl;
                        break;
                    }
                }
            }
            else if (playerInput.length() == 4) {
                if (playerInput[1] == 'x') {
                    std::pair<int, int>newLocation = std::make_pair(int(playerInput[2]) - 97, 8 - atoi(&playerInput[3]));
                    ChessPiece movingPiece;
                    
                    switch (playerInput[0]) {
                    case 'B':
                        movingPiece = findMovablePiece(PieceType::BISHOP, newLocation, true);
                        if (movingPiece.getColour() == currentTurn) {
                            makeMove(movingPiece, newLocation);
                        }
                        else {
                            switch (currentTurn) {
                            case Colour::WHITE:
                                std::cout << "It is currently white's turn" << std::endl;
                                break;
                            case Colour::BLACK:
                                std::cout << "It is currently black's turn" << std::endl;
                                break;
                            }
                        }
                        break;
                    case 'K':
                        movingPiece = findMovablePiece(PieceType::KING, newLocation, true);
                        if (movingPiece.getColour() == currentTurn) {
                            makeMove(movingPiece, newLocation);
                        }
                        else {
                            switch (currentTurn) {
                            case Colour::WHITE:
                                std::cout << "It is currently white's turn" << std::endl;
                                break;
                            case Colour::BLACK:
                                std::cout << "It is currently black's turn" << std::endl;
                                break;
                            }
                        }
                        
                        break;
                    case 'Q':
                        movingPiece = findMovablePiece(PieceType::QUEEN, newLocation, true);
                        if (movingPiece.getColour() == currentTurn) {
                            makeMove(movingPiece, newLocation);
                        }
                        else {
                            switch (currentTurn) {
                            case Colour::WHITE:
                                std::cout << "It is currently white's turn" << std::endl;
                                break;
                            case Colour::BLACK:
                                std::cout << "It is currently black's turn" << std::endl;
                                break;
                            }
                        }
                        break;
                    case 'N':
                        movingPiece = findMovablePiece(PieceType::KNIGHT, newLocation, true);
                        if (movingPiece.getColour() == currentTurn) {
                            makeMove(movingPiece, newLocation);
                        }
                        else {
                            switch (currentTurn) {
                            case Colour::WHITE:
                                std::cout << "It is currently white's turn" << std::endl;
                                break;
                            case Colour::BLACK:
                                std::cout << "It is currently black's turn" << std::endl;
                                break;
                            }
                        }
                        break;
                    case 'R':
                        movingPiece = findMovablePiece(PieceType::ROOK, newLocation, true);
                        if (movingPiece.getColour() == currentTurn) {
                            makeMove(movingPiece, newLocation);
                        }
                        else {
                            switch (currentTurn) {
                            case Colour::WHITE:
                                std::cout << "It is currently white's turn" << std::endl;
                                break;
                            case Colour::BLACK:
                                std::cout << "It is currently black's turn" << std::endl;
                                break;
                            }
                        }
                        break;
                    case 'a': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(0, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(0, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(0, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(0, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(0, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(0, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(0, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getBoard()[0][i], newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'b': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(1, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(1, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(1, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(1, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(1, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(1, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(1, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(1, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'c': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(2, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(2, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(2, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(2, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(2, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(2, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(2, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(2, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'd': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(3, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(3, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(3, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(3, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(3, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(3, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(3, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(3, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'e': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(4, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(4, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(4, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(4, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(4, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(4, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(4, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(4, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'f': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(5, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(5, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(5, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(5, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(5, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(5, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(5, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(5, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'g': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(6, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(6, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(6, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(6, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(6, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(6, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(6, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(6, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'h': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(7, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(7, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(7, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(7, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(7, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(7, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(7, i)).getpieceLocation(), newLocation, true)) {
                                        makeMove(chessboard.getPiece(std::make_pair(7, i)), newLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }

                    }
                }
                else {
                    std::cout << "Invalid input" << std::endl;
                    continue;
                }
            }
        }
    }
    void makeMove(ChessPiece from, std::pair<int, int> newPieceLocation) {
        chessboard.movePiece(from, newPieceLocation);
        chessboard.resetBoard();
        chessboard.showBoard();
        switch (currentTurn) {
        case Colour::WHITE:
            currentTurn = Colour::BLACK;
            break;
        case Colour::BLACK:
            currentTurn = Colour::WHITE;
            break;
        }
    }
    ChessPiece findMovablePiece(PieceType pt, std::pair<int, int> newPieceLocation, bool takingPiece) {        
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (chessboard.getBoard()[j][i].getPieceType() == pt) {
                        if (chessboard.getBoard()[j][i].getColour() == currentTurn) {
                            if (chessboard.isMoveLegal(chessboard.getBoard()[j][i].getpieceLocation(), newPieceLocation, takingPiece)) {
                                return chessboard.getBoard()[j][i];
                            }
                            else continue;
                        }
                        else continue;
                    }
                    else continue;
                }
            }
            std::cout << "There was no movable pieces." << std::endl;
            
    }
};

int main() {
    ChessGame game;
    game.newGame();
}
