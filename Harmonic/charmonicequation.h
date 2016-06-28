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
    CHarmonicEquation();
    CHarmonicEquation(HarmonicFunction func);

    void SetAmplitude(float amplitude);
    void SetFriquence(float friquency);
    void SetPhase(float phase);

    float Solve(float x);

    QString ToString() const;

private:
    HarmonicFunction m_function;
    float m_amplitude;
    float m_friquency;
    float m_phase;

    std::function<qreal(qreal)> m_funcCaller;
};

Q_DECLARE_METATYPE(CHarmonicEquation);

#endif // CHARMONICEQUATION_H
