/*
 * SPUtilities.h
 *
 *  Created on: Apr 23, 2013
 *      Author: saul
 */

#ifndef SPUTILITIES_H_
#define SPUTILITIES_H_
#define TRUE  1
#define FALSE 0
#include "includes.h"

/*
 * Rounds to the nearest integer value
 * @param x, double value to round up
 * */

double round2(double x);
/*
*Returns the interpolated function
*@param f, the function to interpolate
*@param g
*@param x, x values corresponding to the function f
*@param y, interpolated function
*/
void interp1(vector f, vector g, vector x, double* y);

/*
 * @param xO, original x axis values
 * @param xN, new x axis values
 * @param yO, original y axis values, a  y sample per column
 * @param extrapolate, states whether the algorithm must extrapolate or not
 * @return matrix, yN with the interpolated results
 * */
matrix interp1Mat(vector xO, vector xN, matrix yO, int extrapolate);
/*
*Calculates the logarithm in base 2
*@param x, number to calculate
*@return double, the logatithm in base 2
*/
double log2(double x);
/*
*Rounds a double to the nearest integer value
*@param x, number to round
*@return double, rounded number
*/
#ifndef round
double round(double x);
#endif

/*
*Converts hz value to the mel scale
*@param hz, value in hz
*@return double, mel value
*/
double hz2mel(double hz);

/*
*Converts from hertz to ERBs
*@param hz, value in hz
*@return double, ERBs value
*/
double hz2erb(double hz);

/*
*Converts from ERBs to hertz
*@param hz, value in hz
*@return double, erb value
*/
double erb2hz(double erb);

/*
*A silly function that treats NaNs as 0.
*@param hz, value in hz
*@return double, erb value
*/
double fixnan(double x);

/*
*Returns the maximum between the received numbers
*@param x, number to compare
*@param y, number to compare
*@return double,result
*/
double maxim(double x, double y);
/*
*Converts the hz scale value in to a ERB scale value
*@param hz, the value in hz
*@return double, the value in ERB scale
*/
double hz2erbs(double hz);

/*
*Converts the ERB scaled array in to a HZ scale array
*@param erbs, the array in ERBS
*@param size, the array's size
*/
void v_erbs2hz(vector erbs);
/*
*Filter function that receives the coeficients of the characteristic function of the transfer function
*MATLAB like filter function
*@param b, filter coeficients
*@param L,
*@param x, input signal
*@param y, output signal
*@param tam, the size of the vector x
*/
void Filter_B(double * b, int L, double * x  ,int size_x, double* y);
/*
*Filter function that receives the coeficients of A and B's polynoms from the transfer function
*MATLAB like filter function
*@param b, b's filter coeficients
*@param a, a's filter coeficients
*@param L,
*@param x, input signal
*@param y, output signal
*@param tam, the size of the vector x
*/
void Filter_AB(double * b, double * a, int L, double * x  ,int size_x, double* y);
/*
*Normalizes an array, with the minimum frequency at f[0] and the maximum at f[size-1]
*@param f, array of frecuencies
*@param size, f's size
*/
void normalize(vector f);
/*
*Uses lineal interpolation to interpolate the function given in f
*@param f, function to interpolate
*@param g,
*@param x,
*@param end,
*@return double, the interpolated function
*/
double interp(double* f, double* g, double x, int end);
/*
*Reduces the sample rate of the signals given in the X vector.
*@param X, Matrix with a signal per row, representing the cochlea's response in frequency band
*@param Y, the Downsampled matrix
*@param size_x
*/
void Downsample_Vector(double* X, double* Y, int size_x);

/*
*Upsample the signals given in the X vector.
*@param X, Matrix with a signal per row, representing the cochlea's response in frequency band
*@param Y, the Upsampled matrix
*@param size_x
*/
void Upsample_Vector(double* X, double* Y, int size_x);

/*
*freqz make frequency filter response from filter coefficients
*@param n,filter order (vector b has size n+1)
*@param b, vector of filter coefficients
*@param nf, size of vectors f and a (must be power of 2 : 128, 256, 512,1024 ...)
* Outputs:
*@param f, vector of response frecuenses
*@param a, vector of response magnitudes
*/
void fir2(int n, double *f,double *m, int nf, double *b);
/*
 * Half wave rectification
 * Receives the array
 * */
void MaxRCerosVector(double* x, int size_x);
/*
*Calculates the maximum element in a given array
*@param r, the array
*@param l, the maximum element to take into account in the search
*/
void Max(double** x, int size_x, int size_c, double lim);
/*
 * checks all the values in the matrix mat, and if the current entry is minor than  value, copies a 0 to the new matrix,
 * otherwise it leaves the same value
 * @param value, value to check
 * @param mat, matrix to compare
 * @return matrix
 * */
matrix max(double value, matrix mat);
/*
 * Substracts two matrices
 * @param op1, first operator
 * @param op2, second operator
 * */
void minus_local(matrix op1, matrix op2);

/*
 *Returns a Hanning window in y
 *@param y, array to store the hanning window
 *@param np,
 */
void Hanning(double *y, int np);

/*
 * Reads a sound file
 * @param ptrName, name of the file to read
 * @param nyquist, stores the nyquist frequency of the file
 * @param fs, sampling frequency of the file is stores
 * @param soundLength, soundLength in seconds of the file
 * @param frames, number of frames of the sound
 * @param x, vector storing the signal information
 * */
vector readSoundFile(char ptrName[], double* nyquist, double* fs, double* soundLength, int* ptrFrames);
#endif
