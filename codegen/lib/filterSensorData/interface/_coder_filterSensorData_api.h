/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_filterSensorData_api.h
 *
 * Code generation for function '_coder_filterSensorData_api'
 *
 */

#ifndef _CODER_FILTERSENSORDATA_API_H
#define _CODER_FILTERSENSORDATA_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void filterSensorData(real_T x[50], real_T y[50]);
extern void filterSensorData_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void filterSensorData_atexit(void);
extern void filterSensorData_initialize(void);
extern void filterSensorData_terminate(void);
extern void filterSensorData_xil_shutdown(void);
extern void filterSensorData_xil_terminate(void);

#endif

/* End of code generation (_coder_filterSensorData_api.h) */
