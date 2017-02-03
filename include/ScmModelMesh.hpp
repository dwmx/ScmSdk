#ifndef __INCLUDED_SCMMODELMESH_HPP__
#define __INCLUDED_SCMMODELMESH_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelMesh : public ScmData
    {
    private:
        friend class ScmModel;

    private:
        class ScmModelTriangleArray;
        struct ScmModelTriangle
        {
            uint16_t    indices[3];
            uint8_t     texu[3];
            uint8_t     texv[3];
            uint8_t     polygroup;
        };

        class ScmModelVertexArray;
        struct ScmModelVertex
        {
            float32_t   offsets[6];
            uint8_t     joints[2];
            uint8_t     weights[2];
        };

        struct ScmModelPolygroup
        {
            uint16_t    skinPage;
            uint32_t    flags;
            uint8_t     damageJoint;
            char        groupName[kSCM_NameLen];
        };

    private:
        char                    m_name[kSCM_NameLen];
        ScmModelTriangleArray * m_pTriangles;
        ScmModelVertexArray *   m_pVertices;
        ScmModelPolygroup       m_polygroups[kSCM_NumPolyGroups];

    private:
        ScmModelMesh(void);
    public:
        ~ScmModelMesh(void);

    public:
        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);
    };
};

#endif