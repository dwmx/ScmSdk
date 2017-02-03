#include "../include/ScmModelEvent.hpp"

namespace Scm
{
    ScmModelEvent::ScmModelEvent(void)
    {}

    ScmModelEvent::~ScmModelEvent(void)
    {}

    void ScmModelEvent::Pack(ScmBuffer * const pBuffer)
    {
        //pBuffer->Write(&m_name[0], sizeof(char) * 64);
    }

    void ScmModelEvent::Unpack(ScmBuffer * const pBuffer)
    {}
};