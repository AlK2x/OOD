#include "charmonicequation.h"
#include <functional>
#include <qmath.h>

CHarmonicEquation::CHarmonicEquation(HarmonicFunction func)
    :m_function(func), m_amplitude(1), m_friquency(1), m_phase(0)
{
    m_funcCaller = (func == HarmonicFunction::cos) ? qCos : qSin;
}

void CHarmonicEquation::SetAmplitude(double amplitude)
{
    m_amplitude = amplitude;
}

void CHarmonicEquation::SetFriquence(double friquency)
{
    m_friquency = friquency;
}

void CHarmonicEquation::SetPhase(double phase)
{
    m_phase = phase;
}

void CHarmonicEquation::SetFunction(HarmonicFunction function)
{
    m_function = function;
    m_funcCaller = (function == HarmonicFunction::cos) ? qCos : qSin;
}

double CHarmonicEquation::GetAmplitude() const
{
    return m_amplitude;
}

double CHarmonicEquation::GetFriquency() const
{
    return m_friquency;
}

double CHarmonicEquation::GetPhase() const
{
    return m_phase;
}

HarmonicFunction CHarmonicEquation::GetFunction() const
{
    return m_function;
}

double CHarmonicEquation::Solve(double x)
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
