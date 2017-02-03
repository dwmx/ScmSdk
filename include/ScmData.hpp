#ifndef __INCLUDED_SCMDATA_HPP__
#define __INCLUDED_SCMDATA_HPP__

#include "ScmTypes.hpp"
#include "ScmBuffer.hpp"

namespace Scm
{
    class ScmData
    {
    protected:
        ScmData(void) {}
    public:
        ~ScmData(void) {}
       
    public:
        virtual void Pack(ScmBuffer * const pBuffer) = 0;
        virtual void Unpack(ScmBuffer * const pBuffer) = 0;
    };
};

#endif