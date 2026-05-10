#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "Internal_utils_batch.h"

void imodwt(double *Win, double *Vin, int *N, int *j, int *L, 
            double *ht, double *gt, double *Vout) {
  
  int k, n, t;
  
  for(t = 0; t < *N; t++) {
    k = t;
    Vout[t] = (ht[0] * Win[k]) + (gt[0] * Vin[k]);
    for(n = 1; n < *L; n++) {
      k += (int) pow(2.0, (double) *j - 1.0);
      if(k >= *N) k -= *N;
      Vout[t] += (ht[n] * Win[k]) + (gt[n] * Vin[k]);
    }
  }
}

void modwt(double *Vin, int *N, int *j, int *L, double *ht, double *gt, 
           double *Wout, double *Vout){
  
  int k, n, t;
  
  for(t = 0; t < *N; t++) {
    k = t;
    Wout[t] = ht[0] * Vin[k];
    Vout[t] = gt[0] * Vin[k];
    for(n = 1; n < *L; n++) {
      k -= (int) pow(2.0, (double) *j - 1.0);
      if(k < 0) k += *N;
      Wout[t] += ht[n] * Vin[k];
      Vout[t] += gt[n] * Vin[k];
    }
  }
  
}

/*   decorana Function from vegan Package   */

#include <R.h>

void data2hill(double *x,
               int *mi, int *n, int *nid, int *ibegin, int *iend,
               int *idat, double *qidat)
{
  int nr, nc, i, j, ij, now;
  
  nr = *mi;
  nc = *n;
  if (nr <= 0 || nc <= 0)
    error("zero extent dimensions");
  
  now=0;
  for (i=0; i<nr; i++) {
    for (j=0; j<nc; j++) {
      ij = i+nr*j;
      if (x[ij] > 0.0) {
        idat[now] = j+1;
        qidat[now] = x[ij];
        now++;
      }
    }
    iend[i] = now;
  }
  ibegin[0] = 1;
  for (i=1; i<nr; i++)
    ibegin[i] = iend[i-1] + 1;
  *mi = nr;
  *n = nc;
  *nid = now; 
}

/* Decorana functions have been replaced with C++ implementation in decorana.cpp */
