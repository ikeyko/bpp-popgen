/*
 * File Genetix.h
 * Author : Sylvain Gaillard <yragael2001@yahoo.fr>
 * Last modification : Friday July 30 2004
 *
 * Copyright (C) 2004 Sylvain Gaillard and the
 *                    PopLib Development Core Team
 *
 * This file is part of PopLib.
 *
 * PopLib is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * PopLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PopLib; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// Secured inclusion of header's file
#ifndef _GENETIX_H_
#define _GENETIX_H_

// From Utils
#include <Utils/TextTools.h>
#include <Utils/FileTools.h>
#include <Utils/Exceptions.h>
#include <Utils/StringTokenizer.h>

// From local Pop
#include "AbstractIDataSet.h"
#include "BasicAlleleInfo.h"

/**
 * @brief The Genetix input format for poplib.
 */
class Genetix : public AbstractIDataSet {

	public: // Constructor and destructor
		Genetix();
		~Genetix();

	public:
		/**
		 * @name The IDataSet interface.
		 * @{
		 */
		void read(istream & is, DataSet & data_set) throw (Exception);
		void read(const string & path, DataSet & data_set) throw (Exception);
		DataSet * read(istream & is) throw (Exception);
		DataSet * read(const string & path) throw (Exception);
		/**
		 * @}
		 */

		/**
		 * @name The IODataSet interface
		 * @{
		 */
		virtual const string getFormatName();
		virtual const string getFormatDescription();
		/**
		 * @}
		 */
};

#endif // _GENETIX_H_