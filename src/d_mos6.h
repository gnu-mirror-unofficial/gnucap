/* $Id: d_mos6.h,v 20.7 2001/09/29 05:31:06 al Exp $ -*- C++ -*-
 * Copyright (C) 2001 Albert Davis
 * Author: Albert Davis <aldavis@ieee.org>
 *
 * This file is part of "GnuCap", the Gnu Circuit Analysis Package
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *------------------------------------------------------------------
 * mos model equations: spice level 6 equivalent
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_MOS6_H_INCLUDED
#define D_MOS6_H_INCLUDED

#include "d_mos123.h"
/*--------------------------------------------------------------------------*/
class SDP_MOS6
  :public SDP_MOS123{
public:
  explicit SDP_MOS6(const COMMON_COMPONENT*);
public:
};
/*--------------------------------------------------------------------------*/
class TDP_MOS6
  :public TDP_MOS123{
public:
  explicit TDP_MOS6(const DEV_MOS*);
public:
  double phi;	// 
  double beta;	// 
  double vbi;	// 
};
/*--------------------------------------------------------------------------*/
class MODEL_MOS6
  :public MODEL_MOS123{
public:
  // using generated copy constructor, should be unreachable
  explicit MODEL_MOS6();
  ~MODEL_MOS6() {--_count;}
public: // override virtual
  bool      parse_front(CS&);
  void      parse_params(CS&);
  void      parse_finish();
  SDP_CARD* new_sdp(const COMMON_COMPONENT* c)const;
  void      print_front(OMSTREAM&)const;
  void      print_params(OMSTREAM&)const;
  void      print_calculated(OMSTREAM&)const;
  void      tr_eval(COMPONENT*)const;
public: // not virtual
  static int count() {return _count;}
private: // strictly internal
  enum {LEVEL=6};
  static int _count;
public: // input parameters
  double kv;	// Saturation voltage factor
  double nv;	// Saturation voltage coeff.
  double kc;	// Saturation current factor
  double nc;	// Saturation current coeff.
  double nvth;	// Threshold voltage coeff.
  double ps;	// Sat. current modification  par.
  double gamma1;	// Bulk threshold parameter 1
  double sigma;	// Static feedback effect par.
  double lambda0;	// Channel length modulation param
  double lambda1;	// Channel length modulation param. 1
public: // calculated parameters
  bool calc_kc;	// 
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
