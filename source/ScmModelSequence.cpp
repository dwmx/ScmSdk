#include <string>
#include <vector>
#include <unordered_map>
#include "../include/ScmModelSequence.hpp"

namespace Scm
{
    struct JointTransform
    {
        float32_t position[3];  // XYZ joint translation
        float32_t rotation[3];  // Yaw Pitch Roll joint rotation
        float32_t scale[3];     // XYZ joint scaling
    };

    typedef std::unordered_map<const char *, JointTransform> SequenceFrame;

    class ScmModelSequence::SequenceFrameArray
        : public std::vector<SequenceFrame> {};

    ////////////////////////////////////////////////////////////////////////////
    ScmModelSequence::ScmModelSequence(void)
        :   m_pModel(0),
            m_firstFrame(0),
            m_numFrames(0),
            m_linearVelocity(0.0f),
            m_bNormalized(0),
            m_pFrameArray(0)
    {
        memset(&this->m_name[0], 0, sizeof(char) * kSCM_NameLen);
        this->m_name[0] = '\0';
        this->m_pFrameArray = new SequenceFrameArray;
    }

    ScmModelSequence::~ScmModelSequence(void)
    {
#define SAFE_DELETE_ARRAY(x) if(x != 0) { delete x; x = 0; }
        SAFE_DELETE_ARRAY(this->m_pFrameArray);
#undef SAFE_DELETE_ARRAY
    }

    ////////////////////////////////////////////////////////////////////////////
    //  Compression functions
    typedef std::vector<uint8_t> ScmModelSequenceCompression;
    static void CompressSequence(
        ScmModelSequence * pSequence,
        ScmModelSequenceCompression * pCompression)
    {
        pCompression->clear();
    }

    static void DecompressSequence(
        ScmModelSequence * pSequence,
        ScmModelSequenceCompression * pCompression)
    {
        pCompression->clear();
    }

    ////////////////////////////////////////////////////////////////////////////
    void ScmModelSequence::Pack(ScmBuffer * const pBuffer)
    {
        pBuffer->Write(&this->m_name[0], sizeof(char) * kSCM_NameLen);
        pBuffer->Write(&this->m_firstFrame, sizeof(uint32_t));
        pBuffer->Write(&this->m_numFrames, sizeof(uint32_t));
        pBuffer->Write(&this->m_linearVelocity, sizeof(float32_t));
        pBuffer->Write(&this->m_bNormalized, sizeof(uint8_t));

        // Compression
        ScmModelSequenceCompression scmSequenceCompressed;
        CompressSequence(this, &scmSequenceCompressed);
        uint32_t compressedLength = scmSequenceCompressed.size();

        pBuffer->Write(&compressedLength, sizeof(uint32_t));
        pBuffer->Write(&scmSequenceCompressed[0], sizeof(uint8_t) * compressedLength);
    }

    void ScmModelSequence::Unpack(ScmBuffer * const pBuffer)
    {}

    ////////////////////////////////////////////////////////////////////////////
    void ScmModelSequence::PushFrame(void)
    {
        this->m_pFrameArray->push_back(SequenceFrame());
        // TODO: Get a list of all joints from the model
        // and push a blank transform for all of them,
        // then only use valid joint names
    }

    void ScmModelSequence::JointFrameTransform(
        const char * jointName,
        float32_t posx, float32_t posy, float32_t posz,
        float32_t rotx, float32_t roty, float32_t rotz,
        float32_t sclx, float32_t scly, float32_t sclz)
    {
        // TODO: check joint name to ensure it's a joint already
        // added to the model
        if (this->m_pFrameArray->size() <= 0)
            return;

        // TODO: Get a pointer to the transform in the map instead
        // of creating a new one
        JointTransform jointTransform;
        memcpy(&jointTransform.position[0], &posx, sizeof(float32_t) * 3);
        memcpy(&jointTransform.rotation[0], &rotx, sizeof(float32_t) * 3);
        memcpy(&jointTransform.scale[0], &sclx, sizeof(float32_t) * 3);

        // Copy this joint transform to the hash map
        this->m_pFrameArray->back()[jointName] = jointTransform;
    }
};