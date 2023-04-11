#define RUN_TESTS
#include <YSI_Core/y_testing>
#include <FCNPC>

Test:something(){
    new myFirstNPC = INVALID_PLAYER_ID;
    myFirstNPC = FCNPC_Create("FirstNPC");
    //FCNPC_Spawn(myFirstNPC, 0, 0.0, 0.0, 3.1);
}
