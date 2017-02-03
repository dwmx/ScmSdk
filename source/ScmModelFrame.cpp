#include "../include/ScmModelFrame.hpp"

namespace Scm
{
    ScmModelFrame::ScmModelFrame(void)
    {}

    ScmModelFrame::~ScmModelFrame(void)
    {}

    void ScmModelFrame::Pack(ScmBuffer * const pBuffer)
    {
        pBuffer->Write(&m_sequenceIndex, sizeof(int16_t));
        pBuffer->Write(&m_eventID, sizeof(int16_t));
        pBuffer->Write(&m_boundsUlc[0], sizeof(float32_t) * 3);
        pBuffer->Write(&m_boundsLrc[0], sizeof(float32_t) * 3);
        pBuffer->Write(&m_bounds, sizeof(int32_t));
    }

    void ScmModelFrame::Unpack(ScmBuffer * const pBuffer)
    {}
};