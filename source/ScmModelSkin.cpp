#include <string>
#include "../include/ScmDef.hpp"
#include "../include/ScmModelSkin.hpp"

namespace Scm
{
    ScmModelSkin::ScmModelSkin(void)
        :   m_bitmapWidth(0),
            m_bitmapHeight(0),
            m_bitmap(0)
    {
        memset(&this->m_palette[0], 0, sizeof(this->m_palette));
    }

    ScmModelSkin::~ScmModelSkin(void)
    {
        if (m_bitmap != 0)
            delete m_bitmap;
        m_bitmap = 0;
    }

    void ScmModelSkin::Pack(ScmBuffer * const pBuffer)
    {
        //pBuffer->Write(&this->m_name[0], sizeof(this->m_name));
        pBuffer->Write(&this->m_palette[0], sizeof(this->m_palette));
        pBuffer->Write(&this->m_bitmapWidth, sizeof(int32_t));
        pBuffer->Write(&this->m_bitmapHeight, sizeof(int32_t));
        pBuffer->Write(&this->m_bitmap[0],
            sizeof(uint8_t) * this->m_bitmapWidth * this->m_bitmapHeight);
    }

    void ScmModelSkin::Unpack(ScmBuffer * const pBuffer)
    {}
};