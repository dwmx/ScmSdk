#include <iostream>
#include "../include/ScmStreams.hpp"

namespace Scm
{
    ScmStreams::ScmStreams(void)
    {}

    ScmStreams::~ScmStreams(void)
    {}

    void ScmStreams::Import(ScmBuffer * const pBuffer, const char * file)
    {
        FILE * pFile;
        fopen_s(&pFile, file, "rb");
        fseek(pFile, 0, SEEK_END);
        int size = ftell(pFile);
        uint8_t * buffer = new uint8_t[size];
        fread(&buffer[0], sizeof(uint8_t), size, pFile);
        pBuffer->Write(&buffer[0], (uint32_t)size);
        delete[] buffer;
        fclose(pFile);
    }

    void ScmStreams::Export(ScmBuffer * const pBuffer, const char * file)
    {
        FILE * pFile;
        fopen_s(&pFile, file, "wb");
        fwrite(pBuffer->GetData(), pBuffer->GetSize(), 1, pFile);
        fclose(pFile);
        pFile = 0;
    }
};