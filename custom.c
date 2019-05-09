// custom code

#define _MAX 12

int max = _MAX;
int step = 0;
int i = 0;
int r = 50;
int g = 50;
int b = 50;

void loop_colors()
{
    if (g < 240)
    {
        g++;
    }
}

void _light(int i, int j)
{
    loop_colors();
    light(i, j, r, g, b);
}

void effect1()
{
    // restart
    if (max == 0)
    {
        reset();
        max = _MAX;
        step = 0;
        i = 0;
        r = 50;
        g = 50;
        b = 50;
    }

    // down
    if (step == 0)
    {
        if (i < max)
        {
            _light(i, _MAX - max);
            i++;
        }
        else
        {
            i = 1;
            step = (step + 1) % 4;
        }
    }

    // right
    if (step == 1)
    {

        if (i < max - (_MAX - max))
        {
            _light(max - 1, i + (_MAX - max));
            i++;
        }
        else
        {
            i = 1;
            step = (step + 1) % 4;
        }
    }

    // up
    if (step == 2)
    {

        if (i < max - (_MAX - max))
        {
            _light(max - i - 1, max - 1);
            i++;
        }
        else
        {
            i = 1;
            step = (step + 1) % 4;
        }
    }

    // left
    if (step == 3)
    {

        if (i < max - (_MAX - max) - 1)
        {
            _light(_MAX - max, max - 1 - i);
            i++;
        }
        else
        {

            max = max - 1;
            i = (_MAX - max);
            step = (step + 1) % 4;
        }
    }
}

void loop()
{
    effect1();
}
