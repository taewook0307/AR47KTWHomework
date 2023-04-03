#pragma once

class int2
{
public:
    int X;
    int Y;

    int2 GetPos() const
    {
        return int2{ X, Y };
    }

    int2 Half()
    {
        return int2{ X / 2, Y / 2 };
    }

    void SetPos(int _X, int _Y)
    {
        X = _X;
        Y = _Y;
    }
};

