#ifndef __INCLUDED_SCMSTREAMS_HPP__
#define __INCLUDED_SCMSTREAMS_HPP__

#include "ScmBuffer.hpp"

namespace Scm
{
    class ScmStreams
    {
    public:
        ScmStreams(void);
        ~ScmStreams(void);

        // Read the contents of file into pBuffer
        void Import(ScmBuffer * const pBuffer, const char * file);

        // Write the contents of pBuffer into file
        void Export(ScmBuffer * const pBuffer, const char * file);
    };
};

#endif