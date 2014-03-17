#include "trajectory.hh"

using namespace std;

namespace aidaTT
{
// the only constructor for a trajectory: known track parameters and trajectory elements
    trajectory::trajectory(const trackParameters& tp,
                           const vector<trajectoryElement>& elems,
                           IFittingAlgorithm* fa, IPropagation* pm, IGeometry* geom)
        : _referenceParameters(tp) , _fittingAlgorithm(fa) , _propagation(pm), _geometry(geom)
    {
        // copy the elements
        // TODO like this? trajectoryElements should know about their position?
//            _initialTrajectoryElements.resize(elems.size());
        //~ for(vector<trajectoryElement>::const_iterator elem = elems.begin(), last = elems.end(); elem < last; ++elem)
        //~ _initialTrajectoryElements.push_back(*elem);
    }



}
