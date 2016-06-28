#include "equationsolver.h"
#include <functional>

CEquationSolver::CEquationSolver()
{
    m_x.reserve(1000);
    m_y.reserve(1000);
}

void CEquationSolver::Solve(std::shared_ptr<CHarmonicEquation> func)
{
    for (float i = m_xMin; i < m_xMax ;i += m_step)
    {
        m_x.push_back(i);
        m_y.push_back(func->Solve(i));
    }
}

QVector<float> CEquationSolver::GetXPoints()
{
    return m_x;
}

QVector<float> CEquationSolver::GetYPoints()
{
    return m_y;
}

float CEquationSolver::GetMinX() const
{
    return m_xMin;
}

float CEquationSolver::GetMaxX() const
{
    return m_xMax;
}

float CEquationSolver::GetMinY() const
{
    return -1.0;
}

float CEquationSolver::GetMaxY() const
{
    return 1.0;
}

