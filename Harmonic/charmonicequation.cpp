#include "charmonicequation.h"
#include <functional>
#include <qmath.h>

CHarmonicEquation::CHarmonicEquation()
    :m_function(HarmonicFunction::sin)
{
}

CHarmonicEquation::CHarmonicEquation(HarmonicFunction func)
    :m_function(func), m_amplitude(1), m_friquency(1), m_phase(0)
{
    m_funcCaller = (func == HarmonicFunction::cos) ? qCos : qSin;
}

void CHarmonicEquation::SetAmplitude(float amplitude)
{
    m_amplitude = amplitude;
}

void CHarmonicEquation::SetFriquence(float friquency)
{
    m_friquency = friquency;
}

void CHarmonicEquation::SetPhase(float phase)
{
    m_phase = phase;
}

float CHarmonicEquation::Solve(float x)
{
    return m_amplitude * m_funcCaller(x * m_friquency + m_phase);
}

QString CHarmonicEquation::ToString() const
{
    std::string funcName;
    switch (m_function)
    {
        case HarmonicFunction::cos:
            funcName = "cos";
            break;
        case HarmonicFunction::sin:
            funcName = "sin";
            break;
        default:
            throw new std::runtime_error("Unknown Harmonic Function");
            break;
    }

    std::ostringstream ss;
    ss << boost::format("%1%*%2%(%3%*x+%4%)")
                % m_amplitude
                % funcName
                % m_friquency
                % m_phase;
    return QString(ss.str().c_str());
}
