#pragma once

class BoolFlag
{
public:
    explicit BoolFlag(bool flag) 
        : m_flag(flag)
    {
    };


    bool read() const
    {
        return m_flag;
    }


    void write(bool v)
    {
        m_flag = v;
    }
private:
    bool m_flag;
};
