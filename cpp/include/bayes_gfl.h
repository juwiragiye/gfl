/****************************************************************************
 * Copyright (C) 2016 by Wesley Tansey                                      *
 *                                                                          *
 * This file is part of the the GFL library / package.                      *
 *                                                                          *
 *   GFL is free software: you can redistribute it and/or                   *
 *   modify it under the terms of the GNU Lesser General Public License     *
 *   as published by the Free Software Foundation, either version 3 of      *
 *   the License, or (at your option) any later version.                    *
 *                                                                          *
 *   GFL is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with GFL. If not, see <http://www.gnu.org/licenses/>.    *
 ****************************************************************************/

#ifndef GRAPH_FL_H
#define GRAPH_FL_H

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"


/************************
 *     Main methods     *
 ************************/
void bayes_gfl_gaussian_laplace (int n, double *y, double *w,
                                int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                double lambda_hyperparam_a, double lambda_hyperparam_b,
                                int iterations, int burn, int thin,
                                double **beta_samples, double *lambda_samples);

void bayes_gfl_gaussian_doublepareto (int n, double *y, double *w,
                                      int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                      double lambda_hyperparam_a, double lambda_hyperparam_b,
                                      double lam_walk_stdev, double lam0, double dp_hyperparameter,
                                      int iterations, int burn, int thin,
                                      double **beta_samples, double *lambda_samples);

void bayes_gfl_binomial_laplace (int n, int *trials, int *successes,
                                 int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                 double lambda_hyperparam_a, double lambda_hyperparam_b,
                                 int iterations, int burn, int thin,
                                 double **beta_samples, double *lambda_samples);

void bayes_gfl_binomial_doublepareto (int n, int *trials, int *successes,
                                      int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                      double lambda_hyperparam_a, double lambda_hyperparam_b,
                                      double lam_walk_stdev, double lam0, double dp_hyperparameter,
                                      int iterations, int burn, int thin,
                                      double **beta_samples, double *lambda_samples);

void bayes_gfl_poisson_laplace (int n, int *obs,
                                 int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                 double lambda_hyperparam_a, double lambda_hyperparam_b,
                                 int iterations, int burn, int thin,
                                 double **beta_samples, double *lambda_samples);

void bayes_gfl_poisson_doublepareto (int n, int *obs,
                                      int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                      double lambda_hyperparam_a, double lambda_hyperparam_b,
                                      double lam_walk_stdev, double lam0, double dp_hyperparameter,
                                      int iterations, int burn, int thin,
                                      double **beta_samples, double *lambda_samples);

/********************
 *  Gibbs sampling  *
 ********************/
double sample_lambda_laplace(const gsl_rng *random, double *beta, 
                               int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                               double a, double b);

double sample_lambda_doublepareto(const gsl_rng *random, double *beta,
                                  int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                  double a, double b,
                                  double lam0, double gamma, double lam_walk_stdev);

void sample_prior_aux_laplace(const gsl_rng *random, double *beta,
                                int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                double lambda, double *s);

void sample_prior_aux_doublepareto(const gsl_rng *random, double *beta, 
                                   int dk_rows, int *dk_rowbreaks, int *dk_cols, double *deltak,
                                   double lambda, double dp_hyperparameter, double *s);

void sample_likelihood_gaussian(const gsl_rng *random,
                                int n, double *y, double *w,
                                int *dk_rowbreaks, int *dk_cols, double *dk_vals,
                                double *s, int **coefs, int *coef_breaks,
                                double *beta);

void sample_likelihood_binomial(const gsl_rng *random,
                                int n, int *trials, int *successes, 
                                int *dk_rowbreaks, int *dk_cols, double *dk_vals,
                                double *s, int **coefs, int *coef_breaks,
                                double *beta);

void sample_likelihood_poisson(const gsl_rng *random,
                                int n, int *obs, 
                                int *dk_rowbreaks, int *dk_cols, double *dk_vals,
                                double *s, int **coefs, int *coef_breaks,
                                double *beta);

/***********
 *  Utils  *
 ***********/
void calc_coefs(int n, 
                int dk_rows, int *dk_rowbreaks, int *dk_cols,
                int **coefs, int *coef_breaks);

#endif












