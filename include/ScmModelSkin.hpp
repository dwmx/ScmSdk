#ifndef __INCLUDED_SCMMODELSKIN_HPP__
#define __INCLUDED_SCMMODELSKIN_HPP__

#include "ScmTypes.hpp"
#include "ScmDef.hpp"
#include "ScmData.hpp"

namespace Scm
{
    class ScmModelSkin : public ScmData
    {
    private:
        friend class ScmModel;

    private:
        char        m_name[kSCM_NameLen];
        uint8_t     m_palette[768];
        int32_t     m_bitmapWidth;
        int32_t     m_bitmapHeight;
        uint8_t *   m_bitmap;

    private:
        ScmModelSkin(void);
    public:
        ~ScmModelSkin(void);

    public:
        void Pack(ScmBuffer * const pBuffer);
        void Unpack(ScmBuffer * const pBuffer);
    };
};

#endif