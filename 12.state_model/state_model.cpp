#include "state_model.h"


Work::Work()
{
    currentState = new ForenoonState();
    Hour = 8;
    WorkFinish=false;
}
