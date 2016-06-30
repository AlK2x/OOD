#include "equationsolver.h"
#include <functional>
#include <QDebug>

CEquationSolver::CEquationSolver()
{
    int size = static_cast<int>((m_xMax - m_xMin) / m_step) + 2;
    m_x.resize(size);
    m_y.resize(size);
    m_y.fill(0.0);
}

void CEquationSolver::Solve(QVector<std::shared_ptr<CHarmonicEquation>> m_funcList)
{
    int j = 0;


    for (double i = m_xMin; i < m_xMax ;i += m_step, ++j)
    {
        for (auto & func : m_funcList)
        {
            m_y[j] += func->Solve(i);
        }
        m_x[j] = i;
        //m_y[j] = func->Solve(i);
    }

    m_yMin = m_yMax = m_y[0];
    for (int i = 0; i < m_y.size(); ++i)
    {
        if (m_y[i] < m_yMin) m_yMin = m_y[i];
        if (m_y[i] > m_yMax) m_yMax = m_y[i];
    }
}

const QVector<double> & CEquationSolver::GetXPoints()
{
    return m_x;
}

const QVector<double> & CEquationSolver::GetYPoints()
{
    return m_y;
}

double CEquationSolver::GetMinX() const
{
    return m_xMin;
}

double CEquationSolver::GetMaxX() const
{
    return m_xMax;
}

double CEquationSolver::GetMinY() const
{
    return m_yMin;
}

double CEquationSolver::GetMaxY() const
{
    return m_yMax;
}

