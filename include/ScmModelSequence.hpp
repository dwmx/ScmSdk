#ifndef __INCLUDED_SCMMODELSEQUENCE_HPP__
#define __INCLUDED_SCMMODELSEQUENCE_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelSequence : public ScmData
    {
    private:
        friend class ScmModel;
        class SequenceFrameArray;

    private:
        ScmModel *  m_pModel;
        char        m_name[kSCM_NameLen];
        uint32_t    m_firstFrame;
        uint32_t    m_numFrames;
        float32_t   m_linearVelocity;
        uint8_t     m_bNormalized;
        SequenceFrameArray * m_pFrameArray;

    private:
        ScmModelSequence(void);

    public:
        ~ScmModelSequence(void);

        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);

        void PushFrame(void);
        void JointFrameTransform(
            const char * jointName,
            float32_t posx, float32_t posy, float32_t posz,
            float32_t rotx, float32_t roty, float32_t rotz,
            float32_t sclx, float32_t scly, float32_t sclz);
    };
};

#endif