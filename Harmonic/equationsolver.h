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

    void Solve(QVector<std::shared_ptr<CHarmonicEquation>> m_funcList);

    const QVector<double> & GetXPoints();
    const QVector<double> & GetYPoints();

    double GetMinX() const;
    double GetMaxX() const;

    double GetMinY() const;
    double GetMaxY() const;

private:
    std::shared_ptr<CHarmonicEquation> m_pFunc;

    double m_xMin = 0.0;
    double m_xMax = 10.0;
    double m_step = 0.01;

    double m_yMin;
    double m_yMax;

    QVector<double> m_x;
    QVector<double> m_y;
};

#endif // CEQUATIONSOLVER_H
