#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <string_view>

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
    std::pair<int, int> latestMoveLocation;
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
        
        auto beforeLocation = from.getpieceLocation();
        setPiece(from, newLocation);
        
        setPiece(ChessPiece(), beforeLocation);
        latestMoveLocation = newLocation;
    }
    void promotePiece(ChessPiece from, std::pair<int, int> newLocation, PieceType choice) {

        auto beforeLocation = from.getpieceLocation();
        setPiece(ChessPiece(choice, from.getColour(), newLocation), newLocation);
        setPiece(ChessPiece(), beforeLocation);
        latestMoveLocation = newLocation;
    }
    void epmovePiece(ChessPiece from, std::pair<int, int> newLocation, std::pair<int, int> takenPieceLocation) {
        //for en passant
        auto beforeLocation = from.getpieceLocation();
        setPiece(from, newLocation);

        setPiece(ChessPiece(), takenPieceLocation);
        setPiece(ChessPiece(), beforeLocation);
        latestMoveLocation = newLocation;
    }
    void castle(ChessPiece king, ChessPiece teammate, bool Kingside) {
        auto kingBeforeLocation = king.getpieceLocation();
        auto teammateBeforeLocation = teammate.getpieceLocation();
        if (Kingside) {
            setPiece(king, std::make_pair(kingBeforeLocation.first + 2, kingBeforeLocation.second));
            setPiece(teammate, std::make_pair(teammateBeforeLocation.first - 2, teammateBeforeLocation.second));
            setPiece(ChessPiece(), kingBeforeLocation);
            setPiece(ChessPiece(), teammateBeforeLocation);
        }
        else {
            setPiece(king, std::make_pair(kingBeforeLocation.first - 2, kingBeforeLocation.second));
            setPiece(teammate, std::make_pair(teammateBeforeLocation.first + 3, teammateBeforeLocation.second));
            setPiece(ChessPiece(), kingBeforeLocation);
            setPiece(ChessPiece(), teammateBeforeLocation);
        }
    }
    ChessPiece getKing(Colour kingColour) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (getPiece(std::make_pair(j, i)).getColour() == kingColour && getPiece(std::make_pair(j, i)).getPieceType() == PieceType::KING) {
                    return getPiece(std::make_pair(j, i));
                }
            }
        }
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
                    //if (latestMoveLocation.second == 3 && getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN && )
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
                if (pieceLocation.second == newPieceLocation.second) {
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
                if (pieceLocation.second == newPieceLocation.second) {
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
    std::pair<int, int> latestMoveLocation;
    
    
    bool isMoveCheck(std::pair<int, int> pieceLocation, std::pair<int, int> newPieceLocation) {
        Colour enemykingColour = (chessboard.getPiece(pieceLocation).getColour() == Colour::BLACK) ? Colour::WHITE : Colour::BLACK;
        return chessboard.isMoveLegal(newPieceLocation, chessboard.getKing(enemykingColour).getpieceLocation(), true);
    }
    bool isMoveCheckmate(Colour colourincheck, std::pair<int, int> checkingPieceLocation) {
        Colour checkedKingColour = (colourincheck == Colour::BLACK) ? Colour::WHITE : Colour::BLACK;
        ChessPiece checkedKing = chessboard.getKing(checkedKingColour);
        //check for a piece that can take the piece checking the king
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (chessboard.getBoard()[j][i].getColour() == colourincheck) {
                    if (chessboard.getBoard()[j][i].getColour() == currentTurn) {
                        if (chessboard.isMoveLegal(chessboard.getBoard()[j][i].getpieceLocation(), checkingPieceLocation, true) && std::make_pair(j, i) != checkingPieceLocation) {
                            if (chessboard.getBoard()[j][i].getPieceType() == PieceType::KING) {
                                //the king can take the piece, but will he still be in check?
                                for (int m = 0; i < 8; i++)
                                {
                                    for (int n = 0; j < 8; j++)
                                    {                                        
                                        if (chessboard.getBoard()[j][i].getColour() != colourincheck) {
                                            if (chessboard.isMoveLegal(chessboard.getBoard()[j][i].getpieceLocation(), checkingPieceLocation, true)) {
                                                return true;
                                            }
                                            else continue;
                                        }
                                        else continue;

                                    }
                                }
                            }
                            //but, if he is not in check after that,
                            return false;
                        }
                        else continue;
                    }
                    else continue;
                }
                else continue;
            }
        }
        //now see if that piece can be blocked or the king can move away
        std::vector<std::pair<int, int>> possiblekingLocations = {
            std::make_pair(checkedKing.getpieceLocation().first + 1, checkedKing.getpieceLocation().second),
            std::make_pair(checkedKing.getpieceLocation().first - 1, checkedKing.getpieceLocation().second),
            std::make_pair(checkedKing.getpieceLocation().first, checkedKing.getpieceLocation().second + 1),
            std::make_pair(checkedKing.getpieceLocation().first, checkedKing.getpieceLocation().second - 1),
            std::make_pair(checkedKing.getpieceLocation().first + 1, checkedKing.getpieceLocation().second + 1),
            std::make_pair(checkedKing.getpieceLocation().first + 1, checkedKing.getpieceLocation().second - 1),
            std::make_pair(checkedKing.getpieceLocation().first - 1, checkedKing.getpieceLocation().second + 1),
            std::make_pair(checkedKing.getpieceLocation().first - 1, checkedKing.getpieceLocation().second - 1),
        };
        //cleanup        
        for (auto i = possiblekingLocations.begin(); i != possiblekingLocations.end();) {
            if ((*i).first < 0 || (*i).first > 7 || (*i).second < 0 || (*i).second > 7) {
                i = possiblekingLocations.erase(i);
            }
            else if (chessboard.getPiece((*i)).getColour() == colourincheck) {
                i = possiblekingLocations.erase(i);
            }
            else {
                ++i;
            }
        }

        for (int i = 0; i < possiblekingLocations.size(); i++) {
            if (chessboard.isMoveLegal(checkingPieceLocation, possiblekingLocations[i], true)) {
                return true;
            }
        }
        //find the movement between the checking piece and the king
        std::vector<std::pair<int, int>> gridMovement;
        switch (chessboard.getPiece(checkingPieceLocation).getPieceType()) {
        case PieceType::KNIGHT:
            //there is no movement that can be blocked, and since we ruled out it being taken, it's definitely checkmate
            return true;
            break;
        case PieceType::BISHOP:
        {
            if (checkingPieceLocation.first > checkedKing.getpieceLocation().first) {
                //moving to the left
                if (checkingPieceLocation.second > checkedKing.getpieceLocation().second) {
                    //moving upwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first - i, checkingPieceLocation.second - i));
                    }

                }
                else {
                    //moving downwards
                    for (int i = 1; i < checkedKing.getpieceLocation().second - checkingPieceLocation.second; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first - i, checkingPieceLocation.second + i));
                    }

                }
            }
            else {
                //moving to the right
                if (checkingPieceLocation.second > checkedKing.getpieceLocation().second) {
                    //moving upwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        //check if empty
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first + i, checkingPieceLocation.second - i));
                    }

                }
                else {
                    //moving downwards
                    for (int i = 1; i < checkedKing.getpieceLocation().second - checkingPieceLocation.second; i++)
                    {
                        //check if empty
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first + i, checkingPieceLocation.second + i));

                        // finally, if it is possible

                    }
                }
                
            }
            break;
        }
        case PieceType::ROOK:
        {
            if (checkingPieceLocation.first == checkedKing.getpieceLocation().first) {
                //moving on the y axis
                if (checkingPieceLocation.second > checkedKing.getpieceLocation().second) {
                    //moving upwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first, checkingPieceLocation.second - i));
                    }

                }
                else {
                    //moving downwards
                    for (int i = 1; i < checkedKing.getpieceLocation().second - checkingPieceLocation.second; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first, checkingPieceLocation.second + i));
                    }

                }
            }
            else {
                //moving on the x axis
                if (checkingPieceLocation.first > checkedKing.getpieceLocation().first) {
                    //moving left
                    for (int i = 1; i < checkingPieceLocation.first - checkedKing.getpieceLocation().first; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first - i, checkingPieceLocation.second));
                    }

                }
                else {
                    //moving right
                    for (int i = 1; i < checkedKing.getpieceLocation().first - checkingPieceLocation.first; i++)
                    {                        
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first + i, checkingPieceLocation.second));
                    }
                }

            }
            break;
        }
        case PieceType::QUEEN: 
        {
            if (checkingPieceLocation.first > checkedKing.getpieceLocation().first) {
                //moving to the left
                if (checkingPieceLocation.second == checkedKing.getpieceLocation().second) {
                    for (int i = 1; i < checkingPieceLocation.first - checkedKing.getpieceLocation().first; i++) {
                        //check if empty
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first - i, checkingPieceLocation.second));
                    }
                }
                else if (checkingPieceLocation.second > checkedKing.getpieceLocation().second) {
                    //moving upwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first - i, checkingPieceLocation.second - i));
                    }
                    
                }
                else {
                    //moving downwards
                    for (int i = 1; i < checkedKing.getpieceLocation().second - checkingPieceLocation.second; i++)
                    {                        
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first - i, checkingPieceLocation.second + i));
                    }
                    
                }
            }
            else if (checkingPieceLocation.first < checkedKing.getpieceLocation().first) {
                //moving to the right
                if (checkingPieceLocation.second == checkedKing.getpieceLocation().second) {
                    for (int i = 1; i < checkedKing.getpieceLocation().first - checkingPieceLocation.first; i++) {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first + i, checkingPieceLocation.second));
                                         
                    }
                }
                if (checkingPieceLocation.second > checkedKing.getpieceLocation().second) {
                    //moving upwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first + i, checkingPieceLocation.second - i));

                        }        
                    
                    
                }
                else {
                    //moving downwards
                    for (int i = 1; i < checkedKing.getpieceLocation().second - checkingPieceLocation.second; i++)
                    {
                        //check if empty
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first + i, checkingPieceLocation.second + i));
                        
                    }

                }
            }
            else if (checkingPieceLocation.first == checkedKing.getpieceLocation().first) {
                //moving in the y-axis
                if (checkingPieceLocation.second > checkedKing.getpieceLocation().second) {
                    //moving upwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        //check if empty
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first, checkingPieceLocation.second - i));
                    }
                    
                }
                else {
                    //moving downwards
                    for (int i = 1; i < checkingPieceLocation.second - checkedKing.getpieceLocation().second; i++)
                    {
                        
                        gridMovement.push_back(std::make_pair(checkingPieceLocation.first, checkingPieceLocation.second + i));
                            
                    }
                    
                }
            }
            break;
        }
        case PieceType::PAWN:
            //there is no intermediate movement between a pawn and a king, and since we ruled out it being taken, it's definitely checkmate
            return true;
        case PieceType::KING:
            //There is no way this should be activated, send out an error message
            std::cout << "Error!, check back at IsMoveCheckmate function";
            break;
        };
        //do some cleanup
        for (auto i = gridMovement.begin(); i != gridMovement.end();) {
            if ((*i) == checkingPieceLocation || (*i) == checkedKing.getpieceLocation()) {
                i = gridMovement.erase(i);
            }            
            else {
                ++i;
            }
        }
        //now, for those places of movement, find a piece that can block it
        for (int grids = 0; grids < gridMovement.size(); grids++) {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {                    
                    if (chessboard.getBoard()[j][i].getColour() == currentTurn) {
                        if (chessboard.isMoveLegal(chessboard.getBoard()[j][i].getpieceLocation(), gridMovement[grids], false)) {
                            return false;
                        }
                        else continue;
                    }
                    else continue;                    
                }
            }
        }
        //finally, with no pieces to block the path, with no pieces to take the checking piece, and the king not able to move anywhere, it is checkmate.
        return true;
    }


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
                if (movingPiece.getPieceType() == PieceType::EMPTY) {
                    //if it returns nothing.
                    continue;
                }

                switch (currentTurn) {
                case Colour::WHITE:
                    if (newLocation.second == 0) {
                        std::cout << "Your pawn must be promoted" << std::endl;
                        continue;
                    }
                    break;
                case Colour::BLACK:
                    if (newLocation.second == 7) {
                        std::cout << "Your pawn must be promoted" << std::endl;
                        continue;
                    }
                    break;
                }
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
                if (playerInput == "0-0") {
                    //king side castling
                    std::pair<int, int>kingLocation = chessboard.getKing(currentTurn).getpieceLocation();
                    std::pair<int, int>rookLocation = std::make_pair(kingLocation.first + 3, kingLocation.second);
                    switch (currentTurn){
                    case Colour::WHITE:
                        
                        if (kingLocation == std::make_pair(4, 7) && latestMoveLocation != std::make_pair(4, 7) && rookLocation == std::make_pair(7, 7) && latestMoveLocation != std::make_pair(7, 7) && chessboard.getPiece(std::make_pair(5, 7)).getPieceType() == PieceType::EMPTY && chessboard.getPiece(std::make_pair(6, 7)).getPieceType() == PieceType::EMPTY) {
                            castleMove(chessboard.getPiece(kingLocation), chessboard.getPiece(rookLocation), true);
                        }
                        else {
                            std::cout << "Castling could not be done." << std::endl;
                        }
                        break;
                    case Colour::BLACK:
                        if (kingLocation == std::make_pair(4, 0) && latestMoveLocation != std::make_pair(4, 0) && rookLocation == std::make_pair(7, 0) && latestMoveLocation != std::make_pair(7, 0) && chessboard.getPiece(std::make_pair(5, 0)).getPieceType() == PieceType::EMPTY && chessboard.getPiece(std::make_pair(6, 0)).getPieceType() == PieceType::EMPTY) {
                            castleMove(chessboard.getPiece(kingLocation), chessboard.getPiece(rookLocation), true);
                        }
                        else {
                            std::cout << "Castling could not be done." << std::endl;
                        }
                        break;
                    }
                    continue;
                }
                else {
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
                        newLocation = std::make_pair(int(playerInput[0]) - 97, 8 - atoi(&playerInput[1]));
                        switch (currentTurn) {
                        case Colour::WHITE:
                            if (newLocation.second == 0) {
                                //promotion by movement
                                ChessPiece movingPiece = findMovablePiece(PieceType::PAWN, newLocation, false);
                                if (movingPiece.getPieceType() == PieceType::EMPTY) {
                                    //if it returns nothing.
                                    continue;
                                }
                                switch (playerInput[2]) {
                                case 'B':
                                    promoteMove(movingPiece, newLocation, PieceType::BISHOP);
                                    continue;
                                case 'Q':
                                    promoteMove(movingPiece, newLocation, PieceType::QUEEN);
                                    continue;
                                case 'N':
                                    promoteMove(movingPiece, newLocation, PieceType::KNIGHT);
                                    continue;
                                case 'R':
                                    promoteMove(movingPiece, newLocation, PieceType::ROOK);
                                    continue;

                                }
                            }
                            else {
                                std::cout << "Invalid movement" << std::endl;
                                continue;
                            }
                        case Colour::BLACK:
                            if (newLocation.second == 7) {
                                //promotion by movement
                                ChessPiece movingPiece = findMovablePiece(PieceType::PAWN, newLocation, false);
                                if (movingPiece.getPieceType() == PieceType::EMPTY) {
                                    //if it returns nothing.
                                    continue;
                                }
                                switch (playerInput[2]) {
                                case 'B':
                                    promoteMove(movingPiece, newLocation, PieceType::BISHOP);
                                    continue;
                                case 'Q':
                                    promoteMove(movingPiece, newLocation, PieceType::QUEEN);
                                    continue;
                                case 'N':
                                    promoteMove(movingPiece, newLocation, PieceType::KNIGHT);
                                    continue;
                                case 'R':
                                    promoteMove(movingPiece, newLocation, PieceType::ROOK);
                                    continue;

                                }
                            }
                            else {
                                std::cout << "Invalid movement" << std::endl;
                                continue;
                            }
                        }
                    }
                    if (movingPiece.getPieceType() == PieceType::EMPTY) {
                        //if it returns nothing.
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
            }
            else if (playerInput.length() == 4) {

                if (playerInput[1] == 'x') {
                    std::pair<int, int>newLocation = std::make_pair(int(playerInput[2]) - 97, 8 - atoi(&playerInput[3]));
                    ChessPiece movingPiece;
                    if (chessboard.getPiece(newLocation).getPieceType() != PieceType::EMPTY) {

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
            else if (playerInput.length() == 5) {
            if (playerInput == "0-0-0") {
                std::pair<int, int>kingLocation = chessboard.getKing(currentTurn).getpieceLocation();
                std::pair<int, int>rookLocation = std::make_pair(kingLocation.first - 4, kingLocation.second);
                switch (currentTurn) {
                case Colour::WHITE:

                    if (kingLocation == std::make_pair(4, 7) && latestMoveLocation != std::make_pair(4, 7) && rookLocation == std::make_pair(0, 7) && latestMoveLocation != std::make_pair(0, 7) && chessboard.getPiece(std::make_pair(1, 7)).getPieceType() == PieceType::EMPTY && chessboard.getPiece(std::make_pair(2, 7)).getPieceType() == PieceType::EMPTY && chessboard.getPiece(std::make_pair(3, 7)).getPieceType() == PieceType::EMPTY)  {
                        castleMove(chessboard.getPiece(kingLocation), chessboard.getPiece(rookLocation), false);
                    }
                    else {
                        std::cout << "Castling could not be done." << std::endl;
                    }
                    break;
                case Colour::BLACK:
                    if (kingLocation == std::make_pair(4, 0) && latestMoveLocation != std::make_pair(4, 0) && rookLocation == std::make_pair(0, 0) && latestMoveLocation != std::make_pair(0, 0) && chessboard.getPiece(std::make_pair(1, 0)).getPieceType() == PieceType::EMPTY && chessboard.getPiece(std::make_pair(2, 0)).getPieceType() == PieceType::EMPTY && chessboard.getPiece(std::make_pair(3, 0)).getPieceType() == PieceType::EMPTY) {
                        castleMove(chessboard.getPiece(kingLocation), chessboard.getPiece(rookLocation), false);
                    }
                    else {
                        std::cout << "Castling could not be done." << std::endl;
                    }
                    break;
                }
                continue;
            }
            else {
                std::pair<int, int>newLocation = std::make_pair(int(playerInput[2]) - 97, 8 - atoi(&playerInput[3]));
                if (playerInput[1] == 'x') {
                    //pawn promotion by taking a piece
                    PieceType choice;
                    switch (playerInput[4]) {
                    case 'B':
                        choice = PieceType::BISHOP;
                        break;
                    case 'Q':
                        choice = PieceType::QUEEN;
                        break;
                    case 'N':
                        choice = PieceType::KNIGHT;
                        break;
                    case 'R':
                        choice = PieceType::ROOK;
                        break;
                    default:
                        std::cout << "Invalid input" << std::endl;
                        continue;
                    }
                    switch (playerInput[0]) {
                    case 'a': {
                        if (chessboard.getPiece(newLocation).getColour() == Colour::WHITE) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(0, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(0, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(0, i)).getpieceLocation(), newLocation, true)) {
                                        promoteMove(chessboard.getPiece(std::make_pair(0, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getBoard()[0][i], newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(1, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(1, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(2, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(2, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(3, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(3, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(4, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(4, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(5, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(5, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(6, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(6, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(7, i)), newLocation, choice);
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
                                        promoteMove(chessboard.getPiece(std::make_pair(7, i)), newLocation, choice);
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
            }
}
            else if (playerInput.length() == 9) {
            //en passant
            if (playerInput[1] == 'x' && playerInput[5] == 'e' && playerInput[6] == '.' && playerInput[7] == 'p' && playerInput[8] == '.') {
                std::pair<int, int>newLocation = std::make_pair(int(playerInput[2]) - 97, 8 - atoi(&playerInput[3]));
                
                if (chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                    switch (playerInput[0]) {

                    case 'a': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(0, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(0, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(0, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(0, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(0, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(0, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(0, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getBoard()[0][i], newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'b': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(1, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(1, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(1, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(1, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(1, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(1, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(1, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(1, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'c': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(2, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(2, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(2, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(2, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(2, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(2, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(2, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(2, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'd': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(3, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(3, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(3, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(3, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(3, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(3, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(3, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(3, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'e': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(4, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(4, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(4, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(4, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(4, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(4, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(4, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(4, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'f': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(5, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(5, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(5, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(5, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(5, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(5, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(5, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(5, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'g': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(6, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(6, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(6, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(6, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(6, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(6, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(6, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(6, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        break;
                    }
                    case 'h': {
                        if (chessboard.getPiece(latestMoveLocation).getColour() == Colour::WHITE && latestMoveLocation.second == 4) {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(7, i)).getColour() == Colour::BLACK && chessboard.getPiece(std::make_pair(7, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(7, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(7, i)), newLocation, latestMoveLocation);
                                    }
                                    else continue;
                                }
                                else continue;
                            }
                        }
                        else {
                            for (int i = 0; i < 8; i++) {
                                if (chessboard.getPiece(std::make_pair(7, i)).getColour() == Colour::WHITE && chessboard.getPiece(std::make_pair(7, i)).getPieceType() == PieceType::PAWN) {
                                    if (chessboard.isMoveLegal(chessboard.getPiece(std::make_pair(7, i)).getpieceLocation(), newLocation, true) && chessboard.getPiece(latestMoveLocation).getPieceType() == PieceType::PAWN) {
                                        epmakeMove(chessboard.getPiece(std::make_pair(7, i)), newLocation, latestMoveLocation);
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
            }
                }
                else {
                std::cout << "Invalid input" << std::endl;
                continue;
}
        }
    }
    void promoteMove(ChessPiece from, std::pair<int, int> newPieceLocation, PieceType choice) {
        chessboard.promotePiece(from, newPieceLocation, choice);
        chessboard.resetBoard();
        chessboard.showBoard();
        bool checkEvent = isMoveCheck(from.getpieceLocation(), newPieceLocation);
        if (checkEvent) {
            std::cout << "In check" << std::endl;
            if (isMoveCheckmate(from.getColour(), newPieceLocation)) {
                std::string output = (from.getColour() == Colour::WHITE) ? "White has won." : "Black has won.";
                std::cout << output << std::endl;
                gameRunning = false;
            }
        }
        latestMoveLocation = newPieceLocation;
        switch (currentTurn) {
        case Colour::WHITE:
            currentTurn = Colour::BLACK;
            break;
        case Colour::BLACK:
            currentTurn = Colour::WHITE;
            break;
        }
    }
    void makeMove(ChessPiece from, std::pair<int, int> newPieceLocation) {        
        chessboard.movePiece(from, newPieceLocation);
        chessboard.resetBoard();
        chessboard.showBoard();
        bool checkEvent = isMoveCheck(from.getpieceLocation(), newPieceLocation);
        if (checkEvent) {
            std::cout << "In check" << std::endl;
            if (isMoveCheckmate(from.getColour(), newPieceLocation)) {
                std::string output = (from.getColour() == Colour::WHITE) ? "White has won." : "Black has won.";
                std::cout << output << std::endl;                 
                gameRunning = false;
            }
        }
        latestMoveLocation = newPieceLocation;
        switch (currentTurn) {
        case Colour::WHITE:
            currentTurn = Colour::BLACK;
            break;
        case Colour::BLACK:
            currentTurn = Colour::WHITE;
            break;
        }
    }
    void epmakeMove(ChessPiece from, std::pair<int, int> newPieceLocation, std::pair<int, int> takenPieceLocation) {
        chessboard.epmovePiece(from, newPieceLocation, takenPieceLocation);
        chessboard.resetBoard();
        chessboard.showBoard();
        bool checkEvent = isMoveCheck(from.getpieceLocation(), newPieceLocation);
        if (checkEvent) {
            std::cout << "In check" << std::endl;
            if (isMoveCheckmate(from.getColour(), newPieceLocation)) {
                std::string output = (from.getColour() == Colour::WHITE) ? "White has won." : "Black has won.";
                std::cout << output << std::endl;
                gameRunning = false;
            }
        }
        latestMoveLocation = newPieceLocation;
        switch (currentTurn) {
        case Colour::WHITE:
            currentTurn = Colour::BLACK;
            break;
        case Colour::BLACK:
            currentTurn = Colour::WHITE;
            break;
        }
    }
    void castleMove(ChessPiece king, ChessPiece teammate, bool kingSide) {
        if (kingSide) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chessboard.getBoard()[j][i].getPieceType() != PieceType::EMPTY && chessboard.getBoard()[j][i].getColour() != king.getColour() && chessboard.isMoveLegal(chessboard.getBoard()[j][i].getpieceLocation(), std::make_pair(king.getpieceLocation().first + 2, king.getpieceLocation().second), true)) {
                        //the castle will put the king in check, so it's not possible.
                        std::cout << "Castle not possible" << std::endl;
                        return;
                    }
                    else continue;
                }
            }
            chessboard.castle(king, teammate, kingSide);
        }
        else {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chessboard.getBoard()[j][i].getPieceType() != PieceType::EMPTY && chessboard.getBoard()[j][i].getColour() != king.getColour() && chessboard.isMoveLegal(chessboard.getBoard()[j][i].getpieceLocation(), std::make_pair(king.getpieceLocation().first - 2, king.getpieceLocation().second), true)) {
                        //the castle will put the king in check, so it's not possible.
                        std::cout << "Castle not possible" << std::endl;
                        return;
                    }
                    else continue;
                }
            }
            chessboard.castle(king, teammate, kingSide);
        }
        chessboard.resetBoard();
        chessboard.showBoard();
        latestMoveLocation = std::make_pair(NULL, NULL);
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
            return ChessPiece();
            
            
    }
};

int main() {
    std::cout << "Welcome to chess!\nUse normal chess algebraic notation.\nTo enter the game, just hit enter! (Remember white starts first)" << std::endl;
    std::cin.get();
    system("cls");
    ChessGame game;   
    game.newGame();
}
