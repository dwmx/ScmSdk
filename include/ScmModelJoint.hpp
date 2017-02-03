#ifndef __INCLUDED_SCMMODELJOINT_HPP__
#define __INCLUDED_SCMMODELJOINT_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelJoint : public ScmData
    {
    private:
        friend class ScmModel;

    private:
        struct ScmModelPlane
        {
            float32_t normal[3];
            float32_t pointRadius;
        };

    private:
        ScmModel *      m_pModel;
        char            m_name[kSCM_NameLen];
        int32_t         m_parent;
        int32_t         m_children[kSCM_MaxChildJoints];
        uint32_t        m_jointGroup;
        uint32_t        m_flags;
        ScmModelPlane   m_collisionBox[6];

    private:
        ScmModelJoint(void);
    public:
        ~ScmModelJoint(void);

    public:
        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);

    public:
        void SetName(const char * name);
    };
};

#endif