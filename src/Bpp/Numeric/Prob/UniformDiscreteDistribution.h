//
// File: UniformDiscreteDistribution.h
// Created by: Laurent Guéguen
// Created on: April 2010
//

/*
Copyright or © or Copr. CNRS, (2010)

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

#ifndef _UNIFORMDISCRETEDISTRIBUTION_H_
#define _UNIFORMDISCRETEDISTRIBUTION_H_

#include "AbstractDiscreteDistribution.h"
#include "../Constraints.h"
#include "../RandomTools.h"

namespace bpp
{

/**
 * @brief Discretized Uniform distribution.
 * All categories are equidistributed all along a given interval.
 *
 * @author Laurent Gueguen
 */
class UniformDiscreteDistribution:
  public AbstractDiscreteDistribution
{
private:
  std::vector<double> bounds_;

  double min_;
  double max_;
public:
    /**
     * @brief Build a new discretized uniform distribution.
     * @param n the number of categories to use.
     * @param min The minimun value (default 0)
     * @param max The maximum value (default 1)
     */
    UniformDiscreteDistribution(unsigned int n, double min = 0., double max = 1.);

    virtual ~UniformDiscreteDistribution();

    UniformDiscreteDistribution* clone() const { return new UniformDiscreteDistribution(*this); }
  
  public:
    Domain getDomain() const;
    void fireParameterChanged(const ParameterList & parameters);

  double getLowerBound() const { return max_;}
  double getUpperBound() const { return min_;}
  
  double randC() const throw (Exception)
    {
      return RandomTools::giveRandomNumberBetweenZeroAndEntry(max_-min_)+min_;
    }
    
protected:
  void applyParameters(unsigned int numberOfCategories);
  
};

} //end of namespace bpp.

#endif  //_UNIFORMDISCRETEDISTRIBUTION_H_
