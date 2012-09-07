//
// File: IOParametrizable.h
// Created by: Laurent Guéguen
// Created on: lundi 3 septembre 2012, à 14h 35
//

/*
  Copyright or © or Copr. CNRS, (November 16, 2004)

  This software is a computer program whose purpose is to provide classes
  for phylogenetic data analysis.

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

#ifndef _IOPARAMETRIZABLE_H_
#define _IOPARAMETRIZABLE_H_

#include "../Numeric/ParameterAliasable.h"

#include <Bpp/Exceptions.h>
#include "IoFormat.h"
#include "OutputStream.h"

#include <map>
namespace bpp
{
  /**
   * @brief General interface for parametrizable Output.
   */
  class IOParametrizable:
    public virtual IOFormat
  {
  public:
    IOParametrizable() {}
    virtual ~IOParametrizable() {}

  public:
    virtual const std::string getDataType() const { return "Parametrizable"; }
  };

//  /**
//   * @brief General interface for distance matrix readers.
//   */
//  class IParametrizable:
//    public virtual IOParametrizable
//  {
//  public:
//    IParametrizable() {}
//    virtual ~IParametrizable() {}
//
//  public:
//    /**
//     * @brief Read a discrete distribution from a string.
//     *
//     * @param distrlDescription A string describing the distribution in the format.
//     * @param unparsedParameterValues [out] a map that will contain
//     *                                all the distribution parameters names
//     *                                and their corresponding unparsed
//     *                                value, if they were found.
//     * @param verbose Print some info to the 'message' output stream.
//     * @return A new Parametrizable object according to options specified.
//     * @throw Exception if an error occured.
//     */
//
//    virtual Parametrizable* read(const std::string& distrDescription,
//                                       std::map<std::string, std::string>& unparsedParameterValues,
//                                       bool verbose) = 0;
//
//  };
//

  /**
   * @brief General interface writers.
   */
  class OParametrizable:
    public virtual IOParametrizable
  {
  public:
    OParametrizable() {}
    virtual ~OParametrizable() {}

  public:
    /**
     * @brief Write a Parametrizable to a stream.
     *
     * @param param A pointer to a Parametrizable object;
     * @param out The output stream;
     * @param names the names of the parameters to be written;
     * @param writtenNames is the vector of the written
     *        parameters so far [in, out];
     * @param printComma boolean if a comma should be written at the
     *        beginning of the description.
     */
    
    virtual void write(const Parametrizable* parametrizable,
                       OutputStream& out,
                       const std::vector<std::string>& names,
                       std::vector<std::string>& writtenNames,
                       bool printComma=false) const = 0;
 
    /**
     * @brief Write a ParameterAliasable to a stream.
     *
     * @param param A pointer to a Parametrizable object;
     * @param out The output stream;
     * @param globalAliases parameters linked to global alias; 
     * @param names the names of the parameters to be written;
     * @param writtenNames is the vector of the written
     *        parameters so far [in, out];
     * @param printLocalAliases boolean if local aliases should be written;
     * @param printComma boolean if a comma should be written at the
     *        beginning of the description.
     */
    
    virtual void write(const ParameterAliasable* parametrizable,
                       OutputStream& out,
                       std::map<std::string, std::string>& globalAliases,
                       const std::vector<std::string>& names,
                       std::vector<std::string>& writtenNames,
                       bool printLocalAliases = true,
                       bool printComma=false) const = 0;
  };


} //end of namespace bpp.

#endif //_IOPARAMETRIZABLE_H_

