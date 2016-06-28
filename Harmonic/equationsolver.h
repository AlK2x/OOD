#ifndef CEQUATIONSOLVER_H
#define CEQUATIONSOLVER_H

#include "charmonicequation.h"
#include <QVector>
#include <QFunctionPointer>
#include <qmath.h>


class CEquationSolver
{
public:
    CEquationSolver();

    void Solve(std::shared_ptr<CHarmonicEquation> func);

    QVector<float> GetXPoints();
    QVector<float> GetYPoints();

    float GetMinX() const;
    float GetMaxX() const;

    float GetMinY() const;
    float GetMaxY() const;

private:
    std::shared_ptr<CHarmonicEquation> m_pFunc;

    float m_xMin = 0.0;
    float m_xMax = 10.0;
    float m_step = 0.01;

    QVector<float> m_x;
    QVector<float> m_y;
};

#endif // CEQUATIONSOLVER_H
