/* -*- c++ -*- */
/* 
 * Copyright 2014 Institute for Theoretical Information Technology,
 *                RWTH Aachen University
 *                www.ti.rwth-aachen.de
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_OFDM_BER_MEASUREMENT_IMPL_H
#define INCLUDED_OFDM_BER_MEASUREMENT_IMPL_H

#include <ofdm/ber_measurement.h>

namespace gr {
  namespace ofdm {

    class ber_measurement_impl : public ber_measurement
    {
     private:
    	 unsigned long long d_sliding_window_length;
    	 long long int d_bits_in_win;
    	 long long int d_errs_in_win;

     public:
      ber_measurement_impl(unsigned long long sliding_window_length);
      ~ber_measurement_impl();

      float get_ber()
          {
            return static_cast<float>(d_errs_in_win)/d_bits_in_win;
          }

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace ofdm
} // namespace gr

#endif /* INCLUDED_OFDM_BER_MEASUREMENT_IMPL_H */

