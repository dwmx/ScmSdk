#include <vector>
#include "../include/ScmBuffer.hpp"

namespace Scm
{
    ////////////////////////////////////////////////////////////////////////////
    //  ScmByteArray
    //
    class ScmBuffer::ScmByteArray : public std::vector<uint8_t> {};

    ////////////////////////////////////////////////////////////////////////////
    //  ScmBuffer
    //
    ScmBuffer::ScmBuffer(void)
        : m_pData(0)
    {
        this->m_pData = new ScmByteArray;
    }

    ScmBuffer::~ScmBuffer(void)
    {
        delete this->m_pData;
        this->m_pData = 0;
    }

    ////////////////////////////////////////////////////////////////////////////
    void * ScmBuffer::GetData(void)
    {
        return &this->m_pData[0];
    }

    uint32_t ScmBuffer::GetSize(void)
    {
        return this->m_pData->size();
    }

    ////////////////////////////////////////////////////////////////////////////
    void ScmBuffer::Clear(void)
    {
        this->m_pData->clear();
    }

    void ScmBuffer::Write(void * pSource, uint32_t size)
    {
        for (uint32_t i = 0; i < size; ++i)
        {
            this->m_pData->push_back(((uint8_t *)pSource)[i]);
        }
    }
};