/*
 *  android_logger.cpp
 *
 *  Copyright (C) 2026
 *  Terrapane Corporation
 *  All Rights Reserved
 *
 *  Author:
 *      Paul E. Jones <paulej@packetizer.com>
 *
 *  Description:
 *      This is a logger that builds on the standard Logger in order to emit
 *      logs to the native Android logger.
 *
 *  Portability Issues:
 *      Android-specific code.
 */

#include <android/log.h>
#include <terra/logger/logger.h>
#include <terra/logger/log_level.h>
#include <terra/logger/null_ostream.h>
#include <terra/logger/android_logger.h>

namespace Terra::Logger
{

namespace
{

// Just a dummy stream that has no meaning since our EmitMessage will log to
// the native Android logger
NullOStream &GetNullOStream()
{
    static NullOStream null_stream;

    return null_stream;
}

} // namespace

/*
 *  AndroidLogger::AndroidLogger()
 *
 *  Description:
 *      Constructor for the AndroidLogger object.
 *
 *  Parameters:
 *      android_log_tag [in]
 *          The log tag expected by Android
 *
 *      minimum_log_level [in]
 *          The log level at which messages will be logged.  Any message with
 *          a greater log level value (i.e., lower priority) will not be logged.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      None.
 */
AndroidLogger::AndroidLogger(std::string android_log_tag,
                             LogLevel minimum_log_level) :
    Logger(nullptr,
           {},
           minimum_log_level,
           LogFacility::Stream,
           GetNullOStream()),
    tag{std::move(android_log_tag)}
{
}

/*
 *  AndroidLogger::EmitLogMessage()
 *
 *  Description:
 *      This function will emit the log message to the Android system logger.
 *
 *  Parameters:
 *      log_level [in]
 *          Log level for this particular message.
 *
 *      message [in]
 *          The message to log.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      This function is called only by the root Logger object in the heirarchy
 *      of parent/child Logger objects.  As such, it can safely rely on
 *      log_facility being set to something other than "Inherit".
 */
void AndroidLogger::EmitLogMessage(LogLevel log_level,
                                   const std::string &message) const
{
    switch (log_level)
    {
        case LogLevel::Critical:
            __android_log_print(ANDROID_LOG_FATAL,
                                tag.c_str(),
                                "%s",
                                message.c_str());
            break;

        case LogLevel::Error:
            __android_log_print(ANDROID_LOG_ERROR,
                                tag.c_str(),
                                "%s",
                                message.c_str());
            break;

        case LogLevel::Warning:
            __android_log_print(ANDROID_LOG_WARN,
                                tag.c_str(),
                                "%s",
                                message.c_str());
            break;

        case LogLevel::Notice:
            __android_log_print(ANDROID_LOG_INFO,
                                tag.c_str(),
                                "%s",
                                message.c_str());
            break;

        case LogLevel::Info:
            __android_log_print(ANDROID_LOG_INFO,
                                tag.c_str(),
                                "%s",
                                message.c_str());
            break;

        case LogLevel::Debug:
            __android_log_print(ANDROID_LOG_DEBUG,
                                tag.c_str(),
                                "%s",
                                message.c_str());
            break;
    }
}

} // namespace Terra::Logger
