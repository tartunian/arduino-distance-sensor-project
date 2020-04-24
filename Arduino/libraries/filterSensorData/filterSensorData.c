/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filterSensorData.c
 *
 * Code generation for function 'filterSensorData'
 *
 */

/* Include files */
#include "filterSensorData.h"
#include "filterSensorData_data.h"
#include "filterSensorData_initialize.h"

/* Function Definitions */
void filterSensorData(const double x[50], double y[50])
{
  dsp_FIRFilter_0 *obj;
  int i;
  double acc1;
  int j;
  double acc2;
  if (isInitialized_filterSensorData == false) {
    filterSensorData_initialize();
  }

  /* FILTERSENSORDATA Filters input x and returns output y. */
  /*  MATLAB Code */
  /*  Generated by MATLAB(R) 9.7 and DSP System Toolbox 9.9. */
  /*  Generated on: 18-Apr-2020 00:11:07 */
  /*  To generate C/C++ code from this function use the codegen command. Type */
  /*  'help codegen' for more information. */
  obj = &Hd.cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* Consume delay line and beginning of input samples */
  for (i = 0; i < 50; i++) {
    acc1 = 0.0;
    for (j = 0; j < i + 1; j++) {
      acc2 = x[(long)(i - j)] * obj->P1_Coefficients[(long)j];
      acc1 += acc2;
    }

    for (j = 0; j < 502 - i; j++) {
      acc2 = obj->W0_states[(long)j] * obj->P1_Coefficients[(long)((i + j) + 1)];
      acc1 += acc2;
    }

    y[(long)i] = acc1;
  }

  /* Update delay line for next frame */
  for (i = 451; i >= 0; i--) {
    obj->W0_states[(long)(i + 50)] = obj->W0_states[(long)i];
  }

  for (i = 0; i < 50; i++) {
    obj->W0_states[(long)(49 - i)] = x[(long)i];
  }

  /*  [EOF] */
}

void filterSensorData_free(void)
{
  if (!Hd.matlabCodegenIsDeleted) {
    Hd.matlabCodegenIsDeleted = true;
  }
}

void filterSensorData_init(void)
{
  Hd.matlabCodegenIsDeleted = true;
}

/* End of code generation (filterSensorData.c) */