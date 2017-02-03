#ifndef __INCLUDED_SCMMODELFRAME_HPP__
#define __INCLUDED_SCMMODELFRAME_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelFrame : public ScmData
    {
    private:
        friend class ScmModel;

    private:
        int16_t m_sequenceIndex;
        int16_t m_eventID;
        float32_t m_boundsUlc[3];
        float32_t m_boundsLrc[3];
        int32_t m_bounds;

    private:
        ScmModelFrame(void);

    public:
        ~ScmModelFrame(void);

        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);
    };
};

#endif