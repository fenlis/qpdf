// Write bits into a bit stream.  See BitStream for reading.

#ifndef __BITWRITER_HH__
#define __BITWRITER_HH__

#include <qpdf/DLL.h>

class Pipeline;

class DLL_EXPORT BitWriter
{
  public:
    // Write bits to the pipeline.  It is the caller's responsibility
    // to eventually call finish on the pipeline.
    BitWriter(Pipeline* pl);
    void writeBits(unsigned long val, int bits);
    // Force any partial byte to be written to the pipeline.
    void flush();

  private:
    Pipeline* pl;
    unsigned char ch;
    unsigned int bit_offset;
};

#endif // __BITWRITER_HH__
