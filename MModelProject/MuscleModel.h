#include "MaralMuscle.h"
#include <OpenSim/Simulation/Model/Model.h>

#include <math.h>



using namespace std;
using namespace OpenSim;
using namespace SimTK;




void MaralMuscle::constructProperties()
{
    constructProperty_fiber_damping(0.1); //damped model used by default
    constructProperty_default_activation(0.1);
    constructProperty_default_fiber_length(getOptimalFiberLength());

    constructProperty_activation_time_constant(0.010);
    constructProperty_deactivation_time_constant(0.040);
    constructProperty_minimum_activation(0.01);

    constructProperty_maximum_pennation_angle(acos(0.1));

    constructProperty_ActiveForceLengthCurve(ActiveForceLengthCurve());
    constructProperty_ForceVelocityCurve(ForceVelocityCurve());
    constructProperty_FiberForceLengthCurve(FiberForceLengthCurve());
    constructProperty_TendonForceLengthCurve(TendonForceLengthCurve());

    setMinControl(get_minimum_activation());
}