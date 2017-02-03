#ifndef __INCLUDED_SCMBUFFER_HPP__
#define __INCLUDED_SCMBUFFER_HPP__

#include "ScmTypes.hpp"

namespace Scm
{
    class ScmBuffer
    {
    private:
        class ScmByteArray;
        ScmByteArray * m_pData;

    public:
        ScmBuffer(void);
        ~ScmBuffer(void);

        void * GetData(void);
        uint32_t GetSize(void);

        void Clear(void);
        void Write(void * pSource, uint32_t size);
    };
};

#endif