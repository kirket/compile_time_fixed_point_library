#ifndef SPUC_NOISE
#define SPUC_NOISE
// Copyright(c) 1993-1996 Tony Kirke
// author="Tony Kirke" *
/*
 * SPUC - Signal processing using C++ - A DSP library
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
/*!   \brief Gaussian noise routine
  \ingroup miscfunc random
*/
//!   Gaussian noise routine
//!   Can create (double) gaussian white noise
//!          or  (double) uniform noise
class noise
{   
	protected:
	char s;            //! Switch 
	double x;          //! Saved calculated value
    long idum;         //! Random seed
    
	public:                            
    //! Constructor
	noise(double i=1349555.0);						// Constructor
  	//! Gaussian noise
	double gauss();
	//! Uniform noise
	double uni();             
	//! Uniform noise
	double uniform();
	//!  Change seed
	void set_seed(unsigned i=1349555) { idum = i;}
} ;
#endif
