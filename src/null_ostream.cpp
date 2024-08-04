/*
 *  null_ostream.cpp
 *
 *  Copyright (C) 2024
 *  Terrapane Corporation
 *  All Rights Reserved
 *
 *  Author:
 *      Paul E. Jones <paulej@packetizer.com>
 *
 *  Description:
 *      This file defines the NullOStream for use with the Logger.  It will
 *      act as an output stream, but emit nothing.  This is useful for programs
 *      that want to specify outputting to a streaming destination, but
 *      actually produce no output.
 *
 *  Portability Issues:
 *      None.
 */

#include <sstream>
#include <terra/logger/null_ostream.h>

namespace Terra::Logger
{

namespace
{

// Define the NullBuffer object that just discards input
class NullBuffer : public std::stringbuf
{
    public:
        NullBuffer() noexcept = default;

    protected:
        // Do nothing with the input, but report that all characters consumed
        std::streamsize xsputn([[maybe_unused]] const char *s,
                               std::streamsize count) override
        {
            return count;
        }
};

// Define a single, static instance of the NullBuffer object
NullBuffer null_buffer;

} // namespace

/*
 *  NullOStream::NullOStream()
 *
 *  Description:
 *      Constructor for the NullOStream object.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      None.
 */
NullOStream::NullOStream() noexcept : std::ostream(&null_buffer)
{
}

} // namespace Terra::Logger
