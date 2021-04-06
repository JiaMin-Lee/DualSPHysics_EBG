//HEAD_DSPH
/*
 <DUALSPHYSICS>  Copyright (c) 2020 by Dr Jose M. Dominguez et al. (see http://dual.sphysics.org/index.php/developers/). 

 EPHYSLAB Environmental Physics Laboratory, Universidade de Vigo, Ourense, Spain.
 School of Mechanical, Aerospace and Civil Engineering, University of Manchester, Manchester, U.K.

 This file is part of DualSPHysics. 

 DualSPHysics is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License 
 as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 
 DualSPHysics is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details. 

 You should have received a copy of the GNU Lesser General Public License along with DualSPHysics. If not, see <http://www.gnu.org/licenses/>. 
*/

/// \file JCellDivCpuSingle.h \brief Declares the class \ref JCellDivCpuSingle.

#ifndef _JCellDivCpuSingle_
#define _JCellDivCpuSingle_

#include "JCellDivCpu.h"

//##############################################################################
//# JCellDivCpuSingle
//##############################################################################
/// \brief Defines the class responsible of generating the Neighbour List in Single-Core.

class JCellDivCpuSingle : public JCellDivCpu
{
protected:
  void CalcCellDomain(const unsigned *dcellc,const typecode *codec);
  void MergeMapCellBoundFluid(const tuint3 &celbmin,const tuint3 &celbmax,const tuint3 &celfmin,const tuint3 &celfmax,tuint3 &celmin,tuint3 &celmax)const;
  void PrepareNct();

  void PreSortFull(unsigned np,const unsigned *dcellc,const typecode *codec,unsigned* cellpart,unsigned* partsincell)const;
  void PreSortFluid(unsigned np,unsigned pini,const unsigned *dcellc,const typecode *codec,unsigned* cellpart,unsigned* partsincell)const;
  void MakeSortFull(const unsigned* cellpart,unsigned* begincell,unsigned* partsincell,unsigned* sortpart)const;
  void MakeSortFluid(unsigned np,unsigned pini,const unsigned* cellpart,unsigned* begincell,unsigned* partsincell,unsigned* sortpart)const;
  void PreSort(const unsigned* dcellc,const typecode *codec);

public:
  JCellDivCpuSingle(bool stable,bool floating,byte periactive
    ,bool celldomfixed,TpCellMode cellmode,float scell
    ,tdouble3 mapposmin,tdouble3 mapposmax,tuint3 mapcells
    ,unsigned casenbound,unsigned casenfixed,unsigned casenpb,std::string dirout);

  void Divide(unsigned npb1,unsigned npf1,unsigned npb2,unsigned npf2,bool boundchanged
    ,const unsigned *dcellc,const typecode* codec,const unsigned* idpc,const tdouble3* posc,TimersCpu timers);

  ullong GetAllocMemory()const{ return(JCellDivCpu::GetAllocMemory()); }
  ullong GetAllocMemoryNp()const{ return(JCellDivCpu::GetAllocMemoryNp()); };
  ullong GetAllocMemoryNct()const{ return(JCellDivCpu::GetAllocMemoryNct()); };
};

#endif


