#ifndef helixUtils_HH
#define helixUtils_HH

#include "trackParameters.hh"

/** Define helper function for accessing helix properties. 
 *  Typically all functions are defined once to take a trackParameters object
 *  and once to take a Vector5 with helix parameters and a Vector3D for the
 *  reference point if needed, so they can be used outside of aidaTT with
 *  little overhead.
 *
 *  @version $Id
 *  @author Ch. Rosemann, F. Gaede, DESY
 */

namespace aidaTT
{

  /// unsigned radius in xy-plane from helix parameters
  double calculateRadius(const Vector5& hp) ;

  /// unsigned radius in xy-plane - unsigned  from track parameters
  inline double calculateRadius(const trackParameters& tp) { 
    return calculateRadius( tp.parameters() ) ;
  }

  /// x-position of center of circle in xy-plane from helix parameters and reference point 
  double calculateXCenter(const Vector5& hp, const Vector3D& rp) ;


  /// x-position of center of circle in xy-plane from track parameters
  inline double calculateXCenter(const trackParameters& tp) {
    return calculateXCenter( tp.parameters() , tp.referencePoint() ) ;
  }

  /// y-position of center of circle in xy-plane from helix parameters and reference point 
  double calculateYCenter(const Vector5& hp, const Vector3D& rp) ;


  /// y-position of center of circle in xy-plane from track parameters
  inline double calculateYCenter(const trackParameters& tp) {
    return calculateYCenter( tp.parameters() , tp.referencePoint() ) ;
  }

  /// x-position of PCA in xy-plane from helix parameters and reference point 
  inline double calculateX0(const Vector5& hp, const Vector3D& rp) {

    return ( sin( - calculatePhi0(hp) ) * calculateD0(hp) ) + rp.x();
  }

  /// x-position of PCA in xy-plane from track parameters
  inline double calculateX0(const trackParameters& tp) {
    return calculateX0( tp.parameters() , tp.referencePoint() ) ; 
  }
  
  /// y-position of PCA in xy-plane from helix parameters and reference point 
  inline double calculateY0(const Vector5& hp, const Vector3D& rp) {
    return ( cos( calculatePhi0(hp) ) * calculateD0(hp) ) + rp.y();
  }

  /// y-position of PCA in xy-plane from track parameters
  inline double calculateY0(const trackParameters& tp) {
    return calculateY0( tp.parameters() , tp.referencePoint() ) ; 
  }
  
  /// azimuth angle at position x,y (on the track) from helix parameters and reference point 
  double calculatePhifromXY(double x, double y, const Vector5& hp, const Vector3D& rp) ;

  /// azimuth angle at position x,y (on the track) from track parameters
  inline double calculatePhifromXY(double x, double y, const trackParameters& tp) {
    return calculatePhifromXY( x, y, tp.parameters() , tp.referencePoint() ) ;
  }

  /// path length s at position x,y (on the track) from helix parameters and reference point 
  double calculateSfromXY(double x, double y, const Vector5& hp, const Vector3D& rp) ;

  /// path length s at position x,y (on the track) from track parameters
  inline double calculateSfromXY(double x, double y, const trackParameters& tp) {
    return calculateSfromXY( x, y, tp.parameters() , tp.referencePoint() ) ;
  }
  
  /// path length s at position x,y (on the track) from track parameters
  inline double calculateSfromXY(std::pair<double, double> xy, const trackParameters& tp){
    return calculateSfromXY( xy.first, xy.second, tp);
  }
  
  /// x-position at path length s from helix parameters and reference point 
  double calculateXfromS(double s, const Vector5& hp, const Vector3D& rp) ;

  /// x-position at path length s from track parameters
  inline double calculateXfromS(double s, const trackParameters& tp) {

    return calculateXfromS( s,  tp.parameters() , tp.referencePoint() ) ;
  }

  /// y-position at path length s from helix parameters and reference point 
  double calculateYfromS(double s, const Vector5& hp, const Vector3D& rp) ;

  /// y-position at path length s from track parameters
  inline double calculateYfromS(double s, const trackParameters& tp) {

    return calculateYfromS( s,  tp.parameters() , tp.referencePoint() ) ;
  }

  /// z-position at path length s from helix parameters and reference point 
  double calculateZfromS(double s, const Vector5& hp, const Vector3D& rp) ;

  /// z-position at path length s from track parameters
  inline double calculateZfromS(double s, const trackParameters& tp) {

    return calculateZfromS( s,  tp.parameters() , tp.referencePoint() ) ;
  }

    /// tangent to the track at path length s from helix parameters 
  Vector3D calculateTangent(double s, const Vector5& hp ) ;

  /// tangent to the track at path length s from track parameters
  inline Vector3D calculateTangent(double s, const trackParameters& tp){
    return calculateTangent( s,  tp.parameters() );
  }
  

  /// compute start parameters for a helix from three points, e.g. first, last and middle point )
  void calculateStartHelix(const Vector3D& x1, const Vector3D& x2,   const Vector3D& x3 , 
			   trackParameters& tp , bool backward = false) ;
  
  /// move the helix parameters to a new reference point 
  double moveHelixTo(trackParameters& tp,  const Vector3D& ref, bool updateCovMat=false) ;


  

  
}
#endif // HELIXGYMNASTICS_HH
