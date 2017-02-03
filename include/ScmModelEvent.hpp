#ifndef __INCLUDED_SCMMODELEVENT_HPP__
#define __INCLUDED_SCMMODELEVENT_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelEvent : public ScmData
    {
    private:
        friend class ScmModel;

    private:
        ScmModelEvent(void);
    public:
        ~ScmModelEvent(void);

    public:
        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);
    };
};

#endif