#ifndef __INCLUDED_SCMMODELDATA_HPP__
#define __INCLUDED_SCMMODELDATA_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelData : public ScmData
    {
    private:
        friend class ScmModel;

    protected:
        ScmModel *  m_pModel;
        char        m_name[kSCM_MediumNameLen];
        uint32_t    m_nameLength;
    };
};

#endif