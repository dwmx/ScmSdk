#include <string>
#include "../include/ScmModelJoint.hpp"

namespace Scm
{
    ScmModelJoint::ScmModelJoint(void)
        :   m_pModel(0),
            m_parent(-1),
            m_jointGroup(0),
            m_flags(0)
    {
        memset(&this->m_name[0], 0, sizeof(char) * kSCM_NameLen);
        memset(&this->m_children[0], 0, sizeof(this->m_children));
        memset(&this->m_collisionBox[0], 0, sizeof(this->m_collisionBox));

        this->m_name[0] = '\0';
        this->m_children[0] = -1;
        this->m_children[1] = -1;
        this->m_children[2] = -1;
        this->m_children[3] = -1;

        // TODO: No idea if any of this is in the correct order,
        // or if 999.0f is a good idea for default radius
        float32_t defaultRadius = 999.0f;
        this->m_collisionBox[0].normal[0] = 1.0f;       // UnitX
        this->m_collisionBox[0].pointRadius = defaultRadius;
        this->m_collisionBox[1].normal[1] = 1.0f;       // UnitY
        this->m_collisionBox[1].pointRadius = defaultRadius;
        this->m_collisionBox[2].normal[2] = 1.0f;       // UnitZ
        this->m_collisionBox[2].pointRadius = defaultRadius;
        this->m_collisionBox[3].normal[0] = -1.0f;      // -UnitX
        this->m_collisionBox[3].pointRadius = defaultRadius;
        this->m_collisionBox[4].normal[1] = -1.0f;      // -UnitY
        this->m_collisionBox[4].pointRadius = defaultRadius;
        this->m_collisionBox[5].normal[2] = -1.0f;      // -UnitZ
        this->m_collisionBox[5].pointRadius = defaultRadius;
    }

    ScmModelJoint::~ScmModelJoint(void)
    {}

    void ScmModelJoint::Pack(ScmBuffer * const pBuffer)
    {
        pBuffer->Write(&this->m_name[0], sizeof(char) * kSCM_NameLen);
        pBuffer->Write(&this->m_parent, sizeof(int32_t));
        pBuffer->Write(&this->m_children[0], sizeof(int32_t) * kSCM_MaxChildJoints);
        pBuffer->Write(&this->m_jointGroup, sizeof(uint32_t));
        pBuffer->Write(&this->m_flags, sizeof(uint32_t));
        for (uint32_t i = 0; i < 6; ++i)
        {
            pBuffer->Write(&this->m_collisionBox[i].normal[0], sizeof(float32_t) * 3);
            pBuffer->Write(&this->m_collisionBox[i].pointRadius, sizeof(float32_t));
        }
    }

    void ScmModelJoint::Unpack(ScmBuffer * const pBuffer)
    {}

    void ScmModelJoint::SetName(const char * name)
    {
        memset(&this->m_name[0], 0, sizeof(char) * kSCM_NameLen);
        uint32_t i = 0;
        while (i < kSCM_NameLen - 1 && name[i] != '\0')
        {
            this->m_name[i] = name[i];
            ++i;
        }
        this->m_name[i] = '\0';
    }
};