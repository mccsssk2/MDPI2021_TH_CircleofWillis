// This file is part of PM3 Cerebral 0D model.
//
// PM3 Cerebral 0D model is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// PM3 Cerebral 0D model is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with PM3 Cerebral 0D model.  If not, see <https://www.gnu.org/licenses/>.

/*******************************************************************************
Pumping function for the heart
JJJ, TH
*******************************************************************************/

/*******************************************************************************
Timing Parameters
*******************************************************************************/
/*
These values are calculated in the Time loop by baroreflex. Assigned to local
variables to not crowd code;
*/
double Ts     = data->Ts     ;
double Tasys  = data->Tasys  ;
double Tav    = data->Tav    ;
double act_fxn_v, act_fxn_a;

/*******************************************************************************
Ventricular Elastance
*******************************************************************************/
if((loc_t > Tav) && (loc_t <= Tav + Ts)){
  act_fxn_v   = (1.0 - cos(M_PI*(loc_t-Tav)/Ts));
}else if((loc_t > Tav + Ts) && (loc_t <=Tav + 1.5*Ts)){
  act_fxn_v   = (1.0 + cos(2.0*M_PI*(loc_t-Tav-Ts)/Ts));
}else{
  act_fxn_v   = 0.0;
}

double Elv  = data->Elv = data->Edias_lv + 0.5 * (data->Esys_lv - data->Edias_lv) * act_fxn_v;
double Erv  = data->Erv = data->Edias_rv + 0.5 * (data->Esys_rv - data->Edias_rv) * act_fxn_v;

double Clv  = 1.0 / Elv; //
double Crv 	= 1.0 / Erv; //

/*******************************************************************************
 Atrial Elastance
*******************************************************************************/
if((0 < loc_t) && (loc_t<=Tasys)){
  act_fxn_a   = (1.0 - cos(M_PI*(loc_t/Tasys)));
}else if((Tasys <= loc_t) && (loc_t < 1.5*Tasys)){
  act_fxn_a   = (1.0 + cos(2.0 * M_PI * (loc_t - Tasys)/Tasys));
}else{
  act_fxn_a   = 0.0;
}

double Ela 	=  data->Ela = data->Edias_la + 0.5 * (data->Esys_la-data->Edias_la) * act_fxn_a;
double Era 	=  data->Era = data->Edias_ra + 0.5 * (data->Esys_ra-data->Edias_ra) * act_fxn_a;

double Cla   = 1.0 / Ela;
double Cra   = 1.0 / Era; // new value of elastance ODE variables.
