#include <vector>
#include <string>
#include "../include/ScmModel.hpp"

namespace Scm
{
    class ScmModel::ScmModelSkinArray : public std::vector<ScmModelSkin> {};
    class ScmModel::ScmModelMeshArray : public std::vector<ScmModelMesh> {};
    class ScmModel::ScmModelJointArray : public std::vector<ScmModelJoint> {};
    class ScmModel::ScmModelEventArray : public std::vector<ScmModelEvent> {};
    class ScmModel::ScmModelSequenceArray : public std::vector<ScmModelSequence> {};
    class ScmModel::ScmModelFrameArray : public std::vector<ScmModelFrame> {};

    typedef ScmModel::ScmModelSkinArray::iterator ScmModelSkinIterator;
    typedef ScmModel::ScmModelMeshArray::iterator ScmModelMeshIterator;
    typedef ScmModel::ScmModelJointArray::iterator ScmModelJointIterator;
    typedef ScmModel::ScmModelEventArray::iterator ScmModelEventIterator;
    typedef ScmModel::ScmModelSequenceArray::iterator ScmModelSequenceIterator;
    typedef ScmModel::ScmModelFrameArray::iterator ScmModelFrameIterator;

    ////////////////////////////////////////////////////////////////////////////
    ScmModel::ScmModel(void)
        :   m_scmVersion(kSCM_Version),
            m_modelType(MODELTYPE_NORMAL),
            m_pSkinArray(0),
            m_pMeshArray(0),
            m_pJointArray(0),
            m_pEventArray(0),
            m_pSequenceArray(0),
            m_pFrameArray(0)
    {
        memset(&this->m_resourcePath[0], 0, sizeof(char) * kSCM_LongNameLen);
        memset(&this->m_exportPath[0], 0, sizeof(char) * kSCM_LongNameLen);
        this->m_pSkinArray = new ScmModelSkinArray;
        this->m_pMeshArray = new ScmModelMeshArray;
        this->m_pJointArray = new ScmModelJointArray;
        this->m_pEventArray = new ScmModelEventArray;
        this->m_pSequenceArray = new ScmModelSequenceArray;
        this->m_pFrameArray = new ScmModelFrameArray;
        this->m_cumulativeScale[0] = 1.0;
        this->m_cumulativeScale[1] = 1.0;
        this->m_cumulativeScale[2] = 1.0;
    }
    
    ScmModel::~ScmModel(void)
    {
#define SAFE_DELETE_ARRAY(x) if(x != 0) { delete x; x = 0; }
        SAFE_DELETE_ARRAY(this->m_pSkinArray);
        SAFE_DELETE_ARRAY(this->m_pMeshArray);
        SAFE_DELETE_ARRAY(this->m_pJointArray);
        SAFE_DELETE_ARRAY(this->m_pEventArray);
        SAFE_DELETE_ARRAY(this->m_pSequenceArray);
        SAFE_DELETE_ARRAY(this->m_pFrameArray);
#undef SAFE_DELETE_ARRAY
    }
    
    ////////////////////////////////////////////////////////////////////////////
    //  Pack
    void ScmModel::Pack(ScmBuffer * const pBuffer)
    {
        ////////////////////////////////////////////////////////////////////////
        //  Scm Header
        char scmMagicNumber[4] = "SCM";
        pBuffer->Write(&scmMagicNumber[0], sizeof(char) * 4);
        pBuffer->Write(&this->m_scmVersion, sizeof(uint32_t));
        pBuffer->Write(&this->m_modelType, sizeof(uint32_t));
        pBuffer->Write(&this->m_resourcePath[0], sizeof(char) * kSCM_LongNameLen);
        pBuffer->Write(&this->m_exportPath[0], sizeof(char) * kSCM_LongNameLen);

        ////////////////////////////////////////////////////////////////////////
        //  Skins
        uint32_t scmSkinCount = this->m_pSkinArray->size();
        pBuffer->Write(&scmSkinCount, sizeof(uint32_t));

        for (ScmModelSkinIterator it = this->m_pSkinArray->begin();
            it != this->m_pSkinArray->end(); ++it)
        {
            it->Pack(pBuffer);
        }

        ////////////////////////////////////////////////////////////////////////
        //  Meshes
        uint32_t scmMeshCount = this->m_pMeshArray->size();
        pBuffer->Write(&scmMeshCount, sizeof(uint32_t));

        for (ScmModelMeshIterator it = this->m_pMeshArray->begin();
            it != this->m_pMeshArray->end(); ++it)
        {
            it->Pack(pBuffer);
        }

        ////////////////////////////////////////////////////////////////////////
        //  Joints
        uint32_t scmJointCount = this->m_pJointArray->size();
        pBuffer->Write(&scmJointCount, sizeof(uint32_t));

        for (ScmModelJointIterator it = this->m_pJointArray->begin();
            it != this->m_pJointArray->end(); ++it)
        {
            it->Pack(pBuffer);
        }

        ////////////////////////////////////////////////////////////////////////
        //  Events
        uint32_t scmEventCount = this->m_pEventArray->size();
        pBuffer->Write(&scmEventCount, sizeof(uint32_t));

        for (ScmModelEventIterator it = this->m_pEventArray->begin();
            it != this->m_pEventArray->end(); ++it)
        {
            it->Pack(pBuffer);
        }

        ////////////////////////////////////////////////////////////////////////
        //  Sequences
        uint32_t scmSequenceCount = this->m_pSequenceArray->size();
        pBuffer->Write(&scmSequenceCount, sizeof(uint32_t));

        for (ScmModelSequenceIterator it = this->m_pSequenceArray->begin();
            it != this->m_pSequenceArray->end(); ++it)
        {
            it->Pack(pBuffer);
        }

        ////////////////////////////////////////////////////////////////////////
        //  Frames
        uint32_t scmFrameCount = this->m_pFrameArray->size();
        pBuffer->Write(&scmFrameCount, sizeof(uint32_t));

        for (ScmModelFrameIterator it = this->m_pFrameArray->begin();
            it != this->m_pFrameArray->end(); ++it)
        {
            it->Pack(pBuffer);
        }

        ////////////////////////////////////////////////////////////////////////
        //  Cumulative scale
        pBuffer->Write(&this->m_cumulativeScale[0], sizeof(float32_t) * 3);

        ////////////////////////////////////////////////////////////////////////
        //  Decimation
        for (ScmModelMeshIterator it = this->m_pMeshArray->begin();
            it != this->m_pMeshArray->end(); ++it)
        {
            // Decimation data is per mesh - temporary
            uint32_t decCount = 0;
            uint32_t decChunkSize = 0;
            pBuffer->Write(&decCount, sizeof(uint32_t));
            pBuffer->Write(&decChunkSize, sizeof(uint32_t));
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////
    //  Unpack
    void ScmModel::Unpack(ScmBuffer * const pBuffer)
    {}

    ////////////////////////////////////////////////////////////////////////////
    ScmModelJoint * ScmModel::CreateJoint(void)
    {
        this->m_pJointArray->push_back(ScmModelJoint());
        this->m_pJointArray->back().m_pModel = this;
        return &this->m_pJointArray->back();
    }

    ScmModelSequence * ScmModel::CreateSequence(void)
    {
        this->m_pSequenceArray->push_back(ScmModelSequence());
        this->m_pSequenceArray->back().m_pModel = this;
        return &this->m_pSequenceArray->back();
    }
};