#include "karel.h"
#include <iostream>


void PickAllBeepers();
void TurnRight();
void PutDoubleBeepers(int& beeper_cell);
void PickAllBeepers(int& beeper_cell);
void GrapAndPut(int& beeper_cell);

//==============================================================================
/// Программа для робота Карела
///
void KarelProgram() {
/// @todo Добавить программу для Карела
 bool is_even = false;
    int beeper_cell = 0;
    while(FrontIsClear()){
        while(FrontIsClear()){
            GrapAndPut(beeper_cell);
            Move();
        }
        GrapAndPut(beeper_cell);
        if(!is_even){
            TurnLeft();
            if(!FrontIsClear())
                return;
            Move();
            TurnLeft();

        }
        else{
            TurnRight();
            if(!FrontIsClear())
                return;
            Move();
            TurnRight();
        }
        is_even = !is_even;
        }

}

void PutDoubleBeepers(int& beeper_cell){
    for( ;beeper_cell > 0; beeper_cell--){
        for(int i = 0; i < 2; i++)
            PutBeeper();
    }

}

void PickAllBeepers(int& beeper_cell){
    while (BeepersPresent()){
        PickBeeper();
        beeper_cell++;
    }
}

void TurnRight(){
    for(int i = 0; i < 3; i++){
        TurnLeft();
    }
}

void GrapAndPut(int& beeper_cell){
    PickAllBeepers(beeper_cell);
    PutDoubleBeepers(beeper_cell);
}
int main() {
    LoadWorld("worlds/Double_beepers_01.w");
    KarelProgram();
    Finish();
    return 0;
}