/*
 *  android_logger.h
 *
 *  Copyright (C) 2026
 *  Terrapane Corporation
 *  All Rights Reserved
 *
 *  Author:
 *      Paul E. Jones <paulej@packetizer.com>
 *
 *  Description:
 *      This is a custom logger that builds on the Terrapane Logger in order
 *      to emit logs to native Android logging subsystem.
 *
 *  Portability Issues:
 *      Android-specific code.
 */

#pragma once

#include "logger.h"

namespace Terra::Logger
{

class AndroidLogger : public Logger
{
    public:
        explicit AndroidLogger(std::string android_log_tag,
                               LogLevel minimum_log_level = LogLevel::Debug);

    protected:
        std::string tag;
        void EmitLogMessage(LogLevel log_level,
                            const std::string &message) const override;
};


} // namespace Terra::Logger
