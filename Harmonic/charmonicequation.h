#ifndef CHARMONICEQUATION_H
#define CHARMONICEQUATION_H
#include <stdexcept>
#include <string>
#include <sstream>
#include <boost/format.hpp>
#include <QString>

enum class HarmonicFunction
{
    sin,
    cos
};

class CHarmonicEquation
{
public:
    CHarmonicEquation(HarmonicFunction func);

    void SetAmplitude(double amplitude);
    void SetFriquence(double friquency);
    void SetPhase(double phase);
    void SetFunction(HarmonicFunction function);

    double GetAmplitude() const;
    double GetFriquency() const;
    double GetPhase() const;
    HarmonicFunction GetFunction() const;

    double Solve(double x);

    QString ToString() const;

private:
    HarmonicFunction m_function;
    double m_amplitude;
    double m_friquency;
    double m_phase;

    std::function<qreal(qreal)> m_funcCaller;
};

#endif // CHARMONICEQUATION_H
