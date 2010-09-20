//
// File: ConstantDistribution.h
// Created by: jdutheil <Julien.Dutheil@univ-montp2.fr>
// Created on: Fri Oct 24 08:48:03 2003
//

/*
Copyright or © or Copr. CNRS, (November 17, 2004)

This software is a computer program whose purpose is to provide classes
for numerical calculus.

This software is governed by the CeCILL  license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
*/

#ifndef _CONSTANTDISTRIBUTION_H_
#define _CONSTANTDISTRIBUTION_H_

#include "AbstractDiscreteDistribution.h"

namespace bpp
{

  /**
   * @brief Constant discrete distribution.
   *
   * Only one category with probability 1.0.
   */
  class ConstantDistribution :
    public AbstractDiscreteDistribution
  {
  private:
    double value_;
  public:
    /**
     * @brief Builds a new ConstantDistribution object from a
     *  value
     *
     * @param value
     * @param fixed tells if there is a parameter (named "value")
     * (default false means the value is a parameter).
     *
     */
    ConstantDistribution(double value, bool fixed=false);
    virtual ~ConstantDistribution() {}
  
#if defined(NO_VIRTUAL_COV)
    Clonable* clone() const
    {
      return new ConstantDistribution(*this);
    }
#else
    ConstantDistribution* clone() const
    {
      return new ConstantDistribution(*this);
    }
#endif
  
  public:
    Domain getDomain() const;
    void fireParameterChanged(const ParameterList & parameters);
    double randC() const throw (Exception) { return value_;}

    std::string getName() const;

    double getLowerBound() const{
      return value_;
    }
                               
    double getUpperBound() const{
      return value_;
    }
    
    /**
     * @brief Checks if the Parameters can respect the given
     * Constraint and optionnaly tries to modify their Constraints.
     *
     * @param c The Constraint to respect.
     * @param f boolean flag to say if the Constraints must be changed
     * (if possible) (default: true)
     *
     * @return true if the Constraint is an interval, and the
     * Parameter value accept the new Constraint, if needed.
     *
     * The constraint of Parameter value is changed to the given
     * Constraint.
     */
  
    bool adaptToConstraint(const Constraint& c, bool f=true);

    

  };
  
} //end of namespace bpp.

#endif  //_CONSTANTDISTRIBUTION_H_
