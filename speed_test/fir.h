// 
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
#ifndef _FIR_H
#define _FIR_H
/*! 
  \addtogroup fir FIR filters
*/

/*!  
  \brief  Template Class for Modeling a Finite Impulse Response filter. 
  \ingroup fir
*/
//!  Template works for double, long, complex, etc
//!  Taps initialized to zeros.
//! \image html fir.gif
//! \image latex fir.eps
template <class Numeric> class fir
{
 public: 
  Numeric* coeff;
  Numeric* z; 
  long num_taps;
  Numeric output;
  
 public: 
  //! Set tap weights
  void settap(long i, Numeric tap) { coeff[i] = tap; }  
  //! Reset
  void reset() { 	
	for (int i=0;i<num_taps;i++) z[i] = 0;  
	output = 0;
  }
  //! Get sum of coefficients
  Numeric coeff_sum() { 
	  int i;
	  Numeric s;
	  for (s=0,i=0;i<num_taps;i++) s += coeff[i];
	  return(s);
  }
  //! Get current output
  Numeric out() { return(output); }
  //! Clock in new sample & compute current output
  Numeric check(long i) { return(z[i]); }
  ~fir(void) {
	if (num_taps>0) {
	  delete [] z;
	  delete [] coeff;
	}
  }
  //! Constructor
  fir(void) : coeff(NULL), z(NULL) { ;};
  //! Constructor
  fir(long n) : coeff(NULL), z(NULL), num_taps(n)
	{
	  int i;
	  if (n>0) {
		coeff = new Numeric[n];	
		z = new Numeric[n];
		for (i=0;i<n;i++) z[i] = coeff[i] = 0;  
	  }
	}
  //! Set size of Filter 
  void set_size(long n) 
	{
	  int i;
	  num_taps = n;
	  if (n>0) {
		coeff = new Numeric[n];
		z = new Numeric[n];
		for (i=0;i<n;i++) z[i] = coeff[i] = 0;
	  }
	}
  long get_size(void) { return(num_taps); }
  //!  Constructor that gets coefficients from file (requires fir.cpp) 
  //fir(const char* file) { read_taps(file); };               
  //! Update filter by inputting 1 sample and returning convolved output sample.
  Numeric clock(Numeric in) { return(update(in)); }
  Numeric update(Numeric in) {
	int i;                                                       
	// Update history of inputs
	for (i=num_taps-1;i>0;i--) z[i] = z[i-1];  
	// Add new input
	z[0] = in;   
	// Perform FIR
	for (output=0,i=0;i<num_taps;i++) {
		output += coeff[i]*z[i];
		//std::cout << coeff[i] << " " << z[i] << " " << output << "\n";
	}
	return(output);
  }
  // Tapped delay line uses previous outputs (to behave like an IIR)
  Numeric iir(Numeric in) {
	  int i;
	  for (output=0,i=0;i<num_taps;i++) output += coeff[i]*z[i];
	  // Update history of outputs
	  for (i=num_taps-1;i>0;i--) z[i] = z[i-1];  
	  output += in;
	  // Add new output to delay line
	  z[0] = output;   
	  return(output);
  }
};    

#endif      
