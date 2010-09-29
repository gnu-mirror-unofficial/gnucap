/* $Id: d_diode.h,v 20.13 2001/10/15 00:57:11 al Exp $ -*- C++ -*-
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
 * diode model.
 * netlist syntax:
 * device:  dxxxx n+ n- mname <area> <off> <ic=vd> <model-card-args>
 * model:   .model mname D <args>
 *
 * The section "eval Yj" is a big mess.
 * It will be redone using multiple files, like the MOS models.
 */
/* This file is automatically generated. DO NOT EDIT */
#ifndef D_DIODE_H_INCLUDED
#define D_DIODE_H_INCLUDED

#include "e_subckt.h"
#include "e_model.h"
  enum region_t {INITOFF=-2, REVERSE=-1, UNKNOWN=0, FORWARD=1};
  class DEV_DIODE;
  class DEV_ADMITTANCE;
  class DEV_CAPACITANCE;
/*--------------------------------------------------------------------------*/
class SDP_DIODE
  :public SDP_CARD{
public:
  explicit SDP_DIODE(const COMMON_COMPONENT*);
public:
};
/*--------------------------------------------------------------------------*/
class TDP_DIODE{
public:
  explicit TDP_DIODE(const DEV_DIODE*);
public:
};
/*--------------------------------------------------------------------------*/
class MODEL_DIODE
  :public MODEL_CARD{
public:
  // using generated copy constructor, should be unreachable
  explicit MODEL_DIODE();
  ~MODEL_DIODE() {--_count;}
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
  static int _count;
public: // input parameters
  double js;	// = is, saturation current (per area)
  double rs;	// ohmic resistance (per area)
  double n_factor;	// emission coefficient
  double tt;	// transit time
  double cjo;	// cj, zero-bias jct capacitance (per area)
  double pb;	// vj, junction potential
  double mj;	// m, grading coefficient
  double eg;	// activation energy
  double xti;	// saturation-current temp. exp.
  double kf;	// flicker noise coefficient
  double af;	// flicker noise exponent
  double fc;	// coef for fwd bias depl cap formula
  double bv;	// reverse breakdown voltage
  double ibv;	// current at reverse breakdown
  double cjsw;	// zero bias sidewall cap (per perim.)
  double pbsw;	// sidewall junction potential
  double mjsw;	// sidewall grading coefficient
  double gparallel;	// parallel conductance
  int flags;	// 
  int mos_level;	// 
public: // calculated parameters
};
/*--------------------------------------------------------------------------*/
class COMMON_DIODE
  :public COMMON_COMPONENT{
public:
  explicit COMMON_DIODE(const COMMON_DIODE& p);
  explicit COMMON_DIODE(int c=0);
           ~COMMON_DIODE();
  bool        operator==(const COMMON_COMPONENT&)const;
  COMMON_COMPONENT* clone()const {return new COMMON_DIODE(*this);}
  void        parse(CS&);
  void        print(OMSTREAM&)const;
  void        expand();
  const char* name()const {return "diode";}
  const SDP_CARD* sdp()const {assert(_sdp); return _sdp;}
  bool      has_sdp()const {return _sdp;}
  static int  count() {return _count;}
private: // strictly internal
  static int _count;
public: // input parameters
  double area;	// area factor
  double perim;	// perimeter factor
  bool off;	// flag: assume reverse biased
  double ic;	// initial voltage
  double is_raw;	// saturation current
  double rs_raw;	// series resistance
  double cj_raw;	// zero bias jct capacitance
  double cjsw_raw;	// zero bias sidewall capacitance
  double gparallel_raw;	// parallel conductance
public: // calculated parameters
  const SDP_CARD* _sdp;
  double is_adjusted;	// 
  double rs_adjusted;	// 
  double cj_adjusted;	// 
  double cjsw_adjusted;	// 
  double gparallel_adjusted;	// 
public: // attached commons
};
/*--------------------------------------------------------------------------*/
class EVAL_DIODE_Cj : public COMMON_COMPONENT {
private:
  explicit EVAL_DIODE_Cj(const EVAL_DIODE_Cj& p)
    :COMMON_COMPONENT(p) {unreachable();}
public:
  explicit EVAL_DIODE_Cj(int c=0) :COMMON_COMPONENT(c) {}
  bool operator==(const COMMON_COMPONENT&)const {incomplete(); return false;}
  COMMON_COMPONENT* clone()const {untested(); return new EVAL_DIODE_Cj(*this);}
  const char* name()const {untested(); return "EVAL_DIODE_Cj";}
  void tr_eval(ELEMENT*d)const;
  bool has_tr_eval()const {return true;}
  bool has_ac_eval()const {return false;}
};
/*--------------------------------------------------------------------------*/
class EVAL_DIODE_Yj : public COMMON_COMPONENT {
private:
  explicit EVAL_DIODE_Yj(const EVAL_DIODE_Yj& p)
    :COMMON_COMPONENT(p) {unreachable();}
public:
  explicit EVAL_DIODE_Yj(int c=0) :COMMON_COMPONENT(c) {}
  bool operator==(const COMMON_COMPONENT&)const {incomplete(); return false;}
  COMMON_COMPONENT* clone()const {untested(); return new EVAL_DIODE_Yj(*this);}
  const char* name()const {untested(); return "EVAL_DIODE_Yj";}
  void tr_eval(ELEMENT*d)const;
  bool has_tr_eval()const {return true;}
  bool has_ac_eval()const {return false;}
};
/*--------------------------------------------------------------------------*/
class DEV_DIODE : public BASE_SUBCKT {
private:
  explicit DEV_DIODE(const DEV_DIODE& p);
public:
  explicit DEV_DIODE();
           ~DEV_DIODE() {--_count;}
private: // override virtual
  char      id_letter()const {return 'D';}
  const char* dev_type()const{return "diode";}
  int       numnodes()const  {return 2;}
  CARD*     clone()const     {return new DEV_DIODE(*this);}
  void      parse(CS&);
  void      print(OMSTREAM&,int)const;
  void      expand();
  //void    map_nodes();     //BASE_SUBCKT
  //void    precalc();       //BASE_SUBCKT
  //void    dc_begin();      //BASE_SUBCKT
  //void    tr_begin();      //BASE_SUBCKT
  //void    tr_restore();    //BASE_SUBCKT
  //void    dc_advance();    //BASE_SUBCKT
  //void    tr_advance();    //BASE_SUBCKT
  //bool    tr_needs_eval(); //BASE_SUBCKT
  //void    tr_queue_eval(); //BASE_SUBCKT
  //bool    do_tr();         //BASE_SUBCKT
  //void    tr_load();       //BASE_SUBCKT
  //double  tr_review();     //BASE_SUBCKT
  //void    tr_accept();     //BASE_SUBCKT
  //void    tr_unload();     //BASE_SUBCKT
  double    tr_probe_num(CS&)const;
  //void    ac_begin();      //BASE_SUBCKT
  //void    do_ac();         //BASE_SUBCKT
  //void    ac_load();       //BASE_SUBCKT
  //XPROBE  ac_probe_ext(CS&)const;//CKT_BASE/nothing
public:
  static int  count() {return _count;}
public: // may be used by models
private: // not available even to models
  static int _count;
public: // input parameters
public: // calculated parameters
  region_t _region;	// fwd, reverse, unknown
  double _gd;	// conductance to pass to capacitor
  double _isat;	// is adjusted for temp, etc.
public: // netlist
  DEV_CAPACITANCE* _Cj;
  DEV_ADMITTANCE* _Yj;
private: // node list
  enum {n_anode=0, n_cathode=1};
  node_t _nodes[2];
};
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
#endif
