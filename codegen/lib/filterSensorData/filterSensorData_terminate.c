/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * filterSensorData_terminate.c
 *
 * Code generation for function 'filterSensorData_terminate'
 *
 */

/* Include files */
#include "filterSensorData_terminate.h"
#include "filterSensorData.h"
#include "filterSensorData_data.h"

/* Function Definitions */
void filterSensorData_terminate(void)
{
  filterSensorData_free();
  isInitialized_filterSensorData = false;
}

/* End of code generation (filterSensorData_terminate.c) */
