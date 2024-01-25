#include <eigen3/Eigen/Dense>
#include <qpOASES.hpp>
#include "tf.h"
#include <iostream>
USING_NAMESPACE_QPOASES

int main( )
{
	USING_NAMESPACE_QPOASES


	/* Setup data of first QP. */
	Eigen::MatrixXd mat;
	Eigen::VectorXd vec;
	mat.resize(2,2);
	mat<<1,0,0,5;
	vec.resize(2);
	vec<<1.5,1;
	tf trans;
	real_t* H = trans.mat2real(mat);
	real_t A[1*2] = { 1.0, 1.0 };
	real_t* g = trans.vec2real(vec);
	real_t lb[2] = { 0.5, -2.0 };
	real_t ub[2] = { 5.0, 2.0 };
	real_t lbA[1] = { -1.0 };
	real_t ubA[1] = { 2.0 };

	/* Setting up QProblem object. */
	QProblem example( 2,1 );/*QProblem(变量的数量，约束的数量)*/

	Options options;
	example.setOptions( options );/*使用默认设置*/

	/* Solve first QP. */
	int_t nWSR = 10;/*一次计算的迭代次数*/
	example.init( H,g,A,lb,ub,lbA,ubA, nWSR );

	/* Get and print solution of first QP. */
	real_t xOpt[2];/*原始解*/

	example.getPrimalSolution( xOpt );

	Eigen::VectorXd xout=trans.real2vec(2,xOpt);

	std::cout<<"\n"<<xout<<"\n";

	return 0;
}
