#include "input.h"

input::input()
{
    cout << "setting m_windowClosed to false" << endl;
    m_windowClosed = false;

    for (int i = 0; i < 323; i++)
    {
        cout << "setting m_keysHeld[" << i << "] to false" << endl;
        m_keysHeld[i] = false;
    }
}

input::~input()
{

}

void input::readInput()
{
    cout << "in readInput()" << endl;
    if (SDL_PollEvent(&m_event))
    {
        cout << "started SDL_PollEvent" << endl;
        if (m_event.type == SDL_QUIT)
        {
            cout << "event tyep quit, setting windowClosed to true" << endl;
            m_windowClosed = true;
        }
        if (m_event.type == SDL_KEYDOWN)
        {
            cout << "event keydown, setting key to true" << endl;
            m_keysHeld[m_event.key.keysym.sym] = true;
        }
        if (m_event.type == SDL_KEYUP)
        {
            cout << "event keyup, setting key to true" << endl;
            m_keysHeld[m_event.key.keysym.sym] = false;
        }
    }
}

bool* input::getInput()
{
    cout << "in getInput(), returning m_keysHeld which is " << m_keysHeld << endl;
    return m_keysHeld;
}

bool input::windowClosed()
{
    cout << "in windowClosed(), returning " << m_windowClosed << endl;
    return m_windowClosed;
}
