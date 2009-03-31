//
// File MultiSeqIndividual.h
// Author : Sylvain Gaillard
// Last modification : Tuesday August 03 2004
//

/*
   Copyright or � or Copr. CNRS, (November 17, 2004)

   This software is a computer program whose purpose is to provide classes
   for population genetics analysis.

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

#ifndef _MULTISEQINDIVIDUAL_H_
#define _MULTISEQINDIVIDUAL_H_

// From STL
#include <map>
#include <vector>

using namespace std;

// From Utils
#include <Utils/Clonable.h>
#include <Utils/Exceptions.h>

// From SeqLib
#include <Seq/Sequence.h>
#include <Seq/VectorSequenceContainer.h>
#include <Seq/SequenceExceptions.h>

// From PopGenLib
#include "Locality.h"
#include "Coord.h"
#include "Date.h"
#include "MultilocusGenotype.h"
#include "GeneralExceptions.h"

namespace bpp
{

  /**
   * @brief <center><b>*** UNUSED CLASS ***</b></center>The MultiSeqIndividual class.
   *
   * <center><b>*** UNUSED CLASS ***</b></center>
   * This class is designed to store data on a single individual.
   * This individual can store numerous sequence for each place. It was the first
   * working implementation which manages sequences as a map of sequence container.
   * We have replaced it with a simplest individual with only one sequence per
   * locus.
   *
   * @author Sylvain Gaillard
   */
  class MultiSeqIndividual
  {
    public: // Constructors and destructor :

      /**
       * @brief Build a void new MultiSeqIndividual.
       */
      MultiSeqIndividual();

      /**
       * @brief Build a new MultiSeqIndividual with an identifier.
       */
      MultiSeqIndividual(const string & id);

      /**
       * @brief Build a new MultiSeqIndividual with parameters.
       *
       * @param id The id of the MultiSeqIndividual as a string.
       * @param date The date of the MultiSeqIndividual as a Date object.
       * @param coord The coordinates of the MultiSeqIndividual as a Coord object.
       * @param locality The locality of the MultiSeqIndividual as a pointer to a Locality
       * object.
       * @param sex The sex of the MultiSeqIndividual as an unsigned short.
       */
      MultiSeqIndividual(const string & id,
          const Date & date,
          const Coord<double> & coord,
          Locality<double> * locality,
          const unsigned short sex);

      /**
       * @brief The MultiSeqIndividual copy constructor.
       */
      MultiSeqIndividual(const MultiSeqIndividual &ind);

      /**
       * @brief Destroy an MultiSeqIndividual.
       */
      virtual ~MultiSeqIndividual();

    public: // Methodes

      /**
       * @brief The MultiSeqIndividual copy operator.
       *
       * @return A ref toward the assigned MultiSeqIndividual.
       * Make a copy of each atribute of the MultiSeqIndividual.
       */
      MultiSeqIndividual & operator= (const MultiSeqIndividual & ind);

      /**
       * @brief Set the id of the MultiSeqIndividual.
       *
       * @param id The id of the MultiSeqIndividual as a string.
       */
      void setId(const string id);

      /**
       * @brief Get the id of the MultiSeqIndividual.
       *
       * @return The id of the MultiSeqIndividual as a string.
       */
      string getId() const;

      /**
       * @brief Set the sex of the MultiSeqIndividual.
       *
       * @param sex An unsigned short coding for the sex.
       */
      void setSex(const unsigned short sex);

      /**
       * @brief Get the sex of the MultiSeqIndividual.
       *
       * @return The sex of the MultiSeqIndividual as an unsigned short.
       */
      unsigned short getSex() const;

      /**
       * @brief Set the date of the MultiSeqIndividual.
       *
       * @param date The date as a Date object.
       */
      void setDate(const Date & date);

      /**
       * @brief Get the date of the MultiSeqIndividual.
       *
       * @return A pointer toward a Date object if the MultiSeqIndividual has a date.
       * Otherwise throw a NullPointerException.
       */
      const Date * getDate() const throw (NullPointerException);

      /**
       * @brief Tell if this MultiSeqIndividual has a date.
       */
      bool hasDate() const;

      /**
       * @brief Set the coodinates of the MultiSeqIndividual.
       *
       * @param coord A Coord object.
       */
      void setCoord(const Coord<double> & coord);

      /**
       * @brief Set the coordinates of the MultiSeqIndividual.
       *
       * @param x The X coordinate as a double.
       * @param y The Y coordinate as a double.
       */
      void setCoord(const double x, const double y);

      /**
       * @brief Get the coordinates of the Induvidual.
       *
       * @return A pointer toward a Coord object if the MultiSeqIndividual has
       * coordinates. Otherwise throw a NullPointerException.
       */
      const Coord<double> * getCoord() const throw(NullPointerException);

      /**
       * @brief Tell if this MultiSeqIndividual has coordinates.
       */
      bool hasCoord() const;

      /**
       * @brief Set the X coordinate of the MultiSeqIndividual.
       *
       * @param x The X coordinate as a double.
       *
       * Set the X coordinate if the MultiSeqIndividual has coordinates.
       * Otherwise throw a NullPointerException.
       */
      void setX(const double x) throw(NullPointerException);

      /**
       * @brief Set the Y coordinate of th MultiSeqIndividual.
       *
       * @param y The Y coordinate as a double.
       *
       * Set the Y coordinate if the MultiSeqIndividual has coordinates.
       * Otherwise throw a NullPointerException.
       */
      void setY(const double y) throw(NullPointerException);

      /**
       * @brief Get the X coordinate of the MultiSeqIndividual.
       *
       * @return The X coordinate as a double if the MultiSeqIndividual has coordinates.
       * Otherwise throw a NullPointerException.
       */
      double getX() const throw(NullPointerException);

      /**
       * @brief Get the Y coordinate of the MultiSeqIndividual.
       *
       * @return The Y coordinate as a double if the MultiSeqIndividual has coordinates.
       * Otherwise throw a NullPointerException.
       */
      double getY() const throw(NullPointerException);

      /**
       * @brief Set the locality of the MultiSeqIndividual.
       *
       * @param locality A pointer to a Locality object.
       */
      void setLocality(const Locality<double> * locality);

      /**
       * @brief Get the locality of the MultiSeqIndividual.
       *
       * @return A pointer to the Locality of the MultiSeqIndividual.
       */
      const Locality<double> * getLocality() const throw (NullPointerException);

      /**
       * @brief Tell if this MultiSeqIndividual has a locality.
       */
      bool hasLocality() const;

      /**
       * @brief Get a pointer to the VectorSequenceContainer at a named locus.
       *
       * @param id The id of the sequence set (i.e. locus).
       */
      const VectorSequenceContainer * getVectorSequenceContainer(const string & id) const
        throw (Exception);

      /**
       * @brief Add a sequence in a named sequence set.
       *
       * @param id The id of the sequence set.
       * @param sequence The sequence to add.
       * @throw AlphabetMismatchException if the sequence's alphabet doesn't match the container's alphabet.
       * @throw BadIdentifierException if sequence's name is already in use.
       */
      void addSequence(const string & id, const Sequence & sequence)
        throw (Exception);

      /**
       * @brief Get a named sequence from a named sequence set.
       *
       * @param id The id of the sequence set.
       * @param name The name of the sequence.
       *
       * @return A pointer to the sequence.
       */
      const Sequence * getSequence(const string & id, const string & name)
        const throw(Exception);

      /**
       * @brief Get an indexed sequence from a named sequence set.
       *
       * @param id The id of the sequence set.
       * @param i The index of the sequence in the sequence set.
       *
       * @return A pointer tothe sequence.
       */
      const Sequence * getSequence(const string & id, const unsigned int i)
        const throw(Exception);

      /**
       * @brief Get the sequence set ids.
       *
       * @return All the keys of the sequence sets in a vector.
       */
      vector<string> getSequencesKeys() const;

      /**
       * @brief Remove a named sequence from a named sequence set.
       *
       * @param id The id of the sequence set.
       * @param name The name of the sequence.
       *
       * @return A pointer to a copy of the removed sequence.
       */
      Sequence * removeSequence(const string & id, const string & name);

      /**
       * @brief Delete a named sequence from a named sequence set.
       *
       * @param id The id of the sequence set.
       * @param name The name of the sequence.
       */
      void deleteSequence(const string & id, const string & name);

      /**
       * @brief Tell if the MultiSeqIndividual has some sequences.
       */
      bool hasSequences() const;

      /**
       * @brief Count the number of sequece set.
       */
      unsigned int getNumberOfSequenceSet() const;

      /**
       * @brief Get the number of sequences in a sequence set.
       */
      unsigned int getNumberOfSequences(const string & id) const
        throw (Exception);

      /**
       * @brief Add a genotype.
       *
       * @param genotype The MultilocusGenotype to add.
       */
      void addGenotype(const MultilocusGenotype & genotype);

      /**
       * @brief Get the genotype.
       */
      const MultilocusGenotype * getGenotype() const throw (NullPointerException);

      /**
       * @brief Tell if the MultiSeqIndividual has a MultilocusGenotype.
       */
      bool hasGenotype() const;

    protected:
      string _id;
      unsigned short _sex;
      Date * _date;
      Coord<double> * _coord;
      const Locality<double> * _locality;
      map<string,VectorSequenceContainer *> _sequences;
      MultilocusGenotype * _genotype;
  };

} //end of namespace bpp;

#endif // _MULTISEQINDIVIDUAL_H_

