#ifndef __INCLUDED_SCMMODEL_HPP__
#define __INCLUDED_SCMMODEL_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"
#include "ScmModelSkin.hpp"
#include "ScmModelMesh.hpp"
#include "ScmModelJoint.hpp"
#include "ScmModelEvent.hpp"
#include "ScmModelSequence.hpp"
#include "ScmModelFrame.hpp"

namespace Scm
{
    class ScmModel : public ScmData
    {
    public:
        class ScmModelSkinArray;
        class ScmModelMeshArray;
        class ScmModelJointArray;
        class ScmModelEventArray;
        class ScmModelSequenceArray;
        class ScmModelFrameArray;

    private:
        uint32_t                m_scmVersion;
        uint32_t                m_modelType;
        char                    m_resourcePath[kSCM_LongNameLen];
        char                    m_exportPath[kSCM_LongNameLen];
        ScmModelSkinArray *     m_pSkinArray;
        ScmModelMeshArray *     m_pMeshArray;
        ScmModelJointArray *    m_pJointArray;
        ScmModelEventArray *    m_pEventArray;
        ScmModelSequenceArray * m_pSequenceArray;
        ScmModelFrameArray *    m_pFrameArray;
        float32_t               m_cumulativeScale[3];

    public:
        ScmModel(void);
        ~ScmModel(void);
        
    public:
        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);

        void SetResourcePath(const char * path);
        void SetExportPath(const char * path);

        ScmModelJoint * CreateJoint(void);
        ScmModelSequence * CreateSequence(void);
    };
};

#endif