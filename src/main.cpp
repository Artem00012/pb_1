//==============================================================================
///
/// @file
/// @brief Программа для робота Карела и стартовая функция
///
//==============================================================================


#include "karel.h"
#include <iostream>

void PickAllBeepers();
void TurnRight();
//==============================================================================
/// Программа для робота Карела
///
void KarelProgram() {
    bool is_even = false;
    while(FrontIsClear()){
        while(FrontIsClear()){
            PickAllBeepers();
            Move();
        }
        PickAllBeepers();
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

void PickAllBeepers(){
    while (BeepersPresent())
        PickBeeper();
}

void TurnRight(){
    for(int i = 0; i < 3; i++){
        TurnLeft();
    }
}
//==============================================================================
/// Стартовая функция
///
int main() {
    LoadWorld("worlds/CB_02.w");
    KarelProgram();
    Finish();
    return 0;
}