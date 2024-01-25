#include <eigen3/Eigen/Dense>
#include <qpOASES.hpp>
USING_NAMESPACE_QPOASES

class tf
{
public:
    real_t *mat2real(Eigen::MatrixXd mat)
    {
        real_t *real = new real_t[mat.rows() * mat.cols()];
        int k = 0;
        real_t *data = mat.data();
        for (int i = 0; i < mat.rows(); i++)
        {
            for (int j = 0; j < mat.cols(); j++)
            {
                real[k++] = data[i * mat.rows() + j];
            }
        }
        return real;
    }

    real_t *vec2real(Eigen::VectorXd vec)
    {
        real_t *real = new real_t[vec.size()];
        real = vec.data();
        return real;
    }

    Eigen::MatrixXd real2mat(int rows,int cols,real_t real[])
    {
        Eigen::MatrixXd mat;
        mat.resize(rows,cols);
        double *data=mat.data();
        for(int i=0;i<rows*cols;i++)
        {
            data[i]=real[i];
        }
        return mat;
    }

    Eigen::VectorXd real2vec(int size,real_t real[])
    {
        Eigen::VectorXd vec;
        vec.resize(size);
        for(int i=0;i<size;i++)
        {
            vec[i]=static_cast<double>(real[i]);
        }
        return vec;
    }
};
