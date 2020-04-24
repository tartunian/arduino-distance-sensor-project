/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filterSensorData_types.h
 *
 * Code generation for function 'filterSensorData_types'
 *
 */

#ifndef FILTERSENSORDATA_TYPES_H
#define FILTERSENSORDATA_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_dsp_FIRFilter_0
#define struct_dsp_FIRFilter_0

struct dsp_FIRFilter_0
{
  int S0_isInitialized;
  double W0_states[502];
  double P0_InitialStates;
  double P1_Coefficients[503];
};

#endif                                 /*struct_dsp_FIRFilter_0*/

#ifndef typedef_dsp_FIRFilter_0
#define typedef_dsp_FIRFilter_0

typedef struct dsp_FIRFilter_0 dsp_FIRFilter_0;

#endif                                 /*typedef_dsp_FIRFilter_0*/

#ifndef typedef_dspcodegen_FIRFilter
#define typedef_dspcodegen_FIRFilter

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  boolean_T isSetupComplete;
  dsp_FIRFilter_0 cSFunObject;
} dspcodegen_FIRFilter;

#endif                                 /*typedef_dspcodegen_FIRFilter*/
#endif

/* End of code generation (filterSensorData_types.h) */
